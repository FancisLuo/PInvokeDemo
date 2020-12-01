using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace MyCSharpClient
{
    public class DLLInterface
    {
        private const string DllName = @"G:\TestSpace\CPPTest\PInvokeTest\MyConsoleApp\x64\Debug\CPPDemoDll.dll";

        [DllImport(DllName, EntryPoint = "Add")]
        private extern static int Add(int a, int b);

        public static int DLL_Add(int a, int b)
        {
            return Add(a, b);
        }
    }
}
