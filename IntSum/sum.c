#include<stdio.h>
#include<limits.h>

void Test(int N); //Performs 
int main (void)
{
    int N;                          //Number Of test cases
    
    printf("Enter the number of test cases you want to perform:\n");
    scanf("%d",&N);
    Test(N);
}

void Test(int N)
{
    while(N!=0)
    {
        int a,b,c;
        int add, sub, mul, sub1;
        float divide, divide1;
        printf("Enter the three numbers\n");
        scanf("%d %d %d",&a,&b,&c);
        add = a+b;
        sub = a-b;
        sub1 = b-a;
        mul = a*b;
        divide = (float)a/b;
        divide1 = (float)b/a;
        
        if(c == add)
        {
            printf("Possible\n");
            N--;
            continue;
        }
        else if(c == sub)
        {
            printf("Possible\n");
            N--;
            continue;
        }
        else if(c == sub1)
        {
            printf("Possible\n");
            N--;
            continue;
        }
        else if(c == mul)
        {
            printf("Possible\n");
            N--;
            continue;
        }
        else if((float)c == divide)
        {
            printf("Possible\n");
            N--;
            continue;
        }
        else if(c == divide1)
        {
            printf("Possible\n");
            N--;
            continue;
        }
        else 
            printf("Imossible\n");
            N--;
    }
}