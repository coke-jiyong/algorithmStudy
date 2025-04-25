#include <iostream>
using namespace std;

int main(void)
{
    long long A, B;
    cin >> A >> B;
    if (A == B)
    {
        for (int i = 0; i < A; i++)
            cout << 1;
        cout << endl;
        return 0;
    }

    long long n = A > B ? A % B : B % A;
    for (int i = 0; i < n; i++)
        cout << 1;
    cout << endl;
    return 0;
}