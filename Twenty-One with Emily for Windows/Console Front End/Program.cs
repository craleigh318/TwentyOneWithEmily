using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_Front_End
{
    class Program
    {
        static void Main(string[] args)
        {
            BackEnd.ManagedModel model = new BackEnd.ManagedModel();
            System.Console.WriteLine("Your random number is:" + model.getNumber());
        }
    }
}
