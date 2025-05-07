#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int N, X, firstSum = 0;
    cin >> N >> X;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < X; i++)
        firstSum += v[i];

    int start = 0, end = X, cnt = 1, n = firstSum, max = firstSum;
    while (end != N)
    {
        int a = n - v[start++] + v[end++];
        if (a > max)
        {
            max = a;
            cnt = 1;
        }
        else if (a == max)
            cnt++;
        n = a;
    }
    if (max == 0)
        cout << "SAD" << '\n';
    else
        cout << max << '\n'
             << cnt << '\n';
    return 0;
}