#include <iostream>
#include <string>

void Log(const char* message) {
	std::cout << message << std::endl;
}

void Log(std::string message) {
	std::cout << message << std::endl;
}

