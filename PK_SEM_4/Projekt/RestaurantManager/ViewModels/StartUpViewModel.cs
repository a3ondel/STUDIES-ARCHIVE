using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Utility;
using RestaurantManager.Views;

namespace RestaurantManager.ViewModels
{
    using EUserType = UserModel.EUserType;

    /// <summary>
    /// User selection class
    /// </summary>
    public sealed class StartUpViewModel : CoreViewModel<StartUpView>
    {
        private enum VCommands
        {
            GoBack = 0
        }
        private enum ArgCommands
        {
            SetView = 0, StartVerifiedView = 1, InViewSelection = 2
        }
        //can be modified after constructor in {}
        public static readonly string UserDataFileName = "LoginData.json";

        #region Commands
        public CoreCommand<object> SetViewCommand
        {
            get => GetArgCommand(ArgCommands.SetView);

            set => SetArgCommand(ArgCommands.SetView, ref value);

        }
        public CoreCommand<object> StartVerifiedViewCommand
        {
            get => GetArgCommand(ArgCommands.StartVerifiedView);

            set => SetArgCommand(ArgCommands.StartVerifiedView, ref value);
        }
        public CoreCommand GoBackCommand
        {
            get => GetVoidCommand(VCommands.GoBack);
            set => SetVoidCommand(VCommands.GoBack, ref value);
        }
        public CoreCommand<object> InViewSelectionCommand
        {
            get => GetArgCommand(ArgCommands.InViewSelection);
            set => SetArgCommand(ArgCommands.InViewSelection, ref value);
        }
        #endregion

        #region InternalViews
        private LoginViewModel _loginViewModel;
        public LoginViewModel LoginViewModelLink
        {
            get => _loginViewModel;
            set => OnPropertyChanged(ref _loginViewModel, value);
        }
        #endregion

        #region CTOR
        public StartUpViewModel(StartUpView link) : base(link)
        {
            InViewSelectionCommand = new CoreCommand<object>(ViewSelectionMethod);
        }
        #endregion

        #region Data

        private List<UserModel> _loadedUsers;


        #endregion

        #region Methods
        private void ViewSelectionMethod(object usertype)
        {
            //checking if UserDataExist otherwise 
            if (LoadUsers(UserDataFileName))
            {
                Enum.TryParse(usertype as string, out EUserType userType);
                switch (userType)
                {
                    //case waiter or manager user logging option chosen
                    case EUserType.Waiter:
                    case EUserType.Manager:
                        {
                            LoginViewModelLink = new LoginViewModel(new LoginView(), userType)
                            {
                                UserList = _loadedUsers,
                                GoBackCommand = this.GoBackCommand,
                                ConfirmedLoginCommand = StartVerifiedViewCommand
                            };

                            SetViewCommand.Execute(LoginViewModelLink.ViewLink);

                        }
                        break;
                    
                    //go back to applicationViewModel and run StartVerifiedView
                    case EUserType.Kitchen: 
                        StartVerifiedViewCommand.Execute(new PassedUser(userType, null));
                        //Kitchen view 
                        break;

                    default:
                        throw new Exception("WRONG USER TYPE PASSED");
                }
            }
            else
            {
                MessageBox.Show("There is problem with users data file! Restart App");
            }
        }

        private bool LoadUsers(string fileName)
        {
            try
            {
                _loadedUsers = FileHelper.FileReader<List<UserModel>>(fileName);
            }
            catch (Exception e)
            {
                MessageBox.Show($"{e.Message}\nPress OK to Go back");
                //ConfirmedLoginCommand.Execute(new PassedUser(UserModel.EUserType.Error, null));
                return false;
            }


            return true;
        }
        #endregion
    }
}
