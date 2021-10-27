#include <iostream>
#include <cmath>

using namespace std;

double SumIter(const int k, const int N);
double SumRecUpP(const int N, const int i);
double SumRecUpM(const int k, const int i);
double SumRecDownP(const int N, const int i, double t);
double SumRecDownM(const int k, const int i, double t);

int main() {
	int k, N;
	cout << "Enter k: "; cin >> k;
	cout << "Enter N: "; cin >> N;
	cout << "(iter)        Result: " << SumIter(k, N)		 << endl;
	cout << "(rec up ++)   Result: " << SumRecUpP(N, k)	 	 << endl;
	cout << "(rec up --)   Result: " << SumRecUpM(k, N)		 << endl;
	cout << "(rec down ++) Result: " << SumRecDownP(N, k, 0) << endl;
	cout << "(rec down --) Result: " << SumRecDownM(k, N, 0) << endl;
	return 0;
}

double SumIter(const int k, const int N) {
	double sum = 0;
	for (int i = k; i <= N; i++)
		sum += (sin(1. * i) * cos(1. * i)) /
				(1 + pow(sin(1. * i), 2));
	return sum;
}

double SumRecUpP(const int N, const int i) {
	if (i > N)
		return 0;
	else
		return (sin(1. * i) * cos(1. * i)) /
		(1 + pow(sin(1. * i), 2)) + SumRecUpP(N, i + 1);
}

double SumRecUpM(const int k, const int i) {
	if (i < k)
		return 0;
	else
		return (sin(1. * i) * cos(1. * i)) /
		(1 + pow(sin(1. * i), 2)) + SumRecUpM(k, i - 1);
}

double SumRecDownP(const int N, const int i, double t) {
	t = t + (sin(1. * i) * cos(1. * i)) /
		(1 + pow(sin(1. * i), 2));
	if (i >= N)
		return t;
	else
		return SumRecDownP(N, i + 1, t);
}

double SumRecDownM(const int k, const int i, double t) {
	t = t + (sin(1. * i) * cos(1. * i)) /
		(1 + pow(sin(1. * i), 2));
	if (i <= k)
		return t;
	else
		return SumRecDownM(k, i - 1, t);
}