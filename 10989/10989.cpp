#include <iostream>
using namespace std;
#define endl '\n'
#define MAX 10001
int arr[MAX];
int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        arr[n]++;
    }
    for (int i = 0; i < MAX; i++)
        if (arr[i] != 0)
            for (int j = 0; j < arr[i]; j++)
                cout << i << '\n';

    return 0;
}