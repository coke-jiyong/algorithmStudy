#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // 2진수 -> 10진수 -> 8진수 주어지는 2진수가  1,000,000 자리까지이므로 long long 으로도 불가
    // string N;
    // cin >> N;
    // int idx = 0;
    // long long sum = 0;
    // for (int i = N.length() - 1; i >= 0; i--)
    // {
    //     int a = N[i] - '0';
    //     sum += (a * pow(2, idx++));
    // }
    // string answe r;
    // while (sum != 0)
    // {
    //     int a = sum % 8;
    //     answer += (a + '0');
    //     sum /= 8;
    // }

    // for (int i = answer.length() - 1; i >= 0; i--)
    //     cout << answer[i];
    // cout << endl;

    string N;
    cin >> N;

    for (int i = 0; i < N.length() % 3; i++)
        N = '0' + N;

    for (int i = 0; i < N.length(); i += 3)
    {
        int sum = 0;
        sum += (N[i] - '0') * 4;
        sum += (N[i + 1] - '0') * 2;
        sum += (N[i + 2] - '0') * 1;
        cout << sum;
    }
    cout << endl;
    return 0;
}