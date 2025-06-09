#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> card;
vector<int> comp;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        card.push_back(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        comp.push_back(a);
    }
}

bool is_exist_by_binary_search(int target)
{
    int startIdx = 0;
    int endIdx = card.size() - 1;
    while (startIdx <= endIdx)
    {
        int midIdx = (startIdx + endIdx) / 2;

        if (card[midIdx] > target)
            endIdx = midIdx - 1;
        else if (card[midIdx] < target)
            startIdx = midIdx + 1;
        else
            return true;
    }

    return false;
}

void sol()
{
    sort(card.begin(), card.end());
    for (auto &i : comp)
    {
        if (is_exist_by_binary_search(i))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
    cout << endl;
}

int main(void)
{
    input();
    sol();
    return 0;
}