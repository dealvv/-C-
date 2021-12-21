#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	double all;
	ifstream it("input.txt");
	cout << fixed << setprecision(3);
	while (it >> all) {
		cout << all << endl;
	}
}