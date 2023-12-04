#include <iostream>
#include <iterator>
#include <vector>

// Processor interface
class Handler {
public:
    Handler* next;

    virtual void handle(int request) = 0;
};

// Class of Concrete Handler 1
class ConcreteHandler1 : public Handler {
public:
    ConcreteHandler1() {
        next = nullptr;
    }

    void handle(int request) override {
        if (request <= 10) {
            std::cout << "A specific handler 1 processed the request" << request << std::endl; 
        }
        else {
            // Forwarding the request to the next handler
            if (next != nullptr) {
                next->handle(request);
            }
        }
    }
};

// Class of Concrete Handler 2
class ConcreteHandler2 : public Handler {
public:
    ConcreteHandler2() {
        next = nullptr;
    }

    void handle(int request) override {
        if (request <= 20) {
            std::cout << "A specific handler 2 processed the request" << request << std::endl;
        }
        else {
            // Forwarding the request to the next handler
            if (next != nullptr) {
                next->handle(request);
            }
        }
    }
};

// Class of Concrete Handler 3
class ConcreteHandler3 : public Handler {
public:
    ConcreteHandler3() {
        next = nullptr;
    }

    void handle(int request) override {
        std::cout << "A specific handler 3 processed the request" << request << std::endl;
    }
};

int main() {
    // We create a chain of handlers
    Handler* handler1 = new ConcreteHandler1();
    handler1->next = new ConcreteHandler2();
    handler1->next->next = new ConcreteHandler3();

    // We pass the request to the chain of handlers
    handler1->handle(15);

    return 0;
}