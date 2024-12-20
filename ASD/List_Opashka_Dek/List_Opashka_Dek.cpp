#include <iostream>

//Spisuc -------------------------------------------------
struct Spisuc {
    int value;
    Spisuc* next;
}*start = nullptr;

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

void Add_before_key(int k, int key) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q;
        while (p->value != key)
        {
            p = p->next;
        }
        q = new Spisuc;
        q->next = p->next;
        p->next = q;
        q->value = p->value;
        p->value = k;
    }
    else {
        start = new Spisuc;
        start->value = key;
        start->next = nullptr;
    }
}

void Add_after_key(int k, int key) {
    if (start) {
        Spisuc* p = start;
        Spisuc* q;
        while (p->value != key)
        {
            p = p->next;
        }
        q = new Spisuc;
        q->value = k;
        q->next = p->next;
        p->next = q;
    }
    else {
        start = new Spisuc;
        start->value = k;
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

int Remove_first() {
    if (start) {
        int n;
        Spisuc* p = start;
        start = start->next;
        n = p->value;
        delete p;
        return n;
    }
    else {
        return -1;
    }
}

int Remove_before(int k) {
    if (start) {
        int n = 0;
        Spisuc* p = start;
        Spisuc* q = p;
        while (p->value != k) {
            q = p;
            p = p->next;
        }
        if (q != p) {
            n = q->value;
            q->value = p->value;
            q->next = p->next;
        }
        else {
            q = p->next;
            start = q;
        }
        delete p;
        return n;
    }
    else {
        return -1;
    }
}

int Remove(int k) {
    if (start) {
        int n = 0;
        Spisuc* p = start;
        Spisuc* q = p;
        while (p->value != k) {
            q = p;
            p = p->next;
        }
        if (q != p) {
            n = p->value;
            q->next = p->next;
        }
        else {
            q = p->next;
            start = q;
        }
        delete p;
        return n;
    }
    else {
        return -1;
    }
}

int Remove_after(int k) {
    if (start) {
        int n;
        Spisuc* p = start;
        Spisuc* q = p;
        while (p->value != k) {
            p = p->next;
        }
        q = p->next;
        n = q->value;
        p->next = q->next;
        delete q;
        return n;
    }
    else {
        return -1;
    }
}

int Remove_last() {
    if (start) {
        int n;
        Spisuc* p = start;
        Spisuc* q = p;
        while (p->next) {
            q = p;
            p = p->next;
        }
        n = p->value;
        delete p;
        q->next = nullptr;
    }
    else {
        return -1;
    }
}

void PrintSpisuc() {
    Spisuc* p = start;
    while (p) {
        std::cout << p->value << std::endl;
        p = p->next;
    }
}
//----------------------------------------------------------------------------

//Opashka---------------------------------------------------------------------
struct Opashka {
    int value;
    Opashka* next;
}*first = nullptr, * last = nullptr;

void Add_v_opashka(int key) {
    if (first) {
        Opashka* p = last;
        last = new Opashka;
        last->value = key;
        last->next = nullptr;
        p->next = last;
    }
    else {
        last = new Opashka;
        last->value = key;
        first = last;
        last->next = nullptr;
    }
}

int Remove_ot_opashka() {
    if (first == last) {
        if (first) {
            int n = first->value;
            delete first;
            first = nullptr;
            last = nullptr;
            return n;
        }
        else {
            return -1;
        }
    }
    else {
        int n;
        Opashka* p = first;
        first = first->next;
        n = p->value;
        delete p;
        return n;
    }
}

void Print_Opashka() {
    Opashka* p = first;
    while (p) {
        std::cout << p->value << std::endl;
        p = p->next;
    }
}
//------------------------------------------------------------

//Dek---------------------------------------------------------
struct Dek {
    int value;
    Dek* next;
}*left = nullptr, * right = nullptr;

void Add_left(int key) {
    if (left) {
        Dek* p = left;
        left = new Dek;
        left->value = key;
        left->next = p;
    }
    else {
        left = new Dek;
        left->value = key;
        right = left;
        left->next = nullptr;
    }
}

void Add_right(int key) {
    if (left) {
        Dek* p = left;
        while (p->next) {
            p = p->next;
        }
        right = new Dek;
        right->value = key;
        p->next = right;
        right->next = nullptr;
    }
    else {
        left = new Dek;
        left->value = key;
        right = left;
        left->next = nullptr;
    }
}

int Remove_left() {
    if (left == right) {
        if (left) {
            int n = left->value;
            delete left;
            left = nullptr;
            right = nullptr;
            return n;
        }
        else {
            return -1;
        }
    }
    else {
        int n;
        Dek* p = left;
        n = p->value;
        left = left->next;
        delete p;
        return n;
    }
}

int Remove_right() {
    if (left == right) {
        if (left) {
            int n = left->value;
            delete left;
            left = nullptr;
            right = nullptr;
            return n;
        }
        else {
            return -1;
        }
    }
    else {
        int n;
        Dek* p = left;
        Dek* q = right;
        while (p->next != right) {
            p = p->next;
        }
        n = q->value;
        right = p;
        right->next = nullptr;
        delete q;
        return n;
    }
}

void Print_Dek() {
    Dek* p = left;
    while (p) {
        std::cout << p->value << std::endl;
        p = p->next;
    }
}
//-----------------------------------------------------------------------------

int main()
{
    /*Add_at_the_begining(7);
    Add_at_the_begining(11);
    Add_at_the_begining(18);
    Add_at_the_begining(21);
    Add_before_key(12, 18);
    Add_after_key(12, 18);
    Add_at_the_end(100);
    Remove_before(7);
    Remove_after(100);
    Remove(21);
    PrintSpisuc();*/

    /*Add_v_opashka(1);
    Add_v_opashka(3);
    Add_v_opashka(7);
    Add_v_opashka(11);
    Add_v_opashka(12);
    Add_v_opashka(18);
    Add_v_opashka(21);
    Remove_ot_opashka();
    Print_Opashka();*/

    //Add_left(1);
    //Add_left(2);
    //Add_left(3);
    //Add_left(4);
    //Add_left(5);
    //Add_right(6);
    ////Remove_left();
    ////Remove_right();
    //Print_Dek();
}

