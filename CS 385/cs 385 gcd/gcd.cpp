/*
 * gcd.cpp
 *
 *  Created on: 2016年1月21日
 *      Author: JamesJz
 */

/*
 * gcd.cpp
 * Jan 28, 2016
 *Zhiyuan(James) Zhang
 *I pledge my honor that I have abided by the Stevens Honor System------James
 *
 */

#include<iostream>
#include<sstream>

using namespace std;

int gcdre(int a, int b) {
	if (b == 0) {
		return a;
	} else if (a == 0) {
		return b;

	} else {
		return gcdre(b, a % b);
	}
}

/*
 * the gcdre is the gcd done using recursive method
 */

int gcdin(int a, int b) {
	int gcd;
	if (b == 0) {
		return a;
	} else if (a == 0) {
		return b;
	} else {
		for (int i = 1; i <= a && i <= b; i++) {
			if (a % i == 0 && b % i == 0) {
				gcd = i;
			}
		}
	}
	return gcd;
}

/*this is gcd done in normal way with a for loop, interative.
 *
 */
/*
 * ./gcd 48 12
 * in this case,
 * ./gcd is argv[0] 48 is argv[1] 12 is argv[2]
 * argc=3
 */

int main(int argc, const char *argv[]) {

	if (!(argc == 3)) {
		cerr << "Usage: ./gcd <integer m> <integer n>" << endl;
		return 1;
	}
	/*
	 * if input is not 3 item, then return error
	 *
	 */
	int a;
	istringstream iss0(argv[1]);
	if (!(iss0 >> a)) {
		cerr << "Error: The first argument is not a valid integer." << endl;
		return 1;
	}
	/*
	 * if the second item, which is the first number
	 * is not greater than 0 then
	 * return error.
	 */
	int b;
	istringstream iss1(argv[2]);
	if (!(iss1 >> b)) {
		cerr << "Error: The second argument is not a valid integer." << endl;
		return 1;
	}
	/*check if the second number is greater than 0, else give a error.
	 *
	 */
	cout << "Iterative: gcd(" << a << ", " << b << ") = " << gcdin(a, b)
			<< endl;
	cout << "Recursive: gcd(" << a << ", " << b << ") = " << gcdin(a, b)
			<< endl;
	return 0;

}
/*
 * control shift f
 * will clean everything for you
 */
