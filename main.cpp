#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

// Estructura para representar un punto en d dimensiones
struct Point {
    vector<double> coordinates;

    Point(int dimensions) {
        coordinates.resize(dimensions);
    }
};

// Función para calcular la distancia euclidiana entre dos puntos
double euclideanDistance(const Point& p1, const Point& p2) {
    double sum = 0.0;
    for (size_t i = 0; i < p1.coordinates.size(); ++i) {
        double diff = p1.coordinates[i] - p2.coordinates[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    // Dimensiones requeridas
    vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};

    for (int d : dimensions) {
        // Genera 100 puntos aleatorios en d dimensiones
        vector<Point> points(100, Point(d));
        uniform_real_distribution<> dis(0.0, 1.0);

        for (Point& p : points) {
            for (double& coord : p.coordinates) {
                coord = dis(gen);
            }
        }

        // Calcula y muestra las distancias entre todos los pares de puntos
        vector<double> distances;
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = i + 1; j < points.size(); ++j) {
                double distance = euclideanDistance(points[i], points[j]);
                distances.push_back(distance);
            }
        }

        // Exporta las distancias a un archivo de texto
        string filename = "D:/UNSA/4/EDA/EDA-LAB1/distances_" + to_string(d) + ".txt";
        ofstream outFile(filename);

        if (outFile.is_open()) {
            for (double distance : distances) {
                outFile << distance << endl;
            }
            outFile.close();
            cout << "Archivo " << filename << " generado." << endl;
        } else {
            cerr << "No se pudo abrir el archivo " << filename << " para escritura." << endl;
        }
    }
    
    return 0;
}