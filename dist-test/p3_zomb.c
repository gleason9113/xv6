#ifdef CS333_P3
#include "types.h"
#include "user.h"

//Test ZOMBIE list
//Process will fork.
//Parent will wait 30secs
//Child will exit immediately.
//Use ctrl-z to examine ZOMBIE list.

int 
main(void)
{
  printf(1, "This process will pause briefly. Press ctrl-p and ctrl-z now.\n");
  sleep(6 * TPS);
  printf(1, "This process will now fork. Child will exit. Parent will sleep. Press ctrl-z now.\n");
  int pid;
 
  pid = fork();

  if(pid < 0){
    printf(2, "Error when forking!\n");
    exit();
  }
  if(pid == 0){
    exit();
  }
  if(pid > 0){
    sleep(30 * TPS);
  }
  printf(1, "All processes exiting! \n");
  exit();
}

#endif //CS333_P3
