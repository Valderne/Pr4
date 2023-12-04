#include <iostream>
#include <iterator>
#include <vector>

// Інтерфейс Обробника
class Handler {
public:
    Handler* next;

    virtual void handle(int request) = 0;
};

// Клас Конкретного обробника 1
class ConcreteHandler1 : public Handler {
public:
    ConcreteHandler1() {
        next = nullptr;
    }

    void handle(int request) override {
        if (request <= 10) {
            std::cout << "A specific handler 1 processed the request" << request << std::endl; //Конкретний обробник 1 обробив запит
        }
        else {
            // Передача запиту наступному обробнику
            if (next != nullptr) {
                next->handle(request);
            }
        }
    }
};

// Клас Конкретного обробника 2
class ConcreteHandler2 : public Handler {
public:
    ConcreteHandler2() {
        next = nullptr;
    }

    void handle(int request) override {
        if (request <= 20) {
            std::cout << "A specific handler 2 processed the request" << request << std::endl;//Конкретний обробник 2 обробив запит 
        }
        else {
            // Передача запиту наступному обробнику
            if (next != nullptr) {
                next->handle(request);
            }
        }
    }
};

// Клас Конкретного обробника 3
class ConcreteHandler3 : public Handler {
public:
    ConcreteHandler3() {
        next = nullptr;
    }

    void handle(int request) override {
        std::cout << "A specific handler 3 processed the request" << request << std::endl;//Конкретний обробник 3 обробив запит 
    }
};

int main() {
    // Створюємо ланцюг обробників
    Handler* handler1 = new ConcreteHandler1();
    handler1->next = new ConcreteHandler2();
    handler1->next->next = new ConcreteHandler3();

    // Передаємо запит ланцюгу обробників
    handler1->handle(15);

    return 0;
}