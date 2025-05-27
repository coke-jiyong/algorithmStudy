#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> nums;
/*
    N은 홀수
    1. N개의 수들의 합을 N으로 나눈값
    2. N개의 수들을 증가하는 순서로 나열했을경우 그 중앙에 위치하는 값
    3. N개의 수들 중 가장 많이 나타나는 값
    4. N개의 수들 중 최댓값과 최솟값의 차이
    첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다.
    단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

    첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

    둘째 줄에는 중앙값을 출력한다.

    셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

    넷째 줄에는 범위를 출력한다.
*/
int N;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }
}
void median()
{
    vector<int> v(nums);
    sort(v.begin(), v.end());
    cout << v[N / 2] << endl;
}
void avg()
{
    int n = 0;
    for (auto &i : nums)
        n += i;
    float answer = static_cast<float>(n) / N;
    int result = round(answer);
    if (result < 1 && result > -1)
        cout << 0 << endl;
    else
        cout << result << endl;
}

int main(void)
{
    input();
    median();
    return 0;
}