#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> DP(N);
    DP.assign(N, 1);

    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (v[i] > v[j])
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }
    cout << *max_element(DP.begin(), DP.end()) << endl;
    return 0;
}