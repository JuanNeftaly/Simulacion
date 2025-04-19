#include <iostream>
using namespace std;

// def coins utilizables
int coins[4] = {25, 10, 5, 1};

int main() {
	int t_coins = 0;
	int n = 99;

	size_t sizeTotal = sizeof(coins) / sizeof(coins[0]);

	// para cada moneda en la lista de monedas
	for (int i = 0; i < sizeTotal; i++) {
		// ver cuantas veces cabe la moneda en el cambio
		int cantidad = n / coins[i];

		if (cantidad > 0) {
			cout << "moneda de: " << coins[i] << " cantidad "
			     << cantidad << endl;
			// actualizar valor del cambio
			t_coins = t_coins + cantidad;
			n = n - (coins[i] * cantidad);
		}
	}

	cout << "Total monedas " << t_coins << endl;

	return 0;
}