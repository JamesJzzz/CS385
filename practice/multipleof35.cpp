/*
 * multipleof35.cpp

 *
 *  Created on: 2016年5月20日
 *      Author: JamesJz
 */





#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>


using namespace std;

int main(){
	int x;
	int sum=0;
	cout<<"please cin x"<<endl;
	cin>>x;
	int i;
	for(i=0; i<x ;i++){
		if ((i%5==0) || (i%3==0)){

		if(i%3==0){
			cout<< i<<endl;
			sum = sum+i;
		}
		if (i%5==0){

			cout<<i<<endl;
			sum = sum+i;
		}}

	}
	int sumofwrong=0;
	for(i=0; i<x ;i++){
			if ((i%5==0) && (i%3==0)){
				sumofwrong= sumofwrong+i;
			}
	}

	cout<<"the sum is"<<endl;
	cout<< sum-sumofwrong <<endl;
	return 0;

}


