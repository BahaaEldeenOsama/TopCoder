#include <bits/stdc++.h>
using namespace std;

class Permutiple {
public:

	vector<int> getdist(int x){
		vector<int> v;
		while(x){
			int y = x % 10;
			x = x/10;
			v.push_back(y);
		}
		sort(v.begin(), v.end());
		return v;
	}
	string isPossible(int x){
		vector<int> v0 = getdist(x);
		for(int i = 2; i< 9; ++i){
			vector<int> vi = getdist(i*x);
			if(vi == v0)  return "Possible";
		}
		
		return "Impossible";
	}
};
