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
#include<stdlib.h>

struct problem{
        int p,q,r;
};

struct ProblemSet {
        int n;
        struct problem *ps;
};

int ReadInt(struct ProblemSet *test);                     //Read the values from the files and passes the input to the test function
int TestCases(struct ProblemSet *test);                  //Performs The test cases


int main (void){
    struct ProblemSet *test; 
    test = malloc(sizeof(struct ProblemSet));  
     int r,t,p;              //r -- read flag  t -- test flag   p -- print flag   
   
    r = ReadInt(test);                          //Read the value from the file
    if(!r)
            printf("Read Operation successful\n");
   
    printf("n=%d\n",test->n);
    
    t=TestCases(test);                      //tests all cases
    if(!t)
        printf("Test case Successful\n");   
  /*      
    p = PrintRes(res);                         //Saves the result and prints it in the file    
    if(!p)
        printf("Print the file succesful")
    return 0;   
*/
}


//Function Reads the value from the input file
int ReadInt(struct ProblemSet *test){
     
    int i;
    FILE *finptr;                       //Initialise the pointer to input file location ---Input.txt--------
    
    
    finptr = fopen("Input.txt","r");    //Open the file in read mode
    if(finptr == NULL){
        printf("Error first file open\n");
        exit(0);
    }
    fscanf(finptr,"%d", &(test->n));                           //Scans the number of test cases to be performed
    printf("in Read\n"); 
    printf("The value of N is %d\n",test->n);
    test->ps = malloc(test->n*sizeof(struct problem));   
    for(i=0;i<test->n;i++){
                        fscanf(finptr,"\n%d %d %d",&(test->ps[i].p),&(test->ps[i].q),&(test->ps[i].r));
                        printf("The value of a,b,c is %d %d %d\n",(test->ps[i].p),(test->ps[i].q),(test->ps[i].r));
    }
    fclose(finptr);
    return 0;
}


//This function performs the test operation of each case
int TestCases(struct ProblemSet *test)
{
    int i;
    FILE *foutptr;                                          //Points to the output file --Destination file --Output.txt
    foutptr = fopen("Output.txt","w");
    if(foutptr == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    for(i=0;i<(test->n);i++)                                        //Finds the value of a,b,c for each test case
    {
        int a,b,c;                  
        a = test->ps[i].p;
        b = test->ps[i].q;
        c = test->ps[i].r;
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
    if(test->n){
        return 0;
    }
}