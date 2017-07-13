#include <bits/stdc++.h>
using namespace std;

class RelativeHeights {
public:
	int countWays(vector <int> &h) {
		vector<int> v;
		for(int i=0; i+1 < h.size(); ++i){
			v.push_back(i);
		}
		
		unordered_set<string> s;
		for(int i=0; i < h.size(); ++i){
			sort(v.begin(), v.end(), [&](const int a, const int b){
				int x = a < i? h[a] : h[a+1];
				int y = b < i? h[b] : h[b+1];
				return y > x;
			});
			
			string str ="";
			for(int c : v) str += to_string(c);
			
			s.insert(str);
		}
		
		return s.size();
	}

};
