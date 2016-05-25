#include <bits/stdc++.h>
using namespace std;

class ConductorWalk {
	public:
	vector<int> getObserverRecords( vector<int> orderSeat, vector<int> orderTime, int inspectorSeat ) {
		int currTime = 0;
		vector<int> visits;
		
		for(int i = 0; i < orderSeat.size(); ++i){
			if( orderTime[ i ] > currTime ) currTime = orderTime[ i ];
			
			int order = orderSeat[ i ];
			if( inspectorSeat < order ) {
				visits.push_back( currTime + inspectorSeat );
				visits.push_back( currTime + inspectorSeat +2*(order - inspectorSeat)  );
			} else if( inspectorSeat == order) {
				visits.push_back( currTime + inspectorSeat );
			}
			
			currTime += 2*order;
		}
		
		return visits;
	}
};
