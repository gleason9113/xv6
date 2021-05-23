#include "types.h"
#include "user.h"

int
main(){
  int pid;

  printf(1, "This program verifies that getpriority() returns the correct priority.\n");

  pid = getpid();
  printf(1, "For PID %d (this proc), getpriority() returned:  %d\n", pid, getpriority(pid));
  printf(1, "Pausing, check priority with C-p now.\n");
  sleep(3 *TPS);
  printf(1, "Now testing getpriority with PID 2 (sh).\n");
  printf(1, "For PID 2, getpriority returned: %d\n", getpriority(2));
  printf(1, "Pausing, check priority with C-p now.\n");
  sleep(3 *TPS);
  printf(1, "Now testing getpriority with PID 124 (Invalid).\n");
  printf(1, "For PID 124, getpriority returned: %d\n", getpriority(124));
  printf(1, "Test complete!\n");
  exit();
}

