#ifdef CS333_P4
#include "types.h"
#include "user.h"
#include "pdx.h"

int
main(int argc, char *argv[])
{
  int pid, max;
  unsigned long x = 0;
  if(argc == 1){
    printf(2, "Enter number of processes to create!\n");
    exit();
  }

  max = atoi(argv[1]);

  for (int i = 0; i < max; i++){
    sleep(2 * TPS);
    pid = fork();
    if(pid < 0) {
      printf(2, "Fork failed! \n");
      exit();
     }

     if(pid == 0) {
       sleep(getpid() * TPS);
       do {
         x += 1;
       } while (1);
       printf(1, "Child %d exiting\n", getpid());
       exit();
     }
  }

  pid = fork();
  if(pid == 0) {
    sleep(5);
    do {
      x = x + 1;
    }while(1);
  }

  sleep(200 * TPS);
  wait();
  printf(1, "Parent exiting!\n");
  exit();
}
#endif //CS333_P4

//Source:  https://web.cecs.pdx.edu/~markem/CS333/handouts`
