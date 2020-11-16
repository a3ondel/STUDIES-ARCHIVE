using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.TextFormatting;
using RestaurantManager.Annotations;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Utility;
using RestaurantManager.Views;

namespace RestaurantManager.ViewModels
{
    using UserType=UserModel.EUserType;
    public sealed class ApplicationViewModel : CoreViewModel<ApplicationView>
    {
        #region CONSTATNS
        private const double WindowSizeMultpilier = 1.4;
        private const double WindowWidthWork = 1280;
        private const double WindowHeightWork = 720;
        private const double WindowWidthStart = 735;
        private const double WindowHeightStart = 550;

        #endregion

        #region Internal
        private static StartUpViewModel _startUpViewModel=null;
        private SharedVmHelper _vMHelper;
        private object _activeView = null;
        #endregion

        #region Contructor
        public ApplicationViewModel(ApplicationView link) : base(link)
        {
            InitAppOnStart();

            SetWindowToStartSize();

            SetActiveView(_startUpViewModel.ViewLink);

            SetEvents();
        }
        #endregion

        #region EventsHandlers etc
        private void EscapePressed(object sender, System.Windows.Input.KeyEventArgs e)
        {
            if (e.Key == Key.Escape)
                GoBack();
        }
        private void WindowOnClose(object sender, EventArgs e)
        {
            _vMHelper.SaveData();
        }

        private void SetEvents()
        {
            //setting Event Handler for window closier
            ViewLink.Closed += WindowOnClose;
            
            //Checking if enter is pressed 
            ViewLink.KeyDown += EscapePressed;
        }
        #endregion
        
        #region Window methods 
        private void SetWindowToWorkSize()
        {
            ViewLink.Height = WindowHeightWork * WindowSizeMultpilier;
            ViewLink.Width = WindowWidthWork * WindowSizeMultpilier;
        }
        private void SetWindowToStartSize()
        {
            ViewLink.Height = WindowHeightStart * WindowSizeMultpilier;
            ViewLink.Width = WindowWidthStart * WindowSizeMultpilier;
        }

        
        #endregion

        #region Commands -Commands and method run by those commands

        private CoreCommand<object> _startVerifiedViewCommand;
        private void StartVerifiedView(object userinfo)
        {
            var userInfo = userinfo as PassedUser;

            SetWindowToWorkSize();

            switch (userInfo.UserType)
            {
                case UserType.Waiter://WaiterViewModel with id userInfo.Item2

                    _vMHelper.LoadWaiter();
                    SetActiveView(_vMHelper.GetWaiterView);
                    break;

                case UserType.Manager://MagerViewModel with id userInfo.Item2

                    _vMHelper.LoadManager();
                    SetActiveView(_vMHelper.GetManagerView);
                    break;

                case UserType.Kitchen: //KitchenViewModel 

                    _vMHelper.LoadKitchen();
                    SetActiveView(_vMHelper.GetKitchenView);
                    break;

                default://Unknown error
                    {
                        throw new Exception($"Unknown \"{userInfo.UserType}\" UserType");
                    }
            }
            _vMHelper.SetUserInfo(userInfo);
        }

        private CoreCommand _goBackCommand;
        private void GoBack()
        {
            SetWindowToStartSize();
            SetActiveView(_startUpViewModel.ViewLink);
        }
        
        //changes active view filed and change contenet of content controller in app view
        private CoreCommand<object> _setActiveViewCommand;
        private void SetActiveView(object passedView)
        {
            _activeView = passedView;
            ViewLink.AppController.Content = passedView;
        }
        #endregion
        
        #region Init
        //this method has to be at run at the begining of constructor 
        private void InitAppOnStart()
        {
            //TODO LOADING DATA FROM FILES
            InitCommnds();
            InitFields();
            InitVmHelper();
        }

        //starts in AppOnStartMethod after command init
        private void InitFields()
        {
            _startUpViewModel = new StartUpViewModel(new StartUpView())
            {
                GoBackCommand = _goBackCommand,
                SetViewCommand = _setActiveViewCommand,
                StartVerifiedViewCommand = _startVerifiedViewCommand
            };
        }

        private void InitVmHelper()
        {
            _vMHelper = SharedVmHelper.Instance;
            _vMHelper.LoadData();
            _vMHelper.InGoBackCommand = _goBackCommand;
        }

        private void InitCommnds()
        {
            _goBackCommand = new CoreCommand(GoBack);
            _setActiveViewCommand = new CoreCommand<object>(SetActiveView);
            _startVerifiedViewCommand = new CoreCommand<object>(StartVerifiedView);
        }

        #endregion

    }

    public enum AppCommands
    {
        GoBack = 0
    }

    

}