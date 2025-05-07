#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, X;
    cin >> N >> X;
    vector<int> v(N);
    vector<int> cnt;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    int lastIdx = N - X;
    int max = 0, answer = 0;
    for (int i = 0; i <= lastIdx; i++)
    {
        int last = i + X;
        int sum = 0;
        for (int j = i; j < last; j++)
            sum += v[j];
        cnt.push_back(sum);
        if (max < sum)
            max = sum;
    }
    if (max == 0)
        cout << "SAD" << '\n';
    else
    {
        cout << max << '\n';
        for (auto &i : cnt)
            if (i == max)
                answer++;
        cout << answer << '\n';
    }
    return 0;
}