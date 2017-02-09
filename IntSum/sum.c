/* 
INPUT
Each input file will start with a single integer N (1 ≤ N ≤ 10000) denoting the number of test cases. The
following N lines will contain sets of 3 numbers a, b, c (1 ≤ a, b, c ≤ 10000).
*/

/*
OUTPUT
For each test case, determine whether or not it is possible to produce the third number, c, using the first two
numbers, a and b, using addition, subtraction, multiplication, or division.
*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


//This struct holds the test case values
struct ThreeNum{
    int n1,n2,n3;
};



void ReadInt(void);                     //Read the values from the files and passes the input to the test function
int Test(int N,struct ThreeNum num[]); //Performs The test cases


int main (void){
    ReadInt();  //Read the value from the file
}



void ReadInt(void){
     
    int i,N,d,s;
    //Number Of test cases
    FILE *finptr;                   //Initialise the pointer to input file location ---Input.txt--------
    
    finptr = fopen("Input.txt","r"); //Open the file in read mode
    
    if(finptr == NULL)
    {
        printf("Error first file open\n");
        exit(0);
    }
    
    fscanf(finptr,"%d", &N);            //Scans the number of test cases to be performed
    printf("The value of N is %d\n",N);

    struct ThreeNum num[N];             //Number of test cases
    
    for(i=0;i<N;i++){
        fscanf(finptr,"\n%d %d %d",&num[i].n1, &num[i].n2, &num[i].n3);
        printf("The value of test(%d):a,b,c is %d %d %d\n",i,num[i].n1,num[i].n2,num[i].n3);
    }
    
    fclose(finptr);    
    d = Test(N,num);                //Call the test function to test each case
    if(d==0)
    printf("Test case Successful\n");
      
}

//This function performs the test operation of each case
int Test(int N,struct ThreeNum num[])
{
    int i;
    FILE *foutptr;                  //Points to the output file --Destination file --Output.txt
    foutptr = fopen("Output.txt","w");
    if(foutptr == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    for(i=0;i<N;i++)                //Finds the value of a,b,c for each test case
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
        
        //Test for all the six cases ------ add,mul,sub,div-----
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