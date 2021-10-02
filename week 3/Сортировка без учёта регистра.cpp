#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> num(n);
    for (auto& x : num) cin >> x;
    sort(num.begin(), num.end(), [](string x, string y) {
        for (int i = 0; i < min(x, y).size(); i++) {
            if (tolower(x[i]) != tolower(y[i])) {
                return tolower(x[i]) < tolower(y[i]);
            }
        }
    });
    for (const auto& x : num) cout << x << " "; 
    
}