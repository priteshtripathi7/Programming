#include<stdio.h>
#include<ctype.h>
struct stack{
	char c[40];
	int top;
};
struct stack s;
void main(){
	s.top==-1;int i,j;
	char op[100];
	printf("enter infix exp...");
	scanf("%s",op);
	for(i=0;op[i]!='\0';i++){
		if(op[i]=='('){
			s.c[++s.top]=op[i];
		}
		else if((op[i]=='+')||(op[i]=='-')||(op[i]=='/')||(op[i]=='*')||(op[i]=='^')){
			while(1){
				if((s.top==-1)||(s.c[s.top]=='(')){
					s.c[++s.top]=op[i];
					break;
				}
				else if(((s.c[s.top]=='+')||(s.c[s.top]=='-')||(s.c[s.top]=='/')||(s.c[s.top]=='*'))&&(op[i]=='^')){
					s.c[++s.top]=op[i];
					break;
				}
				else if(((s.c[s.top]=='+')||(s.c[s.top]=='-'))&&((op[i]=='/')||(op[i]=='*'))){
					s.c[++s.top]=op[i];
					break;
				}
				else{
					printf("%c",s.c[s.top]);
					s.top--;
				}
		    }
		}
		else if(op[i]==')'){
			while(s.c[s.top]!='('){
				printf("%c",s.c[s.top]);
				s.top--;
			}
			s.top--;
		}
		else if(isalnum(op[i]))
			printf("%c",op[i]);
		else{
			printf(" invalid expression");s.top=-1;break;
		}
		
	}
	while(s.top!=-1){
		printf("%c",s.c[s.top]);
		s.top--;
	}
}
