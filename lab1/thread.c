//Jaxon Brown
/* 
Explain what pthread is doing in this program. Be specific.

In tis program pthread is creating a 2nd thread independent from the main called child_thread, the sleeper thread. The thread is created using pthread_create(). This sleeper thread runs an infinite loop until enter is pressed, which cancels the thread using pthread_cancel(). The main thread then waits for the child thread to exit using the pthread_join() function, which blocks until the child thread has terminated. This ensures that the child thread has been properly terminated before the program exits.


Explain why the sleeping thread can print its periodic messages while the main thread is waiting for keyboard input.

Because the sleeping thread is running independently of the main thread. While the main thread is blocked waiting for user input, the sleeping thread is able to continue running and printing its messages.
*/


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


static void *child(void *ignored){
  while (1){
   sleep(3);
   printf("Child Slept 3 seconds.\n");
  }  
  return NULL;
}

int main(int argc, char *argv[]){
   pthread_t child_thread;
   int code;
   code = pthread_create(&child_thread, NULL, child, NULL);
   if(code){
      fprintf(stderr, "pthread_create failed with code %d\n", code);
   }
   getchar();
   printf("Enter Pressed\n"); 
  
   pthread_cancel(child_thread);
   pthread_join(child_thread,NULL);

  
   sleep(5);
   printf("Child Killed 5 seconds\n");
   sleep(5);
   printf("Parent Slept 5 seconds.\n");
   return 0;
}