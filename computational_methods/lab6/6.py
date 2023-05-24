# Реалізація методу Рунгу-Кутти
def runge_kutta(h, r, K, a, N0):
    t = 0
    N = N0
    results = [(t, N)]
    while t < 5:
        k1 = h * (r * N * (1 - ((N/K)**a)))
        k2 = h * (r * (N + k1/2) * (1 - (((N + k1/2)/K)**a)))
        k3 = h * (r * (N + k2/2) * (1 - (((N + k2/2)/K)**a)))
        k4 = h * (r * (N + k3) * (1 - (((N + k3)/K)**a)))

        N += (1/6) * (k1 + 2*k2 + 2*k3 + k4)
        t += h
        results.append((t, N))
    return results

# Вхідні параметри
h = 0.1
r = 0.85
K = 2.25
a = 2
N0 = 1.15

# Обчислення розв'язку
solution = runge_kutta(h, r, K, a, N0)

# Виведення результатів
for t, N in solution:
    print(f"Час: {t:.1f}, Чисельність популяції: {N:.4f}")

# Перевірка виконання умов завдання
final_time, final_population = solution[-1]
expected_final_population = 2.25 # Очікувана кінцева чисельність популяції
tolerance = 0.001 # Допустима похибка

if abs(final_population - expected_final_population) <= tolerance:
    print("Умова завдання виконана: правильна кінцева чисельність популяції.")
else:
    print("Умова завдання не виконана: неправильна кінцева чисельність популяції.")
