#include <iostream>

int MaxValue(int mas[], int masLength) {
    int max = INT32_MIN;
    for (int i = 0; i < masLength; i++) {
        if (max < mas[i]) {
            max = mas[i];
        }
    }
    return max;
}

void IndexInicializations(int masiv[], int masLength) {
    int* pointer = masiv;
    for (int i = 0; i < masLength; i++) {
        std::cin >> *pointer;
        pointer++;
    }
}

void MasivPrinting(int mas[], int masLength) {
    int* pointer = mas;
    for (int i = 0; i < masLength; i++) {
        std::cout << " " << *pointer << " ";
        pointer++;
    }
}
