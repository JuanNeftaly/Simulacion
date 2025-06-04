#include <bits/stdc++.h>
using namespace std;

// Función para calcular el número mínimo de letras a agregar
int minLettersToAdd(string s) {
	int n = s.size();
	vector<int> dp;

	for (char c : s) {
		int idx = lower_bound(dp.begin(), dp.end(), c) - dp.begin();
		if (idx == dp.size()) {
			dp.push_back(c);
		} else {
			dp[idx] = c;
		}
	}

	// Queremos una secuencia ordenada del alfabeto, por eso restamos a 26
	return 26 - dp.size();
}

int main() {
	string s;
	cin >> s;
	cout << minLettersToAdd(s) << endl;
	return 0;
}
