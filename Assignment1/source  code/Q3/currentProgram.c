// To compile : 
// gcc newProgram.c -o newProgram
// gcc currentProgram.c -o currentProgram

// TO run : 
// ./currentProgram


#include<sys/wait.h> 
#include<stdio.h>
#include<string.h>
#include<sys/types.h>             // header file for fork()
#include<stdlib.h>
//#define size 5
int main(int argc,char *argv[])
{
    char buffer[100];   

    pid_t x=fork();                // fork() calling
    
    int status,child_pid,i;

    char *args[]={"newProgram.c","First","Second","Third","FOur","FIve",NULL};

   // printf("\nParent enter for waiting state"); // DON"T USE printf here 

    if(x==0)              // child process
    {
        printf("\n\nChild process created ");
        printf("\nChild process id =%d",getpid());
        
        printf("\nNow child process start to execute a new program: \n");
        // any job goes here 
        // newProgram is new object file of newProgram.c
        // i.e object file after
        // gcc -o newProgram newProgram.c

         execv("./newProgram",args); 

// if error then only below code will run
// because execv() is for running different program rather than this one.
// so if other executes successfully then why below will going to execute.

// check for error
        perror("execv");

        printf("\nError in executing new program.");
      //  printf("\nThis may be by following reasons: ");
       // printf("\n1. file Path not found or");
       // printf("\nError in new program file");

// This status is reported by 'WEXITSTATUS'

        exit(1);   // abnormal execution
     } 
    else if(x>0)
       {
        // file discriptor : (integer value of opened file for process)
      
         sprintf(buffer,"\nParent enter for waiting state");   
         write(1,buffer,strlen(buffer));

    //   printf("\nParent enter for waiting state");  DON"T USE printf here 
      
         child_pid=wait(&status);        // return completed process id 

        printf("\n\nparent detect that child process (pid=%d) was done ",child_pid);
        

    //    exit(0);             
       }
       else
       {
           printf(buffer,"\n\n child Process not created ");
           exit(1);                            // unsuccessful termination
       }

//Now for WIFEXITED

 if(WIFEXITED(status))
 printf("\nExit status by child process : %d\n",WEXITSTATUS(status));

return 0;
}
