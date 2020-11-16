using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Models;

namespace RestaurantManager.Utility
{
    public static class ListHelper
    {
        /// <summary>
        /// make list of supplies/indgridents that are not enough in stock
        /// </summary>
        /// <param name="stockRoom"></param>
        /// <param name="requiredIngredients"></param>
        /// <returns></returns>
        public static List<string> MealModelHelper(ref List<SupplyModel> stockRoom, ref List<IngredientModel> requiredIngredients,double times=1)
        {
            if (stockRoom == null || requiredIngredients == null)
                return null;

            var tmpEnumerable = from supplies in stockRoom
                                join requiredIn in requiredIngredients on supplies._Id equals requiredIn._Id into Prodgroup
                                from ingredient in Prodgroup
                                where ingredient.Amount > supplies.Amount
                                select new { Supply = supplies._Name, InStock = supplies.Amount.ToString(), Required = ingredient.Amount.ToString() }.ToString();
            
            return tmpEnumerable.ToList();
        }
        

        //no reference version
        public static List<string> MealModelHelper(List<SupplyModel> stockRoom,  List<IngredientModel> requiredIngredients, double times)
        {
            if (stockRoom == null || requiredIngredients == null)
                return null;

            var tmpEnumerable = from supplies in stockRoom
                join requiredIn in requiredIngredients on supplies._Id equals requiredIn._Id into Prodgroup
                from ingredient in Prodgroup
                where ingredient.Amount*times > supplies.Amount
                select new { Supply = supplies._Name, InStock = supplies.Amount.ToString(), Required =
                    (ingredient.Amount*times).ToString() }.ToString();

            return tmpEnumerable.ToList();
        }


        ///<summary>
        ///changes categorie to orderlist
        /// </summary>
        public static ObservableCollection<OrderModel> MakeOrdersFromCats(CategoryModel passedCategory)
        {
            ObservableCollection<OrderModel> resault=new ObservableCollection<OrderModel>();

            var mealsCollection = passedCategory.CategoryMealsCollection;

            //null if mealcollection is empty
            if (mealsCollection == null)
                return resault;

            foreach (var meal in mealsCollection)
            {
                resault.Add(new OrderModel(meal._Id,1,meal));
            }

            return resault;
        }


        //makes collection of orders based on categoeis
        public static ObservableCollection<OrderModel> LookForOrders(ObservableCollection<CategoryModel> allCategories,string itemName)
        {
            ObservableCollection<OrderModel> resault=new ObservableCollection<OrderModel>();

            foreach (var cat in allCategories)
            {
                if(cat.CategoryMealsCollection==null)
                    continue;

                foreach (var meal in cat.CategoryMealsCollection)
                {
                    if(meal._Name.Contains(itemName))
                        resault.Add(new OrderModel(0,1,meal));
                }
                
            }
            return resault;
        }

        //calculates total price of order
        public static double CalculatePrice(ObservableCollection<OrderModel> oldOrders, ObservableCollection<OrderModel> activeOrders)
        {
            double resault = 0;

            if (oldOrders == null && activeOrders == null)
                return resault;

            if (oldOrders != null)
            {
                foreach (var order in oldOrders)
                {
                    resault += order.Amount * order.Meal.Price;
                }
            }

            if (activeOrders == null)
                return resault;

            foreach (var order in activeOrders)
            {
                resault += order.Amount * order.Meal.Price;
            }

            return resault;
        }


    }
}
