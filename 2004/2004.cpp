#include <iostream>
using namespace std;
int how_many_zero(int n)
{
    int answer = 0;
    for (int i = 5; i <= n; i *= 5)
        answer += n / i;
    return answer;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    int a = how_many_zero(m) + how_many_zero(n - m);
    int b = how_many_zero(n);
    cout << b - a << endl;
    return 0;
}