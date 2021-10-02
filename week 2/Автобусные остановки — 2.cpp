#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
	int n, number = 1;
	map<vector<string>, int> stop_bus;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		int kol_ost;
		cin >> kol_ost;
		vector<string> z(kol_ost);
		for (auto& x : z) {
			cin >> x;
		}
		if (stop_bus.count(z)) {
			cout << "Already exists for " << stop_bus[z] << endl;
		}
		else {
			stop_bus[z] = number;
			cout << "New bus " << number << endl;
			number++;
		}
	}
}