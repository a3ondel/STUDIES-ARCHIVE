using RestaurantManager.Models;

namespace RestaurantManager.DB
{
    public abstract class CountableDB: NameDB
    {
        private double _amount;
        public double Amount
        {
            get => _amount;
            set => OnPropertyChanged(ref _amount,value);
        }

        protected CountableDB(int id, string name, double amount) : base(id, name)
        {
            _amount = amount;
        }

        //for deserialization purpose
        protected CountableDB():base(){}
    }
}
