using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using RestaurantManager.Annotations;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.ViewModels;
using RestaurantManager.ViewModels.Shared;
using RestaurantManager.Views;

namespace RestaurantManager.Utility
{
    public sealed class SharedVmHelper : CoreCommandBook
    {
        #region Singleton imp
        private static readonly Lazy<SharedVmHelper>
            _lazy = new Lazy<SharedVmHelper>(() => new SharedVmHelper());
        private SharedVmHelper() { _sharedData = SharedDataModel.Instance; }
        public static SharedVmHelper Instance => _lazy.Value;
        #endregion

        //GoBackCommand
        public CoreCommand InGoBackCommand
        {
            get => GetVoidCommand(AppCommands.GoBack);
            set => SetVoidCommand(AppCommands.GoBack, ref value);
        }

        #region vms with shared data
        private WaiterViewModel _waiterViewModel = null;
        private ManagerViewModel _managerViewModel = null;
        private KitchenViewModel _kitchenViewModel = null;
        private SharedDataModel _sharedData = null;
        #endregion
        
        #region Vms Props
        public WaiterViewModel WaiterVm
        {
            get => _waiterViewModel;
            set => OnPropertyChanged(ref _waiterViewModel, value);
        }
        public ManagerViewModel ManagerVm
        {
            get => _managerViewModel;
            set => OnPropertyChanged(ref _managerViewModel, value);
        }
        public KitchenViewModel KitchenVm
        {
            get => _kitchenViewModel;
            set => OnPropertyChanged(ref _kitchenViewModel, value);
        }
        public SharedDataModel SharedDataModel
        {
            get => _sharedData;
            set => OnPropertyChanged(ref _sharedData, value);
        }
        #endregion

        //only to make outter code more clean
        #region ViewsGetters
        public WaiterView GetWaiterView => _waiterViewModel.ViewLink;
        public ManagerView GetManagerView => _managerViewModel.ViewLink;
        public KitchenView GetKitchenView => _kitchenViewModel.ViewLink;

        #endregion

        #region Loading Views
        public void LoadWaiter()
        {
            //var tmp=new WaiterView();
            WaiterVm = new WaiterViewModel(new WaiterView())
            {
                GoBackCommand = InGoBackCommand
            };

            //need to be after init
            WaiterVm.LoadUnSafe();

            //clearing memory
            ClearManager();
            ClearKitchen();
        }
        public void LoadManager()
        {
            ManagerVm = new ManagerViewModel(new ManagerView())
            {
                GoBackCommand = InGoBackCommand
            };
            //clearing memory
            ClearWaiter();
            ClearKitchen();
        }
        public void LoadKitchen()
        {
            KitchenVm = new KitchenViewModel(new KitchenView())
            {
                GoBackCommand = InGoBackCommand
            };
            //clearing memory
            ClearWaiter();
            ClearManager();
        }

        #endregion


        private bool _fileError = false;
        #region DataManagment
        public void LoadData()
        {
            //not null coz inited in constr
            if (_sharedData.LoadData() == false)
            {
                MessageBox.Show("There is a problem with files");
                _fileError = true;
            }
            else
            {
                MessageBox.Show("Files are loaded");
            }
        }
        public void SaveData()
        {
            if (_fileError == true)
            {
                
                var res=MessageBox.Show("There was a problem with loading files do you accept posible overding existing data?","Are u sure?",
                    MessageBoxButton.YesNo,MessageBoxImage.Warning);
               
                if(res==MessageBoxResult.No)
                    return;
            }

            if (_sharedData.SaveData() == false)
            {
                MessageBox.Show("There is a problem with files");
                

            }
            else
            {
                MessageBox.Show("Files are saved, Good bye");
            }
        }

        #endregion
        public void SetUserInfo(PassedUser userinfo)
        {
            SharedDataModel.LoggedUser = new PassedUser(userinfo);
        }

        #region Cleaning
        private void ClearWaiter()
        {
            if (WaiterVm != null)
            {
                WaiterVm.ViewLink.DataContext = null;
                WaiterVm.ViewLink = null;
                WaiterVm = null;
            }
        }
        private void ClearManager()
        {
            if (ManagerVm != null)
            {
                ManagerVm.ViewLink.DataContext = null;
                ManagerVm.ViewLink = null;
                ManagerVm = null;
            }
        }
        private void ClearKitchen()
        {
            if (KitchenVm != null)
            {
                KitchenVm.ViewLink.DataContext = null;
                KitchenVm.ViewLink = null;
                KitchenVm = null;
            }
        }
        #endregion
    }
}
