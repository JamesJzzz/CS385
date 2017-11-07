/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Zhiyuan(James) Zhang
 * Date        : Feb 8 2016
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 * 				 ------James Zhang
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * define a class of primessieve.
 */
class PrimesSieve {
public:
	PrimesSieve(int limit) :
			is_prime_(new bool[limit + 1]), limit_(limit) {
		sieve();
	}

	~PrimesSieve() {
		delete[] is_prime_;
	}

	inline int num_primes() const {
		return num_primes_;
	}

	void display_primes() const {
		/*
		 * display the format that it supposed to be in which is
		 * display the same width and then same amount of primes
		 * per line.
		 */

		/*
		 * first of all, display the words of "Number of primes found: "
		 * and "Primes up to blah blah blah:"
		 */

		cout<<endl<<"Number of primes found: "<<num_primes_<<endl;
		    cout<<"Primes up to "<<limit_<<":"<<endl;

		const int max_prime_width = num_digits(max_prime_);
		const int primes_per_row = 80 / (max_prime_width + 1);
		/*
		 * set the width of rach roll and
		 * helper function of how many prime prints per row.
		 */

				/*
				 * if there is only one line of prime.
				 * then do the following
				 */
				if (num_primes_<=primes_per_row){
					for (int n=0; n<=limit_; n++){
						if (is_prime_[n]){
							if(n!=max_prime_){
								cout<<n<<" ";
							}
							else
								cout<<n<<endl;
						}
					}
				}

				/*
				 * if there is more than one line of prime.
				 * then do the following, it will cover up all the cases
				 */

				else{
					for (int p=0, counter=1; p<=limit_;p++){
						if (is_prime_[p]==true){
							if(counter!= primes_per_row){
								if (p!=max_prime_){
									cout<<setw(max_prime_width)<<p<<" ";
									counter=counter+1;
								}
								else{
									cout<<setw(max_prime_width)<<p;
								counter ++;
								}
							}else{
									cout<<setw(max_prime_width)<<p<<endl;
									counter=1;
								}
							}
						}
					}
				}

private:
	bool * const is_prime_;
	const int limit_;
	int num_primes_, max_prime_;

	int count_num_primes() const {
		/*
		 * this function counts the number of prime that is found within the limit.
		 */
		int a = 0;
		for (int i = 2; i <= limit_; i++) {
			if (is_prime_[i])
				a++;
		}
		return a;
	}

	int num_digits(int num) const {
		/*
		 * to determine how many digit is in num.
		 */
		int digits = 0;
		while (num != 0) {
			num = num / 10;
			digits++;
		}
		return digits;
	}

	void sieve() {
		/*
		 * this is the implementation of sieve algorithm.
		 * Let is_prime be an array of boolean values, indexed by integers 2 to n, initially all set to true.
		 for i=2,3,4,...,while i≤ √n : if is_prime_[i] is true:

		 for j=i^2,i^2 +i,i^2 +2i,...,while j≤n: is_prime_[j] = false
		 Now all i such that is_prime[i] is true are prime.
		 */
		for (int i=2;i<=limit_;i++){
			is_prime_[i] = true;
		}
		for(int i =2; i<sqrt(limit_);i++){
			if (is_prime_[i])
			{
				for ( int j= pow(i,2.0); j<=limit_; j=j+i){
					is_prime_[j] = false;
				}
			}
		}
		num_primes_=count_num_primes();

		/*
		 * find the biggest prime and break out from the loop.
		 */
		for(int k=limit_; k>=2; k--){
			if (is_prime_[k]){
				max_prime_=k;
				break;
			}
		}
	}
};

int main(void) {
	cout << "**************************** " << "Sieve of Eratosthenes"
			<< " ****************************" << endl;
	cout << "Search for primes up to: ";
	string limit_str;
	cin >> limit_str;
	int limit;

	// Use stringstream for conversion. Don't forget to #include <sstream>
	istringstream iss(limit_str);

	// Check for error.
	if (!(iss >> limit)) {
		cerr << "Error: Input is not an integer." << endl;
		return 1;
	}
	if (limit < 2) {
		cerr << "Error: Input must be an integer >= 2." << endl;
		return 1;
	}

	/*
	 * call the class so we can print out all the primes from the list.
	 */

	PrimesSieve s(limit);
	s.display_primes();
	return 0;
}
