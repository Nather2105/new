using System;

namespace OM_Lab_3
{
    class Program
    {
        static void Main(string[] args)
        {
            const double eps = 0.00001;
            double x0 = 0, x1 = 0.216;
            int iter = 0;
            bool error = false;
  
            //Метод простої ітерації
            do
            {
                x1 = func(x0);
                iter++;
                if (Math.Abs(x1 - x0) >= eps && iter == 1000)
                {
                    error = true;
                    break;
                }
                x0 = x1;
            } while (Math.Abs(x0 - func(x0)) > eps);
            if (error)
            {
                Console.WriteLine("Not found");
            }
            else
            {
                Console.WriteLine("Anomaly: E = {0} ", Math.Round(x1 + 0.216, 6));
                Console.WriteLine("iterations passed: {0}", iter);
            }
            //Метод Ньютона


            for (iter = 1; eps < Math.Abs(func(x1)); iter = iter + 1)
            {
                Console.WriteLine("Iterations: " + iter);
                if (dfunc(x1) == 0)
                        break;
                Console.WriteLine("E= " + Math.Round(x1+0.216,6));
            }

            Console.ReadKey();
        }
        public static double func(double x)
        {
            double M = 24.851019;
            double e = 0.0933941;
            double f = M + (e * Math.Sin(x));
            return f;
        }
        public static double dfunc(double x)
        {
            return 1 - (0.9339*Math.Cos(x));
        }
        public static double g(double x)
        {
            return x - func(x) / dfunc(x);
        }
    }
}
