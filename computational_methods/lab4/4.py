# import numpy as np
# from scipy.interpolate import interp1d, CubicSpline
# import matplotlib.pyplot as plt
# from datetime import datetime
# import matplotlib.dates as mdates

# # Задана вибірка даних
# dates = ['31.12.2006', '31.12.2007', '31.12.2008', '31.12.2009', '31.12.2010',
#          '31.12.2011', '31.12.2012', '31.12.2013', '31.12.2014', '31.12.2015']
# gdp = [54512, 79955, 101659, 103396, 117343, 126236, 116454, 135065, 142079, 126308]

# # Проінтерполювати функцію в деякій точці x
# x_interpolation = datetime.strptime('31.12.2015', '%d.%m.%Y')

# # Перетворення дат на числові значення
# x = [datetime.strptime(date, '%d.%m.%Y') for date in dates]

# # Поліноміальна інтерполяція
# poly_interp = interp1d([date.timestamp() for date in x], gdp, kind='linear')
# y_poly = poly_interp(x_interpolation.timestamp())

# # Кубічна сплайн-інтерполяція
# cubic_interp = CubicSpline([date.timestamp() for date in x], gdp)
# y_cubic = cubic_interp(x_interpolation.timestamp())

# # Метод найменших квадратів
# x_numeric = np.array([date.timestamp() for date in x])
# A = np.vstack([x_numeric, np.ones(len(x_numeric))]).T
# m, c = np.linalg.lstsq(A, gdp, rcond=None)[0]
# y_lsq = m * x_interpolation.timestamp() + c

# # Конвертувати об'єкти datetime в числові значення
# x_numeric = [date.timestamp() for date in x]

# # Поліноміальна інтерполяція
# poly_func = np.poly1d(np.polyfit(x_numeric, gdp, 3))
# x_interpolation_numeric = x_interpolation.timestamp()
# y_poly = poly_func(x_interpolation_numeric)

# # Графічне відображення результатів
# plt.plot(x, gdp, 'o', label='Вихідні дані')
# plt.plot(x_interpolation, y_poly, 'ro', label='Поліноміальна інтерполяція')
# plt.plot(x_interpolation, y_cubic, 'go', label='Кубічна сплайн-інтерполяція')
# plt.plot(x_interpolation, y_lsq, 'bo', label='Найменші квадрати')

# # Побудувати поліноміальну інтерполяцію на більшій кількості точок для візуалізації
# x_poly = np.linspace(x[0], x[-1], 100)
# y_poly = poly_func([date.timestamp() for date in x_poly])
# plt.plot(x_poly, y_poly, 'r-', label='Поліноміальна інтерполяція')

# plt.xlabel('Дата')
# plt.ylabel('ВВП (млн. дол. США)')
# plt.title('Наближення функції ВВП України')
# plt.legend()
# plt.xticks(rotation=45)
# plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%d.%m.%Y'))
# plt.gcf().autofmt_xdate()
# plt.tight_layout()
# plt.show()


import numpy as np
import matplotlib.pyplot as plt

# X = np.arange(2006, 2016, dtype=np.float64)
# Y = np.array([54512, 79955, 101659, 103396, 117343, 126236, 116454, 135065, 142079, 126308], dtype=np.float64)

X = np.array([2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018], dtype=np.float64)
print(X)
Y = np.array([103396, 117343, 126236, 135065, 142079, 126308, 118729, 113518, 116578, 114707], dtype=np.float64)
def phi(x_array, k):
    return x_array ** k


def GetCoefficients(x, y, n):

    matrix = np.zeros((n, n))
    b = np.zeros(n)

    for i in range(n):
        for j in range(n):
            matrix[i, j] = np.sum(phi(x, i) * phi(x, j))

        b[i] = np.sum(y * phi(x, i))

    return np.linalg.solve(matrix, b)[::-1]


def MaxError(f_res, phi_res):
    return np.max(np.abs(f_res - phi_res))


def MeanError(f_res, phi_res):
    return np.mean(np.abs(f_res - phi_res))


def MeanSquaredError(f_res, phi_res):
    return np.sqrt(np.mean((f_res - phi_res) ** 2))


new_x = np.linspace(X[0], X[-1], 100)
coefficients = GetCoefficients(X, Y, 15)

f = np.poly1d(coefficients)

print('Максимальна похибка: ', MaxError(Y, f(X)))
print('Середня похибка', MeanError(Y, f(X)))
print('Середньоквадратична похибка', MeanSquaredError(Y, f(X)))

plt.figure(figsize=(8, 6))

plt.plot(new_x, f(new_x), color='yellow', label='Середньоквадратичне наближення')
plt.plot(X, Y, '--bo', label='Початкова функція')

plt.legend()
plt.show()

