#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int count = 1, i, Q;
	vector <vector <string>> mes(31);
	string command, s;
	cin >> Q;
	for (int y = 0; y < Q; y++) {
		cin >> command;
		if (command == "NEXT") {
			count++;
			if (count % 12 == 2) {
				for (int i = 28; i < 31; i++) {
					for (const string& x : mes[i]) {
						mes[27].push_back(x);
					}
				}
				mes.resize(28);
			}
			else {
				if (count % 12 == 4 || count % 12 == 6 || count % 12 == 9 || count % 12 == 11) {
					for (const string& x : mes[30]) {
						mes[29].push_back(x);
					}
					mes.resize(30);
				}
				else {
					mes.resize(31);
				}
			}

		}
		else {
			if (command == "DUMP") {
				cin >> i;
				cout << mes[i - 1].size() << ' ';
				for (const string& x : mes[i - 1]) {
					cout << x << ' ';
				}
				cout << endl;
			}
			else {
				cin >> i >> s;
				mes[i - 1].push_back(s);
			}
		}
	}

}