#include <bits/stdc++.h>
using namespace std;

// Función para calcular Longest Increasing Subsequence (LIS)
vector<int> lis_from_left(const vector<int>& arr) {
	int n = arr.size();
	vector<int> dp(n, 1);
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
	return dp;
}

// Función para calcular LIS desde la derecha (es decir, aplicado a la inversa)
vector<int> lis_from_right(const vector<int>& arr) {
	int n = arr.size();
	vector<int> dp(n, 1);
	for (int i = n - 2; i >= 0; --i)
		for (int j = n - 1; j > i; --j)
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
	return dp;
}

int main() {
	int n;
	cin >> n;
	vector<int> pesos(n);
	for (int i = 0; i < n; ++i) {
		cin >> pesos[i];
	}

	// Obtenemos LIS desde la izquierda y derecha
	vector<int> left = lis_from_left(pesos);
	vector<int> right = lis_from_right(pesos);

	int max_len = 0;

	// Combinamos ambas
	for (int i = 0; i < n; ++i) {
		// Restamos 1 porque el elemento en la posición i se cuenta dos
		// veces
		max_len = max(max_len, left[i] + right[i] - 1);
	}

	cout << max_len << endl;
	return 0;
}
