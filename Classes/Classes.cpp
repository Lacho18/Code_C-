#include <iostream>

class Person {
private:
    const char* c_name;
    const char* c_favFood;
    int c_age;
    double c_height;

public:
    Person(const char* name, int age, double height, const char* favFood)
        :c_name(name), c_age(age), c_height(height), c_favFood(favFood) 
    {
        std::cout << "Object created" << std::endl;
    }
 
    ~Person() {
        std::cout << "Object destroyed" << std::endl;
    }

    void printPerson() {
        std::cout << "This person name is " << c_name <<
            ". He is " << c_age << " years old. " <<
            "He is " << c_height << "cm height. " <<
            "His favorite food is " << c_favFood << "." << std::endl;
    }

    static void OutPut() {
        std::cout << "OutPut method called" << std::endl;
    }
};

class Triangle {
private:
    int a, b, c;
    int& ref = a;
    int& ref1 = b;
    int& ref2 = c;
public:
    void setSizes(int a, int b, int c) {

        if (a + b < c || a + c < b || b + c < a) {
            std::cout << "Invalid sizes. This triangle can not exsist!" << std::endl;
            ref = 0;
            ref1 = 0;
            ref2 = 0;
        }
        else {
            ref = a;
            ref1 = b;
            ref2 = c;
        }  
    }

    void printSizes() {
        std::cout << "Sizes : " << a << " " << b << " " << c << std::endl;
    }

    int Perimetur() {
        return a + b + c;
    }

    int S() {
        return a * b * c;
    }

};

struct Rectangle {
    int a, b;
    int& ref = a;
    int& ref2 = b;

    void setSizes (int a, int b) {
        ref = a;
        ref2 = b;
    }

    int Perimetur() {
        return (a + b) * 2;
    }

    int S() {
        return a * b;
    }

    void OutPut() {
        std::cout << "Size a = " << a << ", size b = " << b << ". Perimetur = " << Perimetur() << ", S = " << S() << std::endl;
    }
} rectangle;

int main()
{
    /*
    Person person("Ivan", 18, 1.81, "pizza");

    //person.setPersonParameturs("Ivan", 18, 1.81, "pizza");
    person.printPerson();

    std::cout << "==============================" << std::endl;

    Triangle triangle;
    triangle.setSizes(3, 4, 9);
    triangle.printSizes();
    std::cout << triangle.Perimetur() << " , " << triangle.S() << std::endl;

    std::cout << "==============================" << std::endl;

    rectangle.setSizes(5, 7);
    rectangle.OutPut();

    std::cout << "==============================" << std::endl;

    Person secondPerson = Person("Asen", 21, 1.71, "pasta");
    secondPerson.printPerson(); */

    Person::OutPut();
    {
        Person* person = new Person("Daniel", 20, 3.01, "salata");
        person->printPerson();
        delete person;
    }
    std::cout << "Maikati stara" << std::endl;
   
    return 0;
}
