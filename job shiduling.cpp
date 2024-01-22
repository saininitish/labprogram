#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int jobNumber;
    int serviceTime;
} Job;

int compareJobs(const void *a, const void *b) {
    int timeA = ((Job *)a)->serviceTime;
    int timeB = ((Job *)b)->serviceTime;
    return (timeA > timeB) ? 1 : -1;
}

void scheduleJobs(Job jobs[], int numJobs) {
    
    qsort(jobs, numJobs, sizeof(Job), compareJobs);

    
    printf("Job\tService Time\n");
    for (int i = 0; i < numJobs; i++) {
        printf("%d\t%d\n", jobs[i].jobNumber, jobs[i].serviceTime);
    }

    
    int totalTime = 0;
    for (int i = 0; i < numJobs; i++) {
        totalTime += jobs[i].serviceTime;
    }

    printf("Total Time Spent in the System: %d\n", totalTime);
}

int main() {
    int numJobs = 4;
    Job jobs[] = {
        {1, 5},
        {2, 10},
        {3, 7},
        {4, 8}
    };

    
    scheduleJobs(jobs, numJobs);

    return 0;
}
