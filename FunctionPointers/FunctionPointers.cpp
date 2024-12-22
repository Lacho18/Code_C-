#include <iostream>
#include <array>

template<typename T>
void Log(T message) {
    std::cout << message << std::endl;
}

void MultiplyThisShit(int a, int b) {
    Log(a * b);
}

void PrintValueSquare(int a) {
    Log(a * a);
}

void ForEach(std::array<int, 7> data, void(*func)(int a)) {
    for (int i = 0; i < 7; i++) {
        func(data[i]);
    }
}

int main()
{
    typedef void(*function)(int, int);
    function funciq = MultiplyThisShit;
    funciq(11, 18);
    Log("========================");
    auto PrintElement = PrintValueSquare;
    std::array<int, 7> masiv = {1, 5, 7, 9, 11, 18, 100};
    ForEach(masiv, PrintValueSquare);
    Log("========================");
    ForEach(masiv, []() {
        Log("Called"); })
}
