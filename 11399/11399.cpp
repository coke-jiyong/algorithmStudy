#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> timeTaken;
void input();
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
        int a;
        cin >> a;
        timeTaken.push_back(a);
    }
}

void sol()
{
    sort(timeTaken.begin(), timeTaken.end());
    int answer = 0;
    int currentTime = 0;
    for (int i = 0; i < N; i++)
    {
        currentTime += timeTaken[i];
        answer += currentTime;
    }
    cout << answer << endl;
}