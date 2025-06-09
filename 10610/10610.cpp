#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string N;
vector<int> v;
#define MAX 100000
void input()
{
    cin >> N;
    for (char i : N)
        v.push_back(i - '0');
}

void sol()
{
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    for (auto i : v)
        sum += i;

    if (v[v.size() - 1] != 0 || sum % 3 != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto i : v)
            cout << i;
        cout << endl;
    }
}

int main(void)
{
    input();
    sol();
    return 0;
}