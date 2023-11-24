# include <stdio.h>

void main(){
    struct Process{
        int pid;
        int at;
        int bt;
    };
    struct Process p[100];
    int n, q;

    printf("Enter the No. of Process: ");
    scanf("%d", &n);

    int wt[n], tat[n], rt[n], ct[n];
    float awt=0, atat=0;


    printf("Enter the arrival times: ");
    for(int i=0; i<n; i++){
        scanf("%d", &p[i].at);
    }

    printf("Enter the burst times: ");
    for(int i=0; i<n; i++){
        scanf("%d", &p[i].bt);

        p[i].pid = i+1;
        rt[i] = p[i].bt;
    }

    printf("Enter the Time quantum (q): ");
    scanf("%d", &q);

    // Sort process based on arrival time
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(p[i].at>p[j].at){
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
    int t=0, completed=0;

    while(completed < n){
        int remaining=0;

        for(int i=0; i<n; i++){
            if((p[i].at <= t) && (rt[i]>0)){
                remaining=1;
                if(rt[i] <= q){
                    t += rt[i];
                    rt[i] = 0;
                    ct[i] = t;
                    completed++;
                } else{
                    t += q;
                    rt[i] -= q;
                }
            }
        }

        if(!remaining){
            t++;
        }
    }

    // printf("Completeion time: ");
    for(int i=0; i<n; i++){
        tat[i] = ct[i] - p[i].at;
        wt[i] = tat[i] - p[i].bt;

        // printf("%d ", ct[i]);
        awt += wt[i];
        atat += tat[i];
    }
    printf("\n");
    printf("Average Waitning time: %.2f\n", awt/n);
    printf("Average Turn Around time: %.2f\n", atat/n);
}