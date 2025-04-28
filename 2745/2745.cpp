#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string N;
    int B;
    cin >> N >> B;

    long long sum = 1;
    int idx = 0;
    for (int i = N.length() - 1; i >= 0; i--)
    {
        int a;
        if (N[i] >= '0' && N[i] <= '9')
            a = N[i] - '0';
        else
            a = N[i] - 'A' + 10;

        sum += (pow(B, idx++) * a);
    }
    cout << sum - 1 << endl;
    return 0;
}