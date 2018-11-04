// header files
#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

#define maxSize 100
// signal handler
void intHandler(int sigId)
{    printf("\nSignal Id : %d\n",sigId);   // print signal id
    // printf(" ");     
        char str[maxSize];
        int f,pid,term;
        int fd[2],x,d;
        int i,a=0,b=1,c=0;
        if (pipe(fd) < 0)
        {   printf("Error in pipe calling");
            exit(1);
        }
        f=fork(); // fork call
        if(f<0)
        {
            printf("\nchild process not created\n");
            exit(1);
        }
        else if(f==0)  // child process
    {
        pid=getpid(); // process id
        printf("\nchild process:\nchild process ID=%d",pid);
        sprintf(str,"%d",pid); // int to string
        write(fd[1],str,maxSize); // writing pid

        printf("\nHow many terms for fibbonacci numbers:  ");
        scanf("%d",&term);
            
            close(fd[0]);
            
            for(i=1;i<=term;i++)
            {
                sprintf(str,"%d",c); // int to str
                write(fd[1],str,maxSize); // writeing fibbo num
                c=a+b;a=b;b=c;               
            }
            exit(0);
    }
     else        // parent process
    {   int status;
        int childProcessId=wait(status); // return completed child's pid 
        close(fd[1]);
        int tempPid;
        read(fd[0], str, maxSize);// reading pid
        sscanf(str,"%d",&tempPid); // str to int
        printf("\nparent process:\nchild Process id=%d",tempPid);
        printf("\nfibbonacci numbers : ");
        int temp;
    
        while ((d=read(fd[0], str, maxSize)) > 0) // reading fibo num
    {  
        sscanf(str,"%d",&temp); // str to int
        printf("%d ",temp);
    } 
    printf("\n");

        if (d != 0)
        exit(1);
        exit(0);
    }       
}
int main()
{
  
 // first argument is signal name(as INTEGER)
 // second argument is function(returns nothing ) to be executed
 // and SIGNAL NAME(code) is passed as argument to the function
 // function may be user defined or predefined   

 // signal () 
 // on success returns the previous value of the signal handler 
 // otherwise ERROR as SIG_ERR.
 
   signal(SIGINT,intHandler);    // catching interrupt for 'ctrl+c'       

int i,j,k=1;
printf("You can give interrupt \ ( 'ctrl+c' \ ): \n");
// some computation goes here
    for(i=1;i<=1000000;i++)
    for(j=1;j<=10000;j++);

//if there is no interrupt then below lines will be executed 
    printf("\nAll computation done in  main function ");
    printf("\nso Now returning from main function");
    return 0;
}
