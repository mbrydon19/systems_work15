#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
  printf( "before forking\n");
  int i = fork();
  int f = fork();
  int status;
  if( i && f){
    int child_exited = wait( &status);
    if ( WIFEXITED( status)){
      printf( "child exited pid: %d\n", child_exited);
      printf( "time slept: %d\n", WEXITSTATUS( status));
    }
    printf( "parent process done\n");
    exit(0);
  }
  else{
    printf( "child pid: %d\n", getpid());
    srand( time(NULL) );
    int sleep_time = rand() % 15 + 5;
    sleep( sleep_time);
    printf( "child process done\n");
    return sleep_time;
  }
      return 0;

}
  
