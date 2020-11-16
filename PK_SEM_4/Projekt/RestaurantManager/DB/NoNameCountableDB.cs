namespace RestaurantManager.DB
{
    public abstract class NoNameCountableDB : IdentityDB
    {
        private double _amount;
        public double Amount
        {
            get => _amount;
            set => OnPropertyChanged(ref _amount, value);
        }

        protected NoNameCountableDB(int id, double amount) : base(id)
        {
            _amount = amount;
        }

        //for deserialization purpose
        protected NoNameCountableDB():base(){}
    }
}
