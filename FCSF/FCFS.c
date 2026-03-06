#include <stdio.h>
void main(){
    int n,j,i,k,temp;
    printf("enter no of proceses :");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n];
    printf("enter arival time :");
    for (i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    printf("enter burst time :");
    for (i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    //we should sort the arrival time and burst time accordingly
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }

        }
    }
    ct[0]=bt[0];
    for(i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("process\t at\t bt\t ct\t tat\t wt\t\n");
    for (i=0;i<n;i++){
        printf("p%d\t %d\t %d\t %d\t %d\t %d\t \n",(i+1),at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}
