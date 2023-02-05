#include<stdio.h>

#include<string.h>

int n,i,k=0,m=0;
char a[100][100],str,ft[10];

void alpha(char c){

    if(islower(c)){
        ft[m++] =c;
    }
    for(k=0;k<n;k++){
        if(a[k][0] == c){
            if(islower(a[k][2])){
                ft[m++]= a[k][2];
            }
            else{
                alpha(a[k][2]);
            }
        }
    }

    for(i=0;i<m;i++){
        printf("%c",ft[i]);
    }
    strcpy(ft," ");


}
void main(){

    printf("Enter number of expression:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",&a[i]);
    }

    while(str != 'e'){
        printf("\n Enter the value to find the first:");
        scanf("%c",&str);
        if(str != 'e'){
            alpha(str);
            m=0;
        }

    }

}