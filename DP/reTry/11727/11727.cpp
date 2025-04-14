#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<long long> v(N + 1);
    v[1] = 1;
    v[2] = 3;
    for (int i = 3; i <= N; i++)
    {
        v[i] = (v[i - 1] + v[i - 2] * 2) % 10007;
    }
    // for (auto &i : v)
    //     cout << i << ' ';
    // cout << endl;
    cout << v[N] << endl;
    return 0;
}