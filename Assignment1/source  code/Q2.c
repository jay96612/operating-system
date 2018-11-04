
#include<sys/wait.h>     // for wait()
#include<stdio.h>
#include<string.h>
#include<sys/types.h>             // header file for fork()
#include<stdlib.h>         // for exit()
#define size 5
int main()
{
    char buffer[100];
  //  printf("\nHello ");
   
    pid_t x=fork();                // fork() calling
    
    int status,child_pid,i;

    if(x==0)              // child process
    {
        printf("\n\nChild process created ");
        printf("\nChild process id =%d",getpid());
        
        printf("\nchild process starts some job: \n");
       
       // any job goes here 

        for(i=1;i<size;i++)
        printf("output= %d\n",i);
        exit(0);                  // successful termination 
     }
    else if(x>0)
       {
           // file discriptor : (integer value of opened file for process)
      
         sprintf(buffer,"\nParent enter for waiting state");   
         write(1,buffer,strlen(buffer));

     //   printf("\nParent enter for waiting state");  DON"T USE printf here 
      
         child_pid=wait(&status);        // return completed process id 

        printf("\n\nparent detect that child process (pid=%d) was done \n\n",child_pid);
        exit(0);             
       }
       else
       {
           printf(buffer,"\n\n child Process not created ");
           exit(1);                            // unsuccessful termination
       }


}
