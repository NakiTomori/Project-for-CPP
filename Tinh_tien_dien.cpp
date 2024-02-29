#include <iostream>
using namespace std;

int main()
{
    int csm, csc, tieuthu, tien;
    cout << "Nhap Chi so moi: "; cin >> csm ;
    cout << "Nhap Chi so cu: "; cin >> csc ;
    tieuthu = csm - csc;
    if (tieuthu < 100) {
        tien = tieuthu * 550;
    }
    else {
        if (tieuthu <= 150) {
            tien = (100 * 550) + (tieuthu-100)*1110;
        }
        else {
            if (tieuthu <= 200) {
                tien = (100 * 550) + (50 * 1110) + (tieuthu- 150)*1470;
            }
            else {
                if (tieuthu <= 300 ) {
                    tien = (100 * 550) + (50 * 1110) + (50 * 1470) + (tieuthu - 200)*1600;
                }
                else {
                    if (tieuthu <= 400) {
                        tien = (100 * 550) + (50 * 1110) + (50 * 1470) + (100 * 1600) + (tieuthu - 300) *1720;
                    }
                    else {
                        tien = (100 * 550) + (50 * 1110) + (50 * 1470) + (100 * 1600) + (100 * 1720) + (tieuthu - 400)*1780;
                    }
                }
            }
        }
    }
    cout << "Gia tien dien phai tra = " << tien << " d";
    return 0;
}