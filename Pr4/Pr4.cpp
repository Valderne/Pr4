#include <iostream>
using namespace std;

class Car {
public:
    virtual string getModel() = 0;
    virtual int getHorsepower() = 0;
    virtual int getYear() = 0;
    virtual int getCost() = 0;
    virtual ~Car() {};
};

class Nissan : public Car {
public:
    Nissan(int _horsepower, int _year) {
        horsepower = _horsepower;
        year = _year;
    }
    string getModel() {
        return model;
    }
    int getHorsepower() {
        return horsepower;
    }
    int getYear() {
        return year;
    }
    int getCost() {
        return cost;
    }
private:
    string model = "Nissan";
    int cost = 15000;
    int horsepower;
    int year;
};

class Toyota : public Car {
public:
    Toyota(int _horsepower, int _year) {
        horsepower = _horsepower;
        year = _year;
    }
    string getModel() {
        return model;
    }
    int getHorsepower() {
        return horsepower;
    }
    int getYear() {
        return year;
    }
    int getCost() {
        return cost;
    }
private:
    string model = "Supra";
    int cost = 12000;
    int horsepower;
    int year;
};

class BMW : public Car {
public:
    BMW(int _horsepower, int _year) {
        horsepower = _horsepower;
        year = _year;
    }
    string getModel() {
        return model;
    }
    int getHorsepower() {
        return horsepower;
    }
    int getYear() {
        return year;
    }
    int getCost() {
        return cost;
    }
private:
    string model = "E36";
    int cost = 8000;
    int horsepower;
    int year;
};

int main()
{
    Car* cars[] = { new Nissan(1020,2007), new Toyota(730, 2015), new BMW(715,2000) };
    for (int i = 0; i < size(cars); i++) {
        cout << "Model: " << cars[i]->getModel() << endl
            << "Horsepower: " << cars[i]->getHorsepower() << endl
            << "Year: " << cars[i]->getYear() << endl
            << "Cost: " << cars[i]->getCost() << endl
            << "--------------" << endl;
    }

    for (int i = 0; i < size(cars); i++) {
        delete cars[i];
    }

    return 0;
}