#include <string>
#include <vector>

class CharmingTicketsEasy{
	public:
	int leftSum;
	int rightSum;
	int oddSum;
	int evenSum;
	int num;
		
	int count(int K, std::string good){

		 leftSum  = rightSum = oddSum = evenSum = 0;
		 std::vector<int> arr;
		 for(int i=0; i < good.size(); ++i)
		 	arr.push_back(good[i] - '0');
		 
		 count_utill(0,K, &arr);
		 return num;
	}
	
	void count_utill(int level ,int K, std::vector<int> *good){
		if(level == 2*K){
			if(leftSum == rightSum || oddSum == evenSum)
				++num;
			return;
		} else{
			for(int i =0; i < good->size(); ++i){
				evenSum += good->at(i) * ((1+level)%2 );
				oddSum += good->at(i) * (level % 2);
				leftSum += good->at(i) * (level < K);
				rightSum += good->at(i) * (level >= K);
				
				count_utill(level+1, K, good);
				
				evenSum -= good->at(i) * ((1+level)%2 );
				oddSum -= good->at(i) * (level % 2);
				leftSum -= good->at(i) * (level < K);
				rightSum -= good->at(i) * (level >= K);
			}
		}
	}

};
