using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace RestaurantManager.Core
{
    /// <summary>
    /// Abstract class for AllViewModels 
    /// </summary>
    /// <typeparam name="TYourView"></typeparam>
    public abstract class CoreViewModel<TYourView> : CoreCommandBook
    {
        private TYourView _viewLink = default;

        /// <summary>
        /// Gives direct access to view
        /// </summary>
        public TYourView ViewLink
        {
            get => (TYourView)_viewLink;
            set
            {   //Notify UI //<TYourView> unnecessary
                OnPropertyChanged<TYourView>(ref _viewLink, value);
                _viewLink = value;
            }
        }

        protected CoreViewModel(TYourView view)
        {
            ViewLink = (TYourView)view;

            if (ViewLink != null)
            {
                var convertedView = ((FrameworkElement)(object)ViewLink);

                if (convertedView != null)
                {
                    convertedView.DataContext = this;
                }
                else
                    throw new Exception($"Wrong object passed as View {view.ToString()} {view.GetType()}");
            }
            else
            {
                throw new Exception($"Wrong object passed as View {this.ToString()}");
            }
        }

        #region Nie wiadomo jeszcze czy jest to potrzebne dla bezpieczstwa jest(mozliwe ze nie)

        protected override CoreCommand<object> GetArgCommand(Enum argCommandName)
        {
            return base.GetArgCommand(argCommandName);
        }

        protected override CoreCommand GetVoidCommand(Enum commandName)
        {
            return base.GetVoidCommand(commandName);
        }

        protected override bool SetVoidCommand(Enum commandName, ref CoreCommand command)
        {
            return base.SetVoidCommand(commandName, ref command);
        }

        protected override bool SetArgCommand(Enum commandName, ref CoreCommand<object> command)
        {
            return base.SetArgCommand(commandName, ref command);
        }

        #endregion
    }

    //default CoreViewModel if no View directly connected no need of setting view
    public abstract class CoreViewModel : CoreCommandBook
    {
        protected CoreViewModel()
        {
            Debug.WriteLine($"Warining!!!\nVM with no View directly connected");
        }
    }

}
//List<CoreCommand> externalNoParametrMethods = null, List<CoreCommand<object>>externalParametrMethods=null