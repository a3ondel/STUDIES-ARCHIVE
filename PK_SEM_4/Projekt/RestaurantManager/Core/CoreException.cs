using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantManager.Core
{

   
    public sealed class CommandAlreadyExist : Exception
    {
        public CommandAlreadyExist() { }

        public CommandAlreadyExist(string message) : base($"*******{message} ALREADY EXISTS!*******") { }
    }

    public sealed class CommandDoesntExist : Exception
    {
       
        public CommandDoesntExist() { }

        public CommandDoesntExist(string message) : base($"******Command {message} not found!*******") { }
    }


    public sealed class CommandNAException : Exception
    {

        public CommandNAException() { }

        public CommandNAException(string message) : base($"UNKNOWN ERROR\nMORE:\n{message} ") { }
    }
    
}
