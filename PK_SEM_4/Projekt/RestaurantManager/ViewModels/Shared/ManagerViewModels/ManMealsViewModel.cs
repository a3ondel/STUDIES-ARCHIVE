using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using RestaurantManager.Core;
using RestaurantManager.Views.ManagerViews;

namespace RestaurantManager.ViewModels.Shared.ManagerViewModels
{
    public sealed class ManMealsViewModel :SharedDataViewModel<ManMealsView>
    {
       
        private void OptAdd()
        {
            //deafult optedit - no action
            MessageBox.Show("No ADD Meals option avalible");
        }

        
        private void OptEdit()
        {
            //deafult optedit - no action
            MessageBox.Show("No EDIT Meals option avalible");
        }

        private void OptDel()
        {
            //deafult optedit - no action
            MessageBox.Show("No DEL Meals option avalible");
        }


        public ManMealsViewModel(ManMealsView view) : base(view)
        {
            InitCommands();
        }

        public override void InitCommands()
        {
            OptAddCommand = new CoreCommand(OptAdd);
            OptEditCommand = new CoreCommand(OptEdit);
            OptDelCommand = new CoreCommand(OptDel);
        }
    }
}
