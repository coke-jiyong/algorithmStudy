#include <iostream>
#include <map>
using namespace std;
// 1km마다 1리터기름사용
//       2      3      1
//  [5] -- [2] -- [4] --[1]     <= 기름값이 제일 작은곳에서 ~ 끝까지 , 처음부터 방금기름값이 제일 작은곳까지 다시 반복
//[]값은 기름 값, 위에 값은 거리

//    3    3    4
//[1]--[1]--[1]--[1]        <= 기름값이 같다면 , 걸리는 모든 거리를 더한 값이 최소기름값

//    3    3    4
//[2]--[1]--[2]--[3]        <= 기름값이 같다면 , 걸리는 모든 거리를 더한 값이 최소기름값
// 0    1    2    3

// city[0]에선 무조건 기름을 넣어야 한다.
// city[0] < city[1] 면 city[0]에서 city[2]까지 기름넣고 감.
// 즉 cheapCity = 0 으로부터 시작 [0] < [1] 면 cheapCity = 0 [0] > [1] 면 cheapCity = 1
unsigned int N;
int main(void)
{
    // 도시의개수를 나타내는 정수 N 2<=N<=100,000 ,
    // 두 도시를 연결하는 도로의 길이 N-1개 입력
    // 주유소 가격 N개 입력
    // 총 거리는 1 ~ 1,000,000,000 자연수
    // 리터당 가격은 1 ~ 1,000,000,000

    cin >> N;
    // pair<unsigned int, unsigned int> arr[N]; // <다음도시와 연결하는 길이 , 기름가격>
    long citys[N];
    int distances[N - 1];

    for (int i = 0; i < N - 1; i++)
    {
        cin >> distances[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> citys[i];
    }

    long long cheapCity = 0;
    int disIdx = 0;
    unsigned long long totalPrice = citys[cheapCity] * distances[disIdx++];

    for (int i = 1; i < N - 1; i++)
    {
        if (citys[cheapCity] < citys[i])
        {
            totalPrice += citys[cheapCity] * distances[disIdx++];
        }
        else
        {
            totalPrice += citys[i] * distances[disIdx++];
            cheapCity = i;
        }
    }

    cout << totalPrice << endl;
    return 0;
}
