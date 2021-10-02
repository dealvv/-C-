#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
	vector<int> v1 = v;
	for (int i = v1.size() - 1; i >= 0; i--) {
		v[v1.size() - 1 - i] = v1[i];
	}
}

int main(){
	return 0;
}