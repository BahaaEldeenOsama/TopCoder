#include <bits/stdc++.h>
using namespace std;

class MinCostPalindrome {
	public:

	int getMinimum(string s, int oCost, int xCost) {
		int cost = 0;
		int minCost = 2*std::min( oCost, xCost );

		int n = s.size()-1;
		int nBy2 = s.size()/2;
		
		for (int i = 0; i < nBy2; ++i) {
			if( s[i] == '?' && s[n-i] == '?') cost += minCost;
			else if( s[i] == s[n-i]) cost += 0;
			else if( s[i] == 'x' && s[n-i] == '?') cost += xCost;
			else if( s[i] == 'o' && s[n-i] == '?') cost += oCost;
			else if( s[i] == '?' && s[n-i] == 'x') cost += xCost;
			else if( s[i] == '?' && s[n-i] == 'o') cost += oCost;
			else return -1;
		}
		
		return cost;
	}
};
