#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> M >> N;
    vector<bool> Prime(N + 1, true);
    Prime[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (Prime[i])
            for (int j = i + i; j <= N; j += i)
                Prime[j] = false;

    for (int i = M; i <= N; i++)
        if (Prime[i])
            cout << i << endl;
    return 0;
}
