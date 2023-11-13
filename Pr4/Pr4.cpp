#include <iostream>

using namespace std;

class Vehicle {
protected:
    string name;
    string type;

public:
    Vehicle(string name = "", string type = "") {
        this->name = name;
        this->type = type;
    }

    ~Vehicle() {}

    virtual void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
    }
};

class Car : public Vehicle {
private:
    double fuelCapacity;

public:
    Car(string name = "", string type = "Car", double fuelCapacity = 50)
        : Vehicle(name, type) {
        this->fuelCapacity = fuelCapacity;
    }

    void getInfo() override {
        Vehicle::getInfo();
        cout << "Fuel capacity: " << fuelCapacity << endl;
    }
};

class Truck : public Vehicle {
private:
    double cargoCapacity;

public:
    Truck(string name = "", string type = "Truck", double cargoCapacity = 10000)
        : Vehicle(name, type) {
        this->cargoCapacity = cargoCapacity;
    }

    void getInfo() override {
        Vehicle::getInfo();
        cout << "Cargo capacity: " << cargoCapacity << endl;
    }
};

int main() {
    Vehicle* vehicles[] = {
        new Car("BMW", "Sedan", 60),
        new Truck("Volvo", "Semi-trailer", 40000),
    };

    for (Vehicle* vehicle : vehicles) {
        vehicle->getInfo();
    }

    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
