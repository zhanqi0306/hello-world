/*
方格填数

如下的10个格子
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+

（如果显示有问题，也可以参看【图7-1.jpg】）

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）

一共有多少种可能的填数方案？

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/

#include<iostream>
using namespace std;
#include<vector>
vector<vector<int>> ans{{999,999,999,999,999,999},{999,999,100,100,100,999},
                        {999,100,100,100,100,999},{999,100,100,100,999,999},
                        {999,999,999,999,999,999}};
int res = 0;

//判断当前这个位置是否可以放
bool check(vector<vector<int>> haha,int i,int j,int num){
    for (int m=i-1;m<=i+1;m++)
    {
        for (int n=j-1;n<=j+1;n++)
        {
            if (abs(haha[m][n] - num) == 1)
                return false;
        }
    }
    return true;
}

void trackbacking(vector<vector<int>> & ans,int num){
    if(num == 10){        
        res++;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (ans[i][j] == 999) continue;
            if (ans[i][j]==100 && check(ans,i,j,num))//如果这个二维数组当中有位子可以放 并且满足条件 就把当前这个数字放进去
            {
                ans[i][j] = num;
                trackbacking(ans,num+1);
                ans[i][j] = 100; //回溯
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    trackbacking(ans,0);//现在是往ans这个二维矩阵当中放0
    cout << res << endl;
    return 0;
}


/*
把3行4列矩阵外面加上一圈
然后检查每一个元素 周围一圈的元素是否有连续的 
如果有返回false 如果没有说明当前位置合适
*/