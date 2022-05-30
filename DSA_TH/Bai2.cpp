#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct DATE
{
    int ngay;
    int thang;
    int nam;
};
struct LOP
{
    char mssv[10];
    string hoten;
    float diem;
    DATE ngaysinh;
};
struct Node
{
    LOP info;
    Node *pNext;
};
struct List
{
    Node *pHead;
    Node *pTail;
};
void CreateList(List &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}
Node *CreateNode(LOP x)
{
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddTail(List &ds, Node *p)
{
    if (ds.pHead == NULL)
    {
        ds.pHead = p;
        ds.pTail = p;
    }
    else
    {
        ds.pTail->pNext = p;
        ds.pTail = p;
    }
}
void getInfo(List &ds)
{
    int n;
    LOP x;
    cout << "Nhap so SV : ";
    cin >> n;
    while (n != 0)
    {
        cout << "Nhap MSSV: ";
        cin >> x.mssv;
        cout << "Nhap ho va ten: ";
        cin.ignore();
        getline(cin, x.hoten);

        cout << "Nhap ngay thang nam sinh: ";
        cin >> x.ngaysinh.ngay;
        cin >> x.ngaysinh.thang;
        cin >> x.ngaysinh.nam;

        cout << "Nhap diem thi: ";
        cin >> x.diem;
        Node *p = new Node;
        p = CreateNode(x);
        AddTail(ds, p);
        n--;
    }
}
void display(List ds)
{
    Node *p = ds.pHead;
    cout << "MSSV		HO VA TEN		NGAY SINH		DIEM THI" << endl;
    while (p != NULL)
    {
        cout << p->info.mssv << "		" << p->info.hoten << "		" << p->info.ngaysinh.ngay << "/" << p->info.ngaysinh.thang << "/" << p->info.ngaysinh.nam << "		" << p->info.diem << endl;
        p = p->pNext;
    }
}
void RemoveHead(List &ds)
{
    Node *p;
    if (ds.pHead != NULL)
    {
        p = ds.pHead;
        ds.pHead = ds.pHead->pNext;
        delete p;
        if (ds.pHead == NULL)
            ds.pTail = NULL;
        return;
    }
}
void DeleteAfterQ(List &ds, Node *q)
{
    Node *p;
    if (q != NULL)
    {
        p = q->pNext;
        if (p != NULL)
        {
            if (p == ds.pTail)
                ds.pTail = q;
            q->pNext = p->pNext;
            delete p;
        }
    }
}
void Delete(List &ds, char a[])
{
    Node *p = ds.pHead;
    Node *q = NULL;
    while (p != NULL && strcmp(p->info.mssv, a) != 0)
    {
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return;
    if (q != NULL)
    {
        DeleteAfterQ(ds, q);
        cout << "Da xoa\n";
    }
    else
    {
        RemoveHead(ds);
        cout << "Da xoa\n";
    }
}
void BubbleSort(struct Node *head)
{
    int swapp, i;
    struct Node *p;
    struct Node *l = NULL;
    /* Checking for empty list */
    if (head == NULL)
        return;
    do
    {
        swapp = 0;
        p = head;

        while (p->pNext != l)
        {
            if (p->info.diem > p->pNext->info.diem)
            {
                swap(p->info, p->pNext->info);
                swapp = 1;
            }
            p = p->pNext;
        }
        l = p;
    } while (swapp);
}

int main()
{
    char a[10];
    List ds;
    CreateList(ds);
    getInfo(ds);
    display(ds);
    cout << "Nhap mssv can xoa: ";
    cin >> a;
    Delete(ds, a);
    cout << "Nhap mssv can xoa: ";
    cin >> a;
    Delete(ds, a);
    Node *p = ds.pHead;
    getInfo(ds);
    BubbleSort(p);
    display(ds);
}