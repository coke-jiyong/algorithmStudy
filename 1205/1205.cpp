#include <iostream>
#include <map>
using namespace std;
int main(void)
{

    int N;
    int score;
    int P;
    cin >> N >> score >> P;
    if (N == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    int arr[100] = {0};
    for (int i = 0; i < N; i++)
        cin >> arr[i]; //  내림차순으로 정렬되어서 입력됨.

    int rank = 1;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > score)
        {
            rank++;
        }
        else if (arr[i] == score)
        {
            rank = rank;
        }
        else
        {
            break;
        }
        cnt++;
    }

    if (cnt == P)
    {
        rank = -1;
    }

    cout << rank << endl;
    return 0;
}