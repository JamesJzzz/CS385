
/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Zhiyuan(James) Zhang
 * Date        : Feb 22 2016
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 * 				 ------James Zhang
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.

	vector< vector<int> > ways;
    for (int k = 1; k <= 3 && num_stairs >= k; k ++) {
        // the first step move k stair(s)
        vector< vector<int> > newinput = get_ways(num_stairs - k);
        vector< vector<int> >::iterator it = newinput.begin();

        /*
         * I could not figure out how to use the push back method.
         * always having trouble with more than 3 stair input.
         * so i change it into the insertion method.
         */
        while (it != newinput.end()) {
            it->insert(it->begin(), k);
            it ++;
        }
        ways.insert(ways.end(), newinput.begin(), newinput.end());
    }
    if (num_stairs == 0) {
        ways.push_back(vector<int>());
    }
	return ways;

}

void display_ways(const vector< vector<int> > &ways, int num_stairs) {
    // Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.



	 if (num_stairs == 1) {
			       cout << ways.size() << " way to climb " << num_stairs << " stair." << endl;
			    } else {
			       cout << ways.size() << " ways to climb " << num_stairs << " stairs." << endl;
			    }
	    //calculate the width of the number to make sure that
	 	//the numbers are in-line when the numbers get bigger.
	    unsigned int width = 1, largest = 10;
	    while (ways.size() >= largest) {
	    width ++;
	    largest *= 10;
	    }

	    // print each way in every single separate line
	    vector< vector<int> >::const_iterator it = ways.begin();
	    int i = 1;
	    while (it != ways.end()) {
	        cout << setw(width) << i << ". [";
	        vector<int>::const_iterator itt = it->begin();
	        int k = 0;
	        while (itt != it->end()) {
	            if (k > 0) {
	                cout << ", ";
	            }
	            cout << *itt;
	            k ++;
	            itt ++;
	        }
	        cout << "]" << endl;
	        it ++;
	        i ++;
	    }
}


int main(int argc, char * const argv[]) {

	/*
	 * if the arguement is not enough to make the program run
	 */
	if (argc!=2){
		cerr<<"Usage: ./stairclimber <number of stairs>"<<endl;
		return -1;
	}

	/*
	 * to check that if the input is a string that can be transfered to numbers,
	 */
	int num_stairs;
	istringstream iss(argv[1]);
	if (!(iss >> num_stairs)) {
		cerr<<"Error: Number of stairs must be a positive integer."<<endl;
		return -1;
	}

	/*
	 * see the number we convered from the strings, whether that is greater than 0 or not.
	 */
	else if (num_stairs <=0 ){
		cerr<<"Error: Number of stairs must be a positive integer."<<endl;
		return -1;
	}

	/*
	 * returns everthing that we need for the results.
	 */
	vector< vector<int> > ways = get_ways(num_stairs);
	display_ways(ways, num_stairs);
}


