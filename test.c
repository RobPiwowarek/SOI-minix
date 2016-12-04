#include <stdio.h>
#include <stdlib.h>
#include <lib.h>
#include <unistd.h>
#include <limits.h>

int getgroup(int pid);
void setgroup(int pid, int group);

int getgroup(int pid){
message m;
m.m1_i1 = pid;
printf("PID: %d \n", pid);
return _syscall(MM, GETGROUP, &m);
}

void setgroup(int pid, int group){
message m;
m.m1_i1 = pid;
m.m1_i2 = group;
_syscall(MM, SETGROUP, &m);
}

int main(int argc, char* argv[]){

pid_t pid = getpid();

int group;

int i = 1;

if (argc != 2)
{
printf("Invalid arguments: %s \n", argv[0]);
return 0;
}

group = getgroup(pid);

printf("Process pid (%d) group: %d \n", pid, group);

group = argv[1][0] - '0';

printf("NEW GROUP: %d \n", group);

if (group < 0 || group > 3){
printf("Wrong group index\n");
return 0;
}

printf("Group changed to %d \n", group);
setgroup(pid, group);

group = getgroup(pid);
printf("Process pid (%d) group: %d\n", pid, group);

while(i < INT_MAX){
++i;
}

printf("Process pid (%d) group: %d FINISHING\n", pid, group);

return 0;
}

