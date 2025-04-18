#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
#define endl '\n'

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    map<long long, int> map;
    for (int i = 0; i < N; i++)
    {
        long long n;
        cin >> n;
        map[n]++;
    }
    pair<long long, int> answer(0, 0);
    for (auto &i : map)
    {
        if (i.second > answer.second)
            answer = i;
        else if (i.second == answer.second)
        {
            if (i.first < answer.first)
                answer = i;
        }
    }
    cout << answer.first << endl;
    return 0;
}