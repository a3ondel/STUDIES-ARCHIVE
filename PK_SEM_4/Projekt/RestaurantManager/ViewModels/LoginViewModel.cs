using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using RestaurantManager.Core;
using RestaurantManager.ViewModels;
using RestaurantManager.Views;
using RestaurantManager.Models;
using RestaurantManager.Utility;
using RestaurantManager.ViewModels.Shared;

namespace RestaurantManager.ViewModels
{

    public sealed class LoginViewModel : CoreViewModel<LoginView>, IDataErrorInfo
    {
        private enum VCommands
        {
            GoBack = 0
        }

        private enum ArgCommands
        {
            ConfirmedLogin = 0
        }

        #region ExternalCommands
        public CoreCommand GoBackCommand
        {
            get => GetVoidCommand(VCommands.GoBack);
            set => SetVoidCommand(VCommands.GoBack, ref value);
        }
        public CoreCommand<object> ConfirmedLoginCommand
        {
            get => GetArgCommand(ArgCommands.ConfirmedLogin);
            set => SetArgCommand(ArgCommands.ConfirmedLogin, ref value);
        }

        #endregion

        #region InternalCommands
        //initialize in constructor beacuse methods are non static in this class (and cant be) 
        public CoreCommand InSubmitButtonCommand { get; private set; }

        #endregion

        #region LocalData
        private static UserModel.EUserType _activeUserType;
        private static readonly Regex UserNameRegex = new Regex(@"[^\d\w]");
        private UserModel _runTimeUser;
        private UserModel _userFromList;
        private List<UserModel> _usersList;
        public List<UserModel> UserList
        {
            get => _usersList;
            set => _usersList = value;
        }
        //non static-readonly bc it changes during runtime
        private static bool _userExist = true;
        public Dictionary<string, string> ErrorDictionary { get; private set; } = new Dictionary<string, string>();

        public string UserName
        {
            get => _runTimeUser.UserName;
            set
            {
                _runTimeUser.UserName = value;
                OnPropertyChanged(nameof(UserName));
            }
        }
        public string Password
        {
            get => _runTimeUser.Password;
            set
            {
                _runTimeUser.Password = value;
                OnPropertyChanged();
            }
        }

        #endregion

        #region Constructor
        public LoginViewModel(LoginView view, UserModel.EUserType selectedUserType)
            : base(view)
        {
            OnStart(selectedUserType);
        }

        #endregion

        #region Methods

        //At the startup those methods set things
        private void SetViewType(UserModel.EUserType userType)
        {
            _activeUserType = userType;
            switch (_activeUserType)
            {
                case UserModel.EUserType.Waiter:
                    {
                        ViewLink.UserNameTextBox.Visibility = Visibility.Collapsed;
                        ViewLink.UsernameLabel.Visibility = Visibility.Collapsed;
                        ViewLink.HeaderTextBlock.Text = "WAITER LOGIN ";
                        break;
                    }
                case UserModel.EUserType.Manager:
                    {
                        ViewLink.UserNameTextBox.Visibility = Visibility.Visible;
                        ViewLink.UsernameLabel.Visibility = Visibility.Visible;
                        ViewLink.HeaderTextBlock.Text = "MANAGER LOGIN ";
                        break;
                    }
                default:
                    {
                        throw new Exception($"Wrong User type passed{_activeUserType}");
                    }

            }
        }
        private void InitAllEventHandlers()
        {
            ViewLink.PasswordBox.PasswordChanged += UpdatePassword;
            ViewLink.PasswordBox.KeyDown += PasswordBox_KeyDown;
            ViewLink.UserNameTextBox.KeyDown += PasswordBox_KeyDown;
        }

        private void OnStart(UserModel.EUserType userType)
        {
            SetViewType(userType);
            _runTimeUser = new UserModel(-1, "", "", userType);
            InSubmitButtonCommand = new CoreCommand(SubmitButtonMethod, CanExecuteValidation);
            InitAllEventHandlers();
        }

        //Run time methods for login validation and verification
        private bool LookForUser()
        {
            if (_userFromList != null && _userFromList.UserType == _activeUserType)
            {
                _runTimeUser._Id = _userFromList._Id;
                return _userExist = true;
            }
            else
                return _userExist = false;
        }
        private bool LookForManager()
        {
            _userFromList = _usersList.FindLast(x => x.UserName == _runTimeUser.UserName);
            return LookForUser();

        }
        private bool LookForWaiter()
        {
            _userFromList = _usersList.FindLast(x => x.Password == CryptoHelper.EncryptString(_runTimeUser.Password));
            return LookForUser();

        }
        #endregion

        #region CommandMethods 

        //method that fires after Click of "LOGIN" Button //true for testing
        private void SubmitButtonMethod()
        {
            UserModel encryptedUser = new UserModel(_runTimeUser)
            {
                Password = CryptoHelper.EncryptString(Password)
            };


            if (encryptedUser.Equals(_userFromList)
            //|| true  //testing true
            )
            {
                ConfirmedLoginCommand.Execute(new PassedUser(_activeUserType, _runTimeUser._Id));
            }
            else //if (_activeUserType == UserModel.EUserType.Manager||)
            {
                MessageBox.Show($"Wrong password");
            }

        }

        //method that tells command wether to be activatable //true for testing
        private bool CanExecuteValidation()
        {
            //for testing (only this return)
           // return true;

            if (String.IsNullOrEmpty(UserName) && String.IsNullOrEmpty(Password)
                || !_userExist && _activeUserType != UserModel.EUserType.Waiter)
                return false;
            else
                return true;
        }

        #endregion

        #region EventHanlders
        //method that fires when passwordchanged event execute it
        private void UpdatePassword(object sender, RoutedEventArgs e)
        {
            Password = ViewLink.PasswordBox.Password;
            if (_activeUserType == UserModel.EUserType.Waiter)
            {
                LookForWaiter();
            }
        }

        //event handler method
        private void PasswordBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
                SubmitButtonMethod();
        }

        #endregion

        #region Error
        //Username errors 
        public string this[string name]
        {
            get
            {
                if (_activeUserType == UserModel.EUserType.Manager && name == nameof(UserName))
                {
                    string errorMsg = null;
                    if (string.IsNullOrEmpty(UserName))
                    {
                        errorMsg = "Type your username";
                        _userExist = false;
                    }
                    else if (LookForManager())
                    {
                        ErrorDictionary.Clear();
                    }
                    else
                    {
                        var lastChar = UserName[UserName.Length - 1].ToString();

                        errorMsg = UserNameRegex.IsMatch(lastChar) ? $"{lastChar} is not valid text sybol " : "User Not found";
                    }
                    //adds error and notify UI
                    AddError(name, errorMsg);
                    return errorMsg;
                }
                // null equals error havent occured
                return null;
            }
        }

        //Adds an error to dictionary
        private void AddError(string name, string errorMsg)
        {

            if (ErrorDictionary.ContainsKey(name))
                ErrorDictionary[name] = errorMsg;
            else
            {
                ErrorDictionary.Add(name, errorMsg);
            }

            OnPropertyChanged(nameof(ErrorDictionary));
        }

        //IdataError require to implement this property but it is useless in my case 
        public string Error => null;
        #endregion
    }
}