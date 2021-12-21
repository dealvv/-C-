#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");
	int n, m;
	int value;
	input >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int z = 0; z < m; ++z) {
			input >> value;
			cout << setw(10) << value;
			if (z != m - 1) {
				input.ignore(1);
				cout << " ";
			}
		}
		if (i != n - 1) cout << endl;
	}
}