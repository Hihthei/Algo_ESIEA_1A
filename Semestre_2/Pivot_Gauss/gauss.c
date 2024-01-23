#include <stdio.h>
#include "gauss.h"
#include "matrice.h"

int transposition(double* l1, double* l2,int n){
    if (l1 == l2){
        return -1;
    }
    for (int i = 0; i < n; i++){
        double tmp = l1[i];
        l1[i] = l2[i];
        l2[i] = tmp;
    }
    return 0;
}

int dilatation(double* l, int n, double lambda){
    if (lambda == 0){
        return -1;
    }
    for (int i = 0; i < n; i++) {
        l[i] *= lambda;
    }
    return 0;
}

int transvection(double *li, double *lj, int n, double lambda){
    if (li == lj){
        return -1;
    }
    for (int i = 0; i < n; i++) {
        li[i] += lj[i] * lambda;
    }
    return 0;
}

int gaussAuto(double **M, int m, int n){
    int i = 0;
    for (int j=0;j < n;j++){
        int Li = i;
        while (Li < m && M[Li][j] == 0){
            Li++;
        }
        if (Li == m){
            j++;
        }
        else{
            transposition(M[i], M[Li], n);
            dilatation(M[Li], n, 1/M[Li][j]);
            for (int l = 0; l < m; l++){
                if (l != Li){
                    transvection(M[l], M[Li], n, -M[l][j]);
                }
            }
            i++;
        }
    }
    return 0;
}
