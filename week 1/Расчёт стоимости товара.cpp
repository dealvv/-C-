#include <iostream>
using namespace std;

int main() {
	float N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;
	(N > B) ? cout << N * (1 - Y / 100) : ((N > A) ? cout << N * (1 - X / 100) : cout << N);
}