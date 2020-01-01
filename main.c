#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    int i,j,les,lep;
    char lens[50],lenp[20],t[50],p[20];
    FILE *fp;
    fp = fopen("2input.txt","r");
    while (!feof(fp))
    {
        fscanf(fp,"%[^T]%s\n",&t);printf("%s\n",t);
        fscanf(fp,"%[^P]%s\n",&p);printf("%s",p);
    }
    fclose(fp);
    printf("%s\n\n",t);
    printf("%s",p);
    les=strlen(t);printf("les=%d",les);
    lep=strlen(p);printf("lep=%d",lep);
    fclose(fp);

    j=0;
    for (i=4;i<les;i++)
    {
        if (isalpha(t[i]))
        {
            lens[j]=t[i];
            j++;
        }
    }
    printf("lens=%s",lens);
    return 0;
}

