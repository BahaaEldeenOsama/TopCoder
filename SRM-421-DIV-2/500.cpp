#include <bits/stdc++.h>
#define EPS (0.000000001)
using namespace std;

class EquilibriumPoints {
public:
	vector <double> getPoints( vector <int> x, vector <int> m ) {
		vector <double> ans;
		
		for(int i = 1; i < x.size(); ++i) {
			ans.push_back( equPoint(i , x, m) );
		}
		return ans;
	}
	
	double equPoint(int n, vector <int> x, vector <int> m ) {
		double left = x[n-1];
		double right = x[n];
		double mid;
		
		while( right > left + EPS ){
			mid = (right + left)/2 ;
			
			double leftForce = 0.0;
			for(int i = 0; i < n; ++i){
				leftForce += m[i] / ((mid - x[i])*(mid - x[i]));
			}
			
			double rightForce = 0.0;
			for(int i = n; i < x.size(); ++i) {
				rightForce += m[i]/ ((mid - x[i])*(mid - x[i]));
			}
			
			if(leftForce < rightForce ){
				right = mid;
			} else {
				left = mid;
			}
		}
		return mid;
	}

};
