#include<stdio.h>
#include<string.h>
char a[100];
int i;

void change(int f,int m,int l,int var){
    a[f] = var;
    int j=1;
   if(a[l+1] != '\0'){
        while(a[l+1] != '\0'){
                a[f+j] = a[l+j];
                j++;
        }
    }
    else{
        a[l-1] = '\0';
    }
    i=0;
}
void main(){
    int n,var=64;
    printf("Enter the expression:");
    scanf("%s",&a);
    n = strlen(a);
    for(i=0;i<n;i++){
        if(a[i] == '*'){
            var++;
            printf("%c %c %c %c \n",a[i],a[i-1],a[i+1],var);
            change(i-1,i,i+1,var);
        }
    }
    for(i=0;i<n;i++){
        if(a[i] == '/'){
            var++;
            printf("%c %c %c %c \n",a[i],a[i-1],a[i+1],var);
            change(i-1,i,i+1,var);
        }
    }
    for(i=0;i<n;i++){
        if(a[i] == '+'){
            var++;
            printf("%c %c %c %c \n",a[i],a[i-1],a[i+1],var);
            change(i-1,i,i+1,var);
        }
    }
    for(i=0;i<n;i++){
        if(a[i] == '-'){
            var++;
            printf("%c %c %c %c \n",a[i],a[i-1],a[i+1],var);
            change(i-1,i,i+1,var);
        }
    }

}