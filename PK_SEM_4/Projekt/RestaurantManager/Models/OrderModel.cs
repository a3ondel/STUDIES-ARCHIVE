using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;
using RestaurantManager.DB;
using RestaurantManager.Utility;

namespace RestaurantManager.Models
{
    public sealed class OrderModel : NoNameCountableDB
    {
        private MealModel _meal;

        public MealModel Meal
        {
            get => _meal;
            set => OnPropertyChanged(ref _meal, value);
        }
        
        //need to inform Totalprice to update thats why new
        public new double Amount
        {
            set
            {
                base.Amount = value; 
                OnPropertyChanged(nameof(Amount));
                OnPropertyChanged(nameof(TotalPrice));
                NotifyCollection();
            }
            get => base.Amount;
        }

        public double TotalPrice
        {
            get => _meal.Price * base.Amount;
        }

        public OrderModel(int id, double amount, MealModel meal) : base(id, amount)
        {
            _meal = meal;
            
        }
        public OrderModel(OrderModel obj) :this(obj._Id,obj.Amount,obj._meal) { }

        public string Doable( List<SupplyModel> stockRoom)
        {

            var outOfStockSupplies = ListHelper.MealModelHelper(stockRoom, _meal.RequiredIngredients,base.Amount);

            if (outOfStockSupplies != null)
            {
                //stringbuilder for better performance
                StringBuilder stringBuilder = new StringBuilder();
                foreach (var line in outOfStockSupplies)
                {
                    stringBuilder.Append(line);
                    stringBuilder.AppendLine();
                }
                //Changing formating
                stringBuilder.Replace(@"{", "");
                stringBuilder.Replace(@"}", "");
                stringBuilder.Replace(@" =", ":");

                return stringBuilder.ToString();
            }

            //that indicates there is enough engridients to make a "meal"
            return null;
        }

        public override string ToString()
        {
            return $"{Meal._Name} x{Amount} each:{Meal.Price:C} all:{TotalPrice:C}";
        }
    }
}
