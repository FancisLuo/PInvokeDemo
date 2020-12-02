using System;
using System.Collections.Generic;
using System.Text;

namespace MyCSharpClient
{
    public class Logger
    {
        public static void PrintMsg(string msg)
        {
            Console.WriteLine("[CSharp] " + msg);
        }
    }
}
