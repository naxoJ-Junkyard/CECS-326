//Jaxon Brown



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