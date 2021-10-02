#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	vector<string> ch = { a, b, c };
	sort(ch.begin(), ch.end());
	cout << ch[0];
	return 0;
}