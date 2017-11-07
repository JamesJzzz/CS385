

// Zhiyuan(James) Zhang
// CS 385 Knapsack problem
// May 1 2016
// I pledge my honor that I have abided by the Stevens Honor System.
// ------James Zhang

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

// professor's code
struct Item {
    unsigned int item_number, weight, value;
    string description;

    explicit Item(const unsigned int item_number,
            const unsigned int weight,
            const unsigned int value,
            const string &description) :
                            item_number(item_number),
                            weight(weight),
                            value(value),
                            description(description) {
    }

    friend std::ostream& operator<<(std::ostream& os, const Item &item) {
        os << "Item " << item.item_number << ": " << item.description
                << " (" << item.weight
                << (item.weight == 1 ? " pound" : " pounds") << ", $"
                << item.value << ")";
        os.flush();
        return os;
    }
};

// to check if the input is number.
//


bool is_number(const string& s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}

int main(int argc, char *argv[]) {
    // to check the number of input arguements and see
	// if they are valid or not
    if (argc != 3) {
        cerr << "Usage: ./knapsack <capacity> <filename>" << endl;
        return 1;
    }
    if (!is_number(argv[1]) || atoi(argv[1]) < 0) {
        cerr << "Error: Bad value '" << argv[1] << "' for capacity." << endl;
        return 1;

    }

    unsigned int cap = atoi(argv[1]);
    // Create a ifstream, return error if it fails to convert.
    ifstream input_file(argv[2]);
    if (!input_file) {
        cerr << "Error: Cannot open file '" << argv[2] << "'." << endl;
        return 1;
    }

    // this part read the file first. and check each while loop
    // for testcase 6 and 7.
    // check each line
    // for testcase 7. we create a mistakes reader
    // if there is anything else after value
    // it means we got something else that we don't need
    // then we return a error,
    // or else for testcase 6, we return error if there is not enough information that we need.

    vector<Item> items;
    string line;
    int numLine = 0;
    while (getline(input_file, line)) {
        numLine++;
        stringstream ss(line);
        string name, weight, value,mistakes;
        getline(ss, name, ',');
        getline(ss, weight, ',');
        getline(ss, value, ',');
        getline(ss, mistakes);
        unsigned int numWeight;
        unsigned int valueInt;

        // this means we dont have enough information.
        if (weight.empty() || value.empty() || name.empty()) {
            cerr << "Error: Line number " << numLine << " does not contain 3 fields." << endl;
            return 1;
        }
        // this means we have something more than we need.
        if (!mistakes.empty()){
        	cerr << "Error: Line number " << numLine << " does not contain 3 fields." << endl;
        	return 1;
        }

        if (!is_number(weight) || atoi(weight.c_str()) < 0) {
            cerr << "Error: Invalid weight '" << weight << "' on line number "  << numLine << "." << endl;
            return 1;
        }
        if (!is_number(value) || atoi(value.c_str()) < 0) {
            cerr << "Error: Invalid value '" << value << "' on line number " << numLine << "." << endl;
            return 1;
        }
        numWeight = atoi(weight.c_str());
        valueInt = atoi(value.c_str());
        Item itemCharacteristics(numLine, numWeight, valueInt, name);
        items.push_back(itemCharacteristics);

    }

    cout << "Candidate items to place in knapsack:" << endl;
    for (vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
        cout << "   " << *it << endl;
    }
    cout << "Capacity: " << cap << " pound" << (cap > 1? "s":"") << endl;

    // get a 2D vector,  Set all values of Value equal to 0 from the beginning.

    vector<vector<int> > Value(numLine + 1, vector<int>(cap + 1));
    vector<vector<vector<Item> > > itemsArray(numLine + 1, vector<vector<Item> >(cap + 1));
    for (int i = 0; i <= numLine; i++) {
    	Value[i][0] = 0;
    }
    for (unsigned int j = 0; j <= cap; j++) {
    	Value[0][j] = 0;
    }
    // go through use it or lose it, to try to add values to our vector
    for (int i = 1; i <= numLine; i++) {
        for (unsigned int j = 1; j <= cap; j++) {
            int loose_it = Value[i - 1][j];
            int use_it = Value[i - 1][max(int(j - items[i-1].weight), 0)] + items[i-1].value;

            if (j >= items[i-1].weight) {
            	Value[i][j] = max(loose_it, use_it);
                if (loose_it < use_it) {
                    itemsArray[i][j] = itemsArray[i - 1][max(int(j - items[i-1].weight), 0)];
                    itemsArray[i][j].push_back(items[i-1]);
                } else {
                    itemsArray[i][j] = itemsArray[i - 1][j];
                }
            } else {
            	Value[i][j] = Value[i - 1][j];
                itemsArray[i][j] = itemsArray[i - 1][j];
            }
        }
    }

    vector<Item> solution = itemsArray[numLine][cap];
    cout << "Items to place in knapsack:" << endl;
    int totalWeight = 0;
    for (vector<Item>::iterator it = solution.begin(); it != solution.end(); ++it) {
        totalWeight += it->weight;
        cout << "   " << *it << endl;
    }
    cout << "Total weight: " << totalWeight<< " pound" << (totalWeight > 1? "s":"") << endl;
    cout << "Total value : $"<< Value[numLine][cap] << endl;

}




