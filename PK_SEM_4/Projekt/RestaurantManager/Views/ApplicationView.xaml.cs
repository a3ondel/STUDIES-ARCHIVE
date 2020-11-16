using System;
using System.Collections.Generic;
using System.Diagnostics;
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
using RestaurantManager.ViewModels;

namespace RestaurantManager.Views
{
    /// <summary>
    /// Interaction logic for ApplicationView.xaml
    /// </summary>
    public partial class ApplicationView : Window
    {
        public ApplicationView()
        {
            InitializeComponent();
            Debug.WriteLine("\n\n\n\n\n\n\n\n\n\n\nApplicationView");
           
        }
    }
}
