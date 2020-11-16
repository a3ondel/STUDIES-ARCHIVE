using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace RestaurantManager.Core
{
    /// <summary>
    /// Class that capsulates all posible Commands used in this project 
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class CoreCommand<T> : ICommand
    {
        private readonly Action<T> _exeMethod = null;
        private readonly Predicate<T> _canExeMethod = null;
        
        public bool FixedState { get; set; } = true;

        public CoreCommand(Action<T> exeMethod, Predicate<T> canExeMethod = null)
        {
            //if no exemethod passed throw an exception otherwise assign it
            _exeMethod = exeMethod ?? throw new ArgumentNullException(nameof(exeMethod));

            //if no class checking the avaliblity to run exemethod is passed than it will be
            //provided by FixedState( you can turn method execution off and on with this property )
            _canExeMethod = canExeMethod ?? (_ => FixedState);
        }

        //command manager is forced by dispatcher to update
        public event EventHandler CanExecuteChanged
        {
            add => CommandManager.RequerySuggested += value;
            remove => CommandManager.RequerySuggested -= value;
        }

        public bool CanExecute(object parameter) => _canExeMethod((T)parameter);

        public void Execute(object parameter) => _exeMethod((T)parameter);
    }

    public class CoreCommand : CoreCommand<object>
    {
        public CoreCommand(Action execute)
            : base(_ => execute()) { }

        public CoreCommand(Action execute, Func<bool> canExecute)
            : base(_ => execute(), _ => canExecute()) { }
    }
    }

//Make sure that method you are passing is PUBLIC!!! -idkoo man (adam from future :>)

//Example of usage CoreCommand class:

//var x = new CoreCommand(xx); //basic
//var y = new CoreCommand<object>(yy);//with param
//var z = new CoreCommand<TMP>(zz);

//public void xx() { Debug.WriteLine(23); }
//public void yy(object a) { Debug.WriteLine(a); }
//public void zz(TMP tmp) { Debug.WriteLine(tmp.propertyname); }


//arrow function annotation
//second the use of _ => _.method() for one-line, method-call lambdas, since it reduces the instruction's 
//cognitive weight.Specially when using generics, writing x => x.method() just adds that split-second
//consideration of "What's this 'x'? Is it a coordinate in space?".