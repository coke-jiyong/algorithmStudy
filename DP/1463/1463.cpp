#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000000];
int main() {
  // Write C++ code here
  int N;
  cin >> N;

//DP 0 은 0이다.
  DP[1] = 0;
  for(int i = 2 ; i <= N ; i ++) {
    DP[i] = DP[i-1] + 1;
    if (i % 3 == 0)
      DP[i] = min(DP[i], DP[i/3] + 1);
    if (i % 2 == 0)
      DP[i] = min(DP[i], DP[i/2] + 1);
  }

  cout << DP[N] << endl;
  return 0;
}
