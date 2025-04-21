#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

bool cmp(int a, int b) { return a < b; }
int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    nth_element(arr.begin(), arr.begin() + (K - 1), arr.end());
    cout << arr[K - 1] << endl;

    return 0;
}