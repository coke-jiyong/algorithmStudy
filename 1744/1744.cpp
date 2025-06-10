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
        if (a >= 0)
            pos.push_back(a);
        else
            neg.push_back(a);
    }
}
void debug()
{
    cout << "---pos---" << endl;
    for (auto &i : pos)
        cout << i << ' ';
    cout << "\n---neg---" << endl;
    for (auto &i : neg)
        cout << i << ' ';
    cout << endl;
}
void sol()
{
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    //    debug();
    int answer = 0;
    int len = pos.size();
    if (len % 2 == 1)
    {
        // 뒤에서부터 곱하면서 와야함
    }
    else
    {
        for (int i = 0; i < len; i += 2)
        {
            if (pos[i] == 1 || pos[i] == 0)
                answer += (pos[i] + pos[i + 1]);
            else
                answer += (pos[i] * pos[i + 1]);
        }
    }
}