#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> DP(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    DP.assign(N, 1);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }

    sort(DP.begin(), DP.end());
    cout << DP[N - 1] << endl;
    return 0;
}