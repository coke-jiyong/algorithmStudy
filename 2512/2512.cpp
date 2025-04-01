#include <iostream>
#include <algorithm>
using namespace std;

int N;
int get_index_by_avg(int *arr, int avg)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= avg)
            return i;
    }
}
int main(void)
{
    // 입력된 정수의 합이 M 보다 작으면 상한액 (출력값) 은 입력된 수 중 가장 큰 수
    // 400  90 100 110 120
    // min, max
    // 최저값과 최고값의 중간값부터 시작
    // 중간값을 상한값으로 설정 후 다 더했을때 400이 되지않는다면 중간값을min으로 min~max로 중간값을 구함
    // 이 중간값을 상한선으로 설정 후 다 더했을때 400이 넘는다면
    // N = 지방 수
    // M = 총 예산
    // 10 20 30 30 -> 90
    int M;
    cin >> N;
    int req[N];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> req[i];
        sum += req[i];
    }
    cin >> M;
    sort(req, req + (N - 1));

    if (sum <= M)
    {
        cout << req[N - 1] << endl;
        return 0;
    }

    // cout << "Avg : " << sum / N << endl;
    int avg = sum / N;

    cout << '\n';

    return 0;
}