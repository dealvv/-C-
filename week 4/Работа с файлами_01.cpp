#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string all;
	fstream out("input.txt");
	while (getline(out, all)) {
		cout << all << endl;
	}
}