using RestaurantManager.Core;

namespace RestaurantManager.DB
{
    public abstract class IdentityDB : CoreObservableObject
    {
        private int _id;
        public int _Id
        {
            get => _id;
            set => OnPropertyChanged(ref _id, value);
        }

        protected IdentityDB(int id)
        {
            _id = id;
        }

        //for deseriazlization purpouse
        protected IdentityDB(){}
    }
}
