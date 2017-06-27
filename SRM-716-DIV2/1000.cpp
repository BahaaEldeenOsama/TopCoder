#include <bits/stdc++.h>
using namespace std;

class JumpDistancesOnTreeEasy {
public: 

	void calcDist(unordered_map<int, vector<int>> &G,
		unordered_map<int, unordered_map<int, vector<int>>> &D,
		int r, 
		unordered_set<int> &distances){
		
		unordered_set<int> used;
		stack<int> q_dist;
		stack<int> q_next;
		
		q_dist.push(0);
		q_next.push(r);
		used.insert(r);
		
		while(q_dist.size()) {
			int top = q_next.top(); q_next.pop();
			int dist = q_dist.top(); q_dist.pop();
			
			D[r][dist].push_back(top);
			for(int y : G[top]) {
				if(used.count(y) == 0) {
					used.insert(y);
					q_next.push(y);
					q_dist.push(dist + 1);
					distances.insert(dist + 1 );
				}
			}
		} 
	}

	string isPossible(vector<int> &p, vector<int> &S) {
		unordered_map<int, vector<int>> mp;
		
		for(int i=0; i<p.size(); ++i) {
			mp[p[i]].push_back(i+1);
			mp[i+1].push_back(p[i]);
		}

		unordered_set<int> dist;
		dist.insert(0);
		unordered_map<int, unordered_map<int, vector<int>>> D;

		int n = p.size();
		

		for(int i=0; i<n; ++i){
			calcDist(mp, D, i, dist);
		}

		
		unordered_set<int> used;
		unordered_set<int> visited;
		stack<int> stack; stack.push(0);

		while(stack.size()) {
			int y = stack.top(); stack.pop();

			for(int x: S){
				for(int z: D[y][x]) {
					used.insert(x);
					if(visited.count(z) == 0) {
						visited.insert(z);
						stack.push(z);
					}
				}
			}
		}
		if(used.size() == S.size()) return "Possible";
		return "Impossible";
	}

};
