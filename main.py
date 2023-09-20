import matplotlib.pyplot as plt
import numpy as np

# Lista de dimensiones para las que tienes archivos de distancias
dimensiones = [10, 50, 100, 500, 1000, 2000, 5000]

for d in dimensiones:
    # Cargar distancias desde el archivo correspondiente
    filename = f"distances_{d}.txt"
    distances = np.loadtxt(filename)

    # Generar un histograma
    plt.hist(distances, bins=20, edgecolor='k')
    plt.title(f'Histograma de Distancias (Dimensión {d})')
    plt.xlabel('Distancia')
    plt.ylabel('Frecuencia')
    plt.grid(True)

    # Mostrar el histograma
    plt.show()