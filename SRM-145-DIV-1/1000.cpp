Error Stack over flow on large tet cases.
TODO: Find a way to either prune the search space or do it iteratively

#include <vector>
#include <iostream>
#define MAX(a,b) (a)^(((b)^(a))& -((a)<(b)))

using namespace std;

class HillHike{
	public:
	 long long numPaths(int distance, int maxHeight, vector<int> landmarks){
		long long count = 0;
		bool reachedPeek = false;
		numPaths(--distance, 1, maxHeight, 0,reachedPeek, landmarks, count);
		std::cout << count ;
		return count; 
		
	}
	
	void numPaths(int distance, int currHeight, int maxHeight, int visited, bool reachedPeek, vector<int> landmarks, long long &count){
		if(distance == 0 && currHeight == 0 && landmarks.size() == visited && reachedPeek){
			++count;
			return;
		} else if(distance <= 0 || currHeight <= 0 || currHeight > maxHeight)
			return;
	
	
		if(currHeight == maxHeight)
			reachedPeek = true;
		if(visited < landmarks.size() && landmarks[visited] == currHeight){
			numPaths(distance-1, currHeight-1, maxHeight, visited+1, reachedPeek, landmarks, count);
			numPaths(distance-1, currHeight, maxHeight, visited+1, reachedPeek, landmarks, count);
			numPaths(distance-1, currHeight+1, maxHeight, visited+1, reachedPeek, landmarks, count);
		}
		else{
			numPaths(distance-1, currHeight, maxHeight, visited, reachedPeek, landmarks, count);
			numPaths(distance-1, currHeight+1, maxHeight, visited, reachedPeek, landmarks, count);
			numPaths(distance-1, currHeight-1, maxHeight, visited, reachedPeek, landmarks, count);
		}
	}
};
