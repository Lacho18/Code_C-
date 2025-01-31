#include <iostream>
#include "AddFunctions.cpp"

struct Spisuc {
    int value;
    Spisuc* next;
} *start;

void Add(int number) {
    Spisuc* p = start;
    start = new Spisuc;
    start->value = number;
    start->next = p;
}

void AddBack(int number) {
    Spisuc* p = start;
    Spisuc* q;
    q = new Spisuc;
    q->value = number;
    q->next = nullptr;
    while (p->next) {
        p = p->next;
    }
    p->next = q;
}

void AddBefore(int number, int k) {
    Spisuc* p = start;
    Spisuc* q;
    while (p->value != k) {
        p = p->next;
    }
    q = new Spisuc;
    q->next = p->next;
    q->value = p->value;
    p->next = q;
    p->value = number;

}

void AddAfter(int number, int k) {
    Spisuc* p = start;
    Spisuc* q;
    while (p->value != k) {
        p = p->next;
    }
    q = new Spisuc;
    q->next = p->next;
    q->value = p->value;
    p->next = q;
    p->value = number;
}

void Delete() {
    Spisuc* p = start;
    if (start) {
        start = start->next;
        delete p;
    }
    else {
        std::cout << "Nothing to delete!" << std::endl;
    }
}

void DeleteBefore(int number) {
    Spisuc* p = start;
    Spisuc* q;
    while (p->value != number) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
}

void DeleteLast() {
    Spisuc* p = start;
    Spisuc* q;
    while (p->next) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    delete p;
}

void Sum() {
    Spisuc* p = start;
    int sum = 0;
    while (start) {
        sum += start->value;
        start = start->next;
    }
    std::cout << sum << std::endl;
    start = p;
}

void Print(struct Spisuc) {
    Spisuc* p = start;
    while (start) {
        std::cout << " " << start->value << std::endl;
        start =  start->next;
    }
    start = p;
}

int main()
{
    Add(5);
    Add(7);
    Add(10);
    Add(18);
    AddBack(-7);
    AddBefore(3, 10);
    Sum();
    Print(*start);
}

