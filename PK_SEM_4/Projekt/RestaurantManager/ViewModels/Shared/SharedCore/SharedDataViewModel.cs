using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Core;
using RestaurantManager.Models;
using RestaurantManager.ViewModels.Shared.ManagerViewModels;

namespace RestaurantManager.ViewModels.Shared
{
    public abstract class SharedDataViewModel<TView> :CoreViewModel<TView>, IManagerVM
    {
        //Manager Contains it also 
        private SharedDataModel _sharedData;
        public SharedDataModel SharedData
        {
            get => _sharedData;
            set => _sharedData = value;
        }

        #region Commands
        public CoreCommand OptAddCommand
        {
            get => GetVoidCommand(ManagerViewModel.OptCommands.OptAdd);
            set => ReplaceVoidCommand(ManagerViewModel.OptCommands.OptAdd, ref value);
        }
        
        public CoreCommand OptEditCommand
        {
            get => GetVoidCommand(ManagerViewModel.OptCommands.OptEdit);
            set => ReplaceVoidCommand(ManagerViewModel.OptCommands.OptEdit, ref value);
        }

        public CoreCommand OptDelCommand
        {
            get => GetVoidCommand(ManagerViewModel.OptCommands.OptDel);
            set => ReplaceVoidCommand(ManagerViewModel.OptCommands.OptDel, ref value);
        }

        public virtual void InitCommands()
        {
            throw new Exception("wrong use of InitCommands - only ");
        }

        #endregion

        #region constructor
        protected SharedDataViewModel(TView view) : base(view)
        {
            SharedData = SharedDataModel.Instance;
        }
        #endregion


        public void ManageCollectionEventAdd<T>( ref ObservableCollection<T> collection,EventHandler eventHandler)
        {

            foreach (ICoreObservable x in collection)
            {
                x.CollectionChanged += eventHandler;
            }
        }

        public void ManageCollectionEventRemove<T>(ref ObservableCollection<T> collection, EventHandler eventHandler)
        {

            foreach (ICoreObservable x in collection)
            {
                x.CollectionChanged -= eventHandler;
            }
        }


    }
}
