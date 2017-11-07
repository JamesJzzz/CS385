#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <valarray>
using namespace std;

//Global Variables (Same throughout)
//Global Queue used for BFS
int values[6];
queue<vector< vector<int> > > q;

/*
*    Takes in the vector of states that have been visited.
*    Prints the visited states in the proper format.
*	 Returns void.
*/
void print(vector< vector<int> > visited) {
	vector<int> startState = visited.front();
    cout << "Initial state. (" << startState[0] << ", " << startState[1]
            << ", " << startState[2] << ")" << endl;
    for (vector< vector<int> >::iterator it = ++visited.begin(); it != visited.end();
            ++it) {

        cout << "Pour " << (*it)[3] << " gallon" << ((*it)[3] > 1 ? "s" : "")
                << " from " << (char) (*it)[4] << " to " << (char) (*it)[5]
                << ". (" << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2]
                << ")" << endl;
    }
}

/*
*    Takes in the vector of states that have been visited.
*    Prints the final result and exits the program.
*	 Returns void.
*/
void printLast(vector< vector<int> > visited) {
	print(visited);
    exit(0);
}

/*
*	  Takes in the vector of visited states and the state to compare to.
*	  Compares the "compareState" to the states within the vector of visited states.
*	  Returns true if the states match, and false if they are different.
*/
bool  visitedState(vector< vector<int> > visited, vector<int> compareState) {
    for (vector< vector<int> >::iterator it = visited.begin(); it != visited.end();
            ++it) {
        if (compareState[0] == (*it)[0] && compareState[1] == (*it)[1]
                && compareState[2] == (*it)[2]) {
            return true;
        }
    }
    return false;

}

/*
*	  Takes in a vector of visited states.
*	  Stores the amount of water that was transferred.
*	  Returns the new array with the transfer.
*/
vector< vector<int> > copyvisited(vector< vector<int> > visited) {
    vector< vector<int> > newvisited(visited.begin(), visited.end());
    return newvisited;
}

/*
*	  Takes in no arguments.
*	  Method that contains the logic for pouring water between the jugs
* 	  using the specified order.
*	  Returns void.
*/
void pourWater() {
    if (q.empty()) {
        cout << "No solution." << endl;
        exit(0);
    }
    vector< vector<int> > currentvisited = q.front();

    q.pop();
    vector<int> lastMove = currentvisited.back();

    if (lastMove[0] == values[3] && lastMove[1] == values[4] && lastMove[2] == values[5]) {
        printLast(currentvisited);
    }

    for(int i = 0; i<3; i++){
    	char ichar = 'A' + i;
    	for(int j=(i+1)%3; j != i && j<3; j++){
    		char jchar = 'A' + j;
    		if (lastMove[j] != 0 && values[i] > lastMove[i]){
    			int transferAmnt = min(lastMove[j], values[i] - lastMove[i]);
    			int newi = lastMove[i] + transferAmnt;
    			int newj = lastMove[j] - transferAmnt;
    			vector<int> newState;
    			//i < j < 3-(i+j)
    			if (i<j && j< (3-(i+j))){
    				newState.push_back(newi);
    				newState.push_back(newj);
    				newState.push_back(lastMove[3-(i+j)]);
    			}
    			//j < 3-(i+j) < i
    			if (j< (3-(i+j)) && 3-(j+i) < i){
    			    newState.push_back(newj);
    			    newState.push_back(lastMove[3-(i+j)]);
    			    newState.push_back(newi);
    			}
    			//3-(i+j) < i < j
    			if (3-(i+j)<i && i<j){
    				newState.push_back(lastMove[3-(i+j)]);
    				newState.push_back(newi);
    				newState.push_back(newj);
    			}
    			newState.push_back(transferAmnt);
    			newState.push_back(jchar);
    			newState.push_back(ichar);
    			if (!visitedState(currentvisited, newState)) {
    				vector< vector<int> > newvisited = copyvisited(currentvisited);
    			    newvisited.push_back(newState);
    			    q.push(newvisited);
    			}
    		}
    	}
    }
    pourWater();
}

/*
*	  Main for running Program
*	  Checks for potential Errors, calls pourWater()
*	  Prints error statements.
*/
int main(int argc, char * const argv[]) {
	// Check for error.
	//Case 1: No input arguments || Case 2: Too many input arguments
	if(argc != 7){
        cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
        return 1;
    }
	//Case 3: Invalid Capacity
	// for (int i = 0; i<6; i++){
 //      istringstream iss(argv[i+1]);
 //      char jug = 'A' + (i)%3;
 //      if (!(iss >> values[i])){
 //    	  if (i <3){
 //    		  cerr << "Error: Invalid capacity " << "'" << argv[i+1] << "'" <<  " for jug " << jug << "." << endl;
 //    	  } else {
 //    		  cerr << "Error: Invalid goal " << "'" << argv[i+1] << "'" << " for jug " << jug << "." << endl;
 //          }
 //    	  return 1;
 //      }
 //      if (values[i] < 1 && i < 3){
 //    	  cerr << "Error: Invalid capacity " << "'" << argv[i+1] << "'" <<  " for jug " << jug << "." << endl;
	//       return 1;
	//   }
 //      if (values[i] < 0 && i >= 3){
 //    	  cerr << "Error: Invalid goal " << "'" << argv[i+1] << "'" << " for jug " << jug << "." << endl;
 //    	  return 1;
 //      }
	// }
 //    //case 5: Invalid user input
 //    if (values[2] != values[3] + values[4] + values[5]){

 //    	cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
 //    	return 1;
 //    }
    istringstream iss;

    int cap[3];
    for(int i = 1; i < 4; ++i){
        iss.str(argv[i]);
        if( !(iss >> cap[i - 1]) || cap[i-1] < 1){
            cerr << "Error: Invalid capacity '" << argv[i] << "' for jug ";
            if(i == 1){
                cerr << "A." << endl;
            }
            else if(i == 2){
                cerr << "B." << endl;
            }
            else if(i == 3){
                cerr << "C." << endl;
            }
            return 1;
        }
        iss.clear();
    }

    int goal[3];
    for(int i = 4; i < 7; ++i){
        iss.str(argv[i]);
        if( !(iss >> goal[i - 4]) || goal[i-4] < 0){
            cerr << "Error: Invalid goal '" << argv[i] << "' for jug ";
            if(i == 4){
                cerr << "A." << endl;
            }
            else if(i == 5){
                cerr << "B." << endl;
            }
            else if(i == 6){
                cerr << "C." << endl;
            }
            return 1;
        }
        iss.clear();
    }

    for(int i = 0; i < 3; ++i){
        if( (goal[i]) > cap[i]){
            cerr << "Error: Goal cannot exceed capacity of jug ";
            if(i == 0){
                cerr << "A." << endl;
            }
            else if(i == 1){
                cerr << "B." << endl;
            }
            else if(i == 2){
                cerr << "C." << endl;
            }
            return 1;
        }
    }
    if(goal[0] + goal[1] + goal[2] != cap[2]){
        cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
        return 1;
    }

    	vector<int> startState;
        vector< vector<int> > initial;
        startState.push_back(0);
        startState.push_back(0);
        startState.push_back(values[2]);
        initial.push_back(startState);
        q.push(initial);  //Add initial to the queue
        pourWater();

}
