/*
 * waterjugpuzzle.cpp
 *
 *  Created on: Oct 3, 2015
 *      Author: Shawn J. Fodor
 *      Class: CS 385 A
 *      Pledge: I pledge my honor that I have abided by the Stevens Honor System
 */

 //Inluding Headers//
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

//Class State - represents different states of the waterjug//
//Holds the amunt of water in each cup, the goal, the capacities//
//of each cup, and the steps taken to get there//
class State{
public:
	//Constructor of State//
	State(vector<string> steps, vector<int> current, vector<int>cap, vector<int> goal):
		steps_(steps), current_(current), cap_(cap), goal_(goal) {}

	//Method canPour - returns true if you can pour from one cup to another, otherwise false//
	bool canPour(int from, int to)
	{
		if(current_[from] == 0 || current_[to] == cap_[to])
		{
			return false;
		}
		return true;
	}

	//Method isGoal - returns true if a state matches the goal, otherwise false//
	bool isGoal()
	{
		for(int i = 0; i < 3; ++i)
		{
			if(current_[i] != goal_[i])
			{
				return false;
			}
		}
		return true;
	}

	//Method pour - returns a new State if you pour water from one cup to another//
	State pour(int from,int to){
		int amount;
		if(cap_[to] - current_[to] > current_[from])
		{
			amount = current_[from];
		}
		else
		{
			amount = cap_[to] - current_[to];
		}
		vector<int> new_state;
		for(int i = 0; i < 3; ++i)
		{
			new_state.push_back(current_[i]);
		}

		new_state[from] -= amount;
		new_state[to] += amount;
		vector<string> new_steps;
		new_steps.insert( new_steps.begin(), steps_.begin(), steps_.end());

		string str;
		stringstream convert;
		convert << amount;
		str = "Pour " + convert.str() + " gallon";
		if(amount > 1)
		{
			str += "s";
		}
		str += " from ";
		convert.str("");

		if(from == 0)
		{
			str += "A to ";
		}
		else if(from == 1)
		{
			str += "B to ";
		}
		else if(from == 2)
		{
			str += "C to ";
		}
		if(to == 0)
		{
			str += "A. (";
		}
		else if(to == 1)
		{
			str += "B. (";
		}
		else if(to == 2)
		{
			str += "C. (";
		}
		convert << new_state[0];
		str += convert.str() + ", ";
		convert.str("");
		convert << new_state[1];
		str += convert.str() + ", ";
		convert.str("");
		convert << new_state[2];
		str += convert.str() + ")";
		convert.str("");
		new_steps.push_back(str);
		State next = State(new_steps, new_state, cap_, goal_);
		return next;
	}

	//Method get_state - returns an integer array of the current water levels of the cups in state//
	vector<int> get_state(){
		return current_;
	}

	//Method printSteps - prints all the steps needed to rech this state//
	void printSteps(){
		for(vector<string>::iterator it = steps_.begin(); it != steps_.end(); ++it){
			cout << *it << endl;
		}
	}

//Initialization of private variables//
private:
	vector<string> steps_; 
    vector<int> current_;
    vector<int> cap_; 
    vector<int> goal_; 
};

//Public Function find_solution - breadth-first search to find the best soluton to water-jug//
bool find_solution(vector<int> cap ,vector<int> goal){
	const int length = cap[0];
	const int height = cap[1];
	bool **visited = new bool*[length+1];
	for(int i = 0; i < length + 1; ++i)
	{
		visited[i] = new bool[height + 1];
	}
	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < height; ++j)
		{
			visited[i][j] = false;
		}
	}
	queue<State> theQ;
	vector<string> first_steps;
	stringstream convert;
	convert << cap[2];
	first_steps.push_back("Initial state. (0, 0, " + convert.str() + ")");
	vector<int> int_state;
	int_state.push_back(0);
	int_state.push_back(0);
	int_state.push_back(cap[2]); 
	State next_state = State(first_steps, int_state, cap, goal); 
	if(next_state.isGoal())
	{
		next_state.printSteps();
		return true;
	}
	State new_state = next_state; 
	theQ.push(next_state);
	while(!theQ.empty())
	{
		next_state = theQ.front();
		theQ.pop();
		for(int to = 0; to < 3; ++to)
		{
			for(int from = 2; from >= 0; --from)
			{
 				if(to != from && next_state.canPour(from, to))
 				{
					new_state = next_state.pour(from, to);
					if(!visited[new_state.get_state()[0]][new_state.get_state()[1]])
					{
						visited[new_state.get_state()[0]][new_state.get_state()[1]] = true;
						if(new_state.isGoal())
						{
							new_state.printSteps();
							return true;
						}
						theQ.push(new_state);
					}
				}
			}
		}
	}
	return false;
}

//Main//
int main(int argc, char * const argv[])
{
	if(argc != 7)
	{
		cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
		return 1;
	}
	istringstream iss;
	int cap[3];
	for(int i = 1; i < 4; ++i)
	{
		iss.str(argv[i]);
		if( !(iss >> cap[i - 1]) || cap[i-1] < 1)
		{
			cerr << "Error: Invalid capacity '" << argv[i] << "' for jug ";
			if(i == 1)
			{
				cerr << "A." << endl;
			}
			else if(i == 2)
			{
				cerr << "B." << endl;
			}
			else if(i == 3)
			{
				cerr << "C." << endl;
			}
			return 1;
		}
		iss.clear();
	}
	int goal[3];
	for(int i = 4; i < 7; ++i)
	{
		iss.str(argv[i]);
		if( !(iss >> goal[i - 4]) || goal[i-4] < 0)
		{
			cerr << "Error: Invalid goal '" << argv[i] << "' for jug ";
			if(i == 4)
			{
				cerr << "A." << endl;
			}
			else if(i == 5)
			{
				cerr << "B." << endl;
			}
			else if(i == 6)
			{
				cerr << "C." << endl;
			}
			return 1;
		}
		iss.clear();
	}
	for(int i = 0; i < 3; ++i)
	{
		if( (goal[i]) > cap[i])
		{
			cerr << "Error: Goal cannot exceed capacity of jug ";
			if(i == 0)
			{
				cerr << "A." << endl;
			}
			else if(i == 1)
			{
				cerr << "B." << endl;
			}
			else if(i == 2)
			{
				cerr << "C." << endl;
			}
			return 1;
		}
	}
	if(goal[0] + goal[1] + goal[2] != cap[2])
	{
		cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
		return 1;
	}

	vector<int> goal_;
	for(int i = 0; i<3; i++)
	{
		goal_.push_back(goal[i]);
	}
	vector<int> cap_;
	for(int i = 0; i<3; i++)
	{
			cap_.push_back(cap[i]);
	}
	if( !find_solution(cap_, goal_))
	{
		cout << "No solution." <<endl;
	}
	return 0;
}
