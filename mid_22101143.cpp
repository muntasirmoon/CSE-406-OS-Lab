#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Tahsinul Muntasir Moon"<<endl;
    cout<<"ID-22101143"<<endl;
    cout<<"c2"<<endl;

    int n;
    cout<<"enter no of processes : "<<endl;
    cin>>n;
    int tq;
    cout<<"enter time quant : "<<endl;
    cin>>tq;
    int p[n],aT[n],bT[n],cT[n],taT[n],wT[n];

    for(int i=0;i<n;i++){
        cout<<"Enter Process ID : "<<endl;
        cin>>p[i];
         cout<<"Enter Arrival Time : "<<endl;
        cin>>aT[i];
         cout<<"Enter Burst Time : "<<endl;
        cin>>bT[i];

    }
    int rem_time[n];
    for(int i=0;i<n;i++)
    {
        rem_time[i] = bT[i];
        if(bT[i]>tq){
            cT[i]= bT[i]-tq;
            rem_time[i]=
        }
    }

}
