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

    virtual void getInfo() = 0;
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
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Cargo capacity: " << cargoCapacity << endl;
    }
};