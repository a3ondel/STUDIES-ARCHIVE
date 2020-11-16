using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace RestaurantManager.Views.WaiterViews.SelectedTable.Items
{
    /// <summary>
    /// Interaction logic for PopupWin.xaml
    /// </summary>
    public partial class PopupWin : Window
    {
        public PopupWin()
        {
            InitializeComponent();
            this.Billmsg.DataContext = this;
        }

        public void setMsg(string msg)
        {
            
            this.Billmsg.Text = msg;

        }
    }
}
