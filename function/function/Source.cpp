#include <iostream>

#include "function.h"





class Squared {
public:
	int operator() (int x) { return x*x; }
};

int squared(int x) { return x*x; }


using namespace experimental;

int main() {

	
	function<int(int)> f = Squared();
	std::cout << f(10) << std::endl;

	function<int(int)> g = squared;

	std::cout << g(10) << std::endl;
	


	getchar();
	

	return 0;
}