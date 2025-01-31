#include <iostream>
#include "MasivFunctions.h";
#include <string>

using String = std::string;

void Log(const char* message);
void Log(std::string message);

void Increment(int& value) {
    value++;
}

int main()
{
    /*
    Log("Hello world");

    int masiv[5];

    IndexInicializations(masiv, 5);
    MasivPrinting(masiv, 5);

    std::cout << std::endl
        << "The maximum value is : " << MaxValue(masiv, 5) << std::endl;
    */
    //Log("==============================");

    int a = 5;
    int& ref = a;
    Increment(ref);
    std::cout << a << std::endl;
    std::cout << ref << std::endl;
    Log("===========================");
    const int* number = new int(10);
    int anumber = 18;
    std::cout << *number << std::endl;
    number = (int*)&anumber;
    std::cout << *number << std::endl;
    anumber++;
    std::cout << *number << std::endl;
    Log("===========================");
    String name = std::string("Lacho") + " hello!";
    std::cout << sizeof(name) << std::endl;
    Log(name);
    name[2] = 'z';
    std::cout << sizeof(name) << std::endl;
    Log(name);
    name += " You are a C++ programmer";
    std::cout << sizeof(name) << std::endl;
    Log(name);

    return 0;
}

