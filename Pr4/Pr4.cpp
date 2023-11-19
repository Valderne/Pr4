#include <iostream>
#include <vector>


using namespace std;

// ��������� �����������
class Observer {
public:
    virtual void update() = 0;
};

// ��������� ���������������� ��'����
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// ���������� ��������������� ��'���
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

// ���������� ����������
class ConcreteObserver : public Observer {
public:
    void update() override {
        cout << "The observer received an update" << endl;
    }
};

int main() {
    // ��������� ��������������� ��'���
    ConcreteSubject* subject = new ConcreteSubject();

    // ��������� �����������
    ConcreteObserver* observer = new ConcreteObserver();

    // ������ ����������� �� ���������������� ��'����
    subject->addObserver(observer);

    // �������� ������������
    subject->notifyObservers();

    // ��������� ����������� � ���������������� ��'����
    subject->removeObserver(observer);

    // �������� ������������
    subject->notifyObservers();

    return 0;
}