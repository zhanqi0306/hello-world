/*
寒假作业

现在小学的数学题目也不是那么好玩的。
看看这个寒假作业：

   □ + □ = □
   □ - □ = □
   □ × □ = □
   □ ÷ □ = □

   (如果显示不出来，可以参见【图7-1.jpg】)

每个方块代表1~13中的某一个数字，但不能重复。
比如：
 6  + 7 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

以及：
 7  + 6 = 13
 9  - 8 = 1
 3  * 4 = 12
 10 / 2 = 5

就算两种解法。（加法，乘法交换律后算不同的方案）

你一共找到了多少种方案？
请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
*/

#include<iostream>
#include<vector>
using namespace std;
vector<int> arr{1,2,3,4,5,6,7,8,9,10,11,12,13};
int res  = 0;

void backtracking(int start){
    //if语句当中是判断条件成立的逻辑 注意得加上一个取余为0的判断条件 确保arr[9]是arr[10]的倍数才行
    if (start==13 && 
        arr[0]+arr[1]==arr[2] && 
        arr[3]-arr[4]==arr[5] &&
        arr[6]*arr[7]==arr[8] &&
        arr[9]%arr[10]==0 &&
        arr[9]/arr[10]==arr[11])
        res++;
    
    //对一个数组进行操作 实现回溯全排列的逻辑
    for (int i = start; i < 13; i++)
    {
        {int t=arr[i];arr[i]=arr[start];arr[start]=t;}
        //这是全排列期间的剪枝逻辑 加快运行速度 需要注意当中也要进行回溯
        if(start>=2 && arr[0]+arr[1]!=arr[2] || start>=5 && arr[3]-arr[4]!=arr[5]){
            {int t=arr[i];arr[i]=arr[start];arr[start]=t;} 
            continue;
        }
        backtracking(start+1);
        {int t=arr[i];arr[i]=arr[start];arr[start]=t;}
    }
}
int main(int argc, char const *argv[])
{
    backtracking(0);
    cout << res << endl;
    return 0;
}
