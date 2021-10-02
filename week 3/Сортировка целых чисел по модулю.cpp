#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto& x : num) cin >> x;
    sort(num.begin(), num.end(), [](int x, int y) {
        return abs(x) < abs(y);
        });
    for (const auto& x : num) cout << x << " ";
}