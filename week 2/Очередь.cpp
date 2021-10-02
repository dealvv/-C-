#include <iostream>
#include <string>
#include <vector>
using namespace std;
void WORRY(vector<int>& temp) {
	int index;
	cin >> index;
	temp[index] = 1;
}
void QUIET(vector<int>& temp) {
	int index;
	cin >> index;
	temp[index] = 0;
}
void COME(vector<int>& temp) {
	int index;
	cin >> index;
	temp.resize(temp.size() + index);
}
void WORRY_COUNT(const vector<int>& temp, vector<int>& t) {
	int sum = 0;
	for (const int& x : temp) {
		sum += x;
	}
	t.push_back(sum);
}

int main() {
	int n;
	vector<int> temp;
	vector<int> t;
	cin >> n;
	string com;
	for (int i = 0; i < n; i++) {
		cin >> com;
		if (com == "WORRY") {
			WORRY(temp);
		}
		if (com == "QUIET") {
			QUIET(temp);
		}
		if (com == "COME") {
			COME(temp);
		}
		if (com == "WORRY_COUNT") {
			WORRY_COUNT(temp, t);
		}

	}
	for (const int& x : t) {
		cout << x << endl;
	}
	
	return 0;
}