#include<stdio.h>
#include<string.h>
int i=0,j=0,z=0,n;
char a[100],stk[100];

void check(){
    for(z=0;z<n;z++){
        if(stk[z] == 'i' && stk[z+1] == 'd'){
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n %s \t %s \t reduce to E",stk,a);
            j++;
        }
    }
    for(z=0;z<n;z++){
        if(stk[z] == '(' && stk[z+1]=='E' && stk[z+2]==')'){
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n %s \t %s \t reduce to E",stk,a);
            i=i-2;
        }
    }
    for(z=0;z<n;z++){
        if(stk[z] == 'E' && stk[z+1]=='+' && stk[z+2]=='E'){
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n %s \t %s \t reduce to E",stk,a);
            i=i-2;
        }
    }
    for(z=0;z<n;z++){
        if(stk[z] == 'E' && stk[z+1]=='*' && stk[z+2]=='E'){
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n %s \t %s \t reduce to E",stk,a);
            i=i-2;
        }
    }
}
void main(){

    printf("GRAMMAR : \n E->E+E \n E->E*E \n E->(E) \n E->id");
    printf("\n Enter the input string:");
    scanf("%s",&a);
    n = strlen(a);
    printf("\n stack \t input \t actions");
    for(i=0;j<n;i++,j++){
        if(a[j]=='i' && a[j+1] == 'd'){
            stk[i] = a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j] = ' ';
            a[j+1] = ' ';
            printf("\n %s \t %s \t shift -> id ",stk,a);
            check();
        }
        else{
            stk[i] = a[j];
            stk[i+1] = '\0';
            a[j] = ' ';
            printf("\n %s \t %s \t shift ->symbol",stk,a);
            check();
        }
    }
}
