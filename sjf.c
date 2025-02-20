#include <stdio.h>

void main() {
    int i, j, n, temp;
    int p[100], wt[100], at[100], bt[100], tt[100];
    float avgwt = 0, avgtt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the process ID: ");
        scanf("%d", &p[i]);
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
        printf("Enter arrival time: ");
        scanf("%d", &at[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(at[j] > at[j+1]) {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }        
        }
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(bt[j] > bt[j+1] && at[j] <= at[j+1]) {
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;

                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
            }        
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
        avgwt += wt[i];
    }

    for(i = 0; i < n; i++) {
        tt[i] = wt[i] + bt[i];
        avgtt += tt[i];
    }

    printf("Process Id\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tt[i]);
    }

    printf("Average Waiting Time: %.2f\n", avgwt / n);
    printf("Average Turnaround Time: %.2f\n", avgtt / n);

    printf("\nGantt Chart\n");
    printf("----------------------------------------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("|\tP%d\t|", p[i]);
    }
    printf("\n");
    printf("----------------------------------------------------------------------------------\n");

    printf("0\t\t");
    for(i = 0; i < n; i++) {
        printf("%d\t\t", tt[i]);
    }
    printf("\n");
}

