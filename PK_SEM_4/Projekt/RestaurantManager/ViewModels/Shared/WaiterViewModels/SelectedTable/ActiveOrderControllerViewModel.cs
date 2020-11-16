using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Forms;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Utility;
using RestaurantManager.Views.WaiterViews;
using RestaurantManager.Views.WaiterViews.SelectedTable.Items;
using MessageBox = System.Windows.MessageBox;

namespace RestaurantManager.ViewModels.Shared.WaiterViewModels
{
    public class ActiveOrderControllerViewModel : SharedDataViewModel<ActiveOrderControllerView>
    {
        //mostly to inform bottom block price could be used somewhere else in a future
        public event EventHandler<TableModel> OrdersChanged;

        //Informs TableChoice to update and bottomblock 
        // public event EventHandler<TableModel> TableClosed;
        private BottomBlockViewModel _blockViewModel;
        public BottomBlockViewModel BottomBViewModel
        {
            get => _blockViewModel;
            private set => OnPropertyChanged(ref _blockViewModel, value);
        }

        public OrderModel SelectedOrder
        {
            get { updateTotalPrice(); return null; }
            set =>updateTotalPrice();
        }

        public ObservableCollection<OrderModel> ActiveOrdersCollection
        {
            //returns active orders, if active-table is not null, otherwise null
            get
            {
                updateTotalPrice();
                return _activeTable?.ActiveOrders;
            }
            set
            { 
                _activeTable.ActiveOrders = value;
                updateTotalPrice();
                OnPropertyChanged();
            }
        }

        //not a placeholder- it will be sent by Table choiceVM
        private TableModel _activeTable = null;
        public TableModel ActiveTable
        {
            get
            {
                //updateTotalPrice();
                return _activeTable;
            }
            set
            {
                OnPropertyChanged(ref _activeTable, value);

                //Need to inform UI!
                OnPropertyChanged(nameof(ActiveOrdersCollection));
                updateTotalPrice();


            }
        }

        #region Commands
        private enum ArgCommands
        {
            DeleteOrder = 99, CloseTable = 77
        }
        private enum VCommands
        {
             Bill = 88, AcceptOrder = 22
        }


        public CoreCommand<object> DeleteOrderCommand
        {
            set => SetArgCommand(ArgCommands.DeleteOrder, ref value);
            get => GetArgCommand(ArgCommands.DeleteOrder);
        }
        private void DeleteOrder(object passedOrder)
        {
            OrderModel orderToRemove = (OrderModel)passedOrder;
            ActiveOrdersCollection.Remove(orderToRemove);
            updateTotalPrice();
        }

        //command activated by bottomblock button
        public CoreCommand<object> CloseTableCommand
        {
            get => GetArgCommand(ArgCommands.CloseTable);
            set => SetArgCommand(ArgCommands.CloseTable, ref value);
        }
        //null indactes msg to show
        private void CloseTable(object show)
        {
            if (SharedData.IsTableSelected == false)
            {
                MessageBox.Show("No table selected!", "Warning", MessageBoxButton.OK,
                    MessageBoxImage.Error);
                return;
            }
            
            if(show==null)
                MessageBox.Show("Table have been closed");

            SharedData.TablesCollection.Remove(ActiveTable);
            ActiveTable = null;
            
            SharedData.IsTableSelected = false;

            updateTotalPrice();

        }

        public CoreCommand BillCommand
        {
            get => GetVoidCommand(VCommands.Bill);
            set => SetVoidCommand(VCommands.Bill, ref value);
        }
        private void Bill()
        {
            //TODO MAKE SOME STUFF
            if (ActiveTable != null)
            {
                
                var res=
                    MessageBox.Show($"ARE YOU SURE ABOUT MAKING A BILL AND CLOSE CURRENT TABLE? (TABLE {ActiveTable._Id})","WARNING!"
                        ,MessageBoxButton.YesNo,MessageBoxImage.Warning);
                if(res==MessageBoxResult.No)
                    return;

                //ends here if ...
                if (ActiveTable.ActiveOrders.Count>0)
                {
                    MessageBox.Show("First confirm orders!", "WARNING", MessageBoxButton.OK,MessageBoxImage.Error);
                    return;
                }

                double totalPrice = ListHelper.CalculatePrice(ActiveTable.OldOrders, ActiveTable.ActiveOrders);
                PopupWin popup = new PopupWin();

                StringBuilder billMsg = new StringBuilder();
                foreach (var order in ActiveTable.OldOrders)
                {
                    billMsg.AppendFormat("- {0}\n", order.ToString());
                }

                billMsg.AppendLine($"\nTOTAL PRICE: {totalPrice:C}");

                popup.setMsg(billMsg.ToString());
                popup.Show();
                CloseTable(' ');
            }
            else
            {
                //trash
                MessageBox.Show("No Table is Selected! ","Warning",MessageBoxButton.OK,MessageBoxImage.Error);
            }

        }

        public CoreCommand AcceptOrderCommand
        {
            get => GetVoidCommand(VCommands.AcceptOrder);
            set => SetVoidCommand(VCommands.AcceptOrder, ref value);
        }

        private void AcceptOrder()
        {
            if (ActiveTable == null || ActiveTable.ActiveOrders.Count < 1)
                return;

            foreach (var activeorder in ActiveTable.ActiveOrders)
            {
                ActiveTable.OldOrders.Add(new OrderModel(activeorder));
            }

            OdersToKitchen();
            ActiveTable.ActiveOrders.Clear();
            updateTotalPrice();
            MessageBox.Show("OrderAccepted");
        }

        private void OdersToKitchen()
        {
            if (ActiveTable == null || ActiveTable.ActiveOrders == null)
                return;

            foreach (var order in ActiveTable.ActiveOrders)
            {
                SharedData.AllKitchenOrders.Add(new KitchenOrderModel(ActiveTable._Name, new OrderModel(order)));
            }
        }
        #endregion

        #region EventHandlers
        //adds items to collection
        //passed order can't be null
        public void AddItem(object x, OrderModel e)
        {
            ActiveOrdersCollection?.Add(new OrderModel(e));
            updateTotalPrice();
        }

        //It is bound to event active table chained in Table Choice VM
        public void UpdateTable(object x, TableModel passedTable)
        {
            //referenced in list
            ActiveTable = passedTable;
        }

        //Alias method to orderschanged event invoker 
        private void updateTotalPrice()
        {
            //not prop to avoid inf loop
            OrdersChanged?.Invoke(null, _activeTable);
        }
        #endregion

        #region Constructor
        public ActiveOrderControllerViewModel(ActiveOrderControllerView view) : base(view)
        {
            InitOnStart();
        }

        #endregion

        #region Init
        private void InitOnStart()
        {
            InitCommands();
            InitVms();
        }

        private void InitCommands()
        {
            DeleteOrderCommand = new CoreCommand<object>(DeleteOrder);
            CloseTableCommand = new CoreCommand<object>(CloseTable);
            BillCommand = new CoreCommand(Bill);
            AcceptOrderCommand = new CoreCommand(AcceptOrder);
        }

        //initing internal vms - Bottom block to be exact
        private void InitVms()
        {
            BottomBViewModel = new BottomBlockViewModel();
        }


        //use it after whole init of all needed vms and views
        public void LoadUnSafe()
        {
            //binding reaction to changes
            OrdersChanged += BottomBViewModel.OnOrdersChanged;
            BottomBViewModel.BillCommand = BillCommand;
            BottomBViewModel.CloseTableCommand = CloseTableCommand;

        }
        #endregion

    }

}

#region test
//private void TestInitOrederCollection()
//{
//if (ActiveOrdersCollection != null)
//{
//    ActiveOrdersCollection.Add(new OrderModel(0, 2, new MealModel(0, "kotlet", 1.8, null)));
//    ActiveOrdersCollection.Add(new OrderModel(1, 2, new MealModel(0, "serek", 34.0, null)));
//    ActiveOrdersCollection.Add(new OrderModel(2, 2, new MealModel(0, "serek2", 23.7, null)));
//    ActiveOrdersCollection.Add(new OrderModel(99, 2, new MealModel(0, "serek3", 6.1, null)));
//    ActiveOrdersCollection.Add(new OrderModel(99, 2, new MealModel(0, "serek3", 6.1, null)));
//    ActiveOrdersCollection.Add(new OrderModel(99, 2, new MealModel(0, "serek3", 6.1, null)));
//}
//}
#endregion