#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string FindNameByYear(const map<int, string>& names, int year) {
    string name = "";
    for (const auto& x : names) {
        if (x.first <= year) name = x.second;
        else break;
    }
    return name;
}
string FindAllNameByYear(const map<int, string>& names, int year) {
    string name = "";
    vector<string> all;
    vector<string> all_names;
    for (const auto& x : names) {
        if (x.first <= year) all.push_back(x.second);
        else break;
    }
    if (all.size() == 0) return name;
    else if (all.size() == 1) return all[0];
    else if (all.size() > 1) {
        all_names.push_back(all[all.size() - 1]);
        for (int i = all.size() - 2; i >= 0; --i) {
            if (all[i] != all[i + 1]) all_names.push_back(all[i]);
        }
        if (all_names.size() == 1) return all[0];
        else {
            name += (all_names[0] + " (");
            for (int z = 1; z < all_names.size(); z++) {
                name += all_names[z];
                if (z != all_names.size() - 1) name += ", ";
            }
            name += ")";
            return name;
        }

    }
}

string Print(const string& name1, const string& name2) {
    return name1 + " " + name2;
}
class Person {
public:
    Person(const string& first_name, const string& last_name, const int& year) {
        yeaar = year;
        ChangeFirstName(year, first_name);
        ChangeLastName(year, last_name);
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year >= yeaar) {
            changed_first[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= yeaar) {
            changed_last[year] = last_name;
        }
    }
    string GetFullName(const int& year) const {
        if (year >= yeaar) {
            string name1 = FindNameByYear(changed_first, year);
            string name2 = FindNameByYear(changed_last, year);
            return Print(name1, name2);
        }
        else return "No person";
    }
    string GetFullNameWithHistory(const int& year) const{
        if (year >= yeaar) {
            string name1 = FindAllNameByYear(changed_first, year);
            string name2 = FindAllNameByYear(changed_last, year);
           return Print(name1, name2);
        }
        else return "No person";
    }
private:
    int yeaar;
    map<int, string> changed_first;
    map<int, string> changed_last;
};


int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}