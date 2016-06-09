#include <string>
#include <cmath>
class TheArithmeticProgression {
public: 
double minimumChange(int a, int b, int c) {

	int rhs = c - b;
	int lhs = b - a;
	
	return std::abs( rhs-lhs )/2.0;
}

};
