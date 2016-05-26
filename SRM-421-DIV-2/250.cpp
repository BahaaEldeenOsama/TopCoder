#include <bits/stdc++.h>
using namespace std;

class GymTraining {

	public:
	int trainingTime( int needToTrain, int minPlus, int maxPlus, int trainChange, int restChange ) {
		if( maxPlus < minPlus + trainChange) return -1;
		
		int totalTime = 0;
		int currPlus = minPlus;
		
		while( needToTrain ) {
			if( currPlus + trainChange  <= maxPlus){
				--needToTrain;
				currPlus += trainChange;
			} else {
				currPlus = std::max(minPlus, currPlus - restChange);
			}
			++totalTime;
		}
		return totalTime;
	}
};
