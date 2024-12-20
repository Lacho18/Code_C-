#include <iostream>
#include <string>

int DvoichnoTursene(int masiv[], int leftBorder, int rightBorder, int tursenaStoynost, int size) {
    if (rightBorder >= leftBorder) {
        int sredaNaMasiva = leftBorder + (rightBorder - leftBorder) / 2;
        if (masiv[sredaNaMasiva] == tursenaStoynost) {
            return sredaNaMasiva;
        }
        if (masiv[sredaNaMasiva] > tursenaStoynost) {
            return DvoichnoTursene(masiv, leftBorder, sredaNaMasiva - 1, tursenaStoynost, size);
        }
        return DvoichnoTursene(masiv, sredaNaMasiva + 1, rightBorder, tursenaStoynost, size);
    }
    return -1; 
}

int main() {
	/*int chisla[] = {1, 5, 7, 12, 18, 21, 31, 33, 34, 51, 56, 61, 63, 69, 70, 80, 81, 82, 83, 85, 89, 91, 100};
	int size = 23; 

	int leftBorder = 0;			
	int rightBorder = size;	

	int tursenaStoynost = 70;	

	int result = DvoichnoTursene(chisla, leftBorder, rightBorder, tursenaStoynost, size);
	std::cout << result + 1 << std::endl;*/

    int masivOtChisla[] = {18, 3, 12, 1, -5, -7, 11, -1, 100, 14, 21, 231};
    int size = 12;

    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i; j < size; j++) {            //vlojen cikul v koyto se namira poziciqta na elementa s nay malka stoynost
            if (masivOtChisla[j] < masivOtChisla[min]) {
                min = j;
            }
        }
            
        int c = 0;                                     //razmqna na elementa s nay malka stoynost i purviq element
        c = masivOtChisla[i];
        masivOtChisla[i] = masivOtChisla[min];
        masivOtChisla[min] = c;
    }

    for (int i = 0; i < size; i++) {                    //printirane na masiva 
        std::cout << masivOtChisla[i] << std::endl;
    }
}