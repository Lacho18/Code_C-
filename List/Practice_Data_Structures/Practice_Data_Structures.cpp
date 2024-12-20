#include <iostream>

struct Spisuc {
    int value;
    Spisuc* next;
} *start;


//Fynkcii za dobvqne na elementi v spisuc
void Add_at_the_begining(int key) {
    if (start) {
        Spisuc* p = start;
        start = new Spisuc;
        start->value = key;
        start->next = p;
    }
    else {
        start = new Spisuc;
        start->value = key;
        start->next = nullptr;
    }
}

void Add_before(int key, int k) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q;
        while (p->value != k) {
            p = p->next;
        }
        q = new Spisuc;
        q->next = p->next;
        q->value = p->value;
        p->next = q;
        p->value = key;
    }
    else {
        start = new Spisuc;
        start->value = key;
        start->next = nullptr;
    }
}

void Add_after(int key, int k) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q;
        while (p->value != k) {
            p = p->next;
        }
        q = new Spisuc;
        q->value = key;
        q->next = p->next;
        p->next = q;
    }
    else {
        start = new Spisuc;
        start->value = key;
        start->next = nullptr;
    }
}

void Add_at_the_end(int key) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q;
        while (p->next) {
            p = p->next;
        }
        q = new Spisuc;
        q->value = key;
        p->next = q;
        q->next = nullptr;
    }
    else {
        start = new Spisuc;
        start->value = key;
        start->next = nullptr;
    }
}


//Fynkcii za premahvane na element ot spisuc
int Remove_at_Begining() {
    if (start) {
        Spisuc* p = start;
        start = start->next;
        int n = p->value;
        delete p;
        return n;
    }
    else {
        return -1;
    }
}

int Remove_before(int k) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q = nullptr;
        while (p->value != k) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        q->value = p->value;
        int n = p->value;
        delete p;
        return n;
    }
    else {
        return -1;
    }
}

int Delete_Value(int k) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q = p;
        while (p->value != k) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        int n = p->value;
        delete p;
        return n;
    }
    else {
        return -1;
    }
}

int Remove_after(int k) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q = p;
        while (p->value != k) {
            p = p->next;
        }
        q = p->next;
        int n = q->value;
        p->next = q->next;
        delete q;
        return n;
    }
    else {
        return -1;
    }
}

void Print_Spisuc() {
    Spisuc* p = start;
    while (p) {
        std::cout << p->value << "\n";
        p = p->next;
    }
}

int Remove_last() {
    if (start) {
        Spisuc* p = start;
        Spisuc* q = p;
        while (p->next) {
            q = p;
            p = p->next;
        }
        int n = p->value;
        delete p;
        q->next = nullptr;
        return n;
    }
    else {
        return -1;
    }
}

int main()
{
    start = nullptr;

    Add_at_the_begining(7);
    Add_at_the_begining(11);
    Add_at_the_begining(18);
    Add_at_the_begining(21);
    Print_Spisuc();
    std::cout << "=======================\n";
    int n = Remove_last();
    //std::cout << "Deleted value:" << n << "\n";
    Print_Spisuc();
}

