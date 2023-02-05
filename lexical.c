#include<stdio.h>
#include<string.h>
#include<ctype.h>


void main(){

    char c,token[100],i;
    FILE *fp = fopen("input.txt","r");
    c = fgetc(fp);
    while (c!=EOF){
        if (c == '/'){
            if(fgetc(fp) == '/'){
                c = fgetc(fp);
                while(c!='\n'){
                    c = fgetc(fp);
                }
            }
            else printf("\n %c \t operator",c);
        }
        else if(c == '+' || c == '*' || c=='='){
            printf("\n %c \t operator",c);
        }
        else if(c == '(' || c==')' || c=='{' || c=='}' || c==';'){
            printf("\n %c \t special charactor",c);
        }
        else if(isalpha(c)){
            i=0;
            while(isalpha(c)){
                token[i++] = c;
                c = fgetc(fp);
            }
            token[i++] = '\0';
            if(strcmp(token,"void") ==0 || strcmp(token,"int") ==0){
                printf("\n %s \t Keyword",token);
            }
            else{
                printf("\n %s \t identifer",token);
            }
        }
        else if(isdigit(c)){
            i=0;
            while(isdigit(c)){
                token[i++] = c;
                c = fgetc(fp);
            }
            token[i++] = '\0';
            printf("\n %s \t number",token);
        }
        c = fgetc(fp);
    }
    fclose(fp);
    
}