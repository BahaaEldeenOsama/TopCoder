#include <bits/stdc++.h>
using namespace std;

class PenguinTiles {
	public:
		int minMoves( vector<string> tiles ) {
			int n = tiles.size()-1;
			int m = tiles[0].size()-1;
			
			int rDot, cDot;

			for(int i = 0; i <= n; ++i) {
				for(int j = 0; j <=  m; ++j) {
					if( tiles[i][j] == '.'){
						rDot = i;
						cDot = j;
					}
				}
			}
			
			if(rDot == n && cDot == m) return 0;
			else if(rDot == n || cDot == m) return 1;
			else return 2;
		}
};
