using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using RestaurantManager.ViewModels;
using RestaurantManager.Views;

namespace RestaurantManager
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        private ApplicationViewModel __APPViewModel;

        private void App_OnStartup(object sender, StartupEventArgs e)
        {
            __APPViewModel=new ApplicationViewModel(new ApplicationView());
            __APPViewModel.ViewLink.Show();
           
        }
    }
}
