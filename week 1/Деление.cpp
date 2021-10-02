#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	(b == 0) ? cout << "Impossible" : cout << a / b;
	return 0;
}