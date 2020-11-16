using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using RestaurantManager.Core;
using RestaurantManager.Views;
using RestaurantManager.Models;
using RestaurantManager.ViewModels.Shared.ManagerViewModels;
using RestaurantManager.Views.ManagerViews;

namespace RestaurantManager.ViewModels.Shared
{
    public sealed class ManagerViewModel : PrimeSharedViewModel<ManagerView>
    {
        #region Enums  V-Goback GoCategories, GoSupplies, GoIncome, GoSuppliers, UserManagment,Add, Edit, Del 
        private enum VCommands
        {
            GoBack = 0, GoCategories,GoMeals, GoSupplies, GoUserManagment
        }


        public enum OptCommands
        {
            OptAdd, OptEdit, OptDel
        }

        #endregion

        #region Commands and methods to those
        //external vm go back command
        public CoreCommand GoBackCommand
        {
            get => GetVoidCommand(VCommands.GoBack);
            set => SetVoidCommand(VCommands.GoBack, ref value);
        }
        
        //internal vm commands...
        public CoreCommand GoCategoriesCommand
        {
            get => GetVoidCommand(VCommands.GoCategories);
            set => SetVoidCommand(VCommands.GoCategories,ref value);
        }
        private void GoCategories()
        {
            SetView(_catVM.ViewLink);

            ReplaceInternalCommands(_catVM);

            UpdateSideBarCommands();

        }

        public CoreCommand GoMealsCommand
        {
            get => GetVoidCommand(VCommands.GoMeals);
            set => SetVoidCommand(VCommands.GoMeals, ref value);
        }
        private void GoMeals()
        {
            SetView(_mealsVM.ViewLink);
            
            ReplaceInternalCommands(_mealsVM);

            UpdateSideBarCommands();

        }

        public CoreCommand GoSuppliesCommand
        {
            get => GetVoidCommand(VCommands.GoSupplies);
            set => SetVoidCommand(VCommands.GoSupplies, ref value);
        }
        private void GoSupplies()
        {
            SetView(_supVM.ViewLink);

            ReplaceInternalCommands(_supVM);

            UpdateSideBarCommands();
        }

        public CoreCommand GoUserManagmentCommand
        {
            get => GetVoidCommand(VCommands.GoUserManagment);
            set => SetVoidCommand(VCommands.GoUserManagment, ref value);
        }
        
        private void GoUserManagment()
        {
            SetView(_userVM.ViewLink);
            
            ReplaceInternalCommands(_userVM);

            UpdateSideBarCommands();
        }

        //can be replaced 
        public CoreCommand OptAddCommand
        {
            get => GetVoidCommand(OptCommands.OptAdd);
            set => ReplaceVoidCommand(OptCommands.OptAdd, ref value);
        }
        private void DefaultOptAdd()
        {
            //deafult optedit - no action
            MessageBox.Show("No option avalible");
        }

        //can be replaced
        public CoreCommand OptEditCommand
        {
            get => GetVoidCommand(OptCommands.OptEdit);
            set => ReplaceVoidCommand(OptCommands.OptEdit, ref value);
        }
        private void DefaultOptEdit()
        {
            //deafult optedit - no action
            MessageBox.Show("No option avalible");
        }

        //can be replaced
        public CoreCommand OptDelCommand
        {
            get => GetVoidCommand(OptCommands.OptDel);
            set => ReplaceVoidCommand(OptCommands.OptDel, ref value);
        }
        private void DefaultOptDeld()
        {
            //deafult optedit - no action
            MessageBox.Show("No option avalible");
        }

        private void ReplaceInternalCommands(IManagerVM internalVm)
        {
            OptAddCommand = internalVm.OptAddCommand;
            OptEditCommand = internalVm.OptEditCommand;
            OptDelCommand = internalVm.OptDelCommand;
        }
        private void UpdateSideBarCommands()
        {
            OnPropertyChanged(nameof(OptAddCommand));
            OnPropertyChanged(nameof(OptEditCommand));
            OnPropertyChanged(nameof(OptDelCommand));
        }

        #endregion

        #region InternalVms
        private ManCatViewModel _catVM;
        private ManMealsViewModel _mealsVM;
        private ManSupViewModel _supVM;
        private ManUserViewModel _userVM;
        
        #endregion
        
        #region CTOR(..){empty}
        public ManagerViewModel(ManagerView view) : base(view)
        {
            InitCommands();
            InitVms();
            LoadStartup();
        }

        #endregion

        #region Init

        private void InitVms()
        {
            _catVM=new ManCatViewModel(new ManCatView());
            _mealsVM=new ManMealsViewModel(new ManMealsView());
            _supVM=new ManSupViewModel(new ManSupView());
            _userVM=new ManUserViewModel(new ManUserView());
        }

        private void InitCommands()
        {
            //goback is external
            GoCategoriesCommand=new CoreCommand(GoCategories);
            GoMealsCommand=new CoreCommand(GoMeals);
            GoSuppliesCommand=new CoreCommand(GoSupplies);
            GoUserManagmentCommand=new CoreCommand(GoUserManagment);
           
            //init replecable commands --with empty methods
            OptAddCommand=new CoreCommand(DefaultOptAdd);
            OptEditCommand=new CoreCommand(DefaultOptEdit);
            OptDelCommand = new CoreCommand(DefaultOptDeld);

        }

        private void SetView(object view)
        {
            ViewLink.ManagerTabsController.Content = view;
        }
        #endregion

        //unsafe use it after whole init
        public void LoadStartup()
        {
            GoCategories();
        }
    }
}
