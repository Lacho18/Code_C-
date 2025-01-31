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
