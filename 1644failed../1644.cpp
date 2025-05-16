#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int start, end, answer, sum;

    vector<bool> Prime(N + 1, true);
    Prime[1] = false;

    for (int i = 2; i * i <= N; i++)
        if (Prime[i])
            for (int j = i + i; j <= N; j += i)
                Prime[j] = false;

    vector<int> primeNumber;
    for (int i = 2; i <= N; i++)
        if (Prime[i])
            primeNumber.push_back(i);
    int len = primeNumber.size();
    start = end = answer = sum = 0;
    while (len >= end)
    {
        if (sum < N)
            sum += primeNumber[end++];
        if (sum >= N)
            sum -= primeNumber[start++];
        if (sum == N)
            answer++;
    }
    cout << answer << endl;
    return 0;
}
