#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    map<set<string>, int> number;
    int q, c = 1;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        set<string> bus_stop;
        for (int z = 0; z < n; z++) {
            string stop;
            cin >> stop;
            bus_stop.insert(stop);
        }
        if (number.count(bus_stop)) cout << "Already exists for " << number[bus_stop] << endl;
        else {
            cout << "New bus " << c << endl;
            number[bus_stop] = c;
            c++;
        }
      
    }
}