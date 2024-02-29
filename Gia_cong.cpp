#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int tg = a;
    a = b;
    b = tg;
}

void sort(int A[], int n)     // sort tu be den lon
{
    for (int i = 0; i < n - 1;i++){
        for(int j = 0; j < n-i-1; j++)
            if (A[j] > A[j+1])
                swap(A[j],A[j+1]);
    }        
}

void xuat(int Tg[],int i){
    for(int a = 0; a < i; a++)
        cout << Tg[a] << " ";
    cout << endl;
}


void nhap_tg(int Tg[], int i){
    cout << "Nhap thoi gian cho tung linh kien (tinh theo phut):\n";
    for(int a = 0; a < i; a++){
        cout << "i[" << a+1 << "]: "; cin >> Tg[a];
    }
    sort(Tg,i);
}

void fine_max_time(int Tg[], int May[],int m, int n){
    May[0] = Tg[n-1];
    int max = May[0];
    int right = n - 2;
    int left = 0;
    int j = 1;
    May[j] = Tg[right];
    while (left < right){
        while(May[j] + Tg[left] <= max){
            May[j] = May[j] + Tg[left];
            left++;
        }
        right--;
        sort(May,m);
        j = 0;
        May[j] = May[j] + Tg[right];
        max = May[m-1];
    }
    sort(May,m);
    max = May[m-1];
    //return max;
}

int main(){
    int m, i;
    int tg[100], may[100];
    cout << "Nhap m may gia cong: "; cin >> m;
    cout << "Nhap i linh kien can gia cong: "; cin >> i;
    nhap_tg(tg,i);
    xuat(tg,i);
    fine_max_time(tg,may,m,i);
    cout << "Thoi gian theo may la:\n";
    xuat(may,m);
}