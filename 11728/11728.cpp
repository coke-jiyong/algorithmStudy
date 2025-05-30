#include <iostream>
#include <set>
using namespace std;
#define MAX 1000000
int A[MAX];
int B[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    int a = 0;
    int b = 0;
    while (a < N && b < M)
        if (A[a] <= B[b])
            cout << A[a++] << ' ';
        else
            cout << B[b++] << ' ';
    while (a < N)
        cout << A[a++] << ' ';
    while (b < M)
        cout << B[b++] << ' ';
    cout << endl;
    return 0;
}