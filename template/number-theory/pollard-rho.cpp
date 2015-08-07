long long pollard_rho(const long long &number, const long long &seed) {
	long long x = rand() % (number - 1) + 1, y = x;
	for (int head = 1, tail = 2; ; ) {
		x = multiply_mod(x, x, number);
		x = add_mod(x, seed, number);
		if (x == y) {
			return number;
		}
		long long answer = __gcd(std::abs(x - y), number);
		if (answer > 1 && answer < number) {
			return answer;
		}
		if (++head == tail) {
			y = x;
			tail <<= 1;
		}
	}
}

void factorize(const long long &number, std::vector<long long> &divisor) {
	if (n > 1) {
		if (miller_rabin(n)) {
			divisor.push_back(n);
		} else {
			long long factor = n;
			for (; factor >= number; factor = pollard_rho(number, rand() % (number - 1) + 1));
			factorize(number / factor, divisor);
			factorize(factor, divisor);
		}
	}
}