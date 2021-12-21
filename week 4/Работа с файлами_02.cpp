#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string all;
	ifstream it("input.txt");
	ofstream out("output.txt");
	while (getline(it, all)) {
		out << all << endl;
	}
}