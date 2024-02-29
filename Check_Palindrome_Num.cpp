#include<stdio.h>
#include <iostream>
using namespace std;
 
int main(){
    int n,r,Tong=0,m;
 
    cout << "Nhap so n: ";
     cin >> n;
 
    for(m=n;n!=0;n=n/10){
         r=n%10;
         Tong=Tong*10+r;
    }
    if(m==Tong)
         cout << m << " la so palindrome";
    else
         cout << m << " khong phai la so palindrome";
 
    return 0;
}