using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;
using RestaurantManager.DB;

namespace RestaurantManager.Models
{
    public sealed class UserModel : IdentityDB
    {
        private string _userName;
        private string _password;
        private EUserType _userType;

        public string UserName
        {
            get => _userName;
            set => _userName = value;
        }
        public string Password
        {
            get => _password;
            set => _password = value;
        }

        public UserModel.EUserType UserType
        {
            get => _userType;
            set => _userType = value;
        }

        public UserModel(int id, string login, string password, UserModel.EUserType userType) : base(id)
        {
            _Id = id;
            _userName = login;
            _password = password;
            _userType = userType;
        }

        public UserModel(UserModel prevUser) : this(prevUser._Id,prevUser.UserName,prevUser.Password,prevUser.UserType) {}
        public UserModel():base(){}

        public enum EUserType
        {
            Waiter = 0,
            Manager = 1,
            Kitchen = 2
        }
        
        public bool Equals(UserModel obj)
        {
            if(obj!=null)
             return this._Id == obj._Id && this.UserType == obj.UserType && this.UserName == obj.UserName && this.Password == obj.Password;

            return false;
        }

        public override bool Equals(object obj)
        {
            UserModel objp = (UserModel) obj;
            if (objp != null)
                return this._Id == objp._Id && this.UserType == objp.UserType && this.UserName == objp.UserName && this.Password == objp.Password;

            return false;
        }

        //trash
        public override int GetHashCode()
        {
            return _Id.GetHashCode();
        }
    }

    public class PassedUser
    {
        public UserModel.EUserType UserType { get; set; }
        public int? UserID { get; set; }

        public PassedUser(UserModel.EUserType userType, int? userId)
        {
            UserType = userType;
            UserID = userId;
        }

        public PassedUser(PassedUser obj) :this(obj.UserType,obj.UserID) { }
    }
}
