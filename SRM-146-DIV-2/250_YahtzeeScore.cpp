#include <vector>
#include <algorithm>    // std::sort

#define MAX(a,b)  (a)^(((b) ^(a)) & -((a) < (b)));

class YahtzeeScore{
	public:
		int maxPoints(std::vector<int> toss){
			std::sort (toss.begin(), toss.end());
			
			int max = 0;
			for(int i = 0; i < toss.size();){
				int curr = 0;
				
				for(int j = i; i < toss.size() && toss[i] == toss[j]; ++i)
					curr += toss[i];
				
				max = MAX(max, curr);
			}
			return max; 
			
		}

};
