#define MAX 100
#include <iostream>
using namespace std;
struct Stack
{
    int a[MAX];
    int top;
};
void CreateStack(Stack &s)
{
    s.top = -1;
}
bool isEmpty(Stack &s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
        return false;
}
bool isFull(Stack &s)
{
    if (s.top >= MAX - 1)
    {
        cout << "Stack is full.";
        return true;
    }
    else
        return false;
}
void Push(Stack &s, int item)
{
    if (isFull(s))
    {
        cout << "Stack is full.";
        return;
    }
    else
    {
        s.a[++s.top] = item;
    }
}
int Pop(Stack &s, int x = 0)
{
    if (isEmpty(s))
        return 0;
    else
    {
        x = s.a[s.top];
        s.top--;
        return x;
    }
}
void Calculator(Stack &s, int coSo, int num)
{
    if (coSo == 2 )
        while (num != 0)
        {
            int x = num % coSo;
            Push(s, x);
            num /= coSo;
        }
    else
        cout << "Co so khong hop le.";
    
    while (isEmpty(s)==false)
    {
        int x = Pop(s);
            cout << x;
}}

int main(){
    Stack temp;
    CreateStack(temp);
    int cs=2,s;
    cout<<"Nhap so thap phan: ";
    cin>>s;
    Calculator(temp,cs,s);
    return 0;
}