#ifdef CS333_P2
#include "types.h"
#include "user.h"

int 
main(int argc, char* argv[])
{
  uint start, end, total, secs, msecs;
  start = uptime();
  int id = fork();
  if(id < 0){
    exit();
  }
  else if(id == 0){
    exec(argv[1], argv+1);
  }
  else{
    wait();
    end = uptime();
    total = end - start;
    secs = total / TPS;
    msecs = total % TPS;
    printf(1, "%s ran in %d.%d secs \n", argv[1], secs, msecs);
  }
  exit();
}

#endif //CS333_P2
