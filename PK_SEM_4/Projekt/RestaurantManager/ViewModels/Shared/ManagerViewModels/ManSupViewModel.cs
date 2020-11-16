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
    public sealed class ManSupViewModel :SharedDataViewModel<ManSupView>
    {
        //add command
        private void OptAdd()
        {
            //deafult optedit - no action
            MessageBox.Show("No SUPP ADD option avalible");
        }

        //can be replaced
        private void OptEdit()
        {
            //deafult optedit - no action
            MessageBox.Show("No SUPP EDIT option avalible");
        }

        private void OptDel()
        {
            //deafult optedit - no action
            MessageBox.Show("No SUPP EDIT option avalible");
        }


        public ManSupViewModel(ManSupView view) : base(view)
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
