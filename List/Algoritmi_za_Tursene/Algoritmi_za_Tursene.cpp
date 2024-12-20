#include <iostream>
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        Stop();
    }

    void Stop() {
        auto stop = std::chrono::high_resolution_clock::now();
        auto nachalo = std::chrono::time_point_cast<std::chrono::microseconds>(start).time_since_epoch().count();

        auto kray = std::chrono::time_point_cast<std::chrono::microseconds>(stop).time_since_epoch().count();

        auto duration = kray - nachalo;

        double ms = duration * 0.001;

        std::cout << duration * 0.001 << " 's \n";
    }
};

void SelectionSort(int mas[], int size) {
    int i = 0, j = 1;
    int min = 0; 
    int swap = 0;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (mas[i] > mas[j]) {
                swap = mas[i];
                mas[i] = mas[j];
                mas[j] = swap;
            }
        }
    }
}

void BubbleSort(int mas[], int size) {
    int i, j, swap;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - (i + 1); j++) {
            if (mas[j] > mas[j + 1]) {
                swap = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = swap;
            }
        }
    }
}

//-----------------------------------------------
//Quick sort algotithum
int Partition(int mas[], int L, int R) {
    int privite = mas[R];
    int swap, j, i = L - 1;
    for (j = L; j < R; j++) {
        if (mas[j] < privite) {
            i++;
            swap = mas[i];
            mas[i] = mas[j];
            mas[j] = swap;
        }
    }
    swap = mas[i + 1];
    mas[i + 1] = mas[R];
    mas[R] = swap;
    return(i + 1);
}

void QuickSort(int mas[], int L, int R) {
    int q;
    if (L < R) {
        q = Partition(mas, L, R);
        QuickSort(mas, L, q - 1);
        QuickSort(mas, q + 1, R);
    }
}
//------------------------------------------------------



int lineynoTursene(int mas[], int leftBorder, int rightBorder, int key) {
    for (int i = leftBorder; i <= rightBorder; i++) {
        if (mas[i] == key) {
            return i;
        }
    }

    return -1;
}

int TurseneSusStupka(int mas[], int size, int step, int lookingFor) {
    int i = 0;
    for (i = 0; i < size; i += step) {
        if (lookingFor < mas[i]) {
            return lineynoTursene(mas, i - step, i, lookingFor);
        }
    }
}

int DvoichnoTursene(int mas[], int leftBorder, int rightBorder, int key) {
    int midle = (leftBorder + rightBorder) >> 1;
    int lookingIndex = 0;

        if (key < mas[midle]) {
            rightBorder = midle - 1;
            DvoichnoTursene(mas, leftBorder, rightBorder, key);
        }
        else if (key > mas[midle]) {
            leftBorder = midle + 1;
            DvoichnoTursene(mas, leftBorder, rightBorder, key);
        }
        else {
            return midle;
        }

   
}

void PrintMasiv(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << *mas << " \n";
        mas++;
    }
}

int main()
{
    //int masiv[] = { 1, 7, 15, 100, 112, 18, 10, 11, 3, 20 };
    int masiv[1000];
    int size = sizeof(masiv) / sizeof(masiv[0]);
    for (int i = 0; i < size; i++) {
        masiv[i] = rand() % 5001;
    }

    //PrintMasiv(masiv, size);
    std::cout << "=======================\n\n";
    {
        Timer timer;
        //SelectionSort(masiv, size);
        //BubbleSort(masiv, size);
        QuickSort(masiv, 0, size - 1);
    }
    std::cout << "=======================\n\n";
    //PrintMasiv(masiv, size);
    std::cout << "=======================\n\n";
    std::cout << "=======================\n\n";
    int n;
    {
        Timer timer;
        //n = TurseneSusStupka(masiv, size, 3, 4312);
        //n = lineynoTursene(masiv, 0, size, 4312);
        n = DvoichnoTursene(masiv, 0, size, 4312);
    }
    
    std::cout << n << std::endl;
}

