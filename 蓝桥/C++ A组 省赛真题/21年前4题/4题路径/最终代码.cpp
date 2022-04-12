#include<iostream>
using namespace std;
const long long int INF = 0x7fffffff;
long long int dis[2031][2031];

//求a b的最大公约数(a > b)
int gcd(int a,int b){
    if (a % b == 0)
      return b;
    else{
      return gcd(b,a%b);
    }
}

int main(){
  //把矩阵初始化成INF
  for (int i = 1; i <= 2021; i++)
  {
    for (int j = i;j <= 2021; j++)
    {
      dis[i][j] = dis[j][i] = INF;
    }
  }

  //根据题意再初始化距离矩阵
  for (int i = 1; i <= 2021; i++)
  {
    for (int j = i;j <= 2021; j++)
    {
      if ((j-i) <= 21)
      {
        dis[i][j] = dis[j][i] = (i*j)/gcd(j,i);
      }
    }
  } 
  
  //floyd算法 求所有的最短距离
  for (int n = 1;n <= 2021;n++)
  {
    for (int i = 1; i <= 2021; i++)
    {
      for (int j = 0; j <= 2021; j++)
      {
        if (dis[i][j] > dis[i][n] + dis[n][j])
        {
          dis[i][j] = dis[j][i] = dis[i][n] + dis[n][j];
        }
      }
    }
  }

  cout << dis[1][2021] << endl;

  return 0;
}