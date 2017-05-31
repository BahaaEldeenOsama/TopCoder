#include <bits/stdc++.h>
using namespace std;

class MaximumRangeDiv2{
public:
	int findMax(string &s){
		unordered_map<char,int> mp;
		for(const auto& ch : s) ++mp[ch];
		
		return std::max(mp['-'], mp['+']);
	}
};
