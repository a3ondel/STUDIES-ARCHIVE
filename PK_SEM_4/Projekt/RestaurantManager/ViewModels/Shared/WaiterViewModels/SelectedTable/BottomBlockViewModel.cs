using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Utility;
using RestaurantManager.Views.WaiterViews;

namespace RestaurantManager.ViewModels.Shared.WaiterViewModels
{
   public sealed class BottomBlockViewModel : CoreViewModel
    {

        #region Commands -Only external commands
        //commands used as command passers
        private enum ArgCommands
        {
            CloseTable = 99
        }
        private enum VCommands
        {
            Bill = 44
        }

        public CoreCommand<object> CloseTableCommand
        {
            get => GetArgCommand(ArgCommands.CloseTable);
            set => SetArgCommand(ArgCommands.CloseTable, ref value);

        }
        public CoreCommand BillCommand
        {
            get => GetVoidCommand(VCommands.Bill);
            set => SetVoidCommand(VCommands.Bill, ref value);

        }

        #endregion
        #region CTOR -{}
        public BottomBlockViewModel() { }
        #endregion

        private double _totalPrice = 0;
        public double TotalPrice
        {
            get => _totalPrice;
            set
            {
                OnPropertyChanged(ref _totalPrice, value);
            }
        }

        //event method fires after orderchanged in activecontroller
        public void OnOrdersChanged(object x, TableModel e)
        {
            if (e == null)
                TotalPrice = 0;
            else
            {
                TotalPrice = ListHelper.CalculatePrice(e.OldOrders, e.ActiveOrders);
            }
        }
    }
}
