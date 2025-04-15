#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    vector<int> seq(N);
    vector<int> DP(N);
    for (int n = 0; n < N; n++)
        cin >> seq[n];
    DP[0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            if (seq[i] > seq[j])
                DP[i] = max({DP[i], DP[j]});
        DP[i]++;
    }
    cout << *max_element(DP.begin(), DP.end()) << endl;
    return 0;
}