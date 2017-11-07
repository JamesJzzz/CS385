
/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Zhiyuan(James) Zhang
 * Date        : Feb 15 2016
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 * 				 ------James Zhang
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s) {
    // returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
	for (unsigned int i=0; i < s.length(); i++){
		if (!islower(s[i])){
			return false;
		}

	}
	return true;
}

bool all_unique_letters(const string &s) {
    // returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
	unsigned int data = 0;
	for(size_t i= 0; i<s.length(); i++){
		int position = s[i]-97;
		/*
		 * this is setting the position for a special digit, simply use it to subtract the position of a
		 * which is 97 in this case.
		 * now we can do the unique check.
		 */
		if ( ((data>> position)&1) == 1){
			return false;
		}
		else {
			/*
			 * in here, we update the new data
			 */
			data |= 1<< position;
		}
	}
	return true;
}

int main(int argc, char * const argv[]) {
    // reads and parses command line arguments.
    // Calls other functions to produce correct output.
	if (argc != 2) {
			cout << "Usage: ./unique <string>" << endl;
		} else {
			if (is_all_lowercase(string(argv[1]))) {
				if (all_unique_letters(string(argv[1]))) {
					cout << "All letters are unique." << endl;
				} else {
					cout << "Duplicate letters found." << endl;
				}
			} else {
				cout << "Error: String must contain only lowercase letters."
						<< endl;
			}
		}
}



