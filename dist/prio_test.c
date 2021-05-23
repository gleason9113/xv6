#ifdef CS333_P4
#include "types.h"
#include "user.h"

int setPriority(int new_value){
  printf(1, "\n");
  printf(1, "MAXPRIO == %d", MAXPRIO);
  printf(1, " Set priority to: %d\n", new_value);
  int result = setpriority(getpid(), new_value);
  printf(1, "Sleeping briefly- press C-p now to check priority. Then press C-r to check budget and queue. \n");
  printf(1, "If new priority is in range [0, MAXPRIO] and priority is not set, this test FAILS.\n");
  printf(1, "If new priority is out of range [0, MAXPRIO] and priority is set, this test FAILS.\n\n");
  sleep(3 * TPS);
  return result;
}

int
main(void)
{
  int test_val = MAXPRIO - 1;
  if(test_val < 0)
    test_val *= -1;
  printf(1, "Attempt to set priority to negative value (-5).\n");
  if(setPriority(-5) == -1){
    printf(1, "Attempt to set priority to negative value failed. This test PASSED!\n");
  }
  else{
    printf(1, "Attempt to set priority to negative value succeeded. This test FAILED!\n");
  }
  printf(1, "Attempt to set priority to 0.\n");
  if(setPriority(0) == -1){
    printf(1, "Attempt to set priority to 0 failed. This test FAILED!\n");
  }
  else{
    printf(1, "Attempt to set priority to 0 succeeded. This test PASSED! \n");
  }
  printf(1, "Attempt to set priority to MAXPRIO - 1. If MAXPRIO is 0, this will attempt to set priority to 1 (Invalid).\n");
  if(setPriority(test_val) == -1){
    if(MAXPRIO == 0){
      printf(1, "Attempt to set priority higher than MAXPRIO 0 failed. This test PASSED!\n");
    }
    else{
      printf(1, "Attempt to set priority to valid value failed. This test FAILED!\n");
    }
  }
  printf(1, "Attempt to set priority to MAXPRIO + 1.\n");
  if(setPriority(MAXPRIO + 1) == -1){
    printf(1, "Attempt to set priority higher than MAXPRIO failed.  This test PASSED!\n");
  }
  else{
    printf(1, "Attempt to set priority higher tham MAXPRIO succeeded. This test FAILED!|n");
  }
  exit();
}



#endif //CS333_P4
