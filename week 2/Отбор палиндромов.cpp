#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> pal;
	for (auto x : words) {
		bool a = true;
		for (int i = 0; i < (x.size() / 2); i++) {
			if (!(x[i] == x[x.size() - 1 - i])) a = false;
		}
		if (x.size() >= minLength && a == true) pal.push_back(x);
	}
	return pal;
}

