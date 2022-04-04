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
    if (coSo == 2 || coSo == 8 || coSo == 16)
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
        if (x < 10)
            cout << x;
        else
        {
            switch (x)
            {
            case 10:
                cout << "A";
                break;
            case 11:
                cout << "B";
                break;
            case 12:
                cout << "C";
                break;
            case 13:
                cout << "D";
                break;
            case 14:
                cout << "E";
                break;
            case 15:
                cout << "F";
                break;
            }
        }
    }
}

int main(){
    Stack temp;
    CreateStack(temp);
    int cs,s;
    cout<<"Nhap co so: ";
    cin>>cs;
    cout<<"Nhap so thap phan: ";
    cin>>s;
    Calculator(temp,cs,s);

}