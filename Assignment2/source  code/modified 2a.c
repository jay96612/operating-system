#include<stdio.h>
#include<signal.h>            // for signal()
#include<sys/types.h>             // header file for fork()
#include<stdlib.h>               // for exit()

void intHandler(int sig)        // interrupt handler function to handle interrupt
{
    // printing interrupt message
    printf("\nInterrupt caught ") ;
    printf("\nso executing  the new user defined  function") ;
//    printf("\nInterupt Signal code:  %d",sig) ;
      printf("\n.\n") ;

    switch(sig)
    {
        case 1:
                printf("Interrupt Signal name : SIGHUP") ;
                 break;
        case 2:
                 printf("Interrupt Signal name : SIGINT") ;
                 break;
        case 3:
                 printf("Interrupt Signal name : SIGQUIT") ;
                 break;	 
        case 4:
                 printf("Interrupt Signal name : SIGILL") ;
                 break;	 
        case 5:
                 printf("Interrupt Signal name : SIGTRAP") ;
                 break;
        case 6: 
                 printf("Interrupt Signal name : SIGABRT") ;
                 break;	 
        case 7:
                 printf("Interrupt Signal name : SIGBUS") ;
                 break;	 
        case 8: 
                 printf("Interrupt Signal name : SIGFPE") ;
                 break;	 
        case 9: 
                 printf("Interrupt Signal name : SIGKILL") ;
                 break;	
        case 10:
                 printf("Interrupt Signal name : SIGUSR1") ;
                 break;
        case 11:
                 printf("Interrupt Signal name : SIGSEGV") ;
                 break;	
        case 12: 
                printf("Interrupt Signal name : SIGUSR2") ;
                 break;	
        case 13: 
                printf("Interrupt Signal name : SIGPIPE") ;
                 break;	
        case 14:
                 printf("Interrupt Signal name : SIGALRM") ;
                 break;	
        case 15:
                printf("Interrupt Signal name : SIGTERM") ;
                 break;
// many more ...

    }


// creating new process by calling fork()

     pid_t x= fork() ;    // calling 

      if(x==0)                          // child process , becoz x=0
    {
        printf("\n\nChild process created ") ;
        printf("\nChild process id =%d",getpid()) ;
        printf("\nParent  process id =%d",getppid()) ;

       exit(0) ;                           // successful termination 
     }
    else if(x>0)                     // parent process , becoz x>0
       {
        printf("\n\nParent process:  ") ;
        printf("\nChild process id =%d",getpid()) ;
        printf("\nParent  process id =%d",getppid()) ;
         exit(0) ;             
       }
       else                           // error
       {
           printf("\n\n child Process not created ") ;
           exit(1) ;                            // unsuccessful termination
       }
}

int main()
{
    system("clear");
    printf("Program running from Main function :\n") ;
    printf("\nsome computation is going on ") ;
    printf("\nyou can press 'ctrl-c' to stop ") ;
    printf("\n.\n") ;
    
int i,j;

 // first argument is signal name(as INTEGER)
 // second argument is function(returns nothing ) to be executed
 // and SIGNAL NAME(code) is passed as argument to the function
 // function may be user defined or predefined   

 // signal () 
 // on success returns the previous value of the signal handler 
// otherwise ERROR as SIG_ERR.

printf("\nPid of process (modified 2a)  =%d\n",getpid()) ;

 // catching interrupt (if any)
 // anyone of signal can be generated accordingly the situations

signal(SIGHUP,intHandler) ;      // 1
signal(SIGINT,intHandler) ;     // 2
signal(SIGQUIT,intHandler) ;    // 3
signal(SIGILL,intHandler) ;    // 4
signal(SIGTRAP,intHandler) ;   // 5
signal(SIGABRT,intHandler) ;   //6
signal(SIGBUS,intHandler)  ;   //7
signal(SIGFPE,intHandler)  ;   //8
signal(SIGKILL,intHandler) ;  //9
signal(SIGUSR1,intHandler) ;  // 10 
signal(SIGSEGV,intHandler) ;  // 11
signal(SIGUSR2,intHandler) ;  // 12
signal(SIGPIPE,intHandler) ;  // 13
signal(SIGALRM,intHandler) ;  // 14
signal(SIGTERM,intHandler) ;  // 15

// some computation goes here
// 

//1.  UNCOMMENT this also to check
    // int y=10,x=0;
    // y=y/x;                     //  we are making user type signal
                                // SIGFPE (FPE=floating point error) error
// 2. You CAN  ALSO TERMINATE killing the process from other terminal
// first know pid of this process by command

// pgrep executable_file_name_of_this_code
 
 // and then
// kill x    // where x is pid of this code (as output from above comand) 

// another example of signal

 for(i=1;i<=1000000;i++)
 for(j=1;j<=10000;j++); 

  // press ' ctrl-c ' for SIGINT type error


//if there is no interrupt then below lines will be executed 
    printf("\nAll computation done in  main function ") ;
    printf("\nso Now returning from main function") ;
    return 0;
 }