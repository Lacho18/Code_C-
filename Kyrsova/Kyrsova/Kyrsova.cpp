#include <iostream>

using namespace std;

struct Steck {              //Сруктора описваща стек
    int key;
    Steck* next;
} *p, * q;

struct Spisuc {             //Структура описваща списък
    int key;
    Spisuc* next;
} *start;

void push(Steck*& t, int number) {          //Функция добавяща елемент в стека. Тя добавя винаги на върха на стека
    if (!t) {
        t = new Steck;
        t->key = number;                    //Ако стека е празен
        t->next = NULL;
    }
    else {
        Steck* h = t;
        t = new Steck;
        t->key = number;                    //Ако стека не е празен
        t->next = h;
    }
}

void pop(Steck* t) {                        //Функция премахваща елемент от стек. Премахма последният добавен елемент (Last in, First out)
    if (t) {
        Steck* h = t;
        t = t->next;
        delete h;
    }
}

void PrintSteck(Steck* t) {                 //Функция принтираща елементите на стека
    Steck* p = t;
    while (p) {
        cout << p->key << " ";
        p = p->next;
    }
}

void AddToSpisuc(int number) {             //Функция добавяща елемент в списък, като подрежда елементите по големина
    if (start) {                            //Проверка дали списъкът е празен             
        Spisuc* n = start;
        Spisuc* h = nullptr;

        if (n->next) {                      //Проверка дали в списъка има точно 1 елемент
            while (n->next) {
                h = n;                      //Преустановяване на показателите. Показател h ще сочи предишния елемент, а n настоящия
                n = n->next;

                Spisuc* t = new Spisuc;
                t->key = number;
                if (number > h->key && number < n->key) {     //Проверка дали елемента може да се вмъкне между двата елемента.                            
                    h->next = t;                             //Това ще се случи само ако елемента е със стойност по - голяма от стойността на h и по - малка от стойността на n
                    t->next = n;
                    break;                              //Елемента е добавен и чрез break се прекратява цикъла, съответно и функцията 
                }
                else if (!n->next) {                //Проверка дали е дошъл края на списъка. Ако товасе случи, това означава, че              
                    n->next = t;                    //добавяния елемент е с най - голяма стойност в списъка и отива в края му.
                    t->next = nullptr;
                    break;
                }
                else if (number < h->key) {         //Проверка дали елемента е по - малък от самия стартов елемент
                    t->next = h;
                    start = t;
                    break;
                }
            }
        }
        else {
            //Случай на добавяне на елемент при списък с точно 1 елемент
            h = new Spisuc;
            h->key = number;
            if (number >= n->key) {
                n->next = h;            //Ако елемента е с по - висока стойност отива в края на случая
                h->next = nullptr;
            }
            else {
                start = h;              //Ако е с по - ниска елементът отива в началото
                start->next = n;
            }
        }
    }
    else {
        //в случай, че списъкът е празен
        start = new Spisuc;
        start->key = number;
        start->next = nullptr;
    }
}

void PrintSpisuc() {
    Spisuc* p = start;
    while (p) {
        cout << p->key << " ";
        p = p->next;
    }
}

int main()
{
    cout << "Enter the number of elements in steck 'p'" << endl;
    int N = 0;                                                      //Инициализация на променлива, чиято стойност ще се въвежда от потребителя
    cin >> N;

    for (int i = 0; i < N; i++) {
        push(p, rand() % 100);                      //Въвеждане на стойности на 'p' стека
    }
    cout << "Steck 'p' generated :" << endl;
    PrintSteck(p);                                  //Принтиране на 'p' стека
    cout << " " << endl;
    cout << " " << endl;

    cout << "Enter the number of elements in steck 'q'" << endl;
    cin >> N;

    for (int i = 0; i < N; i++) {
        push(q, rand() % 100);                      //Въвеждане на стойности на 'q' стека
    }
    cout << "Steck 'q' generated :" << endl;
    PrintSteck(q);                                  //Принтиране на 'q' стека
    cout << " " << endl;
    cout << " " << endl;

    cout << "Adding elements from steck 'p' to sorted list....." << endl;
    Steck* Add = p;
    while (Add) {                               //Добавяне на елементите от 'p' стека в списъка
        AddToSpisuc(Add->key);
        Add = Add->next;
    }

    cout << "Printing list elements :" << endl;
    PrintSpisuc();                              //Принтиране на елементите от списъка
}

