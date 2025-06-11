#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<string, int>> v;
void input();
int N, M; // 10000000000
void sol(int);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    return 0;
}

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string title;
        int score;
        cin >> title >> score;
        v.push_back({title, score});
    }

    for (int i = 0; i < M; i++)
    {
        int score;
        cin >> score; // 1000000000
        sol(score);
    }
}

void sol(int score)
{
    int startIdx = 0;
    int endIdx = v.size() - 1;
    int answer = 0;
    while (startIdx <= endIdx)
    {
        int midIdx = (startIdx + endIdx) / 2;
        if (v[midIdx].second < score)
        {
            startIdx = midIdx + 1;
        }
        else if (v[midIdx].second >= score)
        {
            answer = midIdx;
            endIdx = midIdx - 1;
        }
    }
    cout << v[answer].first << '\n';
}