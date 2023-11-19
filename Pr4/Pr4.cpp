#include <iostream>
#include <vector>


using namespace std;

// Інтерфейс спостерігача
class Observer {
public:
    virtual void update() = 0;
};

// Інтерфейс спостережуваного об'єкта
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// Конкретний спостережуваний об'єкт
class ConcreteSubject : public Subject {
private:
    vector<Observer*> observers;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(find(observers.begin(), observers.end(), observer));
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

// Конкретний спостерігач
class ConcreteObserver : public Observer {
public:
    void update() override {
        cout << "The observer received an update" << endl;
    }
};

int main() {
    // Створюємо спостережуваний об'єкт
    ConcreteSubject* subject = new ConcreteSubject();

    // Створюємо спостерігача
    ConcreteObserver* observer = new ConcreteObserver();

    // Додаємо спостерігача до спостережуваного об'єкта
    subject->addObserver(observer);

    // Оповіщаємо спостерігачів
    subject->notifyObservers();

    // Видаляємо спостерігача з спостережуваного об'єкта
    subject->removeObserver(observer);

    // Оповіщаємо спостерігачів
    subject->notifyObservers();

    return 0;
}