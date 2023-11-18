#include <iostream>

using namespace std;

class Dish {
public:
    virtual void prepareIngredients() = 0;
    virtual void cook() = 0;
    virtual void serve() = 0;
};

class Pizza : public Dish {
public:
    void prepareIngredients() override {
        std::cout << "Preparation of ingredients for pizza:" << std::endl;
        std::cout << "-dough" << std::endl;
        std::cout << "-sauce" << std::endl;
        std::cout << "-pizza topping" << std::endl;
    }

    void cook() override {
        std::cout << "Cooking pizza in the oven" << std::endl;
    }

    void serve() override {
        std::cout << "Serving pizza to the table" << std::endl;
    }
};

class Soup : public Dish {
public:
    void prepareIngredients() override {
        std::cout << "Preparation of ingredients for soup:" << std::endl;
        std::cout << "-bouillon" << std::endl;
        std::cout << "-vegetables" << std::endl;
        std::cout << "-meat" << std::endl;
    }

    void cook() override {
        std::cout << "Cooking soup on the stove" << std::endl;
    }

    void serve() override {
        std::cout << "Serve the soup in a plate" << std::endl;
    }
};

class Builder {
public:
    virtual void build(Dish* dish) = 0;
};

class PizzaBuilder : public Builder {
public:
    void build(Dish* dish) override {
        dish->prepareIngredients();
        dish->cook();
        dish->serve();
    }
};

class SoupBuilder : public Builder {
public:
    void build(Dish* dish) override {
        dish->prepareIngredients();
        dish->cook();
        dish->serve();
    }
};

int main() {
    Dish* dish;

    // ЅудуЇмо п≥цу
    PizzaBuilder pizzaBuilder;
    dish = new Pizza();
    pizzaBuilder.build(dish);

    // ЅудуЇмо суп
    SoupBuilder soupBuilder;
    dish = new Soup();
    soupBuilder.build(dish);

    return 0;
}