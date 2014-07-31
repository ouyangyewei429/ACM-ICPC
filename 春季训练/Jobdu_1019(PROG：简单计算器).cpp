/**
 * PROG: 简单计算器
 */
#include <map>
#include <stack>
#include <string>
#include <iomanip>
#include <iostream>
#include <cctype>

using namespace std;

map<char, int> g_grade;  // 符号优先级

/**
 * 预定优先级
 */
void GetGrade()
{
    g_grade['#'] = 1;
    g_grade['+'] = 2;
    g_grade['-'] = 2;
    g_grade['*'] = 3;
    g_grade['/'] = 3;
}

/**
 * @infix:中缀表达式
 */
string GetPostfixBy(const string& infix)
{
    stack<char> symbol;  // 符号栈
    symbol.push('#');

    string postfix;      // 后缀表达式

    /**
     *  1. 栈初始压入 '#' 作为后缀表达式的结束标志
     *  2. 如果当前扫描的字符为数字，则将其整串数字直接输出
           到后缀表达式字符串postfix中，并以 $ 分隔
     *  3. 如果当前扫描的字符是操作符，如果栈顶的操作符优先
           级大于或等于该操作符，则退栈，并将栈顶操作符放入
           后缀表达式字符串postfix中
     *  4. 当扫描完中缀表达式后，字符栈非空，退栈到空
     */
    int strLen = infix.length();
    for (int i=0; i<strLen; ++i)
    {
        if (isdigit(infix[i]))
        {
            postfix += infix[i];
        }
        else if ('+'==infix[i] ||
                 '-'==infix[i] ||
                 '*'==infix[i] ||
                 '/'==infix[i])
        {
            postfix += '$';  // end of number
            while (g_grade[symbol.top()] >= g_grade[infix[i]])
            {
                postfix += symbol.top();
                symbol.pop();
            }
            symbol.push(infix[i]);
        }
    }
    postfix += '$';
    while (!symbol.empty())
    {
        postfix += symbol.top();
        symbol.pop();
    }
    return postfix;
}

/**
 * @postfix:后缀表达式
 */
double CalcBy(const string& postfix)
{
    stack<double> number;

    int strLen = postfix.length();
    for (int i=0; i<strLen; ++i)
    {
        if (isdigit(postfix[i]))
        {
            double temp = 0.0;
            while (isdigit(postfix[i]))
            {
                temp = temp * 10.0 + (postfix[i++] - '0');
            }
            number.push(temp);

            --i;
        }
        else if ('+' == postfix[i] ||
                 '-' == postfix[i] ||
                 '*' == postfix[i] ||
                 '/' == postfix[i])
        {
            double number_b = number.top();
            number.pop();
            double number_a = number.top();
            number.pop();
            double result;
            switch (postfix[i])
            {
                case '+':
                    result = number_a + number_b;
                    break;
                case '-':
                    result = number_a - number_b;
                    break;
                case '*':
                    result = number_a * number_b;
                    break;
                case '/':
                    result = number_a / number_b;
                    break;
                default:
                    result = 0.0;
                    break;
            }
            number.push(result);
        }
    }// End of For
    return (number.top());
}

int main(void)
{
    GetGrade();

    string infix;
    while (getline(cin, infix))
    {
        if ("0" == infix)
        {
            break;
        }
        // cout << infix << endl;
        string postfix = GetPostfixBy(infix);
        cout << std::fixed << setprecision(2) << CalcBy(postfix) << endl;
        //cout << postfix << endl;
    }// End of While
    return 0;
}
