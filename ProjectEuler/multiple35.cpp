

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
	cin>>x;
	int i;
	for(i=0; i<=x ;i++){
		if ((i%5==0) && (i%3==0)){
			return i;
		}
		else{

		if(i%3==0){
			return i;
		}
		if (i%5==0){
			return i;
		}}
		int sum=0;
		sum = sum+i;

	}
	cout<< sum <<endl;
	return 0;

}

