#include<stdio.h>

void main(){
    int smallest, count = 0, t, n;
    float awt = 0, atat = 0, compTime;

    n = 5;
    int at[] = {2,5,1,0,4};
    int bt[] = {6,2,8,3,4};

    int bt_t[n+1];
    for(int i =0; i<n; i++) bt_t[i] = bt[i];
    bt_t[n+1] = 999;

    for(t = 0; count != n; t++){
        smallest = n+1;

        for(int i=0; i<n; i++){
            if(at[i]<= t && bt_t[i] < bt_t[smallest] && bt_t[i] > 0){
                smallest = i;
            }
        }
        bt_t[smallest]--;
        if(bt_t[smallest]==0){
            count++;
            compTime = t + 1;
            printf("\ncompletion time: %.2f\n", compTime);
            awt += compTime - at[smallest] - bt[smallest];
            atat += compTime - at[smallest];
        }
    }

    printf("\n\nAverage waiting time = %.2f\n", awt / n);
    printf("Average Turnaround time = %.2f\n", atat / n);

}