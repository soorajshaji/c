#include<stdio.h>
#include<ctype.h>
char a[100];
int i=0,e=0;

void E(){

    T();
    Edash();

}
void Edash(){
    if(a[i] == '+'){
        i++;
        T();
        Edash();
    }
    else return;
}

void T(){

    F();
    Tdash();

}

void Tdash(){
    if(a[i]=='*'){
        i++;
        F();
        Tdash();
    }
    else return;
}

void F(){
    if (a[i] == '('){
        i++;
        E();
        if (a[i]==')')
        {
            i++;
        }
        else{
            e=1;
        }
        
    }
    else if(isalnum(a[i])){
        i++;
    
    }
    else e=1;

}

void main(){
    printf("Enter the input:");
    scanf("%s",&a);
    E();
    if(strlen(a) ==i && e==0){
        printf("\n Valid");
    }
    else{
        printf("\n Invalid");
    }
}