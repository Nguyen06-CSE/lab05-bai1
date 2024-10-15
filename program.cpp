#include<iostream>
#include<math.h>
#include<conio.h>

#define MAX 1000


using namespace std;


typedef int DaySo[MAX];

#include"menu.h"
#include"printMenu.h"




int main(){
    DaySo a;
    char stop;
    do{
        system("cls");
        print();
        int n, choise;
        cout << "nguoi dung hay chon chuc nang(1-7): ";
        cin >> choise;
        if(choise == 0){
            break;
        }
        cout << "nguoi dung hay nhap so n: ";
        cin >> n;
        cout << "nguoi dung hay nhap mang \n";
        for(int i = 0; i < n; i++){
            cout << "a[" << i <<"]=";
            cin >> a[i];
            cout << endl;
        }
        choiseMenu(a, choise, n );
        _getch();


    }while(true);
    return 0;
}