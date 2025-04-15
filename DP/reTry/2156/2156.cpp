#include <iostream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> wine(N);
    vector<int> DP;
    for (int i = 0; i < N; i++)
        cin >> wine[i];

    DP.push_back(wine[0]);
    DP.push_back(wine[0] + wine[1]);
    int tmp = MAX(wine[0] + wine[2], wine[1] + wine[2]);
    DP.push_back(MAX(DP.at(1), tmp));

    for (int i = 3; i < N; i++)
    {
        tmp = MAX(DP.at(i - 3) + wine[i - 1] + wine[i], DP.at(i - 2) + wine[i]);
        DP.push_back(MAX(tmp, DP.at(i - 1)));
    }

    cout << DP.back() << endl;
    return 0;
}