#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
void CHANGE_CAPITAL(map<string, string>& z, const string& country, const string& new_capital) {
	if (z.count(country)) {
		if (z[country] == new_capital) cout << "Country " << country << " hasn't changed its capital" << endl;
		else cout << "Country " << country << " has changed its capital from " << z[country] << " to " << new_capital << endl;
	}
	else cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	z[country] = new_capital;

}
void RENAME(map<string, string>& z, const string& old_country_name, const string& new_country_name) {
	if (z.count(old_country_name) == 0 || z.count(new_country_name) != 0 || old_country_name == new_country_name) {
		cout << "Incorrect rename, skip" << endl;
	}
	else {
		cout << "Country " << old_country_name << " with capital " << z[old_country_name] << " has been renamed to " << new_country_name << endl;;
		z[new_country_name] = z[old_country_name];
		z.erase(old_country_name);
	}
}
void ABOUT(map<string, string>& z, const string& country) {
	if (z.count(country) == 0) cout << "Country " << country << " doesn't exist" << endl;
	else cout << "Country " << country << " has capital " << z[country] << endl;
}
void DUMP(const map<string, string>& z) {
	if (z.size() == 0) cout << "There are no countries in the world" << endl;
	else for (const auto& x : z) {
		cout << x.first << "/" << x.second << " ";
	}
	cout << endl;
}

int main() {
	int n;
	map<string, string> geografic;
	string command;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;
			CHANGE_CAPITAL(geografic, country, new_capital);
		} 
		else if (command == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			RENAME(geografic, old_country_name, new_country_name);
		}
		else if (command == "ABOUT") {
			string country;
			cin >> country;
			ABOUT(geografic, country);
		}
		else {
			DUMP(geografic);
		}
	}
}