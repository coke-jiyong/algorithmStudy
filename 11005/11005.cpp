#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, B;
    cin >> N >> B;

    string answer;
    for (; N != 0;)
    {
        int a = N % B;
        if (a >= 0 && a <= 9)
            answer += ('0' + a);
        else
            answer += (a - 10 + 'A');

        N /= B;
    }

    reverse(answer.begin(), answer.end());
    cout << answer << endl;

    return 0;
}