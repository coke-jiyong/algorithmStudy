#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    vector<int> DP(n);
    DP[0] = seq[0];
    DP[1] = max(seq[1], seq[1] + seq[0]);
    for (int i = 2; i < n; i++)
        DP[i] = max(seq[i], seq[i] + DP[i - 1]);
    cout << *max_element(DP.begin(), DP.end()) << endl;
    return 0;
}