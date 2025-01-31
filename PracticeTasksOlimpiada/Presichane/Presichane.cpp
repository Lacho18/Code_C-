#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

bool cross(Point A, Point B, Point C, Point D) {

	if (A.y == B.y && C.x == D.x) {
		int x1 = min(A.x, B.x);
		int x2 = max(A.x, B.x);
		int y1 = min(C.y, D.y);
		int y2 = max(C.y, D.y);

		if (x1 < C.x && C.x <= x2 && y1 <= A.y && A.y <= y2) return true;
	}
	else {
		int x1 = min(C.x, D.x);
		int x2 = max(C.x, D.x);
		int y1 = min(A.y, B.y);
		int y2 = max(A.y, B.y);

		if (x1 < A.x && A.x <= x2 && y1 <= C.y && C.y <= y2) return true;
	}

	return false;
}

Point A[2000], B[2000];
int broyNaOtsechky;

int main()
{
	while (cin >> broyNaOtsechky) 
	{
		for (int i = 0; i < broyNaOtsechky; i++) {
			cout << "Enter line " << i << endl;

			cin >> A[i].x;
			cin >> A[i].y;
			cin >> B[i].x;
			cin >> B[i].y;
		}

		int counter = 0;

		for (int i = 0; i < broyNaOtsechky; i++) {
			for (int j = i + 1; j < broyNaOtsechky; j++) {
				if (cross(A[i], B[i], A[j], B[j])) {
					counter++;
				}
			}
		}

		cout << counter << endl;
	}

    return 0;
}

