/*
 * student.cpp
 * Zhiyuan(James) Zhang
 * I pledge my honor that I have abided by the Stevens Honor System.------James.Zhang
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Student {
	/*
	 * set a class for student
	 */
public:
	Student(string first, string last, float gpa, int id) :
			first_(first), last_(last), gpa_(gpa), id_(id) {
	}
	;

	void print_info() const {
		cout << first_ << " " << last_ << ", GPA: " << fixed << setprecision(2)
				<< gpa_ << ", " << "ID: " << id_ << endl;
	}
	/*
	 * a void function that does not return anything.
	 * but we cout the correct information of a student
	 * include first name, last name, gpa, and id.
	 */

	string full_name() const{
		return first_ + " " + last_;
	}
	/*
	 * student full name.
	 */
	int id() const{
		return id_;
	}
	/*
	 * id with a int type
	 */
	float gpa() const{
		return gpa_;
	}
	/*
	 * gpa with a float type
	 */

private:
	string first_;
	string last_;
	float gpa_;
	int id_;
	/*
	 * declear everything in private .
	 */
};

	vector<Student> find_failing_students(const vector<Student> &students) {
		vector<Student> failing_students;
		for (vector<Student>::const_iterator it = students.begin();
				it != students.end(); ++it)
		{
			if (it->gpa() < 1) {
				failing_students.push_back(*it);
				/*
				 * * means to get the actual value elements to the vector.
				 */
			}
		}
		return failing_students;
	}
	/*
	 * this is a void class which find all the failing student
	 * using the vector and iterators.
	 * put them in the vector for the future return in main class
	 */
	void print_students(const vector<Student> &students) {
		for (vector<Student>::const_iterator it = students.begin();
				it != students.end(); ++it) {
			it->print_info();
		}
	}

	/**
	 * Allows the user to enter information for multiple students, then * find those students whose GPA is below 1.0 and prints them to the * screen.
	 */
int main() {
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<Student> students;

	/*
	 * declear everything in int main.
	 */

	do {
		cout << "Enter student's first name: ";
		cin >> first_name;
		cout << "Enter student's last name: ";
		cin >> last_name;
		gpa = -1;
		while (gpa < 0 || gpa > 4) {
			cout << "Enter student's GPA (0.0-4.0): ";
			cin >> gpa;
		}
		cout << "Enter student's ID: ";
		cin >> id;
		students.push_back(Student(first_name, last_name, gpa, id));
		cout << "Add another student to database (Y/N)? ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
	cout << endl << "All students:" << endl;
	print_students(students);
	/*
	 * a big do while loop that does the cin and cout for students information.
	 */
	vector<Student> failing_students;
	failing_students=find_failing_students(students);
	if(failing_students.empty()){
		cout<<endl<<"Failing students:"<<" "<<"None"<<endl;
	}
	else{
		cout << endl << "Failing students:"<<endl;
		print_students(failing_students);
	}

	/*
	 * call the failing student vector again in order to print all the failing student
	 */
		// Print a space and the word 'None' on the same line if no students are // failing.
		// Otherwise, print each failing student on a separate line.
		return 0;
}
