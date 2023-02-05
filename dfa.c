#include<stdio.h>

struct dfa{
    int p,a,b,flag;
}e[100];

int n,f,ch=0;

void unreachable(){
    int i,j,test=0;
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            if(e[i].p == e[j].a || e[i].p == e[j].b){
                test++;
                break;
            }
        }
        if(test==0){
            e[i].flag=1;
        }
        test =0;
        
    }
}
void minimize(){
    int i,j;
    for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                    if(e[i].a == e[j].a && e[i].b == e[j].b && f !=e[j].p){
                        e[j].flag = 1;
                        replace(i,j);
                        ch=0;
                    }
        }
    }
}
void replace(int val, int res){
    int k;
    for(k=0;k<n;k++){
        if(e[k].a == res && f !=e[k].p){
            e[k].a = val;
        }
        if(e[k].b == res && f !=e[k].p){
            e[k].b = val;
        }
    }

}
void main(){
    int i,j;

    printf("Enter the number of operations:");
    scanf("%d",&n);
    printf("\nEnter final:");
    scanf("%d",&f);

    for(i=0;i<n;i++){
        scanf("%d",&e[i].p);
        scanf("%d",&e[i].a);
        scanf("%d",&e[i].b);
        e[i].flag = 0;
    }
    unreachable();
    //unreachable();
    minimize();
    minimize();
    minimize();
    minimize();
    for(i=0;i<n;i++){
        if(e[i].flag == 0){
            printf("\n %d \t %d \t %d",e[i].p,e[i].a,e[i].b);
        }
    }


}