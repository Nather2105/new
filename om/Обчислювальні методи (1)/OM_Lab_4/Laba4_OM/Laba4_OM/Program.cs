using System;

namespace Laba4_OM
{
    class Program
    {
        static void Main(string[] args)
        {
            double [,]m = new double [,]{
                { 1, -3},
                { 3, 2},
                { 4, -3},
                { 6, 4},
    };

            int n = 4;
            double a = 0, b = 0, ResultX = 0, ResultY = 0, ResultXY = 0, ResultSquare = 0;


            for (int i = 0; i < n; i++)
            {
                ResultX += m[i,0];
            }
            Console.WriteLine("X Sum: " + ResultX + "\n");

            for (int i = 0; i < n; i++)
            {
                ResultY += m[i,1];
            }
            Console.WriteLine("Y Sum: " + ResultY + "\n");

                for (int i = 0; i < n; i++)
            {
                ResultXY += m[i,0] * m[i,1];
            }
            Console.WriteLine("Y Sum: " + ResultXY + "\n");

            for (int i = 0; i < n; i++)
            {
                ResultSquare += Math.Pow(m[i,0], 2);
            }
            Console.WriteLine("X^2 Sum: " + ResultSquare + "\n");

            a = (n * ResultXY - ResultX * ResultY) / (n * ResultSquare - ResultX * ResultX);
            b = (ResultY - a * ResultX) / n;

            double max = 0, temp, AVG = 0, AVGSquare = 0;
            for (int i = 0; i < n; i++)
            {
                temp = Math.Abs(m[i,1] - (a * m[i,1] + b));
                AVGSquare += Math.Pow((m[i,1] - (a * m[i,1] + b)), 2);
                AVG += temp;
                if (temp > max)
                {
                    max = temp;
                }
            }
            Console.WriteLine("A = " + a + "B = " + b + "\n");
            Console.WriteLine("Max error " + max + "\n");
            Console.WriteLine("Mid error " + AVG / n + "\n");
            Console.WriteLine("MidSquare error " + Math.Sqrt(AVGSquare / n) + "\n");

        }
    }
}
