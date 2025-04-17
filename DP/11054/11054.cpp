#include <iostream>
#include <vector>
#define max(a, b) (a) > (b) ? (a) : (b)
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; i++)
        cin >> seq[i];
    vector<int> increaseDP(N, 1);
    vector<int> decreaseDP(N, 1);
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (seq[i] > seq[j])
                increaseDP[i] = max(increaseDP[i], increaseDP[j] + 1);

    for (int i = N - 2; i >= 0; i--)
        for (int j = N - 1; j > i; j--)
            if (seq[i] > seq[j])
                decreaseDP[i] = max(decreaseDP[i], decreaseDP[j] + 1);

    int answer = 0;
    for (int i = 0; i < N; i++)
        if (increaseDP[i] + decreaseDP[i] > answer)
            answer = increaseDP[i] + decreaseDP[i];

    cout << answer - 1 << endl;
    return 0;
}