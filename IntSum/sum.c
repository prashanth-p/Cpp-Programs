#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

//This struct holds the test case values
struct ThreeNum{
    int n1,n2,n3;
};
int Test(int N,struct ThreeNum num[]); //Performs The test cases

int main (void){
    
    int i,N,d,s;
    //Number Of test cases
    s = sizeof(struct ThreeNum);
    printf("%d",s);
    FILE *finptr;                   //Initialise the file location pointer
    
    finptr = fopen("Input.txt","r"); //Open the file in read mode
    
    if(finptr == NULL)
    {
        printf("Error first file open\n");
        exit(0);
    }
    
    fscanf(finptr,"%d", &N);
    printf("The value of N is %d\n",N);

    struct ThreeNum num[N];
    
    for(i=0;i<N;i++){
        fscanf(finptr,"\n%d %d %d",&num[i].n1, &num[i].n2, &num[i].n3);
        printf("The value of a,b,c is %d %d %d\n",num[i].n1,num[i].n2,num[i].n3);
    }
    
    fclose(finptr);    
  
    
    d = Test(N,num);
    if(d==0)
        printf("Test case Successful\n");
}

int Test(int N,struct ThreeNum num[])
{
    int i;
    FILE *foutptr;
    foutptr = fopen("Output.txt","w");
    if(foutptr == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    for(i=0;i<N;i++)
    {
        int a,b,c;
        a = num[i].n1;
        b = num[i].n2;
        c = num[i].n3;
        int add, sub, mul, sub1;
        float divide, divide1;
        add = a+b;
        sub = a-b;
        sub1 = b-a;
        mul = a*b;
        divide = (float)a/b;
        divide1 = (float)b/a;
        
        if(c == add){
            printf("Possible\n");
            fprintf(foutptr,"Possible\n");
            continue;
        }
        else if(c == sub){
            printf("Possible\n");
            fprintf(foutptr,"Possible\n");
            continue;
        }
        else if(c == sub1){
            printf("Possible\n");
            fprintf(foutptr,"Possible\n");
            continue;
        }
        else if(c == mul){
            printf("Possible\n");
            fprintf(foutptr,"Possible\n");
            continue;
        }
        else if((float)c == divide){
            printf("Possible\n");
            fprintf(foutptr,"Possible\n");
            continue;
        }
        else if((float)c == divide1){
            printf("Possible\n");
            fprintf(foutptr,"Possible\n");
            continue;
        }
        else{
            printf("Imossible\n");
            fprintf(foutptr,"Impossible\n");
        }
    }
    fclose(foutptr);
    if(N)
    {
        return 0;
    }
}