using System;
using RestaurantManager.DB;

namespace RestaurantManager.Models
{
    /// <summary>
    /// Class to identify Id of supply and ammount required to make a "meal"
    /// </summary>
    /// <remarks>
    ///Item1 = ID
    /// Item2 = Ammount
    /// </remarks>
    public sealed class IngredientModel:NoNameCountableDB
    {

        /// <summary>
        /// 
        /// </summary>
        /// <param name="id"></param>
        /// <param name="amount"></param>
        public IngredientModel(int id, double amount) : base(id, amount) { }

        //for deserialization purpose
        public IngredientModel():base(){}
    }
}
