%{
	char Stack[100];
	int ptr=0;
	void push(char);
	void pop();
   char peek();
   int precedenceOrder(char );
   int isEmpty();
%}

%%
quit return 0;

exit return 0;

end return 0;

kill return 0;

[a-zA-Z]* {
   printf("bad input");
}

[0-9]* {
   printf("%s", yytext);
}

[+\-\*\/\(\)\^] {
   char op=yytext[0];
   if(isEmpty() || op=='(') {
      push(op);
   } else if(op==')') {
      while(!isEmpty() && peek()!='('){
         printf("%c",peek());
         pop();
      }
      pop();
   } else if(precedenceOrder(op)>precedenceOrder(peek())) {
      push(op);
   } else if(precedenceOrder(op)<=precedenceOrder(peek())) {
      while(!isEmpty() && precedenceOrder(op)<=precedenceOrder(peek())){
         printf("%c",peek());
         pop();
      }
      push(op);
   }
}

[\n] {
   int i;
   while(!isEmpty()){
      char ch = peek();
      if(ch!='(' && ch!=')'){
         printf("%c",ch);
      }
      pop();
   } 
}
%%
int yywrap(){return 1;};
int main(){
   yylex();
   exit(0);
}

int isEmpty(){
   return ptr==0;
}

void pop(){
 ptr--;
}

char peek(){
   return Stack[ptr-1];
}
  
void push(char c){
   Stack[ptr]=c;
   ptr++;
}

int precedenceOrder(char c){
   switch(c){
      case '(':
         return 0;
      case ')':
         return 0;
      case '+':
         return 1;
      case '-':
         return 1;
      case '*':
         return 2;
      case '/':
         return 2;
      case '^':
         return 3;
      default: 
         return -1;
   }
}