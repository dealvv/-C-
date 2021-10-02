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
    if (name1 != "" && name2 != "")  return name1 + " " + name2;
    else if (name1 != "") return name1 + " with unknown last name";
    else if (name2 != "") return name2 + " with unknown first name";
    else return "Incognito";

}
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        changed_first[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        changed_last[year] = last_name;
    }
    string GetFullName(const int& year) {
        string name1 = FindNameByYear(changed_first, year);
        string name2 = FindNameByYear(changed_last, year);
        return Print(name1, name2);
    }
    string GetFullNameWithHistory(const int& year) {
        string name1 = FindAllNameByYear(changed_first, year);
        string name2 = FindAllNameByYear(changed_last, year);
        return Print(name1, name2);
    }
private:
    string name_f, name_l;
    map<int, string> changed_first;
    map<int, string> changed_last;
};


int main() {
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;

    return 0;
}