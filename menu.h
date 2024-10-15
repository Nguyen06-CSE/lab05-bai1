#include<iostream>
#include<math.h>

#define MAX 1000


using namespace std;

typedef int DaySo[MAX];

int timVT(DaySo a, int n, int x );
int timVTSoNT(DaySo a, int n);
void PTXuatHienNhieuNhat(DaySo a, int n);
int phanTuGiaTriNhoNhat(DaySo a, int n);
void cacSoHoanChinh(DaySo a, int n);
void timAmLonNhat(DaySo a, int n);
void timSoDuongNhoNhat(DaySo a, int n);




void choiseMenu(DaySo a,int choise, int n){
    switch(choise){
        case 1:
            int x;
            cout << "hay nhap so x ma ban muon tim kiem: ";
            cin >> x;
            
            if(timVT(a, n, x ) == -1){
                cout << x << " ko co trong mang \n";
            }
            else {
                cout << "vi tri dau tien cua " << x << " trong mang la " << timVT(a, n, x ) << endl;
            }
            break;
        case 2:
                if(timVTSoNT(a, n) == -1){
                cout  << " ko co so NT nao trong mang \n";
            }
            else {
                cout << "vi tri so NT dau tien trong mang la " << timVTSoNT(a, n) << endl;
            }
            break;
        case 3:
                PTXuatHienNhieuNhat(a, n);
            break;
        case 4:
            cout << "phan tu nho nhat trong mang la " << phanTuGiaTriNhoNhat(a, n) << endl;
            break;
        case 5:
            timAmLonNhat(a, n);
            break;
        case 6:
            timSoDuongNhoNhat(a,n);
            // if(timSoDuongNhoVaVT(a, n) == 1){
            //     cout << "mang co phan tu be nhat la " << timSoDuongNhoVaVT(a, n) << " va nam o vi tri 0 trong mang \n"; 
            // }
            // else if(timSoDuongNhoVaVT(a, n) == 0){
            //    cout << "trong mang ko co phan tu co gia tri duong \n"; 
            // }
            // else{
            //     cout << "phan tu nho nhat trong mang la " << timSoDuongNhoVaVT(a, n) << " va co vi tri la " ;
            // }
            break;  
        case 7:

            break;
       
    }
}



int timVT(DaySo a, int n, int x ){
    
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            return i;
        }
    }

    return -1;
}


int timVTSoNT(DaySo a, int n){
    for(int i = 0; i < n; i++){
        if (a[i] < 2){
            return -1;
        }
    }
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0 ){
            return -1;
        }
        else {
            return i;
        }
    }

}

void PTXuatHienNhieuNhat(DaySo a, int n){
    int maxDem = 0;
    int phanTu = a[0];
    for(int i = 0; i < n; i++){
        int dem = 0;
        for(int j = 1; j < n; j++){
            if(a[i] == a[j]){
                ++dem;
            }
        }
        if(dem > maxDem){
            maxDem = dem;
            phanTu = a[i];
        }
    }
    cout << "gia tri " << phanTu << " trong mang a la phan tu xuat hien nhieu nhat voi so lan la " << maxDem << endl;
}



int phanTuGiaTriNhoNhat(DaySo a, int n){
    int minVal = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] < minVal){
            minVal = a[i];
        }
    }

    return minVal;
}



void cacSoHoanChinh(DaySo a, int n){
    int sum = 0;
    for(int j = 1; j <= n; j++){
        for(int i = 0; i < n/2; i++){
            if(j % i ==0){
                sum += i;
            }
        }
        if(j == sum ){
            cout << j << " ";
        }
    }
    
}



void timAmLonNhat(DaySo a, int n){
    int viTri;
    int minVal = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            if(minVal > a[i]){
                minVal = a[i];
                viTri = i;
            }
        }
    }
    if(minVal == 0){
        cout << "trong mang ko co phan tu co gia tri am \n";
    }
    else{
        cout << "phan tu nho nhat trong mang a la " << minVal << ", phan tu do o vi tri " << viTri << endl; 

    }

}



   


void timSoDuongNhoNhat(DaySo a, int n) {
    int minDuong = -1;
    int viTri = -1;
    int countMinDuong = 0;  
    for (int i = 0; i < n; i++) {
        //long de ss 2 dk
        if (a[i] > 0 && (minDuong == -1 || a[i] < minDuong)) {
            minDuong = a[i];
            viTri = i;
        }
    }

    if (minDuong == -1) {
        cout << "ko co gia tri duong trong mang nha." << endl;
    }

    
        for (int i = 0; i < n; i++) {
            if (a[i] == minDuong) {
                countMinDuong++;
            }
        }
    

    if (countMinDuong == 1) {
        cout << "So duong nho nhat: " << minDuong << " o vi tri " << viTri << endl;
    } else {
        cout << "mang co hai gia tri " << minDuong << " nen se ko co gia tri nho nhat" << endl;
    }
}

