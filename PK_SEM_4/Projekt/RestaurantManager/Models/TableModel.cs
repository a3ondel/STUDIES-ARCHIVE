using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.DB;

namespace RestaurantManager.Models
{
    //TODO
    public sealed class TableModel:NameDB
    {
        //initing to avoid nullreferenca
        private ObservableCollection<OrderModel> _oldOrders=new ObservableCollection<OrderModel>();
        public ObservableCollection<OrderModel> OldOrders
        {
            get => _oldOrders;
            set => OnPropertyChanged(ref _oldOrders, value);
        }

        //initing to avoid nullreferenca
        //TODO
        public ObservableCollection<OrderModel> _activeOrders=new ObservableCollection<OrderModel>();
        public ObservableCollection<OrderModel> ActiveOrders
        {
            get => _activeOrders;
            set => OnPropertyChanged(ref _activeOrders, value);
        }


        //mozliwe ze do wyrzucenia maybe trash
        private bool _isSelected;
        public bool IsSelected
        {
            get => _isSelected;
            
            set => OnPropertyChanged(ref _isSelected, value);
        }
        //basic constructor 
        public TableModel(int id, string name) : base(id, name) {}

        public TableModel(int id, string name, ObservableCollection<OrderModel> activeOrders) : base(id, name)
        {
            _activeOrders = activeOrders;
        }

    }
}
