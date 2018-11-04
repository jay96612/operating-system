// Demonstration of fork() systme call.
// why fork();     
// TO CREATE NEW PROCESS 

// whenever a system call fork() 
//then it creates a process which becomes the child process of the caller.
// So caller process i.e parent process

// Now both process starts executing instruction from where fork() is called

// SO to distuinguish child from parent we check return value of fork()

// if fork() returns a negative value ,the child process not cretaed.
//fork() returns 0 to the newly created child process.
//fork() retruns POSITIVE value(>0) ,the process id of child process to the PARENT PROCESS. 

// to get child process id : getpid();
// to get parent process id : getppid();

// exit(0)      : means normal termination of program
// exit(1)      : means abnormal termination of program


#include<stdio.h>
#include<sys/types.h>             // header file for fork()
#include<stdlib.h>
int main()
{
    pid_t x=fork();
    
    if(x==0)    // child 
    {
        printf("\nChild process created ");
        printf("\nChild process id =%d",getpid());
        printf("\nParent  process id =%d",getppid());
           printf("\n");
        exit(0);                                   // successful termination 
     }
    else if(x>0)    // parent 
       {
        printf("\nParent process:  ");
        printf("\nChild process id =%d",getpid());
        printf("\nParent  process id =%d",getppid());
           printf("\n");
        exit(0);             
       }
       else
       {
           printf("\n\n child Process not created ");
           exit(1);                            // unsuccessful termination
       }


       return 0;
}
