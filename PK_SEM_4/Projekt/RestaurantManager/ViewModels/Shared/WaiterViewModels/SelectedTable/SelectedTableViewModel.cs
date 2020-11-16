using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.Views.WaiterViews;

namespace RestaurantManager.ViewModels.Shared.WaiterViewModels
{
    public sealed class SelectedTableViewModel : SharedDataViewModel<SelectedTableView>
    {
        #region Vms -acviteordercontrollervm


        public ActiveOrderControllerViewModel ActiveOrderControllerVM { get; private set; }

        //VM with no view
        

        #endregion

        //One Way Binding 
        private string _tableName = "";
        public string TableName { 
            get=>string.IsNullOrEmpty(_tableName) ? "TABLE NOT SELECTED" : $"TABLE {_tableName}";
            set => OnPropertyChanged(ref _tableName, value);
        }

    #region Eventhandlers

        public void UppdateTableName(object x, TableModel passedTable)
        {
            if (passedTable == null)
                TableName = "";
            else
            {
                TableName = passedTable._Name;
            }
        }
        
        #endregion

        #region Constructor -init
        public SelectedTableViewModel(SelectedTableView view) : base(view)
        {
            StartInit();
        }
        #endregion
        

        #region Init

        //start methods in right sequance
        private void StartInit()
        {
            InitVMs();
            InitViews();
        }

        private void InitVMs()
        {
            ActiveOrderControllerVM=new ActiveOrderControllerViewModel(new ActiveOrderControllerView());
            //BottomBViewModel = new BottomBlockViewModel();//went to activeorder
            
        }

        private void InitViews()
        {
            ViewLink.ActiveOrdedController.Content = ActiveOrderControllerVM.ViewLink;
            //ViewLink.BottomBlockController.Content = _blockViewModel.ViewLink;
        }

        #endregion

        //loading / binding events and commands
        public void LoadUnSafe()
        {
            //do nothing at the moment, no sense of using it
            ActiveOrderControllerVM.LoadUnSafe();
            
        }
    }
}
