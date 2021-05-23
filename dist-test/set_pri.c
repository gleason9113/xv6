#include "types.h"
#include "user.h"

int
main(){
  int pid = -1;
  printf(1, "This program tests the effect of setpriority calls on process budget.\n");
  printf(1, "Before running, ensure that loopforever is running with 5+ processes.\n");
  if(MAXPRIO < 4){
    printf(2, "MAXPRIO must be greater than 4 for this test.\n");
    printf(2, "Current MAXPRIO: %d\n", MAXPRIO);
    exit();
  }

  //Find a valid process ID to work with
  for(int i = 6; i < 20; ++i){
    if(getpriority(i) != -1){
      pid = i;
      break;
    }
  }

  printf(1, "Process ID %d selected. Check process budget and queue now with C-r.\n", pid);
  sleep(5 * TPS);
  printf(1, "Setting priority to 2 now.\n");
  if(setpriority(pid, 2) == -1){
    printf(2, "Setting priority failed! \n");
    exit();
  }
  printf(1, "Priority now set to 2.  Verify that process is in correct queue using C-r.\n");
  printf(1, "Verify that budget is now %d (default value).\n", DEFAULT_BUDGET);

  sleep(5 * TPS);
  printf(1, "Setting PID %d through PID %d to priority 0.\n", pid, (pid + 4));
  printf(1, "Then resetting PID %d through PID %d to same priority.\n", (pid + 1), (pid + 4));
  printf(1, "Use C-r to verify that process order is unchanged.\n");

  for(int i = pid; i <= pid + 4; ++i){
    if(setpriority(i, 0) == -1){
    printf(2, "Setting priority failed! \n");
    exit();
    }
  }
  printf(1, "Press C-r now.\n");
  sleep(5 * TPS);
  printf(1, "Setting priority for PID %d to %d to the current value (%d).\n", pid + 4, pid + 1, getpriority(pid + 1));
  for(int i = pid + 4; i >= pid + 1; --i){
    if(setpriority(i, getpriority(i)) == -1){
    printf(2, "Setting priority failed! \n");
    exit();
    }

  }
  printf(1, "Press C-r again.\n");
  sleep(5 * TPS);


  printf(1, "Test complete!\n");
  exit();
}
