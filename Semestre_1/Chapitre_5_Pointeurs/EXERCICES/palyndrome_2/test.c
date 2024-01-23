// #include<stdlib.h>
// #include<stdio.h>

// int puissance(int a, int b);
// void echangeChaine(int* preverse, int n);
// void test(int* pnombre, int* p_n);

// int main() {

//     int nombre = 0, reverse = 0;
//     int* pnombre = &nombre;
//     int* preverse = &reverse;

//     printf("Quelle est votre nombre de départ ?\nnombre de départ = ");
//     scanf("%d", &nombre);
//     reverse = nombre;

//     int n = 0;
//     int* p_n = &n;
//     int testeur = 0;
//     int compteur = 1;
//     int a = 0, b = 1;

//     while (a != b) {

//         reverse = nombre;
//         test(pnombre, p_n);
//         echangeChaine(preverse, *p_n);
        
//         printf("pnombre = %d, preverse = %d\n1/2\n\n", *pnombre, *preverse);
//         if(*pnombre == *preverse) {
//             printf("Felicitations ! Vous avez trouvez un palyndrome !\n");
//             printf("Il vous a fallu %d essais pour trouver %d !!\n\n", compteur, *pnombre);

//             a = b;
//         }
//         else {
//             *pnombre += *preverse;
//             printf("pnombre = %d, preverse = %d\n2/2\n\n", *pnombre, *preverse);
//         }
//         compteur++;
//     }
//     return 0;
// }

// int puissance(int a, int b) {
//     if (b == 0) return 1;
//     if (b == 1) return a;
//     int valeur = a;
//     for (int i = 0; i < b -1; i++) a = a * valeur;
//     return a;
// }

// void echangeChaine(int* preverse, int n) {

//     int reverse = 0;
//     int finish = 0;

//     for (int i = 1; i < n+1; i++)
//     {
//         reverse = (puissance(10, n-(i)) * (*preverse % puissance(10, i))) / puissance(10, i-1);
//         printf("reverse = %d\n", reverse);
//         finish += reverse;
//         printf("finish = %d\n", finish);
//         *preverse -= (*preverse % puissance(10,i));
//         printf("preverse = %d\n", *preverse);
//         if (i == n) *preverse = finish;
//         printf("%d/%d\n\n", i, n);
//     }
//     return;
// }

// void test(int* pnombre, int* p_n) {
//     int i = 1;
//     while (*p_n == 0)
//     {
//         if (*pnombre < puissance(10, i)) *p_n = i;
//         i++;
//     }
//     return;
// }