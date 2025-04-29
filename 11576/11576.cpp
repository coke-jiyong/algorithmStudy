#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A, B, m;
    cin >> A >> B >> m;
    long long base10 = 0;
    int powN = m - 1;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        base10 += pow(A, powN--) * n;
    }
    cout << base10 << endl;
    // string answer;
    // while (base10 != 0)
    // {
    //     answer = to_string(base10 % B) + answer;
    //     base10 /= B;
    // }

    // for (int i = 0; i < answer.length(); i++)
    //     cout << answer[i] << ' ';
    // cout << '\n';
    return 0;
}