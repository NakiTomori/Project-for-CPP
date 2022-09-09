#include <iostream>
#include <math.h>
using namespace std;

float P[100][100], X[100], A[100][100], X_dau_ra[100][100];
int n, t1, t2, bn;

void nhap()
{
    int i,j;
    cout << "Nhap ma tran xac suat chuyen P " << endl;
    cout << "Nhap so phan tu trang thai: "; cin >> n;
    cout << "Nhap cac phan tu trang thai: " << endl;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
        {
            cout <<"P[" << i+1 << "," << j+1 << "] = ";
            cin >> P[i][j];
        }
    cout << endl << "Nhap ma tran phan phoi ban dau X(0) " << endl;
    cout << "Nhap cac phan tu trang thai: " << endl;
    for ( i = 0; i < n; i++)
    {
        cout <<"X[" << 1 << "," << i+1 << "] = ";
        cin >> X[i];
    }
    cout << endl << "Nhap diem neo dau: "; cin >> t1;
    cout << "Nhap diem neo cuoi: "; cin >> t2;
    cout << "Nhap buoc nhay: "; cin >> bn;
}

int so_chu_ky(int a, int b, int c )
{
    int so_chu_ky;
    so_chu_ky = (a - b) / c;
    return so_chu_ky;
}

void xuat()
{
    int i,j;
    cout << "Ma tran P = " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
         cout << P[i][j] << " ";   
        }
        cout << endl;
    }
    cout << endl << "Ma tran X = " << endl;
    for ( i = 0; i < n; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

void xuat2()
{
    int i,j;
    cout << endl << "Bang du doan la: " << endl;
    for (i = 0; i < so_chu_ky(t2, t1, bn); i++)
    {
        cout << "X(" << i+1 << ")= ";
        for (j = 0; j < n; j++)
        {
         std::cout <<(float) X_dau_ra[i][j] << " ";   
        }
        cout << endl;
    }
}

void tinh_toan_Markov()
{
    int i, j, m, z;
    float tong = 0, tong1 = 0, tong3 = 0, tong4 = 0;
    for ( i = 0; i < n; i++)
            {
                for ( j = 0; j < n; j++)
                {               
                    tong3 = tong3 + (X[j] * P[j][i]);         //tinh X(1)
                }
                X_dau_ra[0][i] = tong3;
                tong3 = 0;
            }
    
    for ( i = 0; i < n; i++)
    {
        for ( m = 0; m < n; m++)
        {
            for ( j = 0; j < n; j++)
            {
                tong = tong + (P[i][j] * P[j][m]);     //day la A^2
            }
            A[i][m] = tong;
            tong = 0;
        }
    }
    for ( i = 0; i < n; i++)
            {
                for ( j = 0; j < n; j++)
                {               
                    tong1 = tong1 + (X[j] * A[j][i]);          //tinh X(2)
                }
                X_dau_ra[1][i] = tong1;
                tong1 = 0;
            }
    for ( z = 2; z <= so_chu_ky(t2, t1, bn) - 1 ; z++)
    {
        for ( i = 0; i < n; i++)
        {
            for ( m = 0; m < n; m++)
            {
                for ( j = 0; j < n; j++)
                {
                    tong = tong + (A[i][j] * P[j][m]);     //day la A^n
                }
                A[i][m] = tong;
                tong = 0;
            }
        }
            for ( i = 0; i < n; i++)
            {
                for ( j = 0; j < n; j++)
                {               
                    tong4 = tong4 + (X[j] * A[j][i]);         //tinh X(n)
                }
                X_dau_ra[z][i] = tong4;
                tong4 = 0;
            }
    }
}

int main()
{
    nhap();
    cout << endl;
    xuat();
    tinh_toan_Markov();
    xuat2();
}