#include <iostream>
#include <algorithm>
using namespace std;

int DP[10];
void solution(int n){
  for(int i = 4; i <= n ; i ++) {
    DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
  }
  cout << DP[n] << endl;
}
int main() {
  // Write C++ code here
  int T;
  cin >> T;
  DP[1]=1;
  DP[2]=2;
  DP[3]=4;

  for(int i = 0 ; i < T; i ++) {
    int n;
    cin >> n ;
    solution(n);
  }
  return 0;
}
