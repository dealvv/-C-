#include <iostream>
#include <string>
using namespace std;


struct Specialization {
	string value;
	explicit Specialization(const string& new_value) {
		value = new_value;
	}
};

struct Course {
	string value;
	explicit Course(const string& new_value) {
		value = new_value;
	}
};

struct Week {
	string value;
	explicit Week(const string& new_value) {
		value = new_value;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(const Specialization& x, const Course& y,const Week& z) {
		specialization = x.value;
		course = y.value;
		week = z.value;
	}
};

int main() {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	return 0;
}