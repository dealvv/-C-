#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    map<string, set<string>> synonym;
    string command, word, word1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "ADD") {
            cin >> word >> word1;
            synonym[word].insert(word1);
            synonym[word1].insert(word);
        }
        else if (command == "COUNT") {
            cin >> word;
            cout << synonym[word].size() << endl;
        }
        else if (command == "CHECK") {
            cin >> word >> word1;
            if (synonym[word].count(word1)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}