#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K, N;
long largest;
vector<long> lans;
void input()
{
    cin >> K >> N;
    largest = 0;
    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        largest = n > largest ? n : largest;
        lans.push_back(n);
    }
}

long all_count(int n)
{
    long cnt = 0;
    for (auto &i : lans)
        cnt += i / n;
    return cnt;
}

void sol()
{
    long right = largest;
    long left = 1;
    long answer = 0;
    while (right >= left)
    {
        long mid = (right + left) / 2;
        long n = all_count(mid);
        if (n < N)
            right = mid - 1;
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }

    cout << answer << endl;
}

int main(void)
{
    input();
    sol();
    return 0;
}