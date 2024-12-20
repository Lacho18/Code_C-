#include <iostream>

void swap(int& a, int& b) {
    int c = 0;
    c = a;
    a = b;
    b = c;
}

void Selection_sort(int mas[], int size) {
    int i, j;
    int min = 0;
    for (i = 0; i < size; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (mas[min] > mas[j]) {
                min = j;
            }
        }
        swap(mas[i], mas[min]);
    }
}

void Buble_sort(int mas[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
            }
        }
    }
}

void Insertion_Sort(int mas[], int size) {
    for (int i = 1; i < size; i++) {
        int key = mas[i];
        int j = i - 1;

        while (j >= 0 && mas[j] > key) {
            mas[j + 1] = mas[j];
            j--;
        }

        mas[j + 1] = key;
    }
}

//Quick sort  -----------------------------------------------
int partition(int mas[], int L, int R) {
    int privite = mas[R];
    int i = L - 1, j;
    for (j = L; j < R; j++) {
        if (mas[j] < privite) {
            i++;
            swap(mas[i], mas[j]);
        }
    }
    swap(mas[i + 1], mas[R]);
    return i + 1;
}

void Quick_sort(int mas[], int leftborder, int rightborder) {
    int q;
    if (leftborder < rightborder) {
        q = partition(mas, leftborder, rightborder);
        Quick_sort(mas, q + 1, rightborder);
        Quick_sort(mas, leftborder, q - 1);
    }
}
//----------------------------------------------------------------------

//Heap sort     --------------------------------------------------------
void heapify(int mas[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && mas[left] > mas[largest]) {
        largest = left;
    }

    if (right < size && mas[right] > mas[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(mas[index], mas[largest]);
        heapify(mas, size, largest);
    }
}

void Heap_Sort(int mas[], int size) {
    int lastWithChilds = size / 2 - 1;

    for (int i = lastWithChilds; i >= 0; i--) {
        heapify(mas, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(mas[0], mas[i]);
        heapify(mas, i, 0);
    }
}
//----------------------------------------------------------------------------

int main()
{
    int masiv[] = { 1, 18, 20, 50, 100, 12, 10, 7, 15, 40, 120, 11, 141 };
    int size = sizeof(masiv) / sizeof(masiv[0]);
    int middle = (size / 2) - 1;

    for (int i = 0; i < size; i++) {
        std::cout << masiv[i] << " ";
    }

    std::cout << "            " << std::endl;

    //Selection_sort(masiv, size);
    //Buble_sort(masiv, size);
    //Insertion_Sort(masiv, size);
    //Quick_sort(masiv, 0, size - 1);
    //Heap_Sort(masiv, size);

    for (int i = 0; i < size; i++) {
        std::cout << masiv[i] << " ";
    }
}

