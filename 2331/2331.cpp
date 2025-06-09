#include <iostream>
#include <vector>
using namespace std;
#define MAX 236197
int arr[MAX];
int A;
int P;
vector<int> answer;
void input()
{
    cin >> A >> P;
}
int cal(string str)
{
    int result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int n = str[i] - '0';
        int mul = 1;
        for (int j = 0; j < P; j++)
            mul *= n;
        result += mul;
    }
    return result;
}
void sol()
{
    int find = 0;
    answer.push_back(A);
    arr[A]++;
    while (1)
    {
        int n = cal(to_string(A));
        if (arr[n] == 0)
        {
            arr[n]++;
            answer.push_back(n);
        }
        else
        {
            find = n;
            break;
        }
        A = n;
    }
    int cnt = 0;
    for (auto &i : answer)
    {
        if (i != find)
            cnt++;
        else
            break;
    }
    cout << cnt << endl;
}
int main(void)
{
    input();
    sol();
    return 0;
}