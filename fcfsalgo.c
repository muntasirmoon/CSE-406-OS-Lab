#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Tahsinul Muntasir Moon\t ID- 22101143\t Section- c2\n");
    printf("FCFS Algorithm Problem Solution\n");
    int pid[10]={0},arT[10]={0},brT[10]={0},TAT[10]={0},WT[10]={0},CT[10]={0};
    int n,i,j,temp=0,sum=0;
    float total_TAT =0,total_WT=0;
    printf("Enter Total Number of PRocess Count\n");
    scanf("%d",&n);
    printf("Enter Process Sequence : \n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("Enter Arrival Time(arT) : \n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arT[i]);
    }
    printf("Enter Burst Time(brT) : \n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&brT[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arT[i]>arT[j])
            {
                temp= arT[i];
                arT[i]=arT[j];
                arT[j]=temp;

                temp= brT[i];
                brT[i]=brT[j];
                brT[j]=temp;

                temp= pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }

    //Calculate Completion time,Turn around Time & Waiting Time of the process>>>

    for(i=0;i<n;i++)
    {
         sum = sum+brT[i];
         CT[i]+=sum;

        TAT[i]=CT[i]-arT[i];
        total_TAT+=TAT[i];

        WT[i]=TAT[i]-brT[i];
        total_WT+=WT[i];

    }
   
    printf("Solution\n");
    printf("\tPID\tArT\tBrT\tCT\tTAT\tWT\t\n\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d\t%d\t%d\t%d\t%d\t%d\t\n\n",pid[i],arT[i],brT[i],CT[i],TAT[i],WT[i]);
    }

    printf("Average Turn Around Time : %f \n",(total_TAT/n));
    printf("Average Waiting Time : %f ",(total_WT/n));

    return 0;

}

