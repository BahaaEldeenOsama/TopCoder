#include <bits/stdc++.h>
using namespace std;

class ImageCompression {
public:
	string isPossible(vector<string> img, int k){
		int n = img.size();
		int m = img[0].size();
		
		int dm = m/k, dn = n/k;
		
		for(int s=0; s<dm; ++s){
			for(int t=0; t<dn; ++t){
				for(int i=0; i<k; ++i){
					for(int j=0; j<k; ++j){
						if(img[t*k +i][s*k + j] != img[t*k][s*k]) return "Impossible";
					}
				}
			}
		}
		
		return "Possible";
	}
};
