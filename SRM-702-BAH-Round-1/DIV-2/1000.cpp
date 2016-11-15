//Timelimit Error on large test cases

#include <bits/stdc++.h>
#define MAXSCORE 1000000
using namespace std;

class SubsetSumExtreme {
public:
	double getExpectation(vector<int> block, vector<int> face){
		
		sort(block.begin(), block.end());
		reverse(block.begin(), block.end());
		sort(face.begin(), face.end());
		int tSum =0;
		for(int& x: block) tSum += x;
		
		return getExp(block, face, tSum);
	}
	
	double getExp(vector<int> block, vector<int> face, int& tSum){
		if( block.size() == 0) return 0.0;
		
		double u = 1.0 / face.size();
		double expScore = 0;
		
		
		for(int k = 0; k < face.size(); ++k){
			double minScore = tSum;
			
			for(int i=1; i < (1<<block.size()); ++i){
				double sum = 0;
				unordered_set<int> idxs;
				int j = i;
				while( j ){
					int id = log2(j - ( j & (j-1)));
					j = (j & (j-1));
					sum += block[id];
					idxs.insert(id);
				}
			
				if(sum == face[k]){
					vector<int> left;
					for(int t=0; t< block.size(); ++t){
						if( idxs.count(t) == 0) left.push_back(block[t]);
					}
					minScore = min(minScore, getExpectation(left, face));
				}
			}
			
			expScore += u * minScore;
			
		}
		
		return expScore;
	}
};
