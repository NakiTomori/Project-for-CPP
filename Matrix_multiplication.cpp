#include <iostream>
#include <math.h>
using namespace std;

float A[100][100], B[100][100], Tich[100][100];
int ah,ac,bh,bc;

void nhap()
{
    int i,j;
    cout << "Day la phep nhan ma tran dang: A x B " << endl;
    cout << "Nhap hang va cot cho ma tran A:" << endl;
    cout << "So hang: "; cin >> ah;
    cout << "So cot: "; cin >> ac;
    cout << "Nhap hang va cot cho ma tran B:" << endl;
    cout << "So hang: "; cin >> bh;
    cout << "So cot: "; cin >> bc;
    if ( ac != bh) {
        cout << "Dimension Error";
    }
    else
    {
        cout << "Nhap cac gia tri cho matrix A:" << endl;
        for ( i = 0; i < ah; i++)
            for ( j = 0; j < ac; j++)
            {
                cout << "A[" << i+1 << "," << j+1 << "] = ";
                cin >> A[i][j];
            }
        cout << endl << "Nhap cac gia tri cho matrix B:" << endl;
        for ( i = 0; i < bh; i++)
            for ( j = 0; j < bc; j++)
            {
                cout << "B[" << i+1 << "," << j+1 << "] = ";
                cin >> B[i][j];
            }
    }
}

void xuat()
{
    int i,j;
    if ( ac == bh)
    {  
        cout << endl << "Ma tran A co dang la: " << endl;
        for (i = 0; i < ah; i++)
        {
            for (j = 0; j < ac; j++)
            {
                cout << A[i][j] << " ";   
            }
            cout << endl;
        }
        cout << "Ma tran B co dang la: " << endl;
        for (i = 0; i < bh; i++)
        {
            for (j = 0; j < bc; j++)
            {
                cout << B[i][j] << " ";   
            }
            cout << endl;
        }
    }
}

void xuat2()
{
    int i,j;
    if ( ac == bh) //thuc ra ngay phan nhap dau kia da cho dieu kien de tinh tich Matrix roi
    {
    cout << endl << "Tich cua Matrix A * Matrix B = " << endl;
    for (i = 0; i < ah; i++)
        {
            for (j = 0; j < bc; j++)
            {
                cout << Tich[i][j] << " ";   
            }
            cout << endl;
        }
    }
}

void Matrix_multiplication()
{
    int i,j,m;
    float tong = 0;
    for ( i = 0; i < ah; i++)
    {
        for ( m = 0; m < bc; m++)
        {
            for ( j = 0; j < bh; j++)
            {
                tong = tong + (A[i][j] * B[j][m]);
            }
            Tich[i][m] = tong;
            tong = 0;
        }
    }
}

int main()
{
    nhap();
    xuat();
    Matrix_multiplication();
    xuat2();
}