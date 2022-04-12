/*
手链样式

小明有3颗红珊瑚，4颗白珊瑚，5颗黄玛瑙。
他想用它们串成一圈作为手链，送给女朋友。
现在小明想知道：如果考虑手链可以随意转动或翻转，一共可以有多少不同的组合样式呢？

请你提交该整数。不要填写任何多余的内容或说明性的文字。
*/
//全排列，特殊去重

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string temp;//存放样式的string字符串
vector<string> ans;//存放结果的ans数组

int res = 0;

void tracebacking(vector<int> & arr , int num){ //num代表手链需要多少颗东西
    if(num == 0){
        int i=0;
        for (;i<ans.size(); i++)
        {
            if (ans[i].find(temp)!=string::npos)//如果当前的样式和之前的重复了 直接返回
                return;
        }
        ans.push_back(temp+temp);
        string xx = temp;
        reverse(xx.begin(),xx.end());
        ans.push_back(xx+xx);
        cout << temp << endl;
        res++;
        return;
    }
    for(int i=0;i<arr.size();i++){ //遍历当中的每一个
        if (arr[i] > 0) //如果当前还有剩余的话 就加入到临时的string当中 用string来表示 
        {
            temp += (i + '0');
            --arr[i];
            tracebacking(arr,num-1);
            arr[i]++;
            temp = temp.substr(0,temp.size()-1);
        }
    }
}

int main(int argc, const char *argv[]) {
    vector<int> arr{3,4,5};//下标0代表3颗红珊瑚 下标1代表4课白珊瑚 下标2代表5课黄玛瑙
    tracebacking(arr,12);
    cout << res << endl;
    return 0;
}
