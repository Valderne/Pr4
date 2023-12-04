#include <iostream>
#include <iterator>
#include <vector>

// ��������� ���������
class Handler {
public:
    Handler* next;

    virtual void handle(int request) = 0;
};

// ���� ����������� ��������� 1
class ConcreteHandler1 : public Handler {
public:
    ConcreteHandler1() {
        next = nullptr;
    }

    void handle(int request) override {
        if (request <= 10) {
            std::cout << "A specific handler 1 processed the request" << request << std::endl; //���������� �������� 1 ������� �����
        }
        else {
            // �������� ������ ���������� ���������
            if (next != nullptr) {
                next->handle(request);
            }
        }
    }
};

// ���� ����������� ��������� 2
class ConcreteHandler2 : public Handler {
public:
    ConcreteHandler2() {
        next = nullptr;
    }

    void handle(int request) override {
        if (request <= 20) {
            std::cout << "A specific handler 2 processed the request" << request << std::endl;//���������� �������� 2 ������� ����� 
        }
        else {
            // �������� ������ ���������� ���������
            if (next != nullptr) {
                next->handle(request);
            }
        }
    }
};

// ���� ����������� ��������� 3
class ConcreteHandler3 : public Handler {
public:
    ConcreteHandler3() {
        next = nullptr;
    }

    void handle(int request) override {
        std::cout << "A specific handler 3 processed the request" << request << std::endl;//���������� �������� 3 ������� ����� 
    }
};

int main() {
    // ��������� ������ ���������
    Handler* handler1 = new ConcreteHandler1();
    handler1->next = new ConcreteHandler2();
    handler1->next->next = new ConcreteHandler3();

    // �������� ����� ������� ���������
    handler1->handle(15);

    return 0;
}