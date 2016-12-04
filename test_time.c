#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

void settime(int group, int time){
message m;
printf("GROUP: %d TIME: %d \n", group, time);

m.m1_i1 = group;
m.m1_i2 = time;

_syscall(MM, SETTIME, &m);
}

int gettime(int group){
message m;
m.m1_i1 = group;

return _syscall(MM, GETTIME, &m);
}

int main(void){

int group = 0;
int time = 0;

printf("Enter group index (0 - 2): ");
scanf("%d", &group);
printf("\n");
printf("Enter new time: ");
scanf("%d", &time);
printf("\n");

printf("Current time: %d \n", gettime(group));
settime(group, time);
printf("New time: %d \n", gettime(group));

return 0;
}
