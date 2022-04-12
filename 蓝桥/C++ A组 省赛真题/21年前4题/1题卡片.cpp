//卡片
//0-9卡片各2021张，问从1开始拼正整数，最大能拼到多少

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {0,1,1,1,1,1,1,1,1,1};
    for (int i = 10;i<=99;i++)
    {
        int a = i%10; //低位
        int t = i/10;
        int b = t%10; //高位
        arr[a]++;
        arr[b]++;
    }
    for (int i = 100; i <= 999; i++)
    {
        int a = i%10; //低位
        int t = i/10;
        int b = t%10; //高位
        t /= 10;
        int c = t%10; //高位
        arr[a]++;
        arr[b]++;
        arr[c]++;
    }
    for (int i = 1000; i <= 5000; i++)
    {
        int a = i%10; //低位
        int t = i/10;
        int b = t%10; //高位
        t /= 10;
        int c = t%10; //高位
        t /= 10;
        int d = t%10;
        arr[a]++;
        arr[b]++;
        arr[c]++;
        arr[d]++;

        for (int j = 0; j < 10; j++)
        {
            if(arr[j] == 2021){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
/*
易错点
刚开始是这样写得
int t = i/10
t = i/10
正确得应该是这样
int t = i/10
t /= 10
注意变量的范围啊
*/