#include "types.h"
#include "user.h"

int
main(){
  int pid = 0;
  printf(1, "This program will fork 10 child processes, which will loop forever. \n");
  printf(1, "Before running this test, ensure that DEFAULT_BUDGET and TICKS_TO_PROMOTE are set at high values.\n");
  printf(1, "Five of the child processes will be assigned to Priority MAXPRIO - 1.\n");
  printf(1, "The rest will receive the default priority (Max).\n");
  printf(1, "While these are running, use C-r to examine the scheduler activity.\n");
  /*
  if(MAXPRIO <= 0){
    printf(2, "MAXPRIO must be greater than 0!\n");
    exit();
  }
  */
   pid = fork();

  if(pid < 0){
    printf(2, "Fork failure!\n");
    exit();
  }
  if(pid == 0){
    int j = 0;
    setpriority(getpid(), MAXPRIO - 1);
    while(1){
      j++;
    }
    exit();
    }
    else{
      wait();
    }
    exit();
 } 
  
