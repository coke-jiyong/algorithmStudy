#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
void input();
void sol();
vector<int> pos, neg;
int main(void)
{
    input();
    sol();
    return 0;
}

void input()
{
    cin >> N;
    int a;
    while (N--)
    {
        cin >> a;
        if (a > 0)
            pos.push_back(a);
        else
            neg.push_back(a);
    }
}

void sol()
{
    sort(pos.begin(), pos.end(), [](int a, int b)
         { return a > b; });
    sort(neg.begin(), neg.end());
    int answer = 0;
    int size = pos.size();
    if (size % 2 == 0)
    {
        for (int i = 0; i < size; i += 2)
        {
            if (pos[i + 1] <= 1)
                answer += (pos[i] + pos[i + 1]);
            else
                answer += (pos[i] * pos[i + 1]);
        }
    }
    else
    {
        int i = 0;
        for (; i < size - 1; i += 2)
        {
            if (pos[i + 1] <= 1)
                answer += (pos[i] + pos[i + 1]);
            else
                answer += (pos[i] * pos[i + 1]);
        }
        answer += pos[i];
    }

    size = neg.size();
    if (size % 2 == 0)
    {
        for (int i = 0; i < size; i += 2)
            answer += (neg[i] * neg[i + 1]);
    }
    else
    {
        int i = 0;
        for (; i < size - 1; i += 2)
            answer += (neg[i] * neg[i + 1]);
        answer += neg[i];
    }
    cout << answer << endl;
    return;
}