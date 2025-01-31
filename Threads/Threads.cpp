#include <iostream>
//thread biblioteka
#include <thread>
#include <chrono>

using namespace std::literals::chrono_literals;

template<typename T>
void Log(T message) {
    std::cout << message << std::endl;
}

class Names {
    std::string* array;
    int size;
    char symbol;

public:
    Names(char symbol) {
        switch (symbol)
        {
        case 'a': array = new std::string[6]{ "Asen", "Asparyh", "Ashly", "Alex", "Anastasia", "Asq" };
                size = 6;
            break;
        case 'b': array = new std::string[5]{ "Bob", "Bilqna", "BaiIvan", "Billy", "Bisera"};
                size = 5;
            break;
        case 'c': array = new std::string[6]{ "Caloqn", "Camelia", "Carolina", "Camen", "Constantin", "Calin"};
                size = 6;
            break;
        case 'd': array = new std::string[6]{ "Dobrin", "Dara", "Danna", "Diona", "Daniel", "Drago" };
                size = 6;
            break;
        default:  Log("Invalid command");
            array = new std::string[1]{ "" };
            break;
        }
    }

    ~Names() {
        Log("Object destroyed");
        delete[]array;
    }

    std::string NameChooser() {
        int index = rand() % this->size;

        return this->array[index];
    }
};

void MyThread() {

    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

/*std::string NameChooser() {
    std::string Amasiv[] = { "Asen", "Asparyh", "Ashly", "Alex", "Anastasia", "Asq" };

    int size = sizeof(Amasiv) / sizeof(Amasiv[0]);
    int index = rand() % size;

    return Amasiv[index];
} */

std::string NameDefinder(std::string ime, char purvaBykva) {
    Log("");
    Log("You choose your name to be with: "); 
    Log(purvaBykva);
    std::this_thread::sleep_for(1s);
    Names imena = Names(purvaBykva);
    ime = imena.NameChooser();
    return ime;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    /*std::thread myThread(MyThread);
    for (int j = 10; j > 0; j--) {
        std::cout << j << std::endl;
        std::this_thread::sleep_for(1s);
    } */

    char symbol;
    std::string name;
    Log("Choose the first letter of which your name wants to start");
    std::cin >> symbol;

    name = NameDefinder(name, symbol);

    Log("Your name chooser choose:");
    Log(name);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << "s " << std::endl;

}

