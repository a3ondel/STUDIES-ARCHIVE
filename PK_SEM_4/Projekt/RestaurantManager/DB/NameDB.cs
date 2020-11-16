namespace RestaurantManager.DB
{
    public abstract class NameDB : IdentityDB
    {
        private string _name;
        public string _Name
        {
            get => _name;
            set => OnPropertyChanged(ref _name, value);
        }

        protected NameDB(int id, string name) : base(id)
        {
            _name = name;
        }
        //for deserialization purpose
        protected NameDB(){}
    }
}
