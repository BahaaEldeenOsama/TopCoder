#include <bits/stdc++.h>
using namespace std;


class InterleavingParenthesisDiv2 {
	int MOD = 10E8 + 7;
public:
	int countWays(string &s1, string &s2){
		int s=0;
		int n = s1.size(), m = s2.size();
		vector<vector<vector<long long int>>> dp(n+1, vector<vector<long long int>>(m+1, vector<long long int>(n+m+2, -1)));
		return utill(s1, s2, 0, 0, s, dp);
	}
	
	int utill(string &s1, string &s2, int i, int j, int stack, vector<vector<vector<long long int>>> &dp){
		if(i >= s1.size() && j >= s2.size()){
			return stack == 0;
		}

		if(dp[i][j][stack] != -1){
		 	return dp[i][j][stack];
		 }

		int	count = 0;
		if(i < s1.size()) {
			if(s1[i] == '('){
				count += utill(s1, s2, i+1, j, stack+1, dp);	
				count = count % MOD;	
			}

			if(stack > 0 && s1[i] == ')' ){
				count += utill(s1, s2, i+1, j, stack-1, dp);
				count = count % MOD;
			}
		}

		if(j < s2.size()) {
			if(s2[j] == '('){
				count += utill(s1, s2, i, j+1, stack+1, dp);
				count = count % MOD;
			}
			
			

			if(stack > 0 && s2[j] == ')' ){
				count += utill(s1, s2, i, j+1, stack-1, dp);
				count = count % MOD;
			}
		}

		dp[i][j][stack] = count;
		return count;
	}
};
