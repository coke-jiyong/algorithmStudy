#include <iostream>
using namespace std;
typedef long long ll;
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)
ll solution(ll a, ll b)
{
    if (a % b == 0)
        return b;
    return solution(b, a % b);
}
int main(void)
{
    ll A, B;
    cin >> A >> B;
    for (int i = 0; i < solution(MAX(A, B), MIN(A, B)); i++)
        cout << 1;
    cout << endl;
    return 0;
}