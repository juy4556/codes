/*
*    DKU Operating System Lab
*        Lab1 (Scheduler Algorithm Simulator)
*        Student id : 32173437
*        Student name : Lee Jun Seok
*
*   lab1_sched_types.h :
*       - lab1 header file.
*       - must contains scueduler algorithm function's declations.
*
*/

#ifndef _LAB1_HEADER_H
#define _LAB1_HEADER_H
#include <stdbool.h>
/*
 * You need to Declare functions in  here
 */

bool flag;
typedef struct bool_node {
    bool data;
    struct bool_node* next;
}bool_node;

typedef struct {
    bool_node* head;
}bool_queue;

typedef struct process {
    int Process;//process num
    int Arrival_T;
    int Service_T;
    int Remain_T;
    int Use_T;
    int Ticket;
    int priority;
    struct process* next;
}process;

typedef struct {
    process* front;
    process* rear;
}process_queue;

int square(int x, int y);

void Push_CPU_Queue(bool_queue* q, bool data);
bool Pop_CPU_Queue(bool_queue* q, bool* use);
void Bool_CPU_init(bool_queue* q);

//process
void Sort(process* p, int left, int right);
void init_process_state(process* p, int n);
void Set_Process(process* p, int process, int Arrival_T, int Service_T);

//queue
void Process_Queue_Init(process_queue* q);
bool Search_Queue(process_queue* q, process* p);
void Push_Process_Queue(process_queue* q, process* p);
process* Pop_Certain(process_queue* q, process* p);
process* Pop_Queue(process_queue* q);

//Scheduling
process* FCFS(process_queue* q);
process* RR(process_queue* q, int tiemquantum, process* cur);
process* SJF(process_queue* q);
process* MLFQ(process_queue* q, process* cur, int max_level, int(*timequantum)(int, int));
process* Lottery(process_queue* q);

//Print
void Print_CPU_Use(bool_queue* queue, int num);
void Print_Scheduling_FCFS(process* p, int num);
void Print_Scheduling_RR(process* p, int num, int timequantum);
void Print_Scheduling_SJF(process* p, int num);
void Print_Scheduling_MLFQ(process* p, int num, int max_level, int (*timequantum)(int, int));
void Print_Scheduling_Lottery(process* p, int num);
#endif /* LAB1_HEADER_H*/#pragma once
