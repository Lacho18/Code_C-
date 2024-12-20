#include <iostream>

using namespace std;

struct Steck {              //�������� �������� ����
    int key;
    Steck* next;
} *p, * q;

struct Spisuc {             //��������� �������� ������
    int key;
    Spisuc* next;
} *start;

void push(Steck*& t, int number) {          //������� �������� ������� � �����. �� ������ ������ �� ����� �� �����
    if (!t) {
        t = new Steck;
        t->key = number;                    //��� ����� � ������
        t->next = NULL;
    }
    else {
        Steck* h = t;
        t = new Steck;
        t->key = number;                    //��� ����� �� � ������
        t->next = h;
    }
}

void pop(Steck* t) {                        //������� ���������� ������� �� ����. �������� ���������� ������� ������� (Last in, First out)
    if (t) {
        Steck* h = t;
        t = t->next;
        delete h;
    }
}

void PrintSteck(Steck* t) {                 //������� ���������� ���������� �� �����
    Steck* p = t;
    while (p) {
        cout << p->key << " ";
        p = p->next;
    }
}

void AddToSpisuc(int number) {             //������� �������� ������� � ������, ���� �������� ���������� �� ��������
    if (start) {                            //�������� ���� �������� � ������             
        Spisuc* n = start;
        Spisuc* h = nullptr;

        if (n->next) {                      //�������� ���� � ������� ��� ����� 1 �������
            while (n->next) {
                h = n;                      //��������������� �� ������������. ��������� h �� ���� ��������� �������, � n ���������
                n = n->next;

                Spisuc* t = new Spisuc;
                t->key = number;
                if (number > h->key && number < n->key) {     //�������� ���� �������� ���� �� �� ������ ����� ����� ��������.                            
                    h->next = t;                             //���� �� �� ����� ���� ��� �������� � ��� �������� �� - ������ �� ���������� �� h � �� - ����� �� ���������� �� n
                    t->next = n;
                    break;                              //�������� � ������� � ���� break �� ���������� ������, ��������� � ��������� 
                }
                else if (!n->next) {                //�������� ���� � ����� ���� �� �������. ��� ������ �����, ���� ��������, ��              
                    n->next = t;                    //��������� ������� � � ��� - ������ �������� � ������� � ����� � ���� ��.
                    t->next = nullptr;
                    break;
                }
                else if (number < h->key) {         //�������� ���� �������� � �� - ����� �� ����� ������� �������
                    t->next = h;
                    start = t;
                    break;
                }
            }
        }
        else {
            //������ �� �������� �� ������� ��� ������ � ����� 1 �������
            h = new Spisuc;
            h->key = number;
            if (number >= n->key) {
                n->next = h;            //��� �������� � � �� - ������ �������� ����� � ���� �� ������
                h->next = nullptr;
            }
            else {
                start = h;              //��� � � �� - ����� ��������� ����� � ��������
                start->next = n;
            }
        }
    }
    else {
        //� ������, �� �������� � ������
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
    int N = 0;                                                      //������������� �� ����������, ����� �������� �� �� ������� �� �����������
    cin >> N;

    for (int i = 0; i < N; i++) {
        push(p, rand() % 100);                      //��������� �� ��������� �� 'p' �����
    }
    cout << "Steck 'p' generated :" << endl;
    PrintSteck(p);                                  //���������� �� 'p' �����
    cout << " " << endl;
    cout << " " << endl;

    cout << "Enter the number of elements in steck 'q'" << endl;
    cin >> N;

    for (int i = 0; i < N; i++) {
        push(q, rand() % 100);                      //��������� �� ��������� �� 'q' �����
    }
    cout << "Steck 'q' generated :" << endl;
    PrintSteck(q);                                  //���������� �� 'q' �����
    cout << " " << endl;
    cout << " " << endl;

    cout << "Adding elements from steck 'p' to sorted list....." << endl;
    Steck* Add = p;
    while (Add) {                               //�������� �� ���������� �� 'p' ����� � �������
        AddToSpisuc(Add->key);
        Add = Add->next;
    }

    cout << "Printing list elements :" << endl;
    PrintSpisuc();                              //���������� �� ���������� �� �������
}

