import numpy as np
import matplotlib.pyplot as plt

def example_function(x):
    y = x ** 3 - 7 * x ** 2 + 14 * x - 6 # Legea functiei
    return y

def metoda_bisectiei(a, b, f, epsilon):
    x_num = (a + b) / 2 # Prima aproximare
    N = int(np.floor(np.log2((b-a) / epsilon))) # Criteriul de oprire

    # # Iteratiile algoritmului
    for i in range(1, N):
        if f(x_num) == 0: # Daca suntem norocosi
            break
        elif np.sign(f(a)) * np.sign(f(x_num)) < 0:
            b = x_num
        else:
            a = x_num

        x_num = (a + b) / 2

    return x_num

A = 0 # Capatul din stanga al intervalului
B = 4 # Capatul din dreapta al intervalului
num_elem = 100
eps = 1e-3 # 10 ** (-3)

x_num1 = metoda_bisectiei(0., 1., example_function, eps)
x_num2 = metoda_bisectiei(1., 3.2, example_function, eps)
x_num3 = metoda_bisectiei(3.2, 4., example_function, eps)

# Discretizarea domeniului
domeniu = np.linspace(A, B, num_elem)

# Valorile functiei in fiecare punct din domeniu (elementwise)
values = example_function(domeniu)

plt.figure(0) # Deschide o figura
plt.plot(domeniu, values, label = 'f(x)') # Adauga graficul in figura
plt.scatter(x_num1, 0)
plt.scatter(x_num2, 0)
plt.scatter(x_num3, 0)
plt.xlabel('x') # Pune label pe axa Ox
plt.ylabel('y = f(x)') # Pune label pe axa Oy
plt.axhline(0, c='black') # Deseneaza axa Ox
plt.axvline(0, c='black') # Deseneaza axa Oy
plt.title('Metoda bisectiei')

plt.show() # Ne arata figura

metoda_bisectiei(a = A, b = B, f = example_function, epsilon = eps)