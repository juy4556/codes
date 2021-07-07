/*
*    DKU Operating System Lab
*        Lab1 (Scheduler Algorithm Simulator)
*        Student id : 32173437
*        Student name : Lee Jun Seok
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
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
 * you need to implement FCFS, RR, SPN, SRT, HRRN, MLFQ scheduler.
 */

int square(int x, int y) {
    if (y == 0)
        return 1;
    else {
        for (int i = 1; i < y; i++)
            x *= x;
    }
    return x;
}
void Push_CPU_Queue(bool_queue* q, bool data) {
    bool_node* temp = (bool_node*)malloc(sizeof(bool_node));
    temp->data = data;
    temp->next = 0;
    bool_node* first;
    if (q->head == NULL) {
        q->head = temp;
    }
    else {
        first = q->head;
        while (first->next) {
            first = first->next;
        }
        first->next = temp;
    }
    return;
}

bool Pop_CPU_Queue(bool_queue* q, bool* use) {
    bool_node* first;
    if (q->head == NULL)
        return false;
    //q->head !=NULL
    else {
        *use = q->head->data;
        first = q->head;
        q->head = q->head->next;
        free(first);
        return true;
    }
}
void Bool_CPU_init(bool_queue* q) {
    bool_node* first;
    while (q->head != NULL) {
        first = q->head;
        q->head = q->head->next;
        free(first);
        first = NULL;
    }
}

void Sort(process* p, int left, int right) {
    int i = left;
    int j = right;
    process pivot = p[(left + right) / 2];
    do {
        while (pivot.Arrival_T > p[i].Arrival_T)
            i++;
        while (pivot.Arrival_T < p[j].Arrival_T)
            j--;
        if (i <= j) {
            process temp = p[i];
            p[i] = p[j];
            p[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) Sort(p, left, j);
    if (right > i) Sort(p, i, right);
}
void init_process_state(process* p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        p[i].Use_T = 0;
        p[i].Remain_T = p[i].Service_T;
        p[i].priority = 0;
        p[i].Ticket = p[i].Service_T;
        p[i].next = 0;
    }
}

void Set_Process(process* p, int process, int Arrival_T, int Service_T) {
    p->Process = process;
    p->Arrival_T = Arrival_T;
    p->Service_T = Service_T;
    p->Use_T = 0;
    p->Remain_T = Service_T;
    p->priority = 0;
    p->Ticket = Service_T;
    p->next = 0;
}

void Process_Queue_Init(process_queue* q) {
    q->front = q->rear = 0;
}
void Push_Process_Queue(process_queue* q, process* p) {
    if (!q->front)
        q->front = q->rear = p;
    else {
        q->rear->next = p;
        q->rear = p;
    }
}
process* Pop_Queue(process_queue* q) {
    if (!q->front)
        return 0;
    else {
        process* temp = q->front;
        if (q->front == q->rear) q->front = q->rear = 0;
        else q->front = q->front->next;
        temp->next = 0;
        return temp;
    }
}
bool Search_Queue(process_queue* q, process* p) {
    if (p == 0)return false;
    for (process* i = q->front; i; i = i->next) {
        if (p == i) return true;
    }
    return false;
}

process* Pop_Certain(process_queue* q, process* p) {
    process* temp = 0;
    process* pre = q->front;
    process* cur = 0;
    for (cur = q->front; cur; cur = cur->next) {
        if (cur == p) {
            if (cur == q->front)
                return Pop_Queue(q);
            else {
                temp = cur;
                pre->next = cur->next;
                temp->next = 0;
                return temp;
            }
        }
        pre = cur;//pre->next is cur
    }
    return 0;
}

void Print_CPU_Use(bool_queue* queue, int num) {
    bool using;
    for (int i = 0; i < num; i++) {
        printf("process%d: ", i);
        while (Pop_CPU_Queue(queue + i, &using)) {
            if (using) printf("бс ");
            else printf("бр ");
        }
        putchar('\n');
        Bool_CPU_init(queue + i);
    }
}
process* FCFS(process_queue* q) {
    process* temp;
    temp = q->front;
    if (!temp)return 0;
    temp->Use_T++;
    temp->Remain_T--;
    if (temp->Remain_T == 0)
        Pop_Queue(q);

    return temp;
}
void Print_Scheduling_FCFS(process* p, int num) {
    process* cur, * next;
    bool_queue* CPU_using;
    process_queue p_queue;
    CPU_using = (bool_queue*)malloc(sizeof(bool_queue) * num);
    Process_Queue_Init(&p_queue);
    for (int i = 0; i < num; i++) {
        CPU_using[i].head = NULL;
    }
    cur = 0;
    next = p;
    for (int time = 0; 1; time++) {
        while (next->Arrival_T == time) {
            Push_Process_Queue(&p_queue, next);
            next++;
        }
        cur = FCFS(&p_queue);
        if (!cur)break;
        int p_id = cur->Process;
        for (int i = 0; i < num; i++) {
            Push_CPU_Queue(&CPU_using[i], i == p_id);
        }
    }
    printf("FCFS\n");
    Print_CPU_Use(CPU_using, num);
    init_process_state(p, num);
    free(CPU_using);
    CPU_using = 0;
}