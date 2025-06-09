#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> trees;
int largest;
void input()
{
    largest = 0;
    cin >> N >> M;
    while (N--)
    {
        int a;
        cin >> a;
        largest = a > largest ? a : largest;
        trees.push_back(a);
    }
}

long cutting(int saw)
{
    long cuttedTrees = 0;
    for (auto &tree : trees)
        if (tree > saw)
            cuttedTrees += (tree - saw);

    return cuttedTrees;
}

void sol()
{
    int left = 0;
    int right = largest;
    int answer = 0;
    int cnt = 0;
    while (left <= right)
    {
        cnt++;
        int saw = (left + right) / 2;
        long cutted = cutting(saw);

        if (cutted >= M)
        {
            left = saw + 1;
            answer = saw;
        }
        else
        {
            right = saw - 1;
        }
    }
    cout << answer << endl;
    cout << cnt << endl;
}

int main(void)
{
    input();
    sol();
    return 0;
}