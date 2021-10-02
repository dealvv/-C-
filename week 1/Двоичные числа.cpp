#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a;
	vector<int> dv;
	cin >> a;
	while (a > 0) {
		dv.push_back(a % 2);
		a /= 2;
	}
	for (int i = dv.size() - 1; i >= 0; i--) {
		cout << dv[i];
	}

	return 0;
}