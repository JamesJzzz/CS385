/*
 * factorial.cpp

 *
 *  Created on: 2017年1月30日
 *      Author: JamesJz
 */
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int intlog(double base, double x) {
    return (int)(log(x) / log(base));
}

int is_p(int a){
	return 5**(intlog(a,5))==a;
}

int main(){
	int n;
	cin >> n;
	int x;
	int answer = 0;
	int h5 = 0;
	for(int i = 0; i< n; i++){
		cin >> x;
	}
	for(int i= 1; i<n; i++){
		answer = factorial(x);
		h5 = x/5;
		return h5;
	}
}




