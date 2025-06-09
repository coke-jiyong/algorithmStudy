#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N, M;
map<int, int> cardNum;
vector<int> comp;
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        cardNum[a]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        comp.push_back(a);
    }
}

void sol()
{
    for (auto &i : comp)
        cout << cardNum[i] << ' ';
    cout << endl;
}

int main(void)
{

    input();
    sol();
    return 0;
}