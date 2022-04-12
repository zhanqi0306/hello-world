//第二题 直线问题
#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct point
{
    int x;//横坐标
    int y;//纵坐标
};


int main(int argc, char const *argv[])
{
    vector<point> p;//把点放到一个简单的结构体当中 然后把所有的点（结构体表示）都放到vector数组当中
    for (int i = 0; i <= 19; i++)
        for (int j = 0;j<=20;j++)
            p.push_back({i,j});
    int len = p.size();
    set<pair<double,double>> lines;//利用set集合
    for (int i = 0; i < len; i++)//以下两个循环 遍历所有的点两次
    {
        for (int j = 0; j<len;j++)
        {
            if (p[i].x != p[j].x && p[i].y != p[j].y)//只统计所有斜直线的情况
            {
                double k = (p[j].y-p[i].y)*1.0 / (p[j].x - p[i].x);//算两点构成直线的斜率
                double b = (p[j].y * (p[j].x - p[i].x) - (p[j].y - p[i].y)*p[j].x)*1.0 / (p[j].x - p[i].x);//算截距
                lines.insert(pair<double,double>(k,b));//然后把斜率截距两个值合成一个值加入到set中即可
            }
        }
    }
    //最终set中每一个元素 都代表一个特殊的直线 
    cout << lines.size() + 20 + 21 << endl;
    
    return 0;
}