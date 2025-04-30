#include <iostream>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    int answer = 0;
    for (int i = 5; i <= N; i += 5)
        answer++;
    cout << answer << endl;
    return 0;
}