#include<stdlib.h>
#include<stdio.h>

int kekchose(int b) //Là on fait un truc
{
    b = b +1;
    return b;
}

int UnTruc(int a) //Ici aussi on fait un truc
{
    int objet = kekchose(a);
    return objet;
}

int main()
{

    printf("%d\n", kekchose(2) * UnTruc(3));
    return 0;
}