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
vector<vector<int>> ans{{9999,100,100,100},{100,100,100,100},{100,100,100,9999}};
int res = 0;

//判断当前这个位置是否可以放
bool check(vector<vector<int>> haha,int i,int j,int num){
    if(i==0&&j==1){
        if(abs(haha[0][2]-num)==1 || abs(haha[1][2]-num)==1 || abs(haha[1][1]-num)==1 || abs(haha[1][0]-num)==1)return false;
    }
    if(i==0&&j==2){
        if(abs(haha[0][3]-num)==1 || abs(haha[1][3]-num)==1 || abs(haha[1][2]-num)==1 || abs(haha[1][1]-num)==1 || abs(haha[0][1]-num)==1) return false;
    }
    if(i==0&&j==3){
        if(abs(haha[1][3]-num)==1 || abs(haha[1][2]-num)==1 || abs(haha[0][2]-num)==1)return false;
    }
    if(i==1&&j==0){
        if(abs(haha[0][1]-num)==1 || abs(haha[1][1]-num)==1 || abs(haha[2][0]-num)==1 || abs(haha[2][1]-num)==1)return false;
    }
    if(i==1&&j==1){
        if(abs(haha[0][1]-num)==1 || abs(haha[0][2]-num)==1 || abs(haha[1][0]-num)==1 || abs(haha[1][2]-num)==1 ||
        abs(haha[2][0]-num)==1 || abs(haha[2][1]-num)==1 || abs(haha[2][2]-num)==1)return false;
    }
    if(i==1&&j==2){
        if(abs(haha[0][1]-num)==1 || abs(haha[0][2]-num)==1 || abs(haha[0][3]-num)==1 || abs(haha[1][1]-num)==1 ||
        abs(haha[1][3]-num)==1 || abs(haha[2][1]-num)==1 || abs(haha[2][2]-num)==1)return false;
    }
    if(i==1&&j==3){
        if(abs(haha[0][2]-num)==1 || abs(haha[0][3]-num)==1 || abs(haha[1][2]-num)==1 || abs(haha[2][2]-num)==1)return false;
    }
    if(i==2&&j==0){
        if(abs(haha[1][0]-num)==1 || abs(haha[1][1]-num)==1 || abs(haha[2][1]-num)==1)return false;
    }
    if(i==2&&j==1){
        if(abs(haha[1][0]-num)==1 || abs(haha[1][1]-num)==1 || abs(haha[1][2]-num)==1 || abs(haha[2][0]-num)==1 || abs(haha[2][2]-num)==1)return false;
    }
    if(i==2&&j==2){
        if(abs(haha[1][1]-num)==1 || abs(haha[1][2]-num)==1 || abs(haha[1][3]-num)==1 || abs(haha[2][1]-num)==1)return false;
    }

    return true;
}

void trackbacking(vector<vector<int>> & ans,int num){
    if(num == 10){        
        res++;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (ans[i][j] == 9999) continue;
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


