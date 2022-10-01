#include <iostream>
#include <vector>
#include <cmath>
#include "windows.h"
using namespace std;
int c[19][60]{  };



int gonka() {


    for (int a = 0; a < 19; a++) {
        for (int b = 0; b < 60; b++) {
            if (c[a][b] == 0) {
                cout << "*";
            }
            else {
                cout << "0";
            }
        }
        cout << '\n';
    }
    for (int jk = 0; jk < 5; jk++) {
        cout << '\n';
    }
    return 0;
}


int zxc(int k = 0, int l = 0) {
    for (int i = 0; i < 5; i++) {       
         c[k + i][l + 0] = 1;      
    }
    c[k + 0][l + 1] = 1, c[k + 4][l + 1] = 1;
    for (int i = 1; i < 4; i++) {
        c[k + i][l + 2] = 1;
    }
    c[k + 0][l + 3] = 1, c[k + 1][l + 3] = 1, c[k + 2][l + 4] = 1, c[k + 3][l + 4] = 1, c[k + 4][l + 5] = 1, c[k + 0][l + 7] = 1, c[k + 1][l + 7] = 1, c[k + 2][l + 6] = 1, c[k + 3][l + 6] = 1;
    for (int i = 0; i < 5; i++) {
        c[k + i][l + 8] = 1;
    }
    c[k + 0][l + 9] = 1, c[k + 4][l + 9] = 1;
    for (int i = 1; i < 4; i++) {
        c[k + i][l + 10] = 1;
    }   
    gonka();

    for (int i = 0; i < 5; i++) {
        c[k + i][l + 0] = 0;
    }
    c[k + 0][l + 1] = 0, c[k + 4][l + 1] = 0;
    for (int i = 1; i < 5; i++) {
        c[k + i][l + 2] = 0;
    }
    c[k + 0][l + 3] = 0, c[k + 1][l + 3] = 0, c[k + 2][l + 4] = 0, c[k + 3][l + 4] = 0, c[k + 4][l + 5] = 0, c[k + 0][l + 7] = 0, c[k + 1][l + 7] = 0, c[k + 2][l + 6] = 0, c[k + 3][l + 6] = 0;
    for (int i = 0; i < 5; i++) {
        c[k + i][l + 8] = 0;
    }
    c[k + 0][l + 9] = 0; c[k + 4][l + 9] = 0;
    for (int i = 1; i < 4; i++) {
        c[k + i][l + 10] = 0;
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
        if (k < 14 and l < 49 and flag == 0) {
            c[k][l] = 1;
            zxc(k, l);
            c[k][l] = 0;
            k++, l++;
            Sleep(timer);
        }
        if (k == 14 and l < 49) {
            c[k][l] = 1;
            flag = 1;
            
        }
        if (flag == 1 and k > 0 and l < 49) {
            c[k][l] = 1;
            zxc(k, l);
            c[k][l] = 0;
            
            k--, l++;
            Sleep(timer);
        }
        if (flag == 1 and k == 0 and l < 49) {
            c[k][l] = 1;
            flag = 0;   
            zxc(k, l);
            c[k][l] = 0;
        }
        if (l == 49) {
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
                if (k < 14 and l > 0 and flag == 0) {
                    c[k][l] = 1;
                    zxc(k, l);
                    c[k][l] = 0;
                    Sleep(timer);
                    k++, l--;
                }
                if (k == 14 and l > 0) {
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
