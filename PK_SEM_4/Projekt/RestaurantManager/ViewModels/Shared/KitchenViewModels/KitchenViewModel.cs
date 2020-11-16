using System.Collections.Generic;
using System.IO;
using System.Windows;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Utility;
using RestaurantManager.ViewModels.Shared.KitchenViewModels;
using RestaurantManager.Views;
using RestaurantManager.Views.KitchenViews;

namespace RestaurantManager.ViewModels.Shared
{
    public sealed class KitchenViewModel : PrimeSharedViewModel<KitchenView>
    {
        private enum VCommands
        {
            GoBack = 0
        }
        private enum ArgCommands
        {
            
        }

        #region Commands - GoBackCommand
        public CoreCommand GoBackCommand
        {
            get => GetVoidCommand(VCommands.GoBack);
            set => SetVoidCommand(VCommands.GoBack, ref value);
        }
        #endregion

        #region KitchenController

        private KitchenControllerViewModel _kitchenControllerVM;
        #endregion

        #region CTOR - TESTING
        public KitchenViewModel(KitchenView view) : base(view)
        {
            InitVms();
            InitViews();
        }
        #endregion

        private void InitViews()
        {
            ViewLink.KitchenContentControl.Content = _kitchenControllerVM.ViewLink;

        }

        private void InitVms()
        {
            _kitchenControllerVM=new KitchenControllerViewModel(new KitchenControllView());

        }

    }

    ////TESTING
    //var TestMeal = new MealModel(1, "kotelschabowy", 10, new List<IngredientModel>(){new IngredientModel(1,15),
    //new IngredientModel(2,200)});


    ////TESTING
    //var TestStock = new List<SupplyModel>(){new SupplyModel(2,"miechso",100,5,"kg"),
    //new SupplyModel(1,"ser",10,50,"kg")};
    ////MessageBox.Show(TestMeal.Doable(ref TestStock));
}
