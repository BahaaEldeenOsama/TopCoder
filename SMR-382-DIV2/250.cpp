#include <vector>

class ContiguousSubsequences{
	public:
	std::vector<int> findMaxAverage(std::vector<int> a, int K){
		std::vector<int> b;
		b.push_back(0);
		
		for(int i = 0; i < a.size(); ++i){
			b.push_back( b[i] + a[i] );
		}
		
		std::vector<int> idx {0, (int)a.size()};
		
		for(int i = 0; i + K < b.size(); ++i){
			for(int j = i + K; j < b.size(); ++j){
				if( (b[j] - b[i])/(j-i) > (b[idx[1]] - b[idx[0]])/( idx[1] - idx[0])){
					idx[0] = i;
					idx[1] = j;
				}
			}
		}
		
		idx[0] += 1;
		return idx;
	}

}
