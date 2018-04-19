
import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('datos.txt')
u_inicial = datos[0,1:-1]
u_final = datos[-2, 1:-1]
x = datos[-1, 1:-1]

plt.figure
plt.plot(x,u_final, label = 'final')
plt.plot(x,u_inicial,label = 'inicial')
plt.savefig('PDE.pdf')
