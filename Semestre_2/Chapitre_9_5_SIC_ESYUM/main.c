/*
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n, i = 1, j, min;

    while (argv[i] != NULL)
    {
        j = i;
        min = atoi(argv[j + 2]);
        while(argv[i] != NULL)
        {
            if(strcmp(argv[j], "P") == 0)
            {
                //TODO
            }
            else if(strcmp(argv[j], "L") == 0)
            {
                n = atoi(argv[j+1]);
                for (int k = j+2; k < j+n+2; k++)
                {
                    if(argv[k] == NULL)
                        break;
                    int num = atoi(argv[k]);
                    if( num < min )
                        min = num;
                }
            }
            i++;
        }
    }
    printf("min = %d\n", min);
    return 0;
}
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n, i = 0, j, min, num;
    char command[50];

    while (1)
    {
        scanf("%s", command);
        if(strcmp(command[i], "\0") == 0)
            break;
        else if(strcmp(command[i], "P") == 0)
        {
            //TODO
        }
        else if(strcmp(command[i], "L") == 0)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &num);
                if(i == 0)
                    min = num;
                else if( num < min )
                    min = num;
            }
        }
        if(strcmp(command, "\0") == 0)
            break;
    }
    printf("min = %d\n", min);
    return 0;
}
