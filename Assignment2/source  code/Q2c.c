#include<stdio.h>
#include<pthread.h>            // header file for thread 

// return type void 
void * func1(void * x)
{
    printf("HELLO WORLD\n");
}

int main()
{
    pthread_t pt1;
// 1st : address of 
// 2n   : attribute
// 3rd : address of function to execute
// 4th : arguments
    pthread_create(&pt1,NULL,&func1,NULL);      
    printf("From main thread \n");

// wait for new created thread to execute
    pthread_join(pt1,NULL);
   return 0;
}