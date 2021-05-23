#include "types.h"
#include "user.h"

int
main(void){
  int pid;
  int x = 0;
  pid = fork();
  if(pid < 0){
    exit();
  }
  if(pid == 0){
    while(1){
      sleep(1 * TPS);
      x = x + 1;
    }
  }
  if(pid > 0){
    wait();
  }
  exit();
}


