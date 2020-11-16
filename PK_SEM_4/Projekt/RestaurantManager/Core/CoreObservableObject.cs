using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Dynamic;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;
using RestaurantManager.Annotations;

namespace RestaurantManager.Core
{
    //unsed in project 
    public interface ICoreObservable
    {
        event EventHandler CollectionChanged;
    }

    public class CoreObservableObject:INotifyPropertyChanged,ICoreObservable
    {
        public event EventHandler CollectionChanged;
        protected virtual void NotifyCollection()
        {
            CollectionChanged?.Invoke(null, null);
        }


        public event PropertyChangedEventHandler PropertyChanged;
        /// <summary>
        /// Notify UI if property changed
        /// </summary>
        /// <param name="propertyName"></param>
        /// <remarks>
        /// No need of parameter if you updates prop inside own setter
        /// </remarks>
        /// Auto generated Annotations.cs
        [NotifyPropertyChangedInvocator]
        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }


        /// <summary>
        /// Update value and notify UI
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="fieldToUpdate"></param>
        /// <param name="value"></param>
        /// <param name="propertyName"></param>
        /// <returns> true when value and fieldToUpdate types matches otherwise false</returns>
        protected virtual bool OnPropertyChanged<T>(ref T fieldToUpdate, T value, [CallerMemberName] string propertyName = "")
        {
            //check if value and field are same Type
            if (EqualityComparer<T>.Default.Equals(fieldToUpdate, value))
                return false;

            //sets the value
            fieldToUpdate = value;

            //Notify UI via onPropChange method
            OnPropertyChanged(propertyName);
            return true;
        }
    }
}
