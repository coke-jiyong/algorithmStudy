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

    vector<int> DP(v);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                DP[i] = max({DP[i], v[i] + DP[j]});
            }
        }
    }
    cout << *max_element(DP.begin(), DP.end()) << endl;
    return 0;
}