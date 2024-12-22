#include <iostream>
#include <string>

void Log(const char* message) {
    std::cout << message << std::endl;
}

class String {
private:
    char* MyMessage;
    unsigned int size;
public:
    String(const char* message) {
        size = strlen(message);
        MyMessage = new char[size + 1];
        memcpy(MyMessage, message, size + 1);
    }

    ~String() {
        delete[] MyMessage;
    }

    String(const String& other) 
        :size(other.size) {
        Log("I was called");
        MyMessage = new char[size + 1];
        memcpy(MyMessage, other.MyMessage, size + 1);
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);

    char& operator[](unsigned int index) {
        return MyMessage[index];
    }

    static void SomeText() {
        Log("This function was called");
    }
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.MyMessage;
    return stream;
}

int Increment() {
    static int i = 0;
    i += 1;
    return i;
}

int main()
{
    String text = "Lacho";
    String anotherText = text;
    anotherText[2] = 'e';
    std::cout << text << std::endl;
    std::cout << anotherText << std::endl;
    String::SomeText();
    std::cout << Increment() << std::endl;
    std::cout << Increment() << std::endl;
    std::cout << Increment() << std::endl;
    std::cout << Increment() << std::endl;
}

