#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    double averageSpeed; 
    string modelName; 
    int passengers; 

public:
    
    virtual double getFuelConsumption(double distance) = 0; 
    virtual double calculateTime(double distance) = 0; 

    
    void Print() {
        cout << "Модель: " << modelName << endl;
        cout << "Средняя скорость: " << averageSpeed << " км/ч" << endl;
        cout << "Количество пассажиров: " << passengers << endl;
    }

    
    void Read() {
        cout << "Введите название модели: ";
        getline(cin, modelName);
        cout << "Введите среднюю скорость (км/ч): ";
        cin >> averageSpeed;
        cout << "Введите количество пассажиров: ";
        cin >> passengers;
    }
};


class Bicycle : public Vehicle {
public:
    double getFuelConsumption(double distance) override {
        return 0; 
    }

    double calculateTime(double distance) override {
        return distance / averageSpeed;
    }
};


class Car : public Vehicle {
public:
    double getFuelConsumption(double distance) override {
        return distance * 0.1; 
    }

    double calculateTime(double distance) override {
        return distance / averageSpeed;
    }
};


class Truck : public Vehicle {
public:
    double getFuelConsumption(double distance) override {
        return distance * 0.5; 
    }

    double calculateTime(double distance) override {
        return distance / averageSpeed;
    }
};

int main() {
    cout << "Выберите тип объекта для демонстрации:" << endl;
    cout << "1. Велосипед" << endl;
    cout << "2. Автомобиль" << endl;
    cout << "3. Грузовик" << endl;
    int choice;
    cin >> choice;

    Vehicle* vehicle = nullptr;

    switch (choice) {
        case 1:
            vehicle = new Bicycle();
            break;
        case 2:
            vehicle = new Car();
            break;
        case 3:
            vehicle = new Truck();
            break;
        default:
            cout << "Неверный выбор" << endl;
            return 1;
    }

    vehicle->Read();

    cout << "Информация о транспортном средстве:" << endl;
    vehicle->Print();

    double distance;
    cout << "Введите расстояние (км): ";
    cin >> distance;

    cout << "Потребление топлива для заданного расстояния: " << vehicle->getFuelConsumption(distance) << " л" << endl;
    cout << "Время движения на заданное расстояние: " << vehicle->calculateTime(distance) << " ч" << endl;

    delete vehicle;
    return 0;
}