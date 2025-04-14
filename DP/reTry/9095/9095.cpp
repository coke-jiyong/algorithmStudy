#include <iostream>
#include <vector>
using namespace std;
int DP[10];

int main(void)
{

    int T;
    cin >> T;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        for (int j = 4; j <= N; j++)
        {
            DP[j] = (DP[j - 1] + DP[j - 2] + DP[j - 3]) % 10007;
        }
        cout << DP[N] << endl;
    }
    return 0;
}
// 1 -> 1
// 2 -> 2
//  3 -> 4 -> 1+2, 2+1 , 1+1+1 , 3
//  4 -> 1+1+1+1, 2+1+1, 1+2+1, 1+1+2, 2+2 , 1+3,3+1 - > 7
//  5 -> 11111, 2111,1211,1121,1112, 122,212,221, 311,131,113 ,32,23 -> 13
