#include <string>

#define MAX(a,b)  (a)^(((b) ^(a)) & -((a) < (b)));
using namespace std;

#define EPSILON 0.0000001

class ExerciseMachine{
	public:
		int getPercentages(string time){
			int totalSeconds = 0;
			for(int i = 0; i < 3; ++i){
				totalSeconds = totalSeconds*60 + atoi(time.substr(3*i,3*i +1).c_str());
			}

			double onePercent = totalSeconds/100.0;			
			double percent = onePercent;
			int intPercent = (int) percent;

			while(percent - intPercent > EPSILON){
				percent += onePercent;
				intPercent = (int) percent;
			}
			return MAX(totalSeconds/intPercent - 1, 0);
		}

};
