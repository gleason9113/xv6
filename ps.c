#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"
//Define the header to be used in output
#define HEAD "\nPID\tName         UID\tGID\tPPID\tElapsed\tCPU\tState\tSize\n"


int
main(int argc, char* argv[])
{
  int max;
  if(argv[1] == NULL){
    max = 64;
  }
  else{
    max = atoi(argv[1]);
  }
  struct uproc* table;
  table = (struct uproc*) malloc(max * sizeof(struct uproc));
  int procs = getprocs(max, table);
  printf(1, "procs: %d\n", procs);
  if(procs < 0){
    printf(2, "An unknown error occurred!\n");
    exit();
  }
  else{
    printf(1, HEAD);
    struct uproc* p = table;
    while(p <= &table[max - 1] && procs > 0){
      uint cpu_total = p->CPU_total_ticks;
      uint cpu_secs = cpu_total/1000;
      uint cpu_frac = cpu_total % 1000;
      uint el_secs = p->elapsed_ticks/1000;
      uint el_frac = p->elapsed_ticks % 1000;
      uint n_len = strlen(p->name);
      n_len = 13 - n_len;
      printf(1, "%d\t%s", p->pid, p->name);
      for(int i = 0; i < n_len; ++i){
        printf(1, " ");
      }
      printf(1, "%d\t", p->uid);
      if(p->uid < 100){
        printf(1, "\t");
      }
      printf(1, "%d\t", p->gid);
      printf(1, "%d\t%d.%d", p->ppid, el_secs, el_frac);
      if(el_frac < 10){
        printf(1, "%s\t", "00");
      }
      else if(el_frac < 100){
        printf(1, "%s\t", "0");
      }
      else{
        printf(1, "\t");
      }
      printf(1, "%d.%d\t%s\t%d\t", cpu_secs, cpu_frac, p->state, p->size);
      printf(1, "\n");
      p++;
      --procs;
    }
  }
  printf(1, "\n");
  free(table);
  exit();
}

    




#endif //CS333_P2
