#include <iostream>
#include <algorithm>

using namespace std;

int globalArray[1000000];

bool comp(int x, int y, int m) {
	int xm = x % m;
	int ym = y % m;

	if (xm < ym) return true;
	if (xm > ym) return false;

	return x < y;
}

int main()
{
	int Tests, numbersCount;

	while (cin >> Tests) {
		cout << "Enter number of numbers." << endl;
		cin >> numbersCount;
		int m;
		cout << "Delete by." << endl;
		cin >> m;

		for (int i = 0; i < numbersCount; i++) {
			cin >> globalArray[i];
		}

		cout << "                " << endl;

		std::sort(globalArray, globalArray + numbersCount, [m](int a, int b) {
			return comp(a, b, m);
		});

		for (int i = 0; i < numbersCount; i++) {
			cout << globalArray[i] << endl;
		}

		cout << " " << endl;
	}

	return 0;
}

