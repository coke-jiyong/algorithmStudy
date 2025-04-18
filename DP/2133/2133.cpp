#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[31];
int main(void)
{
    int N;
    cin >> N;
    if (N % 2 != 0)
        return 0;
    DP[2] = 3;
    for (int i = 4; i <= N; i += 2)
    {
    }
    return 0;
}