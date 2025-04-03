#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> a, const pair<string, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    else
    {
        if (a.first.length() != b.first.length())
        {
            return a.first.length() > b.first.length();
        }
        else
        {
            return a.first < b.first;
        }
    }
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    map<string, int> strMap;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (str.length() >= M)
        {
            strMap[str]++;
        }
    }
    vector<pair<string, int>> v(strMap.begin(), strMap.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << "\n";
    }
    return 0;
}