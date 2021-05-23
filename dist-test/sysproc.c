#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#ifdef PDX_XV6
#include "pdx-kernel.h"
#endif // PDX_XV6
#ifdef CS333_P2
#include "uproc.h"
#endif //CS333_P2

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      return -1;
    }
    sleep(&ticks, (struct spinlock *)0);
  }
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  xticks = ticks;
  return xticks;
}

#ifdef PDX_XV6
// shutdown QEMU
int
sys_halt(void)
{
  do_shutdown();  // never returns
  return 0;
}
#endif // PDX_XV6

#ifdef CS333_P1
int
sys_date(void)
{
  struct rtcdate *current_date;
  if(argptr(0, (void*)&current_date, sizeof(struct rtcdate)) < 0)
    return -1;
  cmostime(current_date);
  return 0;
}
#endif //CS333_P1

#ifdef CS333_P2
uint
sys_getuid(void)
{
  return myproc()->uid;
}

uint 
sys_getgid(void)
{
  return myproc()->gid;
}

uint
sys_getppid(void)
{
  if(!myproc()->parent)
    return myproc()->pid;
  else
    return myproc()->parent->pid;
}

int
sys_setuid(void)
{
  int n;
  argint(0, &n);
  if(n < 0 || n > 32767)
    return -1;
  myproc()->uid = n;
  return 0;
}

int
sys_setgid(void)
{
  int n;
  argint(0, &n);
  if(n < 0 || n > 32767)
    return -1;
  myproc()->gid = n;
  return 0;
}

int
sys_getprocs(void)
{
  int max;
  int copied;
  argint(0, &max);
  if(max < 1){
    return -1;
  }
  struct uproc* table;
  if(argptr(1, (void*)&table, (sizeof(struct uproc) * max)) <0){
    return -1;
  }
  copied = getProcs(max, table);
  return copied;
}
#endif //CS333_P2
#ifdef CS333_P4
int
sys_getpriority(void)
{
  int pid;
  int priority;
  argint(0, &pid);
  if(pid < 1 || pid > NPROC) //Change this to the constant!!!
    return -1; //Invalid PID was provided
  priority = getPriority(pid); //Returns -1 if process is UNUSED or no process matching the PID exists
  return priority; 
}

int
sys_setpriority(void)
{
  int pid, priority, new_priority;
  argint(0, &pid);
  argint(1, &priority);
  if(pid < 1)
    return -1; //Invalid PID
  if(priority < 0 || priority > MAXPRIO)
    return -1; //Invalid priority
  new_priority = setPriority(pid, priority); //setPriority returns -1 for errors, otherwise returns new priority value
  if(new_priority >= 0){
    return 0; //Success
  }
  return -1; //failure
}
#endif //CS333_P4

