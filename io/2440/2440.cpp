#include <iostream>

using namespace std;
int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = N - i; 0 < j; j--)
        {
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}