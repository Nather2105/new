using System;

namespace Lab_5_OM
{
    class Program
    {
        static double f1(double x)
        {
            return Math.Sin(x);
        }
        static double f2(double x)
        {
            return x / 2;
        }
        static double trapeza1(double a, double b, double n)
        {
            double h = (b - a) / n;
            double sum = f1(a) + f1(b);
            for (int i = 1; i <= n - 1; i++)
            {
                sum += 2 * f1(a + i * h);
            }
            sum *= h / 2;
            //Console.WriteLine(sum);
            return sum;
        }
        static double trapeza2(double a, double b, double n)
        {
            double h = (b - a) / n;
            double sum = f2(a) + f2(b);
            for (int i = 1; i <= n - 1; i++)
            {
                sum += 2 * f2(a + i * h);
            }
            sum *= h / 2;
            //Console.WriteLine(sum);
            return sum;
        }
        static void Main(string[] args)
        {
            double a, b;
            double n;
            a = 0;
            b = 1.895;
            n = 1895;
            double result = trapeza1(a, b, n) - trapeza2(a, b, n);
            Console.WriteLine("Sin(X): " + trapeza1(a, b, n));
            Console.WriteLine("X/2: " + trapeza2(a, b, n));
            Console.WriteLine("Obiem: " + result);
            
            Console.ReadLine();
        }
    }
}
