#include <iostream>
#include <cmath>
using namespace std;

void num(int n){
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i){ //如果两因子相同，则只加1  
                cout << i << endl;
            }
            else{
                cout << i << " " << n/i << endl;
            }
        }
    }
}

int main(){
    
    int n;
    cin>>n;
    num(n);
    return 0;
}
