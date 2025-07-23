#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Tahsinul Muntasir Moon"<<" "<<"Id- 22101143"<<" "<<"Section- c2"<<endl;
    cout<<"Shortest Job First Algorithm Problem"<<endl;
    
    int n,temp,tt=0,min,d,i,j;
    float avg_TAT =0,avg_WT=0,total_TAT=0,total_WT=0;
    cout<<"Enter Process Count : "<<endl;
    cin>>n;
    int pid[n],arT[n],brT[n],CT[n],TAT[n],WT[n];
    cout<<"Enter Process Sequence : "<<endl;

    for(i=0;i<n;i++)
    {
        cin>>pid[i];
    }
       cout<<"Enter Arrival Time : "<<endl;

    for(i=0;i<n;i++)
    {
        cin>>arT[i];
    }
       cout<<"Enter Burst Time : "<<endl;

    for(i=0;i<n;i++)
    {
        cin>>brT[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(brT[i]>brT[j])
            {
                temp = pid[i];
                pid[i]=pid[j];
                pid[j]=temp;

                temp = arT[i];
                arT[i]=arT[j];
                arT[j]=temp;

                temp = brT[i];
                brT[i]=brT[j];
                brT[j]=temp;
            }
        }
    }
    min = arT[0];
    for(i=0;i<n;i++)
    {
        if(min>arT[i])
        {
            min = arT[i];
            d=i;
        }
    }
    tt = min;
    CT[d]= tt+brT[d];
    tt = CT[d];

    for(i=0;i<n;i++)
    {
        if(arT[i]!= min)
        {
            CT[i]= brT[i]+tt;
            tt= CT[i];
        }
    }
    for(i=0;i<n;i++)
    {
        TAT[i]= CT[i]-arT[i];
        total_TAT = total_TAT + TAT[i];
        WT[i]= TAT[i]-brT[i];
        total_WT = total_WT + WT[i];
    }
    

    //Table Header Names
     cout << "\n" << left
         << setw(8) << "PID"
         << setw(8) << "ArT"
         << setw(8) << "BrT"
         << setw(8) << "CT"
         << setw(8) << "TAT"
         << setw(8) << "WT"
         << endl;

    cout << string(48, '-') << endl;

    // Table rows
    for (int i = 0; i < n; i++) {
        cout << left
             << setw(8) << pid[i]
             << setw(8) << arT[i]
             << setw(8) << brT[i]
             << setw(8) << CT[i]
             << setw(8) << TAT[i]
             << setw(8) << WT[i]
             << endl;
    }

    avg_TAT = (total_TAT/n);
    avg_WT = (total_WT/n);

    cout<<"Average Turn Around Time : \t"<<avg_TAT<<endl;
     cout<<"Average Turn Waiting Time : \t"<<avg_WT<<endl;

     return 0;
}