#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0; 
};


class Circle : public Figure {
private:
    double radius; 
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return M_PI * radius * radius;
    }

    double perimeter() override {
        return 2 * M_PI * radius;
    }
};


class Rectangle : public Figure {
private:
    double width; 
    double height; 
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override {
        return width * height;
    }

    double perimeter() override {
        return 2 * (width + height);
    }
};


class Triangle : public Figure {
private:
    double a; 
    double b; 
    double c; 
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double area() override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double perimeter() override {
        return a + b + c;
    }
};

int main() {
    int choice;
    cout << "Выберите тип фигуры:\n";
    cout << "1. Круг\n";
    cout << "2. Прямоугольник\n";
    cout << "3. Треугольник\n";
    cin >> choice;

    Figure* figure = nullptr;

    switch (choice) {
        case 1: {
            double radius;
            cout << "Введите радиус круга: ";
            cin >> radius;
            figure = new Circle(radius);
            break;
        }
        case 2: {
            double width, height;
            cout << "Введите ширину и высоту прямоугольника: ";
            cin >> width >> height;
            figure = new Rectangle(width, height);
            break;
        }
        case 3: {
            double a, b, c;
            cout << "Введите стороны треугольника: ";
            cin >> a >> b >> c;
            figure = new Triangle(a, b, c);
            break;
        }
        default:
            cout << "Неверный выбор\n";
            return 1;
    }

    if (figure != nullptr) {
        cout << "Площадь фигуры: " << figure->area() << endl;
        cout << "Периметр фигуры: " << figure->perimeter() << endl;
        delete figure;
    }

    return 0;
}