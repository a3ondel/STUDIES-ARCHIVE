using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Utility;
using RestaurantManager.Views.WaiterViews;

namespace RestaurantManager.ViewModels.Shared.WaiterViewModels
{
    public sealed  class CategoryControllerViewModel : SharedDataViewModel<CategoryControllerView>
    {

        public event EventHandler<ObservableCollection<OrderModel>> ItemsToShowChanged;

        
        //collection only for passing
        private ObservableCollection<OrderModel> _itemsToDisplay=new ObservableCollection<OrderModel>();
        public ObservableCollection<OrderModel> ItemsToDisplay
        {
            get => _itemsToDisplay;
            set
            {
                _itemsToDisplay = value;
                ItemsToShowChanged?.Invoke(null, ItemsToDisplay); }
            }

        private CategoryModel _activeCategory;
        public CategoryModel ActiveCategory
        {
            get => _activeCategory;
            set
            {
                OnPropertyChanged(ref _activeCategory,value);
                ItemsToDisplay = ListHelper.MakeOrdersFromCats(ActiveCategory);
            }
        }

        //testing
        private ObservableCollection<CategoryModel> _tmpCategories=new ObservableCollection<CategoryModel>();
        
        //Categories from SharedData
        public ObservableCollection<CategoryModel> Categories
        {
            get => SharedData.CategoryCollection;
            set
            {

                SharedData.CategoryCollection = value;
                OnPropertyChanged();
            }
        }

        private string _searchtext = "";
        public string SearchTextBox
        {
            get => _searchtext;
            set => OnPropertyChanged(ref _searchtext ,value);
        }

        private enum ArgCommand
        {
            SearchItems=44
        }
        public CoreCommand SearchItemsCommand
        {
            get => GetVoidCommand(ArgCommand.SearchItems);
            set => SetVoidCommand(ArgCommand.SearchItems, ref value);
        }

        private void SearchItems()
        {

            MessageBox.Show($"{SearchTextBox}");
            ItemsToDisplay = ListHelper.LookForOrders(Categories, SearchTextBox);
           
            
            //TODO REACT FOR SEARCHING ITMES
            //CONFIRM SEARCHING
            //TAKES SearchText as obj to send
        }

        #region Constructor - initcommands

        public CategoryControllerViewModel(CategoryControllerView view) : base(view)
        {
           InitCommands();
           
        }

        
        #endregion

        #region Init

        //very important to init it at the begining
        private void InitCommands()
        {
            SearchItemsCommand=new CoreCommand(SearchItems);
        }
        
        
        

        #endregion
    }
}
