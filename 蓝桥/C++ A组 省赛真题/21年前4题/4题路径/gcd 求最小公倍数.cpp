/* #include<iostream>
using namespace std;

//求a b的最大公约数(a > b)
int gcd(int a,int b){
    if (a % b == 0)
      return b;
    else{
      return gcd(b,a%b);
    }
}

int main(){
    cout << gcd(100,88);
    return 0;
}
 */


//最小公倍数
#include<iostream>
using namespace std;

//求a b的最大公约数(a > b)
int gcd(int a,int b){
    if (a % b == 0)
      return b;
    else{
      return gcd(b,a%b);
    }
}

int lcm(int a,int b){
  return (a*b)/gcd(a,b);
}

int main(){
    cout << lcm(100,88);
    return 0;
}
