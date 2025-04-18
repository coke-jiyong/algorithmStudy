#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
bool compare(pair<string, vector<int>> a, pair<string, vector<int>> b)
{
    if (a.second[0] == b.second[0])
    {
        if (a.second[1] == b.second[1])
        {
            if (a.second[2] == b.second[2])
            {
                return a.first < b.first;
            }
            return a.second[2] > b.second[2];
        }
        return a.second[1] < b.second[1];
    }
    return a.second[0] > b.second[0];
}
int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<string, vector<int>>> man(N);
    for (int i = 0; i < N; i++)
    {
        cin >> man[i].first;
        for (int j = 0; j < 3; j++)
        {
            int score;
            cin >> score;
            man[i].second.push_back(score);
        }
    }

    sort(man.begin(), man.end(), compare);
    for (auto &m : man)
        cout << m.first << endl;
    return 0;
}