/*
 标题: 颠倒的价牌
 小李的店里专卖其它店中下架的样品电视机，可称为：样品电视专卖店。
 其标价都是4位数字（即千元不等）。
 小李为了标价清晰、方便，使用了预制的类似数码管的标价签，只要用颜色笔涂数字就可以了（参见p1.jpg）。
 这种价牌有个特点，对一些数字，倒过来看也是合理的数字。如：1 2 5 6 8 9 0 都可以。这样一来，如果牌子挂倒了，有可能完全变成了另一个价格，
 比如：1958 倒着挂就是：8561，差了几千元啊!!
 当然，多数情况不能倒读，比如，1110 就不能倒过来，因为0不能作为开始数字。
 有一天，悲剧终于发生了。某个店员不小心把店里的某两个价格牌给挂倒了。并且这两个价格牌的电视机都卖出去了!
 庆幸的是价格出入不大，其中一个价牌赔了2百多，另一个价牌却赚了8百多，综合起来，反而多赚了558元。
 请根据这些信息计算：赔钱的那个价牌正确的价格应该是多少？
 答案是一个4位的整数，请通过浏览器直接提交该数字。
 注意：不要提交解答过程，或其它辅助说明类的内容。
*/

/*
答案是9088.. （数了一下）
这个主要是把一个整数 然后按照那个规则翻转一下
有额外的条件需要处理处理
*/

#include<iostream>
using namespace std;
const int arr[10] = {1,2,99999,99999,5,9,99999,8,6,0};

//把一个价牌反转
int change(int i){
    int res = 0;
    int temp = 0;
    int flag = 1000;
    while (i!=0)
    {
        temp = i%10;        
        int changed_value = arr[temp-1];
        if (temp == 0)
            changed_value = 0;
        if (changed_value == 99999)
            return -1;
        i = i/10;
        res += changed_value * flag;
        flag /= 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    for (int i = 1000; i < 10000; i++)
    {
        if (i%10 == 0 || change(i)==-1)
            continue;
        //陪了两百多的
        if (i-change(i)>200 && i-change(i)<300)
            cout << i << " - " << change(i) <<" = " << i-change(i) <<endl;

        //赚了800多的
        if (change(i)-i>800 && change(i)-i<900)
            cout << i << " - " << change(i) <<" = " << i-change(i) <<endl;
    }
    return 0;
}


