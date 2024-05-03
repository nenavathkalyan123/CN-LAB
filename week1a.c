#include<stdio.h>
#include<conio.h>
#include<string.h>
int main() {
    printf("enter data:");
    char a[100],b[100],c[100];
    int i,j=0,n,k=0;
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++){
    if((a[i]=='d'&& a[i+1]=='l'&& a[i+2]=='e'||a[i]=='e'&& a[i+1]=='s'&& a[i+2]=='c')){
    c[k++]='e';
    c[k++]='s';
    c[k++]='c';
    }
    c[k++]=a[i];
    }
    c[k++]='\0';
    b[j++]='\0';

printf("%s\n",b);
printf("DLESTX");
printf("%s",c);
printf("DLEETX");
getch();
return 0;

}
