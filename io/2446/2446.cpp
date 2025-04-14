#include <iostream>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    int n = N * 2 - 1;
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < j; k++)
            cout << " ";
        for (int i = 0; i < n - j * 2; i++)
            cout << "*";
        cout << endl;
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - (i + 2); j++) // 2입력 -> 0번 " " 출력 3입력 1번
            cout << " ";
        for (int k = 0; k < 3 + i * 2; k++)
            cout << "*";
        cout << endl;
    }

    return 0;
}