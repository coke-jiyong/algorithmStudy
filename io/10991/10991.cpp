#include <iostream>
using namespace std;
int main(void)
{
    int N;
    cin >> N;

    //"* "
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N - i; j++) // j = 1 ; j <= 3 - 1
            cout << " ";
        for (int j = 0; j < i + 1; j++)
            cout << "* ";
        cout << endl;
    }
    return 0;
}