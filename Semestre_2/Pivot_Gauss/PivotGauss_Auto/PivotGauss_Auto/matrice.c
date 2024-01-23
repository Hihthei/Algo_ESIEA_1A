#include "matrice.h"
#include "gauss_Manual.h"

int interfaceUtilisateur(InfoMat Matrice, int test)
{
    system("cls");

    if (test > 0)
        printf("Veuillez rentrez une reponse correct\n\n");

    //on affiche la matrice
    afficheMat(Matrice);

    printf( "Voulez-vous effectuer le pivot de gauss suivant :\n"
            "   - Manuellement : entrez 1\n"
            "   - Automatiquement : entrez 2\n");

    int tmp = 1;

    printf("\nEntrez votre reponse : ");

    scanf("%d", &tmp);

    if ((tmp != 1) && (tmp != 2))
        tmp = interfaceUtilisateur(Matrice, test + 1);

    return tmp;
}

/// @brief : allou dynamiquement une matrice de taille l * n
/// @param : double ligne le nombre de ligne de la matrice
/// @param : double colonne le nombre de colonne
/// @return : un pointeur sur la zone mémoire allouée
double** allocMat(double ligne, double colonne)
{
    double** mat = (double**)calloc((int)ligne, sizeof(double*));
    if (mat == NULL)
    {
        printf("ERROR : allocation dynamique__allocationDynamique");
        return NULL;
    }
    for (int i = 0; i < ligne; i++) {
        mat[i] = (double*)calloc((int)colonne, sizeof(double));
        if (mat[i] == NULL) {
            printf("ERROR : allocation dynamique__allocationDynamique");
            return NULL;
        }
    }
    return mat;
}

/// @brief : renvoie toutes les bonnes infomartions de la matrice
/// @param : char str le nom du fichier
/// @param : InfoMat Matrice une structure avec les infos de la matrice
/// @return : un pointeur sur la zone mémoire allouée
InfoMat infoMatrice(char* str)
{
    InfoMat MatriceERROR = { 0, 0, NULL }, Matrice;

    Matrice.fichier = NULL;
    Matrice.fichier = fopen(str, "r");

    if (Matrice.fichier == NULL)
        return MatriceERROR;

    int nb_ele_lu = fscanf(Matrice.fichier, "%lf %lf", &Matrice.ligne, &Matrice.colonne);

    if (nb_ele_lu != 2)
    {
        printf("ERROR : lecture du fichier _matrice.c - l.43");
        return MatriceERROR;
    }

    if ((Matrice.ligne > 0) && (Matrice.colonne > 0))
    {
        Matrice.mat = allocMat(Matrice.ligne, Matrice.colonne);

        if (Matrice.mat == NULL)
        {
            printf("ERROR : allocation dynamique _matrice.c - l.53");
            return MatriceERROR;
        }
        remplirMat(Matrice);

        fclose(Matrice.fichier);

        return Matrice;
    }
    fclose(Matrice.fichier);
    return MatriceERROR;
}

/// @brief : affiche la matrice
/// @param : InfoMat Matrice une structure avec les infos de la matrice
/// @return : rien
int afficheMat(InfoMat Matrice)
{
    for (int i = 0; i < Matrice.ligne; i++)
    {
        for (int j = 0; j < Matrice.colonne; j++)
        {
            if (Matrice.mat[i][j] == -0)
                Matrice.mat[i][j] = 0;

            printf("[%.3lf] ", Matrice.mat[i][j]);
        }
        printf("= 0\n");
    }
    printf("\n");
    return EXIT_SUCCESS;
}

/// @brief : rempli la matrice
/// @param : InfoMat Matrice une structure avec les infos de la matrice
/// @param : FILE* fichier un pointeur vers le fichier qui contient la matrice
/// @return : succes
int remplirMat(InfoMat Matrice)
{
    int error = 0;
    for (int i = 0; i < Matrice.ligne; i++)
    {
        for (int j = 0; j < Matrice.colonne; j++)
        {
            error = fscanf(Matrice.fichier, "%lf", &Matrice.mat[i][j]);
            if (error != 1)
            {
                printf("ERROR : lecture du fichier_remplirMat\n\n");
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

int gaussManualAplly(InfoMat Matrice)
{
    while (gaussTest(Matrice) == false)
    {
        int n = gaussManuel(Matrice);

        switch (n)
        {
            //sortir
        case 6:
            break;
            //recommance
        case 7:
            Matrice = restart(Matrice);
            continue;
            //échange de 2 lignes
        case 1:
            interfaceTransposition(Matrice, 0);
            continue;
            //multiplication
        case 2:
            interfaceDilatation(Matrice, 0);
            continue;
            //addition
        case 3:
            interfaceTransvection(Matrice, 0);
            continue;
            //division
        case 4:
            interfaceDivision(Matrice, 0);
            continue;
            //tri matrice
        case 5:
            triMatrice(Matrice);
            continue;
        default:
            continue;
        }
        break;
    }
    //on sort de la boucle car la matrice est échelonnée et réduite, ou qu'on a quitté la boucle
    if (gaussTest(Matrice))
    {
        //on affiche la matrice triée
        afficheMat(Matrice);
        printf("felicitations, la matrice est echelonnee et reduite !\n");
    }
    return EXIT_SUCCESS;
}


/// @brief : free la matrice
/// @param : InfoMat Matrice une structure avec les infos de la matrice
/// @return : succes
int freeMatrice(InfoMat Matrice)
{
    Matrice.ligne = 0;
    Matrice.colonne = 0;

    for (int i = 0; i < Matrice.ligne; i++) {
        free(Matrice.mat[i]);
    }
    free(Matrice.mat);

    if (Matrice.mat != NULL)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

InfoMat restart(InfoMat Matrice)
{
    freeMatrice(Matrice);

    //on rempli toutes les infos importantes (allocation de la matrice, et remplissage)
    Matrice = infoMatrice("Matrice_pivot.txt");

    if (Matrice.ligne == 0 || Matrice.colonne == 0 || Matrice.mat == NULL)
    {
        printf("ERROR : matrice non valide, main.c - l.13\n");

        //on libère la mémoire
        freeMatrice(Matrice);

        return Matrice;
    }

    return Matrice;
}