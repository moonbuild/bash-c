#include<stdio.h>
#include<stdlib.h>


typedef struct {
    float at;
    float wt;
    float bt;
    int id;
    float pt;
    
}P;

void main(){
    int n;
    printf("Enter number of process:-  ");
    scanf("%d",&n);

    P p[n];

    for(int k=0;k<n;k++){
        printf("Enter priority  of  process %d :-  ",k+1);
        scanf("%f",&p[k].at);
        printf("Enter burst time  of  process %d :-  ",k+1);
        scanf("%f",&p[k].bt);
        p[k].id=k+1;

    }
    P temp;
    for(int t=0;t<n-1;t++){
        for(int o=0;o<n-t-1;o++){
            if(p[o].at >p[o+1].at){
                temp= p[o];
                p[o]=p[o+1];
                p[o+1]=temp;

            }
        }
    }

  for(int i=0;i<n;i++){
p[i].pt=p[i].at;
p[i].at=0;

}

  for(int i=0;i<n;i++){
    if(i==0){
    p[i].wt=0;
    }
    else{
        if(p[i].at>p[i-1].wt+p[i-1].bt){
            p[i].wt=0;
        }
        else{
            p[i].wt=p[i-1].wt+p[i-1].at +p[i-1].bt-p[i].at;
        }
    }
    
  }
    float wt=0;
    float bt=0;
    for(int i=0;i<n;i++){
    wt= wt+p[i].wt;
    bt=bt+p[i].wt+p[i].bt;
    }

        for(int t=0;t<n-1;t++){
        for(int o=0;o<n-t-1;o++){
            if(p[o].id >p[o+1].id){
                temp= p[o];
                p[o]=p[o+1];
                p[o+1]=temp;

            }
        }
    }


    printf("\nPID \t PT \t\t BT \t\t WT \t\t TT\n");
    for(int i=0;i<n;i++){
    printf("%d \t %f \t %f \t %f \t %f\n",p[i].id,p[i].pt,p[i].bt,p[i].wt,p[i].wt+p[i].bt);
   
    }

    bt=bt/n;
    wt=wt/n;

    printf("Average waiting time for process is %f\n",wt);
    printf("Average Turnaround time for process is %f\n",bt);



}
