#include<stdio.h>
#include<math.h>
struct stack{
	int n[40];
	int top;
};
struct stack s;
void main(){
	char op[100];
	int i;s.top=-1;
	printf("Enter postfix exp...");
	gets(op);
	for(i=0;op[i]!='\0';i++){
		if((op[i]>47)&&(op[i]<58)){
			s.n[++s.top]=op[i]-48;
		}
		else if(op[i]=='+'){
			s.n[s.top-1]=s.n[s.top-1]+s.n[s.top];
			s.top--;
		}
		else if(op[i]=='-'){
			s.n[s.top-1]=s.n[s.top-1]-s.n[s.top];
			s.top--;
		}
		else if(op[i]=='*'){
			s.n[s.top-1]=s.n[s.top-1]*s.n[s.top];
			s.top--;
		}
		else if(op[i]=='/'){
			s.n[s.top-1]=s.n[s.top-1]/s.n[s.top];
			s.top--;
		}
		else if(op[i]=='^'){
			s.n[s.top-1]=pow(s.n[s.top-1],s.n[s.top]);
			s.top--;
		}
		else
		{
			s.top=-1;break;
		}
	}
	if(s.top!=0)
		printf(" type valid expression ");
	else
		printf("%d",s.n[s.top]);
}
