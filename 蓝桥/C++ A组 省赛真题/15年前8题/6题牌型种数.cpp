/*
牌型种数
小明被劫持到X赌城，被迫与其他3人玩牌。
一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
这时，小明脑子里突然冒出一个问题：
如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？
请填写该整数，不要填写任何多余的内容或说明文字。
*/

#include<iostream>
using namespace std;

int ans = 0;

void tracebacking(int zhangshu,int i){ //  //zhangshu代表现在一共有多少张牌
    if (zhangshu>13 || i>13) //如果已经放了超过13张 或者 抽的花色超过K了 直接返回
        return;
    if (zhangshu == 13)//如果已经放进去13张了 就返回回溯
    {
        ans++;
        return;
    }
    for(int j=0;j<=4;j++){//每一种数字 可能抽到的张数
        tracebacking(zhangshu+j,i+1);
    }
}

int main(){
    tracebacking(0,0); //
    cout << ans << endl;
    return 0;
}
/*解题步骤 
唉 这题用结果去占位 如果模拟正常的逻辑思路就错了
一共是A-K 这13张牌
A可能是0个1个2个。。。4个
反正就是特殊类型的回溯方法
*/