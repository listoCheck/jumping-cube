#include <iostream>
#include <vector>
#include <cmath>
#include "windows.h"
using namespace std;
int c[12][30]{  };



int gonka() {


    for (int a = 0; a < 12; a++) {
        for (int b = 0; b < 30; b++) {
            if (c[a][b] == 0) {
                cout << "*";
            }
            else {
                cout << "0";
            }
        }
        cout << '\n';
    }
    for (int jk = 0; jk < 10; jk++) {
        cout << '\n';
    }
    return 0;
}


int zxc(int k = 0, int l = 0) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            c[k + i][l + j] = 1;
        }
    }
    gonka();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            c[k + i][l + j] = 0;
        }
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int timer = 0;
    cout << "Задайте задержку для вывода поля в миллисекундах, лучше брать от 200 до 500!" << '\n' << "Задержка таймера:";
    cin >> timer;
    
    int k = 0, l = 0;
    bool lk = true;
    int flag = 0;
    while (lk) {
        if (k < 10 and l < 27 and flag == 0) {
            c[k][l] = 1;
            zxc(k, l);
            c[k][l] = 0;
            k++, l++;
            Sleep(timer);
        }
        if (k == 10 and l < 27) {
            c[k][l] = 1;
            flag = 1;
            
        }
        if (flag == 1 and k > 0 and l < 27) {
            c[k][l] = 1;
            zxc(k, l);
            c[k][l] = 0;
            
            k--, l++;
            Sleep(timer);
        }
        if (flag == 1 and k == 0 and l < 27) {
            c[k][l] = 1;
            flag = 0;   
            zxc(k, l);
            c[k][l] = 0;
        }
        if (l == 27) {
            while (l > 0) {
                if (flag == 1 and k > 0 and l > 0) {
                    c[k][l] = 1;                   
                    zxc(k, l);
                    c[k][l] = 0;
                    k--, l--;
                    Sleep(timer);
                }
                if (k == 0 and l > 0) {
                    flag = 0;
                    zxc(k, l);
                }
                if (k < 10 and l > 0 and flag == 0) {
                    c[k][l] = 1;
                    zxc(k, l);
                    c[k][l] = 0;
                    Sleep(timer);
                    k++, l--;
                }
                if (k == 10 and l > 0) {
                    flag = 1;
                    zxc(k, l);
                }
                if (k > 0 and l > 0 and flag == 1) {
                    c[k][l] = 1;
                    zxc(k, l);
                    c[k][l] = 0;
                    Sleep(timer);
                    k--, l--;
                }
            }
        }
    }
    return 0;
}