#include <bits/stdc++.h>
#define MAXSCORE 1000000
using namespace std;

class AlternatingString {
public:
	int maxLength(string str){
		if(str.size() <= 1) return str.size();
		int len = 1;
		int i = 0, j = 0; 
		while( i+1 < str.size() ){
			j = i;
			while( i+1 < str.size() && str[i] != str[1+i])++i ;
			
			++i;
			len = max(len, i-j);	
		}
		
		return len;
	}

};
