#include <stdio.h>

int main() {
    int n, at[10], bt[10], ct[10], wt[10], temp[10], tat[10], pr[10], smallest, count = 0, time;
    double avg_wt = 0, avg_tt = 0, end = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the Arrival Time, Burst Time, and Priority of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        temp[i] = bt[i];
    }

    for (time = 0; count != n; time++) {
        smallest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && bt[i] > 0 && (smallest == -1 || pr[i] < pr[smallest])) {
                smallest = i;
            }
        }

        if (smallest != -1) {
            bt[smallest]--;
            if (bt[smallest] == 0) {
                count++;
                end = time + 1;
                ct[smallest] = end;
                wt[smallest] = end - at[smallest] - temp[smallest];
                tat[smallest] = end - at[smallest];
            }
        }
    }

    printf("\nProcess\tPriority\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tt += tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", i + 1, pr[i], at[i], temp[i], ct[i], tat[i], wt[i]);
    }

    avg_wt /= n;
    avg_tt /= n;
    printf("\nAverage Waiting Time: %.2lf\n", avg_wt);
    printf("Average Turnaround Time: %.2lf\n", avg_tt);

    return 0;
}
