#include <iostream>
#include <vector>
using namespace std;
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다.
// 다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다.
// 연속하는 두 정수 사이에는 빈 칸이 하나 있다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

// 각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.
int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    { // test case
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < 2; j++)
    }
    return 0;
}