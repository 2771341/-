#include <stdio.h>
#define M 100
int s[M];
int t=-1;
void p(int i) {
    if (t==M - 1) 
	{
        printf("满\n");
        return;
    }
    s[++t]=i;
}
int pop() {
    if (t==-1) {
        printf("空\n");
        return -1;
    }
    return s[t--];
}
void c(int n, int b) {
    int o=n;
    if (n==0) {
        printf("%d 转", n);
        if (b==2) {
            printf("2: 0\n");
        } else if (b==8) {
            printf("8: 0\n");
        } else if (b==16) {
            printf("16: 0\n");
        }
        return;
    }
    while (n>0) 
	{
        p(n%b);
        n/=b;
    }
    printf("%d 转", o);
    if (b==2) {
        printf("2: ");
    } else if (b==8) 
	{
        printf("8: ");
    } else if (b==16) 
	{
        printf("16: ");
    }
    while (t!=-1) 
	{
        int d=pop();
        if (b==16 && d>=10) 
		{
            printf("%c", 'A'+d-10);
        } else 
		{
            printf("%d", d);
        }
    }
    printf("\n");
}
int main() 
{
    int n1=10;
    int n2=31;
    c(n1,2);
    c(n1,8);
    c(n1,16);
    c(n2,2);
    c(n2,8);
    c(n2,16);
    return 0;
}
