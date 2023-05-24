using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace laba1_OM
{
    class Program
    {
        
        static void N_Sum_1(int i)
        {
            double Sum = 0;
            int k;
            int n = Convert.ToInt32(Math.Pow(10, i));
            for (k = 1; k <= n; k++)
            {
                Sum += 1 / Math.Sqrt(k);
            }
            Console.WriteLine($"{10}^{i} = {Math.Pow(10, i):N0}");
            Console.WriteLine($"First Sum: {Sum}");
            Console.WriteLine($"First Sum: {(float)Sum}");
            Console.WriteLine($"First Sum: {Sum:N30}");
            Console.WriteLine($"First Sum: {(float)Sum}");

        }
        static void N_Sum_2(int i)
        {
            double Sum = 0;
            int k;
            int n = Convert.ToInt32(Math.Pow(10, i));
            for (k = n; k >= 1; k--)
            {
                Sum += 1 / Math.Sqrt(k);
            }
            Console.WriteLine($"{10}^{i} = {Math.Pow(10, i):N0}");
            Console.WriteLine($"Second Sum: {Sum}");
            Console.WriteLine($"Second Sum: {Sum:N30}");
            Console.WriteLine($"Second Sum: {(float)Sum}");
        }
        static void Main(string[] args)
        {
            int i;
            Console.WriteLine("Enter i: ");
            i = Convert.ToInt32(Console.ReadLine());
            N_Sum_1(i);
            Console.WriteLine("\n");
            N_Sum_2(i);
            Console.WriteLine("\n");
        }
    }
}