using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using RestaurantManager.Core;
using RestaurantManager.Utility;

namespace RestaurantManager.Models
{
    public sealed class SharedDataModel : CoreObservableObject
    {
        private static readonly Lazy<SharedDataModel>
            _lazy = new Lazy<SharedDataModel>(() => new SharedDataModel());

        public static SharedDataModel Instance => _lazy.Value;

        private SharedDataModel() { }


        #region USELESS COMMENTS


        #endregion

        //Property no needed - prob with notifycation
        public event Action TableChangedEvent;

        private ObservableCollection<TableModel> _tablesCollection = new ObservableCollection<TableModel>();
        public ObservableCollection<TableModel> TablesCollection
        {
            get { tableChanged(); return _tablesCollection; }
            set
            {
                tableChanged(); OnPropertyChanged(ref _tablesCollection, value);
            }
        }

        //Property no needed - prob with notifycation
        private ObservableCollection<CategoryModel> _categoryCollection = new ObservableCollection<CategoryModel>();
        public ObservableCollection<CategoryModel> CategoryCollection
        {
            get => _categoryCollection;
            set => OnPropertyChanged(ref _categoryCollection, value);
        }

        private ObservableCollection<SupplyModel> _stockRoom = new ObservableCollection<SupplyModel>();
        public ObservableCollection<SupplyModel> StockRoom
        {
            get => _stockRoom;
            set => OnPropertyChanged(ref _stockRoom, value);
        }

        private ObservableCollection<KitchenOrderModel> _allKitchenOrders = new ObservableCollection<KitchenOrderModel>();

        public ObservableCollection<KitchenOrderModel> AllKitchenOrders
        {
            get => _allKitchenOrders;
            set => OnPropertyChanged(ref _allKitchenOrders, value);
        }

        private PassedUser _loggedUser;
        public PassedUser LoggedUser
        {
            get => _loggedUser;
            set => OnPropertyChanged(ref _loggedUser, value);
        }

        public bool IsTableSelected { get; set; } = false;

        //TIME PLACEHOLDER NIE WIADOMO CZY DODAM

        //all collections are inited
        //loads stockroom and categories (Users are loaded inside managerVM)
        public bool LoadData()
        {
            //testloadData();
           // SaveData();

            _categoryCollection = FileHelper.FileReader<ObservableCollection<CategoryModel>>("..\\Data\\Categories.json");
            _stockRoom = FileHelper.FileReader<ObservableCollection<SupplyModel>>("..\\Data\\StockRoom.json");

            if (_categoryCollection?.Count < 0)
                return false;

            if (_stockRoom?.Count < 0)
                return false;

            return true;

        }

        public bool SaveData()
        {
            if (FileHelper.FileWriter("..\\Data\\Categories.json", _categoryCollection) == false)
                return false;

            if (FileHelper.FileWriter("..\\Data\\StockRoom.json", _stockRoom) == false)
                return false;

            return true;
        }

        private void testloadData()
        {

            //TablesCollection.Add(new TableModel(0,"STOLIK STARTOWY"));

            KATEGORIETEST();
            SUPPLIESTEST();
            //loading categories
            //TODO


        }
        private void KATEGORIETEST()
        {
            CategoryCollection.Add(new CategoryModel(0, "Miesho", "", new ObservableCollection<MealModel>()
            {
                new MealModel(1,"kotelon",4,null),
                new MealModel(2,"pieoogi",2.56,null),
                new MealModel(3,"powietrze",0,null)
            }));
            CategoryCollection.Add(new CategoryModel(1, "Zupy", "", new ObservableCollection<MealModel>(){
                new MealModel(4,"Pomidorowa",7.2,new List<IngredientModel>(){
                    new IngredientModel(1,25),
                    new IngredientModel(2,10)

                })
            }));
            CategoryCollection.Add(new CategoryModel(0, "koktajle", "siema.png"));
        }

        private void SUPPLIESTEST()
        {
            StockRoom.Add(new SupplyModel(13, "mieso", 100, 100, "kg"));
            StockRoom.Add(new SupplyModel(12, "pomidor", 100, 100, "szt"));
        }

        private void tableChanged()
        {
            TableChangedEvent?.Invoke();
        }
    }
}
