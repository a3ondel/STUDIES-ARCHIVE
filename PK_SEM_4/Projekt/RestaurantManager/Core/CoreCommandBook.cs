using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace RestaurantManager.Core
{
    public abstract class CoreCommandBook:CoreObservableObject
    {
        protected Dictionary<Enum, CoreCommand<object>> ExArgCommands = new Dictionary<Enum, CoreCommand<object>>();
        protected Dictionary<Enum, CoreCommand> ExVoidCommands = new Dictionary<Enum, CoreCommand>();

        protected virtual  CoreCommand<object> GetArgCommand(Enum argCommandName)
        {
            if (ExArgCommands.TryGetValue(argCommandName, out CoreCommand<object> resaultCommand))
            {
                return resaultCommand;
            }
            else
            {
                throw new CommandDoesntExist($"{argCommandName.ToString()} not found");
            }
        }

        protected virtual  CoreCommand GetVoidCommand(Enum commandName)
        {
            if (ExVoidCommands.TryGetValue(commandName, out CoreCommand tmpCommand))
            {
                return tmpCommand;
            }
            else
            {
                throw new CommandDoesntExist( commandName.ToString() );
                
            }
        }

        protected virtual bool SetVoidCommand(Enum commandName, ref CoreCommand command)
        {
            if (ExVoidCommands.ContainsKey(commandName))
            {

                 throw new CommandAlreadyExist(commandName.ToString());
            }
            else
            {
                ExVoidCommands.Add(commandName, command);
                return true;
            }
        }

        protected virtual bool SetArgCommand(Enum commandName, ref CoreCommand<object> command)
        {
            if (ExArgCommands.ContainsKey(commandName))
            {
                //throw new Exception($"{commandName.ToString()} ******ALREADY EXISTS!*******");
                MessageBox.Show($"{commandName.ToString()} ******ALREADY EXISTS!*******");
                return true;
            }
            else
            {
                ExArgCommands.Add(commandName, command);
                return true;
            }
        }

        protected virtual bool DelVoidCommand(Enum commandName)
        {

            if (ExVoidCommands.ContainsKey(commandName))
            {

                ExVoidCommands.Remove(commandName);
                return true;
            }
            else
            {
                throw new CommandDoesntExist();
                
            }
        }

        protected virtual bool DelArgCommand(Enum commandName)
        {

            if (ExArgCommands.ContainsKey(commandName))
            {
                ExArgCommands.Remove(commandName);
                return true;
            }
            else
            {
                throw new CommandDoesntExist(commandName.ToString());

            }
        }


        //public beacuse it is safe command
        protected virtual bool ReplaceVoidCommand(Enum commandName, ref CoreCommand command)
        {

            try
            {
                SetVoidCommand(commandName, ref command);
            }
            catch (CommandAlreadyExist e)
            {

                try
                {
                    DelVoidCommand(commandName);
                }
                //this exception should not fire in delvoid after setvoid
                catch (CommandDoesntExist exception)
                {
                    throw new CommandNAException(exception.Message);
                }

                SetVoidCommand(commandName, ref command);

            }
            catch (CommandNAException unknownerror)
            {

                MessageBox.Show(unknownerror.Message);

            }

            return true;
        }

        protected virtual bool ReplaceArgCommand(Enum commandName, ref CoreCommand<object> command)
        {

            try
            {
                SetArgCommand(commandName, ref command);
            }
            catch (CommandAlreadyExist e)
            {

                try
                {
                    DelArgCommand(commandName);
                }
                //this exception should not fire in delarf after setarg
                catch (CommandDoesntExist exception)
                {
                    throw new CommandNAException(exception.Message);
                }

                SetArgCommand(commandName, ref command);

            }
            catch (CommandNAException unknownerror)
            {

                MessageBox.Show(unknownerror.Message);

            }

            return true;
        }


    }
}
