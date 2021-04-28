#ifdef CS333_P2
#include "types.h"
#include "user.h"

//Test setuid 
//Take int value nval
//Pass to setuid
//For values out of range, setuid should return -1
//Function prints error and returns a negative value
//Else function calls getuid() and prints the returned value
static int 
uidtest(int nval)
{
  uint uid = getuid();
  printf(1, "Current UID: %d\n", uid);
  printf(1, "Setting UID to: %d\n", nval);
  if(setuid(nval) < 0)
  {
    printf(2, "Error: Invalid value %d\n", nval);
    uid = getuid();
    printf(1, "Current UID: %d\n", uid);
    printf(1, "Pausing- press ctrl-p now\n");
    sleep(5 * TPS);
    printf(1, "\n\n");
    return -1;
  }
  uid = getuid();
  printf(1, "Current UID: %d\n", uid);
  printf(1, "Pausing- press ctrl-p now\n");
  sleep(5 * TPS);
  printf(1, "\n\n");
  return uid;
}

//Test setgid
//Take int value
//Pass to setgid
//For values out of range, setgid should return -1
//Function prints error and returns a negative value
//Else function calls getgid() and prints the returned value
static int
gidtest(int nval)
{
  uint gid = getgid();
  printf(1, "Current GID: %d\n", gid);
  printf(1, "Setting GID to: %d\n", nval);
  if(setgid(nval) < 0)
  {
    printf(2, "Error: Invalid value %d\n", nval);
    gid = getgid();
    printf(1, "Current GID: %d\n", gid);
    printf(1, "Pausing- press ctrl-p now\n");
    sleep(5 * TPS);
    printf(1, "\n\n");
    return -1;
  }
  gid = getgid();
  printf(1, "Current GID: %d\n", gid);
  printf(1, "Pausing- press ctrl-p now\n");
  sleep(5 * TPS);
  printf(1, "\n\n");
  return gid;
}

//Test fork() modifications
//Take int value nval
//Set process GID and UID to nval
//fork process
//For child process, compare uid and gid to nval
//Test getppid()- get PID of parent- getppid() of child process
static void
forktest(int nval)
{
  uint uid, gid;
  int pid, ppid;
  pid = getpid();
  printf(1, "Parent: PID = %d\n", pid);
  printf(1, "Test value: %d\n", nval);
  if(setuid(nval) < 0)
  {
    printf(2, "Error: invalid UID %d\n", nval);
    return;
  }
  if(setgid(nval) < 0)
  {
    printf(2, "Error: invalid GID %d\n", nval);
  }
  uid = getuid();
  gid = getgid();
  ppid = getppid();
  printf(1, "Parent- UID: %d, GID: %d, PPID: %d\n", uid, gid, ppid);
  pid = fork();
  if(pid == 0)
  {
    uid = getuid();
    gid = getgid();
    ppid = getppid();
    printf(1, "Child- UID: %d, GID: %d, PPID: %d\n", uid, gid, ppid);
    printf(1, "Pausing- press ctrl-p\n");
    sleep(5 * TPS);
    exit();
  }
  else
    pid = wait();
  printf(1, "\n\n");
  exit();
}

//Run tests
//Test cases for uid, gid are:
//nval < 0 (invalid), nval == 0 (valid), nval == 1400 (valid), nval == 32767 (valid), nval == 40000 (invalid)
//Test cases for forktest are:
//nval == 1400 (valid)
//
static void
runtest(void)
{
  uint nval;

  //Test- nval < 0
  nval = -200;
  printf(1, "Test: setuid with negative value \n");
  if(uidtest(nval) < 0)
  {
    printf(1, "This test PASSES! \n");
  }
  else
  {
    printf(1, "This test FAILS! \n");
  }
  printf(1, "Test: setgid with negative value \n");
  if(gidtest(nval) < 0)
  {
    printf(1, "This test PASSES! \n\n\n");
  }
  else
  {
    printf(1, "This test FAILS! \n\n\n");
  }
  
  //Test- nval == 1400
  nval = 1400;
  printf(1, "Test: setuid with value 1400 \n");
  if(uidtest(nval) == 1400)
  {
    printf(1, "This test PASSES! \n");
  }
  else
  {
    printf(1, "This test FAILS! \n");
  }
  printf(1, "Test: setgid with value 1400 \n");
  if(gidtest(nval) == 1400)
  {
    printf(1, "This test PASSES! \n\n\n");
  }
  else
  {
    printf(1, "This test FAILS! \n\n\n");
  }

  //Test- nval == 0
  nval = 0;
  printf(1, "Test: setuid with value 0 \n");
  if(uidtest(nval) == 0)
  {
    printf(1, "This test PASSES! \n");
  }
  else
  {
    printf(1, "This test FAILS! \n");
  }
  printf(1, "Test: setgid with value 0 \n");
  if(gidtest(nval) == 0)
  {
    printf(1, "This test PASSES! \n\n\n");
  }
  else
  {
    printf(1, "This test FAILS! \n\n\n");
  }

  

  //Test- nval == 32767
  nval = 32767;
  printf(1, "Test: setuid with value 32767 \n");
  if(uidtest(nval) == 32767)
  {
    printf(1, "This test PASSES! \n");
  }
  else
  {
    printf(1, "This test FAILS! \n");
  }
  printf(1, "Test: setgid with value 32767 \n");
  if(gidtest(nval) == 32767)
  {
    printf(1, "This test PASSES! \n\n\n");
  }
  else
  {
    printf(1, "This test FAILS! \n\n\n");
  }
  
  //Test: nval == 40000
  nval = 40000;
  printf(1, "Test: setuid with value 40000 \n");
  if(uidtest(nval) < 0)
  {
    printf(1, "This test PASSES! \n");
  }
  else
  {
    printf(1, "This test FAILS! \n");
  }
  printf(1, "Test: setgid with value 40000 \n");
  if(gidtest(nval) < 0)
  {
    printf(1, "This test PASSES! \n\n\n");
  }
  else
  {
    printf(1, "This test FAILS! \n\n\n");
  }
  
  //Test: forktest, value == 1400

  nval = 1400;
  forktest(nval);
  exit();
}

int
main(void)
{
  printf(1, "\n\n");
  runtest();
  exit();
}

#endif //CS333_P2
