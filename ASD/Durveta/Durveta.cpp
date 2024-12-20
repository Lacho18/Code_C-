#include <iostream>

struct Tree {
    int value;
    Tree* left;
    Tree* right;
} *root;

void PrintPrefics(Tree* t) {
    if (t) {
        std::cout << t->value << " ";
        PrintPrefics(t->left);
        PrintPrefics(t->right);
    }
}

void PrintPostfics(Tree* t) {
    if (t) {
        PrintPostfics(t->left);
        std::cout << t->value << " ";
        PrintPostfics(t->right);
    }
}

void PrintInfics(Tree* t) {
    if (t) {
        PrintInfics(t->left);
        PrintInfics(t->right);
        std::cout << t->value << " ";
    }
}

void AddToTree(Tree*& t, int number) {
    if (t == nullptr) {
        t = new Tree;
        t->value = number;
        t->left = nullptr;
        t->right = nullptr;
    }
    else {
        if (t->value > number) {
            AddToTree(t->left, number);
        }
        else {
            AddToTree(t->right, number);
        }
    }
}

Tree* SearchFor(Tree* t, int number) {
    Tree* p = t;
    if (t) {
        if (t->value == number) {
            return t;
        }
        else {
            if (t->value > number) {
                SearchFor(t->left, number);
            }
            else {
                SearchFor(t->right, number);
            }
        }
    }
    else {
        return nullptr;
    }
}

Tree* getPrevius(Tree* t, int number) {
    Tree* p = nullptr;

    if (root->value != number) {
        while (t) {
            if (t->value != number) {
                p = t;
                if (t->value > number) {
                    t = t->left;
                }
                else {
                    t = t->right;
                }
            }
            else {
                return p;
            }
        }
        return root;
    }
    else {
        return root;
    }
}

void DeleteFromTree(Tree* t, int number) {
    Tree* p = SearchFor(t, number);

    if (p) {
        Tree* previus = getPrevius(t, p->value);

        if (p->left == nullptr && p->right == nullptr) {
            if (previus->value > p->value) {
                previus->left = nullptr;
            }
            else {
                previus->right = nullptr;
            }
            delete p;
        }
        else if (p->left != nullptr && p->right == nullptr) {
            if (previus->value > p->value) {
                previus->left = p->left;
            }
            else {
                previus->right = p->left;
            }
            delete p;
        }
        else if (p->left == nullptr && p->right != nullptr) {
            if (previus->value > p->value) {
                previus->left = p->right;
            }
            else {
                previus->right = p->right;
            }
            delete p;
        }
        else {
            Tree* q = p->left;

            while (q->right != nullptr) {
                q = q->right;
            }

            Tree* prevOfQ = getPrevius(t, q->value);


            if (q->left != nullptr) {
                if (prevOfQ->value > q->value) {
                    prevOfQ->left = q->left;
                }
                else {
                    prevOfQ->right = q->left;
                }
            }
            else {
                if (prevOfQ->value > q->value) {
                    prevOfQ->left = nullptr;
                }
                else {
                    prevOfQ->right = nullptr;
                }
            }
            p->value = q->value;
            delete q;
        }
    }
}

int main()
{
    AddToTree(root, 30);
    AddToTree(root, 20);
    AddToTree(root, 25);
    AddToTree(root, 12);
    AddToTree(root, 7);
    AddToTree(root, 37);
    AddToTree(root, 33);
    AddToTree(root, 31);
    AddToTree(root, 38);
    AddToTree(root, 24);
    AddToTree(root, 29);
    AddToTree(root, 5);
    AddToTree(root, 9);
    AddToTree(root, 37);

    Tree* neshto = getPrevius(root, 100);
    std::cout << neshto->value << std::endl;

    int N = 0;
    std::cin >> N;

    PrintPrefics(root);
    DeleteFromTree(root, N);
    std::cout << "\n";
    PrintPrefics(root);
}
