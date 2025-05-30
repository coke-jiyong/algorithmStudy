#include <iostream>
using namespace std;
void how_many_zero(int n)
{
    int a = 0;
    int b = 0;

    for (int i = 2; i <= n; i *= 2)
        a += n / i;
    for (int i = 5; i <= n; i *= 5)
        b += n / i;
    cout << "2: " << a << "개\n"
         << "5: " << b << "개\n";
}

int main(void)
{
    // int n, m;
    // cin >> n >> m;

    how_many_zero(10);
    return 0;
}
