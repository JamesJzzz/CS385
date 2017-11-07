
/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Zhiyuan(James) Zhang
 * Version     : 1.0
 * Date        : March 30 2016
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 * 				 ------James Zhang
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

// Function prototype.
static long mergesort(int array[], int scratch[], int low, int high);

/**
 * Counts the number of inversions in an array in theta(n^2) time.
 */
long count_inversions_slow(int array[], int length) {
	long result = 0;
	    for(int i = 0; i < length - 1; i++)
	        for(int j = i + 1; j < length; j++)
	            if(array[i] > array[j])
	                ++result;

	    return result;
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
	int* helper_array = new int[length];
	    long result = mergesort(array, helper_array, 0, length-1);
	    delete[] helper_array;
	    return result;
}

static long mergesort(int array[], int scratch[], int low, int high) {
	    if(low == high) {
	        return 0;
	    }
	    const int middle = static_cast<unsigned int>(low + (high - low) / 2);
	    long c1 = mergesort(array, scratch, low, middle);
	    long c2 = mergesort(array, scratch, middle + 1, high);
	    long c3 = 0;
	    /*
	     * we copy everything to the helper array we created.
	     */
		for(int i = low; i <= high; i++) {
			scratch[i] = array[i];
		}
		int left = low;
		int right = middle+1;
		int index = low;
		while(left <= middle && right <= high) {
			if(scratch[left] <= scratch[right]) {
				array[index++] = scratch[left++];
			}
			else {
				c3 += middle - left + 1;
				array[index++] = scratch[right++];
			}
		}
	    while (left <= middle)
	        array[index++] = scratch[left++];
	    while (right <= high)
	        array[index++] = scratch[right++];
	    return c1+c2+c3;

}

int main(int argc, char *argv[]) {
	if(argc > 2) {
		        cerr << "Usage: ./inversioncounter [slow]" << endl;
		        return 1;
		    }
	bool slow = false;
	    if(argc == 2){
	        if(strncmp(argv[1], "slow", 4) == 0) {
	            slow = true;
	        }
	        else {
	            cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl;
	            return 1;
	        }
	    }


    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }
    if(index == 0) {
            cerr << "Error: Sequence of integers not received." << endl;
        }
        else {
            long result = 0;
            if(slow){
                result = count_inversions_slow(&values[0], index);
            }
            else{
                result = count_inversions_fast(&values[0], index);
            }

            cout << "Number of inversions: " << result << endl;
        }

    return 0;
}



