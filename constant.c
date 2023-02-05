#include<stdio.h>
#include<string.h>

struct cont{
    char op[10],op1[10],op2[10],res[10];
    int flag;
}e[10];

int n;

void change(int p,char *res){
    int i;
    for(i=p+1;i<n;i++){
        if(strcmp(e[i].op1,e[p].res)==0){
            strcpy(e[i].op1,res);
        }
        if(strcmp(e[i].op2,e[p].res)==0){
            strcpy(e[i].op2,res);
        }

    }
}
void main(){
    int i;
    printf("enter value:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",e[i].op);
        scanf("%s",e[i].op1);
        scanf("%s",e[i].op2);
        scanf("%s",e[i].res);
        e[i].flag = 0;
    }

    for(i=0;i<n;i++){
        if(strcmp(e[i].op ,"=")==0){
            change(i,e[i].op1);
            e[i].flag = 1;
        }
    }
    for(i=0;i<n;i++){
        if(e[i].flag == 0){
            printf("\n %s %s %s %s",e[i].op,e[i].op1,e[i].op2,e[i].res);

        }
    }


}
