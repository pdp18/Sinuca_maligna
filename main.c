#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,jogadas=0;
    printf("Informe X e Y\n");
    scanf("%d%d",&x,&y);
    if(x+2<=8)
    {
        if(y+1<=8)
        {
            printf("(%d , %d) \n",x+2,y+1);
             jogadas++;
        }
        if(y-1>=1)
        {
            printf("(%d , %d) \n",x+2,y-1);
            jogadas++;
        }

    }
    if(x-2>=1)
    {
         if(y+1<=8)
        {
            printf("(%d , %d) \n",x-2,y+1);
             jogadas++;
        }
        if(y-1>=1)
        {
            printf("(%d , %d)\n",x-2,y-1);
            jogadas++;
        }
    }
    if(y+2<=8)
    {
        if(x+1<=8)
        {
            printf("(%d , %d)\n",x+1,y+2);
             jogadas++;
        }
        if(x-1>=1)
        {
            printf("(%d , %d) \n",x-1,y+2);
            jogadas++;
        }
    }
    if(y-2>=1)
    {
         if(x+1<=8)
        {
            printf("(%d , %d)\n",x+1,y-2);
             jogadas++;
        }
        if(x-1>=1)
        {
            printf("(%d , %d) \n",x-1,y-2);
            jogadas++;
        }
    }
    printf("%d jogadas possiveis ",jogadas);
    return 0;
}
