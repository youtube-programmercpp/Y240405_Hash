using System;
using System.Runtime.CompilerServices;

namespace ConsoleApp1
{
    internal class Program
    {
        static byte[] Sha256ByFramework(byte[] contents)
        {
            return System.Security.Cryptography.SHA256CryptoServiceProvider.Create().ComputeHash(contents);
        }
        static byte[] Sha256ByBCryptClr(byte[] contents)
        {
            return (new BCryptClr.AlgorithmProvider("SHA256")).CreateHash().HashData(contents).FinishHash();
        }
        static string make_hex_string(byte[] value)
        {
            System.Text.StringBuilder stringBuilder = new System.Text.StringBuilder();
            foreach (byte b in value)
                stringBuilder.Append(b.ToString("x2"));
            return stringBuilder.ToString();
        }
        static void Main(string[] args)
        {
            string filename = "..\\ConsoleApplication1\\ConsoleApplication1.cpp";
            if (System.Environment.Is64BitProcess)
                filename = "..\\" + filename;
            var contents = System.IO.File.ReadAllBytes(filename);
            System.Console.WriteLine("{0} Sha256ByFramework", make_hex_string(Sha256ByFramework(contents)));
            System.Console.WriteLine("{0} Sha256ByBCryptClr", make_hex_string(Sha256ByBCryptClr(contents)));
            System.Console.ReadKey();
        }
    }
}
