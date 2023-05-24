using System;

internal class LinearSystem {
    public static void Main(string[] args) {
        Random = new Random();

        Console.Write("Введіть розмір матриці: ");
        int n = Convert.ToInt32(Console.ReadLine());

        Console.Write("Введіть значення похибки: ");
        double eps = Convert.ToDouble(Console.ReadLine());

        double[,] matrix = new double[n, n];
        double[] b = new double[n];

        // Generate matrix
        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            for (int j = 0; j < n; j++) {
                matrix[i, j] = (i == j) ? 2 * n : random.NextDouble();
                sum += matrix[i, j];
            }

            b[i] = sum;
        }

        // Get a string that represents the solution of linear system
        var OutputSolution = ((double[] x, int iters) tuple) => {
            string s = "Корені системи:\n";

            for (int i = 0; i < tuple.x.Length; i++) {
                s += $"x{i + 1} = {tuple.x[i]}\n";
            }

            s += $"Кількість ітерацій: {tuple.iters}\n";

            return s;
        };

        // Output
        Console.WriteLine("Метод Якобі ------------------------------------------");
        Console.WriteLine(OutputSolution(JacobiMethod(matrix, b, eps)));

        Console.WriteLine("Метод Ґауса-Зейделя ----------------------------------");
        Console.WriteLine(OutputSolution(GaussSeidelMethod(matrix, b, eps)));
    }


    // Calculation of the Norm of error between
    // the values obtained on the (k)th and (k+1)th iteration
    public static double Norm(double[] xk, double[] xkp) {
        double norm = 0;
        for (int i = 0; i < xk.Length; i++)
            norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);

        return Math.Sqrt(norm);
    }


    /// Checks whether the error of the solution obtained 
    /// at the (k+1) th iteration does not exceed the specified error
    public static bool Сonverge(double[] xk, double[] xkp, double eps) {
        return Norm(xk, xkp) < eps;
    }


    /// Finding solutions to the system of linear equations by the iterative Jacobi method
    public static (double[] x, int iters) JacobiMethod(in double[,] a, in double[] b, double eps = 0.0001) {
        int n = b.Length;
        double[] tmp_x = new double[n];
        double[] x = new double[n];
        double[] p = new double[n];

        int iter = 0;


        b.CopyTo(x, 0); // First approximation

        do {
            x.CopyTo(p, 0);
            b.CopyTo(tmp_x, 0);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j) tmp_x[i] -= a[i, j] * p[j];
                }
           
                x[i] = tmp_x[i] / a[i, i];
            }
            iter++;

        } while (!Сonverge(x, p, eps));

        return (x, iter);
    }

    /// Finding solutions to the system of linear equations by the iterative Gauss-Seidel method
    public static (double[] x, int iters) GaussSeidelMethod(in double[,] a, in double[] b, double eps = 0.0001) {
        int n = b.Length;
        double[] x = new double[n];
        double[] p = new double[n];

        int iter = 0;

        b.CopyTo(x, 0); // First approximation

        do {
            x.CopyTo(p, 0); // Values of previous iteration

            for (int i = 0; i < n; i++) {
                double tmp = 0;

                for (int j = 0; j < n; j++) {
                    if (j < i) tmp += a[i, j] * x[j];
                    else if (j > i) tmp += a[i, j] * p[j];
                }

                x[i] = (b[i] - tmp) / a[i, i];
            }
            iter++;

        } while (!Сonverge(x, p, eps));


        return (x, iter);
    }
}
