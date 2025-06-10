#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<long, long>> meetingTime;

void input();
bool comp(pair<long, long> a, pair<long, long> b);
void sol();

int main(void)
{
    input();
    sol();
    return 0;
}

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long start, end;
        cin >> start >> end;
        meetingTime.push_back({start, end});
    }
}

bool comp(pair<long, long> a, pair<long, long> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void sol()
{
    sort(meetingTime.begin(), meetingTime.end(), comp);
    int answer = 0;
    long current = 0;
    for (auto &i : meetingTime)
    {
        if (current <= i.first)
        {
            current = i.second;
            answer++;
        }
    }
    cout << answer << endl;
}