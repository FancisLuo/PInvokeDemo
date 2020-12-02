using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace MyCSharpClient
{
    public class DLLInterface
    {
        //private const string DllName = @"G:\TestSpace\CPPTest\PInvokeTest\MyConsoleApp\x64\Debug\CPPDemoDll.dll";
        private const string DllName = "CPPDemoDll.dll";

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void PrintCallback(string strMsg);

        [DllImport(DllName, EntryPoint = "Add")]
        private extern static int Add(int a, int b);

        [DllImport(DllName, EntryPoint = "RegisterPrintCallback")]
        private extern static void RegisterPrintCallback(PrintCallback callback);

        [DllImport(DllName, EntryPoint = "StartApp")]
        private extern static void StartApp([MarshalAs(UnmanagedType.LPStr)] string info);

        [DllImport(DllName, EntryPoint = "ExitApp")]
        private extern static void ExitApp([MarshalAs(UnmanagedType.LPStr)] string info);

        public static void InitPrint()
        {
            RegisterPrintCallback(PrintCallbackFunction);
        }

        public static int DLL_Add(int a, int b)
        {
            return Add(a, b);
        }

        public static void Start(string info)
        {
            StartApp(info);
        }

        public static void Exit(string info)
        {
            ExitApp(info);
        }

        private static void PrintCallbackFunction(string msg)
        {
            Console.WriteLine("[Cpp] " + msg);
        }
    }
}
