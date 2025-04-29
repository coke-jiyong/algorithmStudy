#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // 어떻게 이 문제에 대한 해결법을 찾았을까 . . .
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    string answer;
    while (N != 0)
    {
        int a = N % -2;
        N /= -2;
        if (a < 0)
        {
            N += 1;
            a = 1;
        }
        answer = to_string(a) + answer;
    }
    cout << answer << endl;
    return 0;
}