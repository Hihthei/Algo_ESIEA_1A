#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/// <summary> open the file "path" in "Write" mode
/// <param "path"> char* represent the path of the file
/// <returns> pointer for the file
FILE* openWritableFile(char* path)
{
    FILE* test = NULL;
    test = fopen(path, "r");

    if (test != NULL) {
        fclose(test);
        char rep;
        printf("%s : fichier existant, voulez-vous l'ecraser ? (Y pour oui)\n", path);
        scanf("%c", &rep);
        if (rep == 'Y')
        {
            FILE* fichier = NULL;
            fichier = fopen(path, "w");
            if (fichier == NULL)
                return NULL;

            return fichier;
        }
        else
            return NULL;
    }
    test = fopen(path, "w");
    return test;
}

/// <summary> open the file "path" in "Read" mode
/// <param "path"> char* represent the path of the file
/// <returns> pointer for the file
FILE* openReadableFile(char* path)
{
    FILE* fichier = NULL;
    fichier = fopen(path, "r");

    if (fichier != NULL) {
        return fichier;
    }

    return NULL;
}

/// <summary> fet the size of the file
/// <param "file"> pointer of the file
/// <returns> the size of the file
int getFileSize(FILE* pfile)
{
    int n = 0;
    rewind(pfile);

    fseek(pfile, 0, SEEK_END); // fseek déplace le curseur à l'endroit voulu

    //int fseek(FILE * stream, long int offset, int origin);
    /*
    FILE* stream -> pointeur vers le fichier
    long int offset -> +/- le déplacement par apport à l'origin
    int origin -> on déplace le curseur ) cette position : SEEK_SET (début) / SEEK_CUR (position actuelle) / SEEK_END (fin du fichier)
    */

    if (feof(pfile) == 0) // feof permet de savoir si le curseur est actuellement à la fin du fichier (renvoie 0 si fin du fichier)
    {
        n = (int)ftell(pfile); // ftell renvoie le nombre de caractère depuis le début du fichier jusqu'à la position actuelle du curseur

        rewind(pfile); // renvoie le curseur au début du fichier

        return n;
    }

    return 0;
}

/// <summary> copy a file
/// <param name="srcPath"> file to copy
/// <param name="dstPath"> the name of the new file
/// <returns> the size of the copied file, 0 if error
int copyFile(char* srcPath, char* dstPath)
{
    int size;
    FILE* pfile = fopen(srcPath, "rb");
    unsigned char* buf;

    if (!pfile)
        return 0;

    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);

    buf = calloc(size, sizeof(char));
    fread(buf, 1, size, pfile);
    fclose(pfile);

    pfile = fopen(dstPath, "wb");
    fwrite(buf, 1, size, pfile);
    fclose(pfile);

    return size;
}

/// <summary> allue a dynamic char* tab
/// <param name="nbRows"> number of colons in the tab to allue
/// <returns> link for the new tab
char* allocChaineCaract(int nbRows)
{
    assert(nbRows > 0); //assert vérifie que les conditions soient bonnes et met un point d'arrêt en cas de conditions non respectés

    char* tab = (char*)calloc(nbRows, sizeof(char));

    if (tab != NULL)
        return tab;
    else
    {
        printf("ERROR : DYNAMIC ALLOCATION");
        return NULL;
    }
}

int main()
{
    FILE* pfile = openReadableFile("new.txt");

    if (pfile != NULL)
    {
        int size = getFileSize(pfile);

        if (size == 0)
            printf("ERROR : FILE EMPTY\n");
        else
        {
            char* tab = allocChaineCaract(size + 1);
            fgets(tab, size + 1, pfile);
            rewind(pfile);
            printf("size of the file : %d\n\n", size);
            printf("file containt :\n\"%s\"\n", tab);

            copyFile("main.c", "rough.txt");

            free(tab);
        }
        fclose(pfile);
    }
    return 0;
}