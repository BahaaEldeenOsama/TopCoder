#include <bits/stdc++.h>
using namespace std;
	
	bool myFunction (int i,int j) { 
		if( i%10 !=  j%10) return (i%10 <  j%10);
		else return i < j;
	 }

class Cut {
	public:
	int getMaximum( vector<int> eelLengths, int maxCuts) {
		std::sort(eelLengths.begin(), eelLengths.end(), myFunction);
		
		int numElls = 0;
		
		for(int i = 0; i < eelLengths.size()&& maxCuts; ++i){
			int temp = (eelLengths[ i ] / 10);
			bool extra = 0;

			 if( eelLengths[ i ] % 10 == 0 ){				
				--temp;
				extra = temp <= maxCuts ;
			}
			
			temp = max(0, min(temp, maxCuts));
			numElls += temp + extra;
			maxCuts -= temp;
		}
		return numElls;
	}
};
