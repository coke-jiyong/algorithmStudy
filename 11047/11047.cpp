#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> v;
void input()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

void sol()
{
    int answer = 0;
    int len = v.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (v[i] > K)
            continue;
        while (K >= v[i])
        {
            K -= v[i];
            answer++;
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
/*
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
*/