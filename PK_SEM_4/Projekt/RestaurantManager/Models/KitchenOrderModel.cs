using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;

namespace RestaurantManager.Models
{
    public sealed class KitchenOrderModel : CoreObservableObject
    {
        private string _tableName;
        public string TableName
        {
            get => $"Table nr.{_tableName}";
            set => OnPropertyChanged(ref _tableName, value);
        }

        private OrderModel _order;
        public OrderModel Order
        {
            get => _order;
            set => OnPropertyChanged(ref _order, value);
        }

        public string Ammount => $"Ammount: {Order.Amount.ToString()}";
        public KitchenOrderModel(string tableName, OrderModel order)
        {
            _tableName = tableName;

            //new to avoid ref bound 
            _order = new OrderModel(order);
        }
    }
}
