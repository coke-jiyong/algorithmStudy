#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}
int main(void)
{
    int N;
    cin >> N;
    vector<pair<int, string>> man(N);
    for (int i = 0; i < N; i++)
        cin >> man[i].first >> man[i].second;

    stable_sort(man.begin(), man.end(), compare);
    for (auto &m : man)
    {
        cout << m.first << ' ' << m.second << endl;
    }
    return 0;
}