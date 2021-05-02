#ifdef CS333_P3
#include "types.h"
#include "user.h"

//Test sleeping process list
//Pauses
//Then forks and sleeps a process- pauses again
//then ends process- pauses again
//During each pause, compare output of ctrl-s

int 
main(void)
{
  int pid;
  printf(1, "Sleeping process- press ctrl-s now. \n");
  sleep(5 * TPS);
  printf(1, "Forking...\n");
  pid = fork();
  if(pid < 0){
    printf(2, "Error when forking!\n");
    exit();
  }
  if(pid == 0){
    printf(1, "Child process sleeping- press ctrl-s now.\n");
    sleep(5 * TPS);
    exit();
  }
  else{
    wait();
    printf(1, "Child process exited. Press ctrl-s now. \n");
    }
  exit();
}

#endif //CS333_P3
