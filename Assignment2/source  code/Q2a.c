#include<stdio.h>
#include<signal.h>            // for signal()
#include<sys/types.h>             // header file for fork()
#include<stdlib.h>               // for exit()

void intHandler(int sig)        // interrupt handler function to handle interrupt
{
    // printing interrupt message
    printf("\nInterrupt caught ");
    printf("\nso executing  the new user defined  function");
    printf("\nInterupt Signal code:  %d",sig);
    printf("\n.\n");

// creating new process by calling fork()

     pid_t x= fork();    // calling 

      if(x==0)                          // child process , becoz x=0
    {
        printf("\n\nChild process created ");
        printf("\nChild process id =%d",getpid());
        printf("\nParent  process id =%d",getppid());

       exit(0);                           // successful termination 
     }
    else if(x>0)                     // parent process , becoz x>0
       {
        printf("\n\nParent process:  ");
        printf("\nChild process id =%d",getpid());
        printf("\nParent  process id =%d",getppid());
         exit(0);             
       }
       else                           // error
       {
           printf("\n\n child Process not created ");
           exit(1);                            // unsuccessful termination
       }
}
int main()
{
    printf("Program running from Main function :\n");
    printf("\nsome computation is going on ");
    printf("\nyou can press 'ctrl-c' to stop ");
    printf("\n.\n");
    
int i,j;

 // first argument is signal name(as INTEGER)
 // second argument is function(returns nothing ) to be executed
 // and SIGNAL NAME(code) is passed as argument to the function
 // function may be user defined or predefined   

 // signal () 
 // on success returns the previous value of the signal handler 
// otherwise ERROR as SIG_ERR.
 
   signal(SIGINT,intHandler);    // catching interrupt (if any)          

// some computation goes here
// 
    for(i=1;i<=1000000;i++)
    for(j=1;j<=10000;j++);

//if there is no interrupt then below lines will be executed 
    printf("\nAll computation done in  main function ");
    printf("\nso Now returning from main function");
    return 0;
}
