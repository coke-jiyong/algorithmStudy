#include <iostream>
#include <vector>
using namespace std;
int GCD(int a, int b)
{
    if (a >= b)
    {
        if (a % b == 0)
            return b;
        else
            return GCD(b, a % b);
    }
    else
    {
        if (b % a == 0)
            return a;
        else
            return GCD(a, b % a);
    }
}
int main(void)
{

    int T;
    cin >> T;
    while (T)
    {
        T--;
        int n;
        cin >> n;
        long long sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                sum += GCD(v[i], v[j]);
        }
        cout << sum << endl;
    }
    return 0;
}