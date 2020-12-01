using System;

namespace MyCSharpClient
{
    class Program
    {
        static void Main(string[] args)
        {
            var result = DLLInterface.DLL_Add(2, 4);
            Console.WriteLine($"Add result = {result}");

            Console.WriteLine("Hello World!");
        }
    }
}
