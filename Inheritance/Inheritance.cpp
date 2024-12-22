#include <iostream>

class Engine {
protected:
    const char* kind;
public:
    Engine() {
        kind = "1.9 TDI";
    }
    ~Engine() {
        std::cout << "Object destroyed" << std::endl;
    }
    void SetName(const char* name) {
        kind = name;
    }
    virtual void OutPut() {
        std::cout << "This engine kind is : " << kind << std::endl;
    }
};

class Vehicle : public Engine {
private:
    int age;
    const char* color;
public:
    Vehicle() {
        age = 18;
        color = "red";
    }
    void OutPut() override {
        std::cout << "This car is " << age << " years old. It's color is " << color << " and its engine kind is " << kind << "." << std::endl;
    }
};

class Figure {
public:
    virtual void OutPut() = 0;
};

class Rectangle : public Figure {
public:
    void OutPut() override {
        std::cout << "This is a rectangle :)" << std::endl;
    }
};

int main()
{
    Engine* vehicle = new Vehicle();
    vehicle->OutPut();
    Engine* engine = new Engine();
    engine->OutPut();
    Figure* figure = new Rectangle();
    figure->OutPut();
    delete vehicle;
    return 0;
}

