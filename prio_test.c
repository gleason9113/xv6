#ifdef CS333_P4
#include "types.h"
#include "user.h"

int
main(void)
{
  printf(1, "This program will test the set/get priority syscalls.\n");
  printf(1, "This process will now set its priority to 3 (Valid value).\n");
  int set_result = setpriority(getpid(), 3);
  if(set_result == -1){
    printf(2, "Error setting priority!\n");
    exit();
  }
  printf(1, "Priority set. Sleeping briefly. Press ctrl-p now.\n");
  sleep(3 * TPS);
  printf(1, "Setting priority to invalid value (MAXPRIO + 3)\n");
  set_result = setpriority(getpid(), MAXPRIO + 3);
  if(set_result != -1){
    printf(2, "Invalid priority set! \n");
    exit();
  }
  printf(1, "Press ctrl-p now. Verify that Prio is 3.\n");
  sleep(3 * TPS);
  printf(1, "Setting priority to invalid value (-4).\n");
  set_result = setpriority(getpid(), -4);
  if(set_result != -1){
    printf(2, "Invalid priority set! \n");
    exit();
  }
  printf(1, "Press ctrl-p now. Verify that Prio is 3.\n");
  sleep(3 * TPS);
  printf(1, "Test complete! \n");
  exit();
}

#endif //CS333_P4
