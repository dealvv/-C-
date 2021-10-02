#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        changed_first[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        changed_last[year] = last_name;
    }
    string GetFullName(const int& year) {
        string name1 = "", name2 = "";
        for (const auto& x : changed_first) {
            if (x.first <= year) name1 = x.second;
        }
        for (const auto& x : changed_last) {
            if (x.first <= year) name2 = x.second;
        }
        if (name1 != "" && name2 != "")  return name1 + " " + name2;
        else if (name1 != "") return name1 + " with unknown last name";
        else if (name2 != "") return name2 + " with unknown first name";
        else return "Incognito";

    }
private:
    string name_f, name_l;
    map<int, string> changed_first;
    map<int, string> changed_last;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    } 

    return 0;
}

