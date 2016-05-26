#include <bits/stdc++.h>
using namespace std;

class FloorIndicator {
public:
	double averageFloor( int N, vector <string> indicator ){
		vector< vector <int> > validDigits;
		vector<int> mult(N, 1);
		
		for(int i = 0; i < N; ++i) {
			validDigits.push_back( couldBe( 4*i, indicator ) );
		}
		
		for(int i = 1; i < N; ++i){
			mult[ i ] = validDigits[i-1].size() * mult[ i - 1 ];
		}

		int prod = 1;
		for(int i = N-2; i >= 0; --i){
			prod *= validDigits[i+1].size();
			mult[ i ] *= prod;
		}
		 
	double sum = 0;
		int pow10 = (int)pow(10, N-1);
		for(int i = 0; i < N; ++i) {
			if( validDigits[ i ].size() == 0) return -1;

			for(int j = 0; j < validDigits[i].size(); ++j){
				sum += mult[ i ] * pow10  * validDigits[i][j];
			
			}
			pow10  /= 10;
		}

		double count = mult[0]* validDigits[0].size();
		return sum /  count;
	}
	
	vector<int> couldBe( int n, vector<string> indicator ) {
		vector <bool> digits(10 ,true);
		
		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 3 ; ++j){
				char c = indicator[i][j + n];
				
				if( c == '#' && j < 2) digits[ 1 ] = false;
				if( c == '#' && j == 1 && i > 0 && i < 4) digits[ 0 ] = false;
				if( c == '#' && ( ( j < 2 && i == 1 ) || ( j > 0 && i == 3 ) )) digits[ 2 ] = false;
				if( c == '#' && j < 2 && (i == 1 || i == 3) ) digits[ 3 ] = false;

				if( c == '#' && (( i > 2 && j < 2) || ( j == 1 && i < 2) ) ) digits[ 4 ] = false;
				if( c == '#' && ( (j > 0 && i == 1) || ( j < 2 && i == 3) ) ) digits[ 5 ] = false;
				if( c == '#' && ( ( j == 1 && i == 4 ) || ( i == 1 && j > 0) ) ) digits[ 6 ]= false;
				if( c == '#' && ( i < 2 && j < 2)) digits[ 7 ] = false;
				if( c == '#' && ( (i == 1 || i == 3 ) && j == 1) ) digits[ 8 ] = false;
				if( c == '#' && ( ( i == 1 && j == 1) || (i == 3 && j < 2 ))) digits[ 9 ] = false;
			}
		
		}
		vector <int> validDig;
		for(int i = 0; i < 10; ++i){
			if(digits[ i ] ) validDig.push_back( i );
		}
		
		return validDig;
	}
};
