#include <vector>
#include <algorithm>

class BridgeCrossing{
	public:
		int minTime(std::vector<int> times){
			int size = times.size();

			std::sort(times.begin(), times.end());
			int time = 0; 
			
			while(size > 3){
				time += 2*times[1] + times[size - 1] + times[0];	
				size -= 2;
			}
			
			if(size == 1)
				time +=  times[0];
			else if(size == 2)
				time += times[1];
			else
				time += times[2] + times[1] + times[0];
			
			return time;	
		}
};
