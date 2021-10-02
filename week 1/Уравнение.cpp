#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, x1, x2;
	a = b = c = 0;
	cin >> a >> b >> c;
	if (a == 0 && c == 0 || b == 0 && c == 0) cout << 0;
	else if ((b * b - 4 * a * c > 0 && a != 0) > 0) {
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << x1 << ' ' << x2;
	}
	else if (a == 0 && b!= 0) {
		x1 = -c / b;
		cout << x1;
	}
	else if ((b * b - 4 * a * c) == 0 && !( a == 0 && b == 0)) {
		x1 = -b / (2 * a);
		cout << x1;
	}
	
	return 0;
}