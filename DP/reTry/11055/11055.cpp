#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int n = 0; n < N; n++)
        cin >> seq[n];
    vector<int> DP(seq);
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (seq[i] > seq[j])
                DP[i] = max(DP[i], DP[j] + seq[i]);

    cout << *max_element(DP.begin(), DP.end()) << endl;
    return 0;
}
