//This code is ichiri thattikootu. This might work for the questions u'll get in ur OS class or lab etc etc. but this is not the correct implementation. use ur brains and find out wuts wrong with this code eheheheheheh
#include<stdio.h>
#include<math.h>

int DiskScheduling_SSTF(int rq[], int n, int head, int totalTrack)
{
    int trackMovement=0;
    int small=totalTrack, large=0;
    int nearest=totalTrack, difference=totalTrack;
    for(int i=0; i<n; i++)
    {
        if(rq[i]<small)
            small = rq[i];
        if(rq[i]>large)
            large = rq[i];
        if(abs(head-rq[i]) < difference)
        {
            difference = abs(head-rq[i]);
            nearest = rq[i];
        }
    }
    if(nearest > head)
        trackMovement = abs(head-large) + abs(large-small);
    else if(nearest < head)
        trackMovement = abs(head-small) + abs(large-small);
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
// 7   {82, 170, 43, 140, 24, 16, 190}     200     50  output:  208
// 7   {93, 176, 42, 148, 27, 14, 180}     200     55  output:  207
