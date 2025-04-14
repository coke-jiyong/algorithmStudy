#include <iostream>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < N - 1; j++)
                cout << " ";
            cout << "*" << endl;
        }
        else if (i == N - 1)
        {
            for (int i = 0; i < N * 2 - 1; i++)
                cout << "*";
            cout << '\n';
        } else {
            
        }
    }
    return 0;
}