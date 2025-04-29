#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> M >> N;
    vector<bool> is_prime(N + 1, true);
    is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
    }
    for (int i = M; i <= N; i++)
        if (is_prime[i])
            cout << i << endl;
    return 0;
}