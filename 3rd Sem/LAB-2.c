#include<stdio.h>
#include<conio.h>

char str[100],pat[50],rep[50],ans[100];
int i,j,c,m,k,flag = 0 ;

void stringmatch(){
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;m++;
            if(pat[i]=='\0'){
                flag=1;
                for(k=0;rep[k]!='\0';k++,j++)
                    ans[j]=rep[k];
                i=0;c=m;
            }
        }
        else{
            ans[j++]=str[c++];
            m=c;
            i=0;
        }
    }
}


void main(){
    //clrscr();
    printf("Enter main string: \n");
    gets(str);
    printf("Enter pattern string: \n");
   //flushall();
    gets(pat);
    printf("Enter replace string: \n");
    //flushall();
    gets(rep);
    stringmatch();
    if(flag==1)
        printf("Resultant string is : %s",ans);
    else 
        printf("\n Not found ");
    getch();    
}