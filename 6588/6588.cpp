#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

vector<bool> prime(int n)
{
    vector<bool> v(n + 1, true);
    vector<int> oddPrime;
    v[1] = false;

    for (int i = 2; i * i <= n; i++)
        if (v[i])
            for (int j = i + i; j <= n; j += i)
                v[j] = false;
    return v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    vector<bool> oddPrime = prime(MAX);

    while (true)
    {
        bool found = false;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 3; i < oddPrime.size(); i += 2) // 홀수만 보면됨. 2를제외한 모든 소수는 홀수.
        {
            if (oddPrime[i] && oddPrime[n - i])
            {
                cout << n << " = " << i << " + " << n - i << '\n';
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }

    return 0;
}
