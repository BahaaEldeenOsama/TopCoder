#include <bits/stdc++.h>
using namespace std;

class SellingFruits {
public:	
	int maxDays(int x, int f, int d, int p){
		int days = min(f, d/x);
		f -= days;
		d -= x*days;
		days += d / ((long)x+p);
		
		return days;
	}	
};
