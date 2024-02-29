#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int F[90] = {0,1}; //điều kiện là số n nhập vào < 90 (để là {0,1,1} cũng được mà để như bên cũng được)
    int n;
    cout << "Nhap so thu n cua day Fibonacci: "; cin >> n;
    for ( int i = 2; i <= n; i++)
    {
        F[i]= F[i-1] + F[i-2];
    }
    cout << "So thu " << n << " cua day Fibonacci la: " << F[n-1]; // vi n trong ham chinh la n+1 vi bao gom ca so 0 => neu muon tinh n that su thi phai la n-1
    return 0;
}