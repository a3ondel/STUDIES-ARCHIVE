using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Utility;

namespace RestaurantManager.ViewModels.Shared
{
    public abstract class PrimeSharedViewModel<TView> : CoreViewModel<TView>
    {
        private SharedVmHelper _primeVmHelper;
        public SharedVmHelper PrimeVmHelper
        {
            get => _primeVmHelper;
            set => _primeVmHelper = value;
        }

        protected PrimeSharedViewModel(TView view) : base(view)
        {
            PrimeVmHelper = SharedVmHelper.Instance;
           
        }
    }
}
