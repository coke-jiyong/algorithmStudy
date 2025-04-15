#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
long long get_double_num(int idx, int N)
{
    int result = N;
    for (int i = 0; i < idx - 1; i++)
    {
        result = result * 10 + N;
    }
    return result;
}

int solution(int N, int number)
{

    vector<unordered_set<int>> DP(9);

    if (N == number)
        return 1;

    DP[1].insert(N); // 1개의 N으로 표현할 수 있는 수는 N 하나
    DP[2].insert(N * N);
    DP[2].insert(N / N);
    DP[2].insert(N - N);
    DP[2].insert(N + N); // 2개의 N으로 표현할수 있는 수는 사칙연산 + NN
    DP[2].insert(get_double_num(2, N));

    auto result = DP[2].find(number);
    if (result != DP[2].end())
        return 2;

    for (int i = 3; i <= 8; i++)
    {
        DP[i].insert(get_double_num(i, N));
        for (int j = 1; j < i; j++)
        {
            int k = i - j;
            // DP[i].insert(DP[j]의 모든값과 DP[k]의 모든값 사칙연산)
            for (auto &jNum : DP[j])
            {
                for (auto &kNum : DP[k])
                {
                    DP[i].insert(jNum + kNum); // +

                    DP[i].insert(jNum * kNum); // *

                    if (jNum - kNum >= 0)
                        DP[i].insert(jNum - kNum); // -

                    if (kNum != 0)
                        DP[i].insert(jNum / kNum); // /
                }
            }
        }
        result = DP[i].find(number);
        if (result != DP[i].end())
            return i;
    }
    return -1;
}

int main(void)
{

    cout << solution(5, 18900) << endl;
    return 0;
}
