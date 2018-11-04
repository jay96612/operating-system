#include<sys/wait.h> 
#include<stdio.h>
#include<string.h>
#include<sys/types.h>             // header file for fork()
#include<stdlib.h>
//#define size 5
int main(int argc,char *argv[])
{
    printf("\nNow code running from 'newProgram.c' \n");
    printf("\nTotal argument passed : %d\n",argc);
int i;

    printf("Program name: %s\n",argv[0]);

// any code goes here

    for(i=1;i<argc;i++)
    printf("%s\n",argv[i]);   // printing all array of string

// This status is reported by 'WEXITSTATUS'
    exit(0);     // means normal execution
}  