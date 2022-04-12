#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector <long long int> arr; //用来存放n的所有因数

void num(long long int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i){ //如果两因子相同，则只加1  
                arr.push_back(i);
            }
            else{
                arr.push_back(i);
                arr.push_back(n/i);
            }
        }
    }
}

int main(){
    /*
    int 是4字节 能够放10位数字
    long int 是4字节 能够放10位数字
    long long int 是8字节 能够放18位数字
    */
    long long int n; //n是2021041820210418
    cin>>n;
    num(n);
    //调用num函数之后 n的所有因数都存放在arr数组当中了
    //接下来遍历两次
    int res;
    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = 0; j < arr.size(); j++)
      {
        if (n % (arr[i] * arr[j]) == 0)
        {
          res++;
        }
        
      }
      
    }
    cout << res << endl;
    
    return 0;
}