#include <set>
#include <string>
#include <vector>

using namespace std;

class ImageDithering{
	public:
		int count(string dithered, vector<string> screen){
			int patternCount = 0;
			std::set<int> letters;
			for(int i = 0; i < dithered.size(); ++i)
				letters.insert(dithered.at(i));
			
			for(int i = 0; i < screen.size(); ++i){
				string s = screen[i];
				for(int j = 0; j < s.size(); ++j){
					if(letters.find(s.at(j)) != letters.end())
						++patternCount;
				}
			}
			return patternCount;
		}
};
