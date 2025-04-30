#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int A, B, m;
    cin >> A >> B >> m;
    long long base10 = 0;
    int powN = m - 1;
    for (int i = 0; i < m; i++)
    {
        int n; // 여기서 n의 각 숫자는 0이상 A미만임이 보장
        cin >> n;
        base10 += pow(A, powN--) * n;
    }
    vector<int> answer;
    while (base10 != 0)
    {
        answer.push_back(base10 % B);
        base10 /= B;
    }

    reverse(answer.begin(), answer.end());
    for (auto &i : answer)
        cout << i << ' ';
    cout << '\n';
    return 0;
}