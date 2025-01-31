#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

struct elem {
    char key;
    elem* left;
    elem* right;
} *root;

void Add(elem* &t, char value) {
    if (t == NULL) {
        t = new elem;
        t->key = value;
        t->left = NULL;
        t->right = NULL;
    }
    else {
        /*if (t->left == nullptr) {
            Add(t->left, value);
        }
        else if (t->right == nullptr) {
            Add(t->right, value);
        }
        else {
            Add(t->left, value);
        }*/

        if (t->left == NULL) {
            Add(t->left, value);
        }
        else if (t->right == NULL) {
            Add(t->right, value);
        }
        else {
            if (t->left->left != NULL && t->left->right != NULL) {
                Add(t->right, value);
            }
            else if (t->right->left != NULL && t->right->right != NULL) {
                Add(t->right, value);
            }
            else {
                Add(t->left, value);
            }
        }
    }
}

void Infics(elem* t) {
    if (t) {
        Infics(t->left);
        cout << t->key << " ";
        Infics(t->right);
    }
}

int maxProfit(vector<int>& prices) {
    int min = INT32_MAX;
    int max = INT32_MIN;
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (min > prices[i]) {
            min = prices[i];
            minIndex = i;
        }
        if (max < prices[i]) {
            max = prices[i];
            maxIndex = i;
        }
    }

    if (minIndex == maxIndex) {
        return 0;
    }
    else if (minIndex < maxIndex) {
        return prices[maxIndex] - prices[minIndex];
    }
    else {
        int minBeforeMax = 0;
        int maxAfterMin = minIndex;

        for (int i = 0; i < maxIndex; i++) {
            if (prices[minBeforeMax] > prices[i]) {
                minBeforeMax = i;
            }
        }

        for (int i = minIndex; i < prices.size(); i++) {
            if (prices[maxAfterMin] < prices[i]) {
                maxAfterMin = i;
            }
        }

        int variant1 = prices[maxIndex] - prices[minBeforeMax];
        int variant2 = prices[maxAfterMin] - prices[minIndex];

        if (maxIndex == minBeforeMax) {
            return variant2;
        }

        if (minIndex == maxAfterMin) {
            return variant1;
        }

        if (variant1 <= variant2) {
            return variant1;
        }
        else {
            return variant2;
        }
    }
}

int singleNumber(vector<int>& nums) {
    int notDuplicated = 0;

    for (int i = 0; i < nums.size(); i++) {
        bool foundEqual = false;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] == nums[j] && i != j) {
                foundEqual = true;
                break;
            }
        }

        if(!foundEqual) {
            notDuplicated = i;
            break;
        }
    }

    /*for (int i = 1; i < nums.size(); i++) {
        if (nums[notDuplicated] == nums[i]) {
            if (notDuplicated + 1 == i) {
                int j = i + 1;

                while (nums[j] == nums[i]) {
                    j++;
                }

                i = j;
                notDuplicated = j;
            }
            else {
                i = notDuplicated + 1;
                notDuplicated++;
            }
        }
    }*/

    return nums[notDuplicated];
}

int main()
{
    /*Add(root, 'A');
    Add(root, 'C');
    Add(root, 'D');
    Add(root, 'B');
    Add(root, 'N');
    Add(root, 'K');
    Add(root, 'C');
    Add(root, 'L');
    Add(root, 'M');

    Infics(root);*/

    vector<int> masiv = { 1,3,1,-1,3 };
    cout << singleNumber(masiv) << endl;
}


