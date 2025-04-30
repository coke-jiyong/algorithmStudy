#include <iostream>
#include <vector>
using namespace std;

int is_prime(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int main()
{
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (n == 1)
            continue;
        if (n == 2 || n == 3)
            answer++;
        else
            answer += is_prime(n);
    }

    cout << answer << endl;
    return 0;
}