/*
 * gcd.cpp

 *
 *  Created on: 2016年1月21日
 *      Author: JamesJz
 */

#include<iostream>

using namespace std;

int main(){

	int x;
	int y;
	cout<<"First Number: "<<endl;
	cin>>x;
	cout<<"Second Number: "<<endl;
	cin>>y;

int gcd;

	for(int i=1;i<=x&&i<=y;i++){
		if (x%i==0 && y%i==0) {
			gcd=i;
		}
	}

cout<<gcd<<endl;
return 0;

}


