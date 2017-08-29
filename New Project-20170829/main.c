#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#define NULL ((void*)0)
struct stack{
char st[30];
int top;
}s;

void main()
{
char infix[30];
void inftopost(char[]);
printf("Enter infix expression:\n");
gets(infix);
inftopost(infix);
getch();
}

void inftopost(char infix[30])
{
    char postfix[30];
    int i,j;
    char ch,ch1;
    void push(char);
    int instack(char);
    int incoming(char);
    char pop();
    s.top=-1;
    s.top++;
    s.st[s.top]='$';
    i=0;
    j=0;
    while(infix[i]!=NULL)
    {
        ch=infix[i];
        while(instack(s.st[s.top]>incoming(ch)))
        {
            ch1=pop();
            if(ch1='(')
            {
                postfix[j]=ch1;
                j++;
                if(instack(s.st[s.top])!=incoming(ch))
                {
                    push(ch);
                }
                else
                {
                    ch1=pop();
                    if(ch1!='(')
                    {
                        postfix[j++]=ch1;

                    }
                }
            i++;
            }
            while((ch=pop())!='$')
            {
                postfix[j]=ch;
                j++;
            }
        postfix[j]=NULL;
        printf("\n Postfix expresssion=%s",postfix);        }



    }
}

int instack(char ch)
{
    int p;
    switch(ch)
    {
    case '+':
    case '-': p=2;
                break;
    case '*':
    case '/':p=4;
                break;
    case '^':p=5;
        break;
    case '(':p=0;
                    break;
    case '$':p=-1;
            break;
    default: p=8;


    }
   return p;
}

int incoming(char ch)
{
    int p;
    switch(ch)
    {
    case '+':
    case '-': p=1;
                break;
    case '*':
    case '/':p=3;
                break;
    case '^':p=6;
        break;
    case '(':p=9;
                    break;
    case ')':p=0;
            break;
    default: p=7;
    }
   return p;
}

void push(char ch)
{
    s.st[++s.top]=ch;
}

char pop()
{
    return(s.st[s.top--]);
}

