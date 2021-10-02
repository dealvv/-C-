#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
	int n;
	map<string, vector<string>> geografic, stoping;
	string command;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> command;
		if (command == "NEW_BUS") {
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			for (size_t i = 0; i < stop_count; i++) {
				string stop;
				cin >> stop;
				geografic[bus].push_back(stop);
				stoping[stop].push_back(bus);
			}
		}
		else if (command == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			if (stoping.count(stop)) {
				for (auto x : stoping[stop]) cout << x << " ";
			}
			else cout << "No stop";
			cout << endl;
		}
		else if (command == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (geografic.count(bus)) {
				for (auto x : geografic[bus]) {
					cout << "Stop " << x << ": ";
					if (stoping[x].size() != 1) {
						for (auto y : stoping[x]) {
							if (y != bus) cout << y << " ";
						}
					}
					else cout << "no interchange";
					cout << endl;
				}
			}
			else cout << "No bus" << endl;
		}
		else if (command == "ALL_BUSES") {
			if (geografic.size() != 0) {
				for (auto x : geografic) {
					cout << "Bus " << x.first << ": ";
					for (auto y : x.second) cout << y << " ";
					cout << endl;
				}
			}
			else cout << "No buses" << endl;
		}
	}
}