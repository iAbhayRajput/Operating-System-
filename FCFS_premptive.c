#include <stdio.h>

void sortProcessesByArrival(float arrival[], float burst[], int n) {
    int i, j;
    float temp;
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (arrival[i] > arrival[j]) {
                // Swap arrival time
                temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;
                // Swap burst time
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }
}

float waitingtime(float process[],float arrival[],float burst[],int n,float wt[])
    {
        float wtAvg,wtTotal=0 ;
        int i,j;
            wt[1]=0;
            //printf("waitingtime of process1:0\n");
            for (i=2;i<=n;i++)
            {
                wt[i]=burst[i-1]+wt[i-1];
                wtTotal+=wt[i];
                //printf("waitingtime of process%d:%f\n",i,wt[i]);
            }
             wtAvg= wtTotal/n;
            //printf("Average waiting time is :%f\n",wtAvg);
    }
    
float turnaroundtime(float process[],float arrival[],float burst[],int n,float wt[])
    { 
        float tat[n],tatAvg,tatTotal=0;
        int i,j;
        for(j=1;j<=n;j++)
        {
            tat[j]= burst[j]+wt[j];
            tatTotal+=tat[j];
            //printf("turnaround time of process%d:%f\n",j,tat[j]);
        }
        tatAvg= tatTotal/n;
             //printf("Average turnaround time is :%f",tatAvg);
             
              printf ("|process|\t |ArrivalTime|\t |BurstTime|\n");
             for (j=1;j<=n;j++)
             {
                printf ("|%f|\t |%f|\t |%f|\n",process[j],arrival[j],burst[j]);
             }
    }
    
float main()
{
    int n,p,q;
    printf("Enter number of process:");
    scanf("%d",&n);
    float process[n], arrival[n], burst[n];
    for(p=1;p<=n;p++)
    {
        process[p]=p;
        printf("Enter arrival time for P%d:\n",p);
        scanf("%f",&arrival[p]);
        printf("Enter burst time for P%d:\n",p);
        scanf("%f",&burst[p]);
    }
    
    sortProcessesByArrival(arrival, burst, n);
    
    float wt[n];
      waitingtime(process,arrival,burst,n,wt);
      turnaroundtime(process,arrival,burst,n,wt);
      
    return 0;
}
