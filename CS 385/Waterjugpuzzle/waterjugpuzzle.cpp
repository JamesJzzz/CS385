///*******************************************************************************
// * Name        : waterjugpuzzle.cpp
// * Author      : Zhiyuan(James) Zhang
// * Date        : March 7 2016
// * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
// * 				 ------James Zhang
// ******************************************************************************/
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <sstream>
//
//using namespace std;
//
//int cap_A, cap_B, cap_C, goal_A, goal_B, goal_C;
//
//class State {
//public:
//	State(int a, int b, int c, const State *prev, char from, char to,
//			int volumn) :
//			a_(a), b_(b), c_(c), previous(prev), from(from), to(to), v(volumn) {
//	}
//	;
//	State(int a, int b, int c) :
//			a_(a), b_(b), c_(c), previous(NULL), from(0), to(0), v(0) {
//	}
//	;
//
//	int get_A() const {
//		return a_;
//	}
//	int get_B() const {
//		return b_;
//	}
//	int get_C() const {
//		return c_;
//	}
//	char get_from() const {
//		return from;
//	}
//	char get_to() const {
//		return to;
//	}
//	int get_volumn() const {
//		return v;
//	}
//	const State *getPrev() const {
//		return previous;
//	}
//
//	/*
//	 * check if we have been somewhere before,
//	 * using that we mark true when we see two of states are equal.
//	 */
//	bool equals(State &another) const {
//		if (a_ == another.get_A() && b_ == another.get_B()
//				&& c_ == another.get_C()) {
//			return true;
//		}
//		return false;
//	}
//
//private:
//	int a_, b_, c_;
//	// the previous state that reaches this state in bfs order
//	// Which means: Pour (v) gallons from (from) to (to).
//	const State *previous;
//	char from, to;
//	int v;
//};
//
///*
// * now we make a function to check if the state is visited before
// */
//
//bool checkforvisit(State *current, vector<State *> &visit) {
//	for (vector<State *>::iterator it = visit.begin(); it != visit.end();
//			it++) {
//		State *state=*it;
//		if (state->equals(*current)) {
//			return true;
//		}
//	}
//	return false;
//}
//
///*
// * now let's check if the current state is the same as the goal
// */
//
//bool checkforgoal(State *goal, State *current) {
//	return goal->equals(*current);
//
//}
//
///*
// * then make a bfs for pour
// */
//
//State *pour(State *current, State*goal) {
//	vector<State *> visit;
//	queue<State *> queue;
//	queue.push(current);
//
//	while (!(queue.empty())) {
//		current = queue.front();
//		queue.pop();
//
//		/*
//		 * to check if the goal appears.
//		 */
//		if (checkforgoal(goal, current)) {
//			return current;
//		}
//
//		/*
//		 * check for visited
//		 */
//		if (checkforvisit(current, visit)) {
//			continue;
//		}
//		visit.push_back(current);
//
//		if (current->get_C() != 0 && current->get_A() < cap_A) {
//			/*
//			 * then let's pour from c to a
//			 */
//			State *temp = new State(
//					min(cap_A, current->get_A() + current->get_C()),
//					current->get_B(),
//					max(0, current->get_A() + current->get_C() - cap_A),
//					current, 'C', 'A',
//					min(cap_A, current->get_A() + current->get_C())
//							- current->get_A());
//			queue.push(temp);
//		}
//
//		if (current->get_B() != 0 && current->get_A() < cap_A) {
//			// pour from B to A
//			State *temp = new State(
//					min(cap_A, current->get_A() + current->get_B()),
//					max(0, current->get_A() + current->get_B() - cap_A),
//					current->get_C(), current, 'B', 'A',
//					min(cap_A, current->get_A() + current->get_B())
//							- current->get_A());
//			queue.push(temp);
//		}
//
//		if (current->get_C() != 0 && current->get_B() < cap_B) {
//			// pour from C to B
//			State *temp = new State(current->get_A(),
//					min(cap_B, current->get_B() + current->get_C()),
//					max(0, current->get_B() + current->get_C() - cap_B),
//					current, 'C', 'B',
//					min(cap_B, current->get_B() + current->get_C())
//							- current->get_B());
//			queue.push(temp);
//		}
//
//		if (current->get_A() != 0 && current->get_B() < cap_B) {
//			// pour from A to B
//			State *temp = new State(
//					max(0, current->get_B() + current->get_A() - cap_B),
//					min(cap_B, current->get_B() + current->get_A()),
//					current->get_C(), current, 'A', 'B',
//					min(cap_B, current->get_B() + current->get_A())
//							- current->get_B());
//			queue.push(temp);
//		}
//
//		if (current->get_B() != 0 && current->get_C() < cap_C) {
//			// pour from B to C
//			State *temp = new State(current->get_A(),
//					max(0, current->get_C() + current->get_B() - cap_C),
//					min(cap_C, current->get_C() + current->get_B()), current,
//					'B', 'C',
//					min(cap_C, current->get_C() + current->get_B())
//							- current->get_C());
//			queue.push(temp);
//		}
//
//		if (current->get_A() != 0 && current->get_C() < cap_C) {
//			// pour from A to C
//			State *temp = new State(
//					max(0, current->get_C() + current->get_A() - cap_C),
//					current->get_B(),
//					min(cap_C, current->get_C() + current->get_A()), current,
//					'A', 'C',
//					min(cap_C, current->get_C() + current->get_A())
//							- current->get_C());
//			queue.push(temp);
//		}
//	}
//
//	return NULL;
//}
//
//void display(const State*state) {
//	if (state->getPrev() != NULL) {
//		display(state->getPrev());
//
//		cout << "Pour" << state->get_volumn();
//		if (state->get_volumn() > 1) {
//			cout << " gallons ";
//
//		} else {
//			cout << " gallon ";
//		}
//		cout << "from " << state->get_from() << " " << "to " << state->get_to()
//				<< ".";
//	} else {
//		cout << "Initial state.";
//	}
//
//	cout << "(" << state->get_A() << ", " << state->get_B() << ", "
//			<< state->get_C() << ")" << endl;
//}
//
//int main(int argc, char * const argv[]) {
//	if (argc != 7)
//		cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> "
//				"<goal B> <goal C>" << endl;
//	else {
//		istringstream iss1(argv[1]);
//		if (!(iss1 >> cap_A)) {
//			cerr << "Error: Invalid capacity '" << argv[1] << "' for jug A."
//					<< endl;
//			return 1;
//		}
//		istringstream iss2(argv[2]);
//		if (!(iss2 >> cap_B)) {
//			cerr << "Error: Invalid capacity '" << argv[2] << "' for jug B."
//					<< endl;
//			return 1;
//		}
//
//		istringstream iss3(argv[3]);
//		if (!(iss3 >> cap_C)) {
//			cerr << "Error: Invalid capacity '" << argv[3] << "' for jug C."
//					<< endl;
//			return 1;
//		}
//
//		istringstream iss4(argv[1]);
//		if (cap_A <= 0) {
//			cerr << "Error: Invalid capacity '" << argv[1] << "' for jug A."
//					<< endl;
//			return 1;
//		}
//		istringstream iss5(argv[2]);
//		if (cap_B <= 0) {
//			cerr << "Error: Invalid capacity '" << argv[2] << "' for jug B."
//					<< endl;
//			return 1;
//		}
//		istringstream iss6(argv[3]);
//		if (cap_C <= 0) {
//			cerr << "Error: Invalid capacity '" << argv[3] << "' for jug C."
//					<< endl;
//			return 1;
//		}
//		istringstream iss7(argv[4]);
//		if (!(iss7 >> cap_C)) {
//			cerr << "Error: Invalid goal '" << argv[4] << "' for jug A."
//					<< endl;
//			return 1;
//		}
//		istringstream iss8(argv[4]);
//		if (cap_A <= 0) {
//			cerr << "Error: Invalid goal '" << argv[4] << "' for jug A."
//					<< endl;
//			return 1;
//		}
//		istringstream iss9(argv[5]);
//		if (!(iss9 >> cap_C)) {
//			cerr << "Error: Invalid goal '" << argv[5] << "' for jug B."
//					<< endl;
//			return 1;
//		}
//		istringstream iss10(argv[5]);
//		if (cap_A <= 0) {
//			cerr << "Error: Invalid goal '" << argv[5] << "' for jug B."
//					<< endl;
//			return 1;
//		}
//		istringstream iss11(argv[6]);
//		if (!(iss11 >> cap_C)) {
//			cerr << "Error: Invalid goal '" << argv[6] << "' for jug C."
//					<< endl;
//			return 1;
//		}
//		istringstream iss12(argv[6]);
//		if (cap_A <= 0) {
//			cerr << "Error: Invalid goal '" << argv[6] << "' for jug C."
//					<< endl;
//			return 1;
//		}
//		if (goal_A > cap_A) {
//			cerr << "Error: Goal cannot exceed capacity of jug A." << endl;
//			return 1;
//		}
//
//		if (goal_B > cap_B) {
//			cerr << "Error: Goal cannot exceed capacity of jug B." << endl;
//			return 1;
//		}
//		if (goal_C > cap_C) {
//			cerr << "Error: Goal cannot exceed capacity of jug C." << endl;
//			return 1;
//		}
//		if ((goal_A + goal_B + goal_C) != cap_C) {
//			cerr << "Error: Total gallons in goal state must be equal to the "
//					"capacity of jug C." << endl;
//			return 1;
//		}
//
//		State initial_state(0, 0, cap_C);
//		State goal(goal_A, goal_B, goal_C);
//
//		State *result = pour(&initial_state, &goal);
//
//		if (result != NULL) {
//			display (result);
//		}
//		else
//		{
//			cout << "No solution."<<endl;
//		}
//		return 0;
//	}
//}

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
