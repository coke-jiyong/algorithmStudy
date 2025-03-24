#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i].first < v[j].first && v[i].second < v[j].second) // v[i] 보다 v [j] 가 덩치가 크다면
            {
                rank++;
            }
        }
        cout << rank << " ";
        rank = 1;
    }
    return 0;
}
