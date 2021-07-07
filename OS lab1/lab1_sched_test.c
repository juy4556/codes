/*
*    DKU Operating System Lab
*        Lab1 (Scheduler Algorithm Simulator)
*        Student id : 32173437
*        Student name : Lee Jun Seok
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm test code.
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#include <string.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>

#include "lab1_sched_types.h"

/*
 * you need to implement scheduler simlator test code.
 *
 */

int main(int argc, char* argv[]) {
    int n;
    int level;
    int Arrival, Service;
    printf("Number of Process: ");
    scanf_s("%d", &n);
    if (n < 1)return -1;
    process* processes = (process*)malloc(sizeof(process) * n);
    printf("Number of Queue-level: ");
    scanf_s("%d", &level);
    flag = true;
    for (int i = 0; i < n; i++) {
        printf("process%d's Arrival Time, Service Time: ", i);
        scanf_s("%d %d", &Arrival, &Service);
        Set_Process(processes + i, i, Arrival, Service);
    }
    Sort(processes, 0, n - 1);//Sort by Arrival Time

    Print_Scheduling_FCFS(processes, n);


    free(processes);
    processes = 0;
    return 0;
}








