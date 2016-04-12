#include <vector>
#include <map>
#include <cmath>
#include <algorithm>    // std::max

class Similars{
	public:
	int maxsim(int L, int R){
		int max = 0;
		for(int i = L; i < R; ++i){
			for(int j = i+1; j <= R; ++j)
				max = std::max( max, maxsimUtill(i,j) );
		}
		return max;
	}


	int maxsimUtill(int L, int R){
		std::vector<bool> map(10);
		int temp;
		
		while(R > 0){
			temp = R%10;
			R = R/10;
			map[temp] = true;
		}

		int count = 0;
		while(L > 0){
			temp = L%10;
			L = L/10;
			count += map[temp];
			map[temp] = false;
		}
		return count;
	}

};
