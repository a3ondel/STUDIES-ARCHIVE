using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Views.KitchenViews;

namespace RestaurantManager.ViewModels.Shared.KitchenViewModels
{
    public sealed class KitchenControllerViewModel :SharedDataViewModel<KitchenControllView>
    {
        public KitchenControllerViewModel(KitchenControllView view) : base(view) { }

        
    }


}
