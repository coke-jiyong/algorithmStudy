#include <iostream>

using namespace std;
int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        if (i >= N - i - 1)
            cout << "*";
        else
            cout << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "*";
    }
    cout << endl;
    return 0;
}
