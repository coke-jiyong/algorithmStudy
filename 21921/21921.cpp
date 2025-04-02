#include <iostream>
#include <vector>
using namespace std;
int main(void)
{

    int N, X;
    cin >> N >> X;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int sum = 0;
    for (int i = 0; i < X; i++)
        sum += v[i];

    int cnt = 1;
    int max = sum;
    for (int i = 0; i < v.size() - X; i++)
    {
        sum -= v[i];
        sum += v[X + i];
        if (sum > max)
        {
            max = sum;
        }
        else if (sum == max)
        {
            cnt++;
        }
    }

    if (max == 0)
    {
        cout << "SAD" << endl;
    }
    else
    {
        cout << max << endl
             << cnt << endl;
    }
    return 0;
}