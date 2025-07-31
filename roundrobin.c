#include <stdio.h>
#define MAX 10

typedef struct
{
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
    int visited;
    int done;
} Process;

int main()
 {
    int n, i, tq, time = 0, completed = 0;
    Process p[MAX];
    int queue[20], front = 0, rear = 0;
    float totalWT = 0, avgWT;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    printf("Enter Process IDs:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].pid);
    }

    printf("Enter the Arrival Time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].at);
    }

    printf("Enter the Burst Time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].visited = 0;
        p[i].done = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    queue[rear++] = 0;
    p[0].visited = 1;

    while (completed < n)
    {
        int index = queue[front++];

        if (p[index].rt > tq)
        {
            time += tq;
            p[index].rt -= tq;
        }
        else
            {
            time += p[index].rt;
            p[index].rt = 0;
            p[index].ct = time;
            p[index].done = 1;
            completed++;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            totalWT += p[index].wt;
        }

        for (i = 0; i < n; i++)
        {
            if (!p[i].visited && p[i].at <= time)
            {
                queue[rear++] = i;
                p[i].visited = 1;
            }
        }

        if (p[index].rt > 0)
        {
            queue[rear++] = index;
        }

        if (front == rear)
        {
            for (i = 0; i < n; i++)
             {
                if (!p[i].done)
                {
                    queue[rear++] = i;
                    p[i].visited = 1;
                    break;
                }
            }
        }
    }

    printf("\nSolution\n");
    printf("\tPID\tArT\tBrT\tCT\tTAT\tWT\t\n\n");
    for (i = 0; i < n; i++)
     {
        printf("\t%d\t%d\t%d\t%d\t%d\t%d\t\n\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average Waiting Time : %f ", totalWT / n);

    return 0;
}