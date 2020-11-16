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
    public sealed class ManCatViewModel : SharedDataViewModel<ManCatView>
    {

        //can be replaced 
        private void OptAdd()
        {
            //deafult optedit - no action
            MessageBox.Show("No CAT ADD option avalible");
        }

        //can be replaced
        private void OptEdit()
        {
            //deafult optedit - no action
            MessageBox.Show("No CAT EDIT option avalible");
        }


        //can be replaced
        private void OptDel()
        {
            //deafult optedit - no action
            MessageBox.Show("No CAT DEL option avalible");
        }


        public ManCatViewModel(ManCatView view) : base(view)
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
