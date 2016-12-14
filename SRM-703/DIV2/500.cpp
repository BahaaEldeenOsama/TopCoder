//BFS approach
//TimeLimit error on large test cases, 
#include <bits/stdc++.h>
#include <numeric>
#define MAXSCORE 1000000
using namespace std;

class GCDGraph{
public:
	string possible(int n, int k, int x, int y){

		string ans ="";
		bool canReach = std::__gcd(x,y) > k;
		
		unordered_set<int> seen;
		set<int> *unseen = new set<int>(), *nextUnseen = new set<int>();
		if( !canReach) for(int i=k+1; i <= n; ++i) unseen->insert(i);
		
		queue<int> q;
		q.push(x);
		while(q.size() > 0){
			int top = q.front(); q.pop(); 
			
			
			if(top == y){
				canReach = true;
				break;
			}
			if(seen.count(top) == 0){
				seen.insert(top);
				
				for(auto it = unseen->begin(); it != unseen->end();++it ){
					
					if( seen.count(*it) == 0 && std::__gcd(*it, top) > k){
						q.push(*it);
					} else {
						nextUnseen->insert(*it);
					}
				}
				unseen->clear();
				swap(unseen, nextUnseen);
				
			}
			
		}		
		if(canReach) ans = "Possible";
		else ans = "Impossible";
		
		return ans;
	}

};
