int Factorial(int x) {
	if (x > 0) {
		if (x > 1) return x * Factorial(x - 1);
		else return 1;
	}
	else return 1;
}
