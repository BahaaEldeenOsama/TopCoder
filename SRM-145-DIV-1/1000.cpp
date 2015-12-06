#include <vector>
#include <iostream>
#define MAX(a,b) (a)^(((b)^(a))& -((a)<(b)))

using namespace std;

class HillHike{
	private:
		vector<int> landmarks;
		long long* numOfPaths;

		int maxDistance;
		int maxHeight;
		int r1;
		int r2;
		int r3;
		
	public:
		void init(int distance, int maxHeight, vector<int> landmarks){
			numOfPaths = (long long *)malloc(sizeof(long long)*(distance+1)*(maxHeight+2 )*(landmarks.size()+1)*2);

			r3 = 2;
			r2 = (landmarks.size())*2;
			r1 = (maxHeight )*(landmarks.size())*2;

			this->maxHeight = maxHeight;
			this->maxDistance = distance;
			this->landmarks = landmarks;

			//Set the number of paths from each point to -1.
			for(int i = 0; i < distance; ++i)
				for(int j = 0; j < maxHeight + 1; ++j)
					for(int k = 0; k < landmarks.size(); ++k){
						numOfPaths[i*r1 + j*r2 + k*r3 + 0] = -1;
						numOfPaths[i*r1 + j*r2 + k*r3 + 1] = -1;
					}

		}
		
	 	long long numPaths(int distance, int maxHeight, vector<int> landmarks){
			init(distance, maxHeight, landmarks);
			long long ans = numPaths(1,1,0,false);
			free(numOfPaths);
			return ans;
		}
	
	long long numPaths(int currDistance, int currHeight,int visited, bool reachedPeek){
		if(currDistance == maxDistance){
			return reachedPeek && currHeight == 0 && visited == landmarks.size();
			
		} else if(currHeight <= 0 || currHeight > maxHeight ||  currHeight > maxDistance - currDistance){
			return 0;
			
		} else if( visited < landmarks.size() && numOfPaths[currDistance*r1 + currHeight*r2 + visited*r3 + reachedPeek] != -1){
			
			return numOfPaths[currDistance*r1 + currHeight*r2 + visited*r3+ reachedPeek];
		}
		
		reachedPeek = reachedPeek || currHeight == maxHeight;
		
		long long currCount = 0;		

		if(visited < landmarks.size() && landmarks[visited] == currHeight)
			++ visited;
		
		currCount += numPaths(currDistance+1, currHeight, visited, reachedPeek);
		currCount += numPaths(currDistance+1, currHeight+1, visited, reachedPeek);
		currCount += numPaths(currDistance+1, currHeight-1, visited, reachedPeek);

		numOfPaths[currDistance*r1 + currHeight*r2 + visited*r3+ reachedPeek] = currCount;

		return currCount;
	}
};
