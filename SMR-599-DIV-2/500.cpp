#include <bits/stdc++.h>
using namespace std;

class RepeatStringEasy{
	int isSqaure(vector<int> used, string s){

	  bool valid = used.size()%2 == 0;
	  int n = used.size()/2;
	  for(int i=0; valid && i < n; ++i){
	    valid = valid && s[used[i]] == s[used[n+i]];
	  }
	  
	  return valid? used.size(): 0;
	}

	void findCount(vector<int> &used, int pos, string &s, int &length){
		if( pos >= s.size()) {
	    	length = max(length, isSqaure(used, s));
		    return;
		}

	  used.push_back(pos);
	  findCount(used,pos+1, s, length);
	  used.pop_back();
	  findCount(used,pos+1, s, length);
	}
	

public:
	int maximalLength(string s){
		vector<int> used;
		int length = 0;
		
		findCount(used, 0, s, length);
		return length;
	}
};
