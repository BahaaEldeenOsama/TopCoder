#include <bits/stdc++.h>
using namespace std;

class GridSort {
public:
  string sort(int n, int m, vector<int> grid){
    bool valid = true;
    
    for(int i=0; i<n && valid; ++i){
      int ll = ((grid[i*m]-1)/m)*m+1;
      int ul = ll + m-1;
      
      for(int j=0; j<m && valid; ++j){
        valid = valid && grid[i*m + j] <= ul && grid[i*m+j] >= ll;
      }
    }
    
    for(int j=0; j<m && valid; ++j){
      int rem = grid[j]%m;
      for(int i=0; i<n && valid; ++i){
        valid = valid && grid[i*m + j]%m == rem;
      }
    }
    
    if(valid) return "Possible";
    return "Impossible";
  }
}
