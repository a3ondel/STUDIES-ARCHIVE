using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;//observable collection
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;
using RestaurantManager.Views;
using RestaurantManager.Models;
using RestaurantManager.ViewModels.Shared.WaiterViewModels;
using RestaurantManager.ViewModels.Shared.WaiterViewModels.OrderItemSelection;
using RestaurantManager.ViewModels.Shared.WaiterViewModels.TableChoice;
using RestaurantManager.Views.WaiterViews;


namespace RestaurantManager.ViewModels.Shared
{
    public sealed class WaiterViewModel :PrimeSharedViewModel<WaiterView>
    {
        #region Enums  V-Goback  Arg-empty
        private enum VCommands
        {
            GoBack = 0
        }
        private enum ArgCommands
        {
            Byspass=3
        }

        #endregion

        #region ExternalCommands -GoBack
        public CoreCommand GoBackCommand
        {
            get => GetVoidCommand(VCommands.GoBack);
            set => SetVoidCommand(VCommands.GoBack, ref value);
        }

        public CoreCommand<object> BypassCommand
        {
            get => GetArgCommand(ArgCommands.Byspass);
            set => SetArgCommand(ArgCommands.Byspass,ref value);
        }

        #endregion

        #region InternalCommands -empty

        #endregion

        #region LocalData -empty

        #endregion

        #region internalVMs

        private SelectedTableViewModel _selectedTableViewModel;
        private OrderItemSelectionViewModel _orderItemSelectionViewModel;
        private CategoryControllerViewModel _categoryControllerViewModel;
        private TableChoiceViewModel _tableChoiceViewModel;
        #endregion

        #region Constractor - CTOR(..){ InitVM; setViews}
        public WaiterViewModel(WaiterView view) : base(view) 
        {  
            InitViewModels();
            SetViews();
        }
        #endregion

        #region InitViewModels

        private void InitViewModels()
        {
            _selectedTableViewModel=new SelectedTableViewModel(new SelectedTableView());
            _orderItemSelectionViewModel=new OrderItemSelectionViewModel(new OrderItemSelectionView());
            _categoryControllerViewModel = new CategoryControllerViewModel(new CategoryControllerView());
            _tableChoiceViewModel=new TableChoiceViewModel(new TableChoiceView());
        }
        #endregion

        private void SetViews()
        {
            ViewLink.SelectedTableController.Content = _selectedTableViewModel.ViewLink;
            ViewLink.MealControl.Content = _orderItemSelectionViewModel.ViewLink;
            ViewLink.CategoryControl.Content = _categoryControllerViewModel.ViewLink;
            ViewLink.TableChoiceControl.Content = _tableChoiceViewModel.ViewLink;
        }


        /// <summary>
        /// Binding eventhandlers
        /// </summary>
        public void LoadUnSafe()
        {
            _selectedTableViewModel.LoadUnSafe();
            _categoryControllerViewModel.ItemsToShowChanged += _orderItemSelectionViewModel.EvItemsToShowChanged;

            //pass new order
            _orderItemSelectionViewModel.NewOrder += _selectedTableViewModel.ActiveOrderControllerVM.AddItem;


            //loading TableChained from TableChoice
            _tableChoiceViewModel.TableChanged += _selectedTableViewModel.UppdateTableName;
            _tableChoiceViewModel.TableChanged += _selectedTableViewModel.ActiveOrderControllerVM.UpdateTable;
        }

    }
}
