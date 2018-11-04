#include<stdio.h>
#include<signal.h>            // for signal()
#include<sys/types.h>             // header file for fork()
#include<stdlib.h>               // for exit()

int main(int argc,char *argv[])
{
    // argv[0] : program name 
    // argc =total no of arguments

    // extracting into integer

    int pid=atoi(argv[1]);   // atoi converts string into number,
                             // for error checking(string is int or not) use other 
   int sigId;
// checking for 'signal id'  
if(strcmp("SIGHUP",argv[2])==0)
sigId=SIGHUP;
else if(strcmp("SIGINT",argv[2])==0)
sigId=SIGINT;
else if(strcmp("SIGQUIT",argv[2])==0)
sigId=SIGQUIT;
else if(strcmp("SIGILL",argv[2])==0)
sigId=SIGILL;
else if(strcmp("SIGTRAP",argv[2])==0)
sigId=SIGTRAP;
else if(strcmp("SIGABRT",argv[2])==0)
sigId=SIGABRT;
else if(strcmp("SIGBUS",argv[2])==0)
sigId=SIGBUS;
else if(strcmp("SIGFPE",argv[2])==0)
sigId=SIGFPE;
else if(strcmp("SIGKILL",argv[2])==0)
sigId=SIGKILL;
else if(strcmp("SIGUSR1",argv[2])==0)
sigId=SIGUSR1;
else if(strcmp("SIGSEGV",argv[2])==0)
sigId=SIGSEGV;
else if(strcmp("SIGUSR2",argv[2])==0)
sigId=SIGUSR2;
else if(strcmp("SIGPIPE",argv[2])==0)
sigId=SIGPIPE;
else if(strcmp("SIGALRM",argv[2])==0)
sigId=SIGALRM;
else if(strcmp("SIGTERM",argv[2])==0)
sigId=SIGTERM;

printf("\n\nsignal Id : %d\n",sigId);

    printf("\nProcess id of modified Q2a.c is %d",pid);
  // printf("\nSignal Id : %d",sigId);
    printf("\nCalling kill() to kill the process having id :%d \n",pid);
    
// You can send any signal from here 
// that will display in your 'modified Q2a.c' if you have written for that signal 
// otherwise default intHandler  will be called for that    

    kill(pid,sigId);  // It will kill the process having id : pid
                       // and execute the intHandler function for 'SIGINT' signal
                       // you can pass any signal here  

                      

int i,j;    
for(i=1;i<100000;i++)
for(j=1;j<100000;j++);

return 0;
}