#include <iostream>
#include <vector>
/*
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
*/
using namespace std;
int N;
typedef struct node
{
    char left;
    char right;
} NODE;
vector<NODE> v(27);
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char root, l, r;
        cin >> root >> l >> r;
        v[root - 65].left = l;
        v[root - 65].right = r;
    }
}
void pre(char data)
{
    if (data == '.')
        return;
    cout << data;
    pre(v[data - 65].left);
    pre(v[data - 65].right);
}
void in(char data)
{
    if (data == '.')
        return;
    in(v[data - 65].left);
    cout << data;
    in(v[data - 65].right);
}
void post(char data)
{
    if (data == '.')
        return;
    post(v[data - 65].left);
    post(v[data - 65].right);
    cout << data;
}
int main(void)
{
    input();
    pre('A');
    cout << '\n';
    in('A');
    cout << '\n';
    post('A');
    cout << '\n';
    return 0;
}