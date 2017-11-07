/*******************************************************************************
 * Name        : rpmult.cpp
 * Author      : Zhiyuan(James) Zhang
 * Date        : March 13 2016
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 * 				 ------James Zhang
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

unsigned long russian_peasant_multiplication(unsigned int m, unsigned int n) {
	long result = 0;
	// we are making a long because a int will be out of range

	/*
	 * in our program. we make sure that n is the smaller number.
	 * if not, we switch n and m to make n the smaller number
	 * so that when we do devision, we can do it less steps because n is smaller.
	 */
	if (n < m){
		while (n > 0) {
			if (n & 1) {
				result = result + m;
			}
			m = m << 1;
			n = n >> 1;
		}
		return result;
	}

	// is n is bigger, make n the smaller number.
	else{
		int a;
		a = n;
		n = m;
		m = a;
		while (n > 0) {
			if (n & 1) {
				result = result + m;
			}
			m = m << 1;
			n = n >> 1;
		}
		return result;


	}
		//this funcion give us the result we want.
}

int main(int argc, const char *argv[]) {
	// int main checks the input whether is valid or not.
	int m;
	int n;
	if (!(argc == 3)) {
		cerr << "Usage: ./rpmult <integer m> <integer n>" << endl;
	} else {
		istringstream iss0(argv[1]);
		if (!(iss0 >> m)) {
			cerr
					<< "Error: The first argument is not a valid nonnegative integer."
					<< endl;
			return 1;
		}
		if (m < 0) {
			cerr
					<< "Error: The first argument is not a valid nonnegative integer."
					<< endl;
			return 1;
		}

		istringstream iss1(argv[2]);
		if (!(iss1 >> n)) {
			cerr
					<< "Error: The second argument is not a valid nonnegative integer."
					<< endl;
			return 1;
		}
		if (n < 0) {
			cerr
					<< "Error: The second argument is not a valid nonnegative integer."
					<< endl;
			return 1;
		}
		//if everything is good, then we start to print out the result by calling the function above.
		cout << m << " x " << n << " = " << russian_peasant_multiplication(m, n)
				<< endl;
	}

}

