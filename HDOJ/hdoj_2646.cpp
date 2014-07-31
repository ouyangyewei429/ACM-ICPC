#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAXSIZE 1000
//#define localjudge

char inExp[MAXSIZE] = {0};          /* 保存中缀表达式 */ 
char postexp[MAXSIZE] = {0};        /* 保存后缀表达式 */
int  scp[6] = {0, 2, 8, 8, 4, 4};   /* 栈内操作符的优先级 */ 
int  ecp[6] = {0, 12, 8, 8, 4, 4};  /* 栈外操作符的优先级 */ 

int Index(char symbol)
{   /* 返回操作符的索引下标 */ 
    switch (symbol)
    {
        case '$' : return 0;
        case '(' : return 1;
        case '*' : return 2;
        case '/' : return 3;
        case '+' : return 4;
        case '-' : return 5;
    }
}/* priority */

void TransToPostExp(char *infix)
{
    int  sp, ep;              /* StackCharPriority , ExpressCharPriority */
    int  ix=0, top=-1;
    char stack[MAXSIZE] = {0};      /* 设置字符栈 */ 
    
    stack[++top] = '$';       /* 后缀表达式的结束标志 */ 
    while (top!=-1 && *infix!='\0')
    {
        /***
         *  1. 栈初始压入 '$' 作为后缀表达式的结束标志 
         *  2. 如果当前扫描的字符为 '(', 则直接压入栈 
         *  3. 如果当前扫描的字符为  ')', 退栈至 '(', '('前的所有操作符放入postexp中
         *  4. 如果当前扫描的字符为数字，则将其整串数字直接放入栈，并以 # 分隔  
         *  5. 如果当前扫描的字符是操作符，如果栈顶的操作符优先级大于或等于该操作符，
         *     则退栈，并将栈顶操作符放入postexp中
         *  6. 当扫描完中缀表达式后，字符栈非空，退栈到空 
         ***/
        if (*infix>='0' && *infix<='9')
        {
            while (*infix>='0' && *infix<='9')
            {   /* 当前扫描的字符为数字，则将其正串数字直接放入栈 */
                postexp[ix++] = *infix;
                infix++;
            }
            postexp[ix++] = '#';   /* 数字以 # 分隔 */
        }
        else
        {
            switch (*infix)
            {
                case '(' : stack[++top] = *infix; break;
                case ')' :
                {
                    while (top!=-1 && stack[top]!='(')
                    {   /* 退栈至 '('，'('前的所有操作符放入postexp中 */
                        postexp[ix++] = stack[top--];
                    }
                    stack[top--];   /* '(' 退栈 */ 
                };break;
                default :
                {
                    sp = Index(stack[top]);  /* 获得栈顶操作符的下标索引 */ 
                    ep = Index(*infix);      /* 获得当前扫描表达式操作符的下标索引 */
                    for ( ;*infix!='\0' && scp[sp]>=ecp[ep]; )
                    {
                        postexp[ix++] = stack[top--]; /* 操作符退栈到postexp */ 
                        sp = Index(stack[top]);       /* 重新获得栈顶操作符的下标索引 */
                    }
                    
                    if (*infix != '\0')
                    {
                        stack[++top] = *infix;
                    }
                };break;
            }/* End of switch */

            ++infix;  /* 继续扫描中缀表达式的下一字符 */ 
        }/* End of Else */
    }/* End of While */
    
    /* 当扫描完中缀表达式后，字符栈非空，退栈到postexp */
    while (top != -1)
    {
        postexp[ix++] = stack[top--];
    }
    
    return ;
}/* TransToPostExp */

void EvalOfPostExp(char *postfix)
{
    double operand[MAXSIZE] = {0};
    double aNum, bNum, temp;
    int    top=-1;
    
    while (*postfix != '$')
    {
        switch (*postfix)
        {
            case '+' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = bNum + aNum;
            };break;
            case '-' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = bNum - aNum;
            };break;
            case '*' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = 1.0 * bNum * aNum;
            };break;
            case '/' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = 1.0 * bNum / aNum;
            };break;
            default  :
            {
                temp = 0.0;
                while (*postfix>='0' && *postfix<='9')
                {
                    temp = 10.0 * temp + (*postfix-'0');
                    ++postfix;
                }/* End of While */
                operand[++top] = temp;
            };break;
        }/* End of switch */
        
        ++postfix;
    }/* End of While */
    
    printf("The answer is  : %.3lf\n", operand[top]);
}/* EvalOfPostExp */

int main()
{
#ifdef localjudge
    freopen("E:\\EvaluationOfExpression.txt", "r", stdin);
    freopen("E:\\EvaluationOfExpression(result).txt", "w", stdout);
#endif

    while (~scanf("%s", inExp))
    {
        /* 清空缓存后缀表达式的数组 */ 
        memset(postexp, 0, sizeof(postexp));
        
        /* 中缀表达式转换至后缀表达式 */ 
        TransToPostExp(inExp);
        
        /* Evaluation the PostExpression */
        EvalOfPostExp(postexp);
        
        /* 清空缓存中缀表达式的数组 */ 
        memset(inExp, 0, sizeof(inExp));
    }/* End of While */
    
    return 0; 
}
