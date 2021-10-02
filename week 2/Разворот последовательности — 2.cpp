#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> v1;
	for (size_t i = 0; i < v.size(); i++) {
		v1.push_back(v[v.size() - 1 - i]);
	}
	return v1;
}

int main() {
	return 0;
}