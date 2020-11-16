using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using RestaurantManager.DB;
using RestaurantManager.Utility;


namespace RestaurantManager.Models
{
    
    public sealed class MealModel:NameDB
    {
        private double _price;

        public double Price
        {
            get => _price;
            set => OnPropertyChanged(ref _price,value);
        }

        private List<IngredientModel> _ingredients;

        public List<IngredientModel> RequiredIngredients
        {
            get => _ingredients;
            set => _ingredients = value;
        }

        public MealModel(int id, string name, double price, List<IngredientModel> ingredients) : base(id, name)
        {
            _price = price;
            _ingredients = ingredients;
            
            
        }

        /// <summary>
        /// Tells if There is enough ingredients in stock otherwise tells what ingreditents are missing
        /// </summary>
        /// <param name="stockRoom"></param>
        /// <returns>
        /// null represents there is enough supplies in stock
        /// string value represents information about missing ingredients
        /// </returns>
        public string Doable(ref List<SupplyModel> stockRoom)
        {
            var outOfStockSupplies = ListHelper.MealModelHelper(ref stockRoom, ref _ingredients);

            if (outOfStockSupplies != null)
            {
                //stringbuilder for better performance
                StringBuilder stringBuilder=new StringBuilder();
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
        
    }
}
