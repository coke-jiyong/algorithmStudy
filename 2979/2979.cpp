#include <iostream>

// 1대 1분 대당 A원
// 2대 1분 대당 B원
// 3대 1분 대당 C원
using namespace std;
int res[101];
int main(void)
{
    int A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;

    for (int i = 0; i < 3; i++)
    {
        int in, out;
        cin >> in >> out;

        for (int i = in; i < out; i++)
        {
            res[i]++;
        }
    }
    int sum = 0;
    for (int i = 0; i < 105; i++)
    {
        if (res[i] == 1)
        {
            sum += A;
        }
        else if (res[i] == 2)
        {
            sum += (res[i] * B);
        }
        else if (res[i] == 3)
        {
            sum += (res[i] * C);
        }
    }

    cout << sum << endl;
    return 0;
}