#include <iostream>

using namespace std;
int N;
int main(void)
{
    int T;
    cin >> T;

    int teams[200] = {0};
    int ranks[1000];
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int k = 0; k < N; k++)
        {
            int l;
            cin >> l;
            ranks[k] = l;
            teams[l] += 1;
        }
    }

    for (int i = 1; i < 200; i++)
    {
        if (teams[i] == 0)
            break;

        if (teams[i] < 6)
        {
            teams[i] = 1001;
        }
    }

    return 0;
}