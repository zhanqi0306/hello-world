/*
题目标题: 排它平方数
    小明正看着 203879 这个数字发呆。
    原来，203879 * 203879 = 41566646641
    这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数位上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。
    具有这样特点的6位数还有一个，请你找出它！

    再归纳一下筛选要求：
    1. 6位正整数
    2. 每个数位上的数字不同
    3. 其平方数的每个数位不含原数字的任何组成数位

答案是一个6位的正整数。

请通过浏览器提交答案。
注意：只提交另一6位数，题中已经给出的这个不要提交。
注意：不要书写其它的内容（比如：说明性的文字）。*/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool check(vector<int> num1,vector<int> num2){
  //先检查num1上有没有相同的
  sort(num1.begin(),num1.end());
  sort(num2.begin(),num2.end());
  if (num1[0]==num1[1] || num1[1]==num1[2] || num1[2]==num1[3] || num1[3]==num1[4] || num1[4]==num1[5])
  {
    return false;
  }
  for (int i = 0; i < num1.size(); i++)
  {
    for (int j = 0; j < num2.size(); j++)
    {
      if (num1[i] == num2[j])
      {
        return false;
      } 
    } 
  }
  return true;
}

int main(int argc, char const *argv[])
{
  //遍历所有的六位数字
  for (int i = 500000; i < 999999; i++)
  {
    vector<int> num1;
    vector<int> num2;
    int temp = i;
    long long int sqr = pow(i,2);
    while (temp != 0)
    {
      num1.push_back(temp % 10);
      temp /= 10;
    }
    while (sqr != 0)
    {
      num2.push_back(sqr % 10);
      sqr /= 10;
    }

    if (check(num1,num2))
    {
      cout << i << endl;
    }
  }
  return 0;
}


//639172