#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map <char, int> BuildCharCounters(string& z) {
	map <char, int> char_counters;
	for (const char& sim : z) {
		++char_counters[sim];
	}
	return char_counters;
}

int main() {
	int n;
	string a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (BuildCharCounters(a) == BuildCharCounters(b)) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}