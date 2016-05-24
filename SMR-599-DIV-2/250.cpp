// 0/1 knapsack
// O(w*n) space
// O(w*n) mem

#include <bits/stdc++.h>
#define MAX_WEIGHT (5000)
using namespace std;

class MiniatureDachshund {
	public:
	int maxMikan( vector<int> mikan, int weight ) {
		int n = mikan.size();
		int w = max(MAX_WEIGHT - weight, 0);
		vector< vector<int> > DP (n+1, vector<int>( w+1 ));
		
	
		for(int i = 0; i < n; ++i) {
			for(int j = 1; j <= w; ++j) {
				int temp = j-mikan[i]>= 0?  1+DP[i][ j - mikan[i] ]  : 0;
				DP[i+1][j] = max( DP[i][j], temp );
			}
		}
		return DP[n][w];
	}
};
