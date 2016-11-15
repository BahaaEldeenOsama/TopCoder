#include <bits/stdc++.h>
using namespace std;

class TestTaking {
public:
  int findMax(int q, int g, int a){
    return min(a,g) + min(q-a, q-g);
  }

};
