#include <bits/stdc++.h>
using namespace std;

class Initials{
public:
	string getInitials(string str){
		str = " "+str;
		string name = "";
		
		for(int i=1; i < str.size(); ++i){
			if(str[i-1] == ' ') name += str[i];
		}
		
		return name;
	}
};
