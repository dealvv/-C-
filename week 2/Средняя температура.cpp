#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Sr_Ar(const vector<int>& z) {
	int sum = 0;
	for (int x : z) {
		sum += x;
	}
	return sum / z.size();
}

int main() {
	int N, sr, kol = 0;
	cin >> N;
	vector<int> temp(N);
	for (int& x : temp) {
		cin >> x;
	}
	sr = Sr_Ar(temp);
	for (int a : temp) {
		if (a > sr) kol++;
	}
	cout << kol << endl;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] > sr) cout << i << ' ';
	}

	return 0;
}