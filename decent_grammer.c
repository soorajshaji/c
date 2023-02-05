#include<stdio.h>
#include<string.h>
char a[100];
int i=0,y=0;

void A(){
    if(a[i]=='a'){
        i++;
        y =1;
        if(a[i] == 'b'){
            i++;

        }

    }
    else{
        y=0;
    }
}
void main(){

    printf("enter the value:");
    scanf("%s",&a);
    if(a[i]=='a'){
        i++;
        A();
        if(y==1 && a[i]=='d'){
            printf("\nvalid");
        }
        else{
            printf("\ninvalid");
        }

    }
}