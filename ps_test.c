#ifdef CS333_P2
#include "types.h"
#include "user.h"

//Test ps command with different numbers of running processes
//Takes command line argument for # of processes.
//Forks that # of processes, then sleeps.
//Call ps with command line argument if num of processes != 64

int
main(int argc, char* argv[])
{
  int num_procs;
  int pid = 0;
  if(argv[1] == NULL){
    num_procs = 64;
  }
  else{
    num_procs = atoi(argv[1]);
    if(num_procs < 0){
      printf(1, "Invalid number of processes. Default value of 64 will be used.\n");
      num_procs = 64;
    }
  }
  printf(1, "Num of forks to generate: %d\n", num_procs);
  printf(1, "After forking, this will sleep. Run ps cmd to view output.\n");
  for(int i = 0; i < num_procs; ++i){
    pid = fork();
      if(pid < 0){
        exit();
    }
    else if(pid == 0){
      while(1){
        num_procs++;
      }
    }
    else{
      printf(1, " ");
    }
  }
  if(pid > 0){
    printf(1, "\nRun ps <num of processes> to test. \n");
    wait();
  }
  exit();
}


#endif //CS333_P2
