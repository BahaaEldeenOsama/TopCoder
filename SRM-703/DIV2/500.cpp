//BFS approach
//TimeLimit error on large test cases, 
#include <bits/stdc++.h>
#include <numeric>
#define MAXSCORE 1000000
using namespace std;

class GCDGraph{
public:
	string possible(long n, long k, long x, long y){
		
		queue<int> q, unseen;
		q.push(x);
		for(int i=n; i > k; --i) unseen.push(i);
		
		while(q.size() > 0){
			long top = q.front(); q.pop(); 
			
			int m = unseen.size();
			for(; m>0; --m){
				long i = unseen.front(); unseen.pop();
				int tmp = std::__gcd(i, top);				
				int tmp2 = std::__gcd(y, i);				
				
				if(tmp > k && tmp2 > k && i * y <= n * tmp2) return "Possible";
				else if( tmp > k ) q.push(i);
				else unseen.push(i);	
			}
		}		
		return "Impossible";
	}
};
