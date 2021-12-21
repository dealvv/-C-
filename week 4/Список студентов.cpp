#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
	string name;
	string second_name;
	int day;
	int month;
	int year;
};

int main() {
	int n;
	cin >> n;
	vector<Student> students(n);
	for (auto& student : students) {
		cin >> student.name >> student.second_name >> student.day >> student.month >> student.year;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string request;
		int number;
		cin >> request >> number;
		if (number > n  || number < 1 || (request != "name" && request != "date")) cout << "bad request" << endl;
		else {
			int index = number - 1;
			if (request == "name") cout << students[index].name + " " + students[index].second_name << endl;
			else cout << students[index].day << "." << students[index].month << "." << students[index].year << endl;
		}
	}
}