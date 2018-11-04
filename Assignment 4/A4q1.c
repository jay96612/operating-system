// header files
    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <unistd.h>

    int main()
    {
       char c;
       struct flock lock; 
       
       int fd=open("file1.txt",O_RDWR);     // opening file 
       
       if(fd<0) // error checking
       {
         printf("ERROR in opening file");
         exit(1);
       }
       
       printf("\nFile is opening ..");
       
       printf("\nFILE is opened ");
       
       printf("\nHit enter to lock the file ");
       getchar();
       printf("\nWrite lock is applied \n");
       // setting flock structure
       lock.l_type=F_WRLCK;          // type of lock
       lock.l_start=0;              // starting offset for lock
       lock.l_whence=SEEK_SET;      // from where 
       lock.l_len=0;                // length of bytes to lock
       // error checking
       if(fcntl(fd,F_SETLK,&lock)<0)        // checking for error
       {
        printf("\nFailed to lock ");
        while(fcntl(fd,F_SETLK,&lock)<0);
       
       }
       printf("\n Reading from file \n File content :- \n");
       
       while(read(fd,&c,1))      // one by one 
       printf("%c",c);
       
       printf("\nHit enter to unlock");  
       getchar();
       // unlcoking
       lock.l_type=F_UNLCK;                 // unlocking the file 
       lock.l_start=0;
       lock.l_whence=SEEK_SET;
       lock.l_len=0;
       
        if(fcntl(fd,F_SETLK,&lock)<0)         // checking for error
       {
        perror("\nFailed to unlock ");
       }
       
       if(close(fd)<0)
       { 
        perror("\nerror ");
        exit(1);
       }
         printf("\nFile closed");
       
      } 
