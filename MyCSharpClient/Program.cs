using System;

namespace MyCSharpClient
{
    class Program
    {
        static void Main(string[] args)
        {
            DLLInterface.InitPrint();

            var result = DLLInterface.DLL_Add(2, 4);
            //Console.WriteLine($"Add result = {result}");

            //Console.WriteLine("Hello World!");
            Logger.PrintMsg($"Add result = {result}");

            DLLInterface.Start("Start from Program");

            DLLInterface.Exit("Exit by player");
        }
    }
}
