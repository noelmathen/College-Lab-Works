#include<stdio.h>
#include<math.h>// or #include<stdlib.h>

int DiskScheduling_SSTF(int rq[], int n, int head, int totalTrack)
{
    int trackMovement=0, small=999, large=-1,  nearest, difference=999999;
    for(int i=0; i<n; i++)
    {
        if(rq[i]<small)
            small = rq[i];
        if(rq[i]>large)
            large = rq[i];
        if(abs(rq[i] - head) < difference && rq[i] < head){
            difference = abs(rq[i] - head);
            nearest = rq[i];
        }
    }
    trackMovement = abs(head - totalTrack) + abs(totalTrack - 0) + abs(totalTrack - 0);

    return trackMovement;
}

int main()
{
    printf("\nDISK SCEDULING USING SSTF\n\n");
    int n, requestQueue[200], head, totalTrack;
    printf("Enter the number of tracks present in request queue: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter track number %d: ", i+1);
        scanf("%d", &requestQueue[i]);
    }
    printf("\nEnter the total number of tracks in the disk: ");
    scanf("%d", &totalTrack);
    printf("\nEnter the current position of R/W head: ");
    scanf("%d", &head);
    int trackMovement = DiskScheduling_SSTF(requestQueue, n, head, totalTrack-1);
    printf("\nThe total number of track movement using SSTF is: %d", trackMovement);
}

//TEST CASES
// 7   {82, 170, 43, 140, 24, 16, 190}    50  output:  642
// 7   {93, 176, 42, 148, 27, 14, 180}    55  output:  661
