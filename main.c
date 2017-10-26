#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char t[3][10];
    char pyt[30];
    int i, f;
    FILE *c;
    printf("vvedite pyt k faily\n");
    scanf("%s",pyt);

    c = fopen(pyt,"r");
    if(c == NULL)
    {
        printf("FILE CANNOT OPEN\n");
        exit(0);
    }
    while (!feof(c))
    {
        fscanf(c,"%s",t[i]);
        i++;
        if(i == 3)
        {
            f = fork();
            if(f < 0)
            {
                printf("FORK - ERROR");
                exit(1);
            }
            if(f == 0)
            {

                if(t[0][0] == 'm')
                    sleep(0.001*atoi(t[1]));
                if(t[0][0] == 's')
                {
                    sleep(atoi(t[1]));
                }
                if(t[0][0] == 'M')
                    sleep(60*atoi(t[1]));
                if(t[0][0] == 'h')
                    sleep(3600*atoi(t[1]));

                execl(t[2],t[2],NULL);
            }
            i=0;
        }
    }
    if (fclose(c) == EOF)
    {
        printf("CANNOT CLOSE FILE");
        return 0;
    }
    return 0;
}
