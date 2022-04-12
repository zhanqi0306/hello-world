/*
奇妙的数字

小明发现了一个奇妙的数字。它的平方和立方正好把0~9的10个数字每个用且只用了一次。
你能猜出这个数字是多少吗？

请填写该数字，不要填写任何多余的内容。
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

//解题思路
//挨个取两位数的平方和立方 把它们各个位上的数字 放到一个vector数组当中 然后和正确的vector数组相比较
int main(){
	vector<int> a{0,1,2,3,4,5,6,7,8,9};
	for (int i = 10; i < 99; i++)
	{
		vector<int> arr;
		int temp = pow(i,2);
		while (temp!=0)
		{
			arr.push_back(temp%10);
			temp /= 10;
		}
		temp = pow(i,3);
		while (temp!=0)
		{
			arr.push_back(temp%10);
			temp /= 10;
		}
		sort(arr.begin(),arr.end());
		if(arr.size()==10 && arr == a){
			cout << i << " .. " << pow(i,2) << " .. " << pow(i,3);
		}
	}

	
	return 0;
}
