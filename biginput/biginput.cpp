/*
 * biginput.cpp
 *      Author: JamesJz
 */

#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, t, a = 0;
	cin >> n;
	cin >> k;

	while (n--) {
		cin >> t;
		if (t % k == 0) {
			a += 1;
		}
	}
	cout << a;
}

