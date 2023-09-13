#include <iostream>
#include <cmath>

class Ponto {
private:
    double x;
    double y;

public:
    // Construtor padrão
    Ponto() : x(0.0), y(0.0) {}

    // Construtor que permite definir as coordenadas x e y
    Ponto(double x, double y) : x(x), y(y) {}

    // Métodos para definir as coordenadas
    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    // Métodos para obter as coordenadas
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    // Método para calcular a distância até a origem (0,0)
    double calcularDistanciaOrigem() const {
        return std::sqrt(x * x + y * y);
    }
};

int main() {
    Ponto ponto1; // Cria um ponto na origem (0,0)
    Ponto ponto2(3.0, 4.0); // Cria um ponto com coordenadas (3,4)

    std::cout << "Coordenadas do ponto1: (" << ponto1.getX() << ", " << ponto1.getY() << ")" << std::endl;
    std::cout << "Coordenadas do ponto2: (" << ponto2.getX() << ", " << ponto2.getY() << ")" << std::endl;

    std::cout << "Distância do ponto1 até a origem: " << ponto1.calcularDistanciaOrigem() << std::endl;
    std::cout << "Distância do ponto2 até a origem: " << ponto2.calcularDistanciaOrigem() << std::endl;

    return 0;
}
