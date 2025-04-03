#include <iostream>

using namespace std;
int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
            cout << "*";
        for (int k = 0; k < (N * 2) - i - 1; k++)
            cout << " ";
        for (int j = 0; j < i + 1; j++)
            cout << "*";

        cout << endl;
    }

    // for (int i = N - 1; 0 < i; i--)
    // {
    //     for (int j = 0; j < i; j++)
    //         cout << "*";
    //     for (int k =  2*N - i*2)   8 - 6 2 1 0+
    //         cout << " ";
    //     for (int j = 0; j < i; j++)
    //         cout << "*";
    // }

    return 0;
}
