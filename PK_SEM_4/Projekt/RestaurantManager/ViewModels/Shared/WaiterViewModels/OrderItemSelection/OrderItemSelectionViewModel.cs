using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Views.WaiterViews;

namespace RestaurantManager.ViewModels.Shared.WaiterViewModels.OrderItemSelection
{
    public sealed class OrderItemSelectionViewModel : SharedDataViewModel<OrderItemSelectionView>
    {
        //TODO:
        //ADD ORDER COMMAND thats adds order to 'global' list

        #region test

        private OrderModel _selectedOrder = null;
        public OrderModel SelectedOrder
        {
            get => _selectedOrder;
            set { _selectedOrder = value; }
        }

        private ObservableCollection<OrderModel> _activeOrdersCollection = new ObservableCollection<OrderModel>();
        public ObservableCollection<OrderModel> OrdersCollection
        {
            get => _activeOrdersCollection;
            set { OnPropertyChanged(ref _activeOrdersCollection, value); }
        }

        private enum ArgCommands
        {
            AddOrder = 22
        }

        public CoreCommand<object> AddOrderCommand
        {
            get => GetArgCommand(ArgCommands.AddOrder);
            set => SetArgCommand(ArgCommands.AddOrder, ref value);
        }

        //pass list from category to show 
        public void EvItemsToShowChanged(object sender, ObservableCollection<OrderModel> e)
        {
            OrdersCollection = e;
        }

        private void TestInitOrederCollection()
        {
            OrdersCollection.Add(new OrderModel(0, 2, new MealModel(0, "kotslet", 1.8, null)));
            OrdersCollection.Add(new OrderModel(1, 2, new MealModel(0, "kotlset", 1.8, null)));
            OrdersCollection.Add(new OrderModel(2, 2, new MealModel(0, "kotlet", 1.8, null)));
            OrdersCollection.Add(new OrderModel(3, 2, new MealModel(0, "kotslet", 1.8, null)));
            OrdersCollection.Add(new OrderModel(4, 2, new MealModel(0, "kotlset", 1.8, null)));
            OrdersCollection.Add(new OrderModel(0, 2, new MealModel(0, "kotlet", 1.8, null)));
            OrdersCollection.Add(new OrderModel(0, 2, new MealModel(0, "kotlsset", 1.8, null)));
            OrdersCollection.Add(new OrderModel(0, 2, new MealModel(0, "kotlsset", 1.8, null)));
            OrdersCollection.Add(new OrderModel(0, 2, new MealModel(0, "kotlet", 1.8, null)));
        }

        #endregion

        #region Contructor
        public OrderItemSelectionViewModel(OrderItemSelectionView view) : base(view)
        {
            //TestInitOrederCollection();
            InitCommands();

        }
        #endregion

        private void AddOrder(object passedArg)
        {

            if (SharedData.IsTableSelected == false)
            {
                MessageBox.Show("No table selected!", "Warning", MessageBoxButton.OK,
                MessageBoxImage.Error);
                
                return;
            }

            OrderModel tmp = (OrderModel)passedArg;
            if (tmp != null)
            {
                string noSupplies = tmp.Doable(SharedData.StockRoom.ToList());

                if (!string.IsNullOrEmpty(noSupplies))
                {
                    //only information about supplies. After confirm real check appears and apples
                    var resault = MessageBox.Show($"Possible no supllies in Storage\n{noSupplies}\nDo you want to continue?",
                        "WARNING", MessageBoxButton.YesNo);
                   
                    if (resault == MessageBoxResult.No || resault == MessageBoxResult.Cancel)
                        return;
                }
                NewOrder?.Invoke(null, tmp);
            }
        }

        //to pass new order
        public event EventHandler<OrderModel> NewOrder;

        #region Init

        //TODO
        private void InitOnstart()
        {

        }

        private void InitCommands()
        {
            AddOrderCommand = new CoreCommand<object>(AddOrder);
        }



        #endregion

    }
}
