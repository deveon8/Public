#include <iostream>
#include <string.h>
using namespace std;

struct SV
{
    char mssv[40];
    char ten[40];
    float dtb;
};

struct node
{
    SV info;
    node *pNext;
};

struct list
{
    node *pHead;
    node *pTail;
};

void Create(list &ds)
{
    ds.pHead = NULL;
    ds.pTail = NULL;
}

node *CreateNode(SV x)
{
    node *p;
    p = new node;
    if (p == NULL)
    {
      exit(1);
    }
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddHead(list &ds, node *p)
{
    if (ds.pHead == NULL)
    {
        ds.pHead = p;
        ds.pTail = ds.pHead;
    }
    else
    {
        p->pNext = ds.pHead;
        ds.pHead = p;
    }
}
void AddTail(list &ds, node *p)
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
void getInfo(list &ds)
{
    int temp = 1;
    cout << "Nhap thong tin sinh vien\n";
    while (temp != 0)
    {
        SV x;
        fflush(stdin);
        cout << "Nhap ten sinh vien : ";
        cin.getline(x.ten, sizeof x.ten);
        fflush(stdin);
        if (strlen(x.ten) == 0)
            return;
        cout << "Nhap ma so sinh vien : ";
        cin >> x.mssv;
        fflush(stdin);
        cout << "Nhap diem tong ket : ";
        cin >> x.dtb;
        fflush(stdin);
        node *p = new node;
        p = CreateNode(x);
        AddHead(ds, p);
    }
}
void getinfo(SV &x)
{
    fflush(stdin);
    cout << "Nhap ten sinh vien : ";
    cin.getline(x.ten, sizeof x.ten);
    fflush(stdin);
    cout << "Nhap ma sinh vien : ";
    cin >> x.mssv;
    fflush(stdin);
    cout << "Nhap diem tong ket : ";
    cin >> x.dtb;
}

void PrintList(list ds)
{
    node *p;
    p = ds.pHead;
    while (p != NULL)
    {
        cout <<"Ten SV:"<<p->info.ten << endl;
        cout <<"MSSV:"<< p->info.mssv << endl;
        cout <<"DTB:"<<p->info.dtb << endl;
        p = p->pNext;
    }
}

node *Search(list ds, char x[])
{
    cout<<"Nhap mssv SV can tim: ";
    cin>>x;
    fflush(stdin);
    node *p;
    p = ds.pHead;
    while ((p != NULL) && ((p->info.mssv) != x))
        p = p->pNext;
    return p;
}

void Arrange(list &ds)
{
    node *p, *q;
    for (p = ds.pHead; p != ds.pTail; p = p->pNext)
    {
        for (q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->info.dtb > q->info.dtb)
            {
                SV x = p->info;
                p->info = q->info;
                q->info = x;
            }
        }
    }
    PrintList(ds);
}
void DeleteAfterQ(list &ds, node *q)
{
    node *p;
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
void RemoveHead(list &ds)
{
    node *p;
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

int RemoveX(list &ds, char x[])
{
    cout << "Nhap MSSV can xoa:";
    cin >> x;
    node *p = ds.pHead, *q = NULL;
    while ((p != NULL) && (strcmp(p->info.mssv, x) != 0))
    {
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
    {
        return 0;
    }
    if (q != NULL)
        DeleteAfterQ(ds, q);
    else
        RemoveHead(ds);

    return 1;
}
void display(node *p)
{
    cout << "Ten SV:"<<p->info.ten << endl;
    cout << "Ten MSSV:"<<p->info.mssv << endl;
    cout << "DTB:"<<p->info.dtb << endl;
}
void Filter(list ds)
{
    node *p;
    p = ds.pHead;
    while (p != NULL)
    {
        if (p->info.dtb >= 5)
            display(p);
        p = p->pNext;
    }
}
void XepLoai(list ds)
{
    node *p;
    p = ds.pHead;
    while (p != NULL)
    {
        if (p->info.dtb <= 3.6)
        {
            cout << "Xep Loai: Yeu" << endl;
            display(p);
        }
        else if (p->info.dtb >= 5.0 && p->info.dtb < 6.5)
        {
            cout << "Xep Loai: TB" << endl;
            display(p);
        }
        else if (p->info.dtb >= 6.5 && p->info.dtb < 7.0)
        {
            cout << "Xep Loai: TBK" << endl;
            display(p);
        }
        else if (p->info.dtb >= 7.0 && p->info.dtb < 8.0)
        {
            cout << "Xep Loai: Kha" << endl;
            display(p);
        }
        else if (p->info.dtb >= 8.0 && p->info.dtb < 9.0)
        {
            cout << "Xep Loai: Gioi" << endl;
            display(p);
        }
        else
        {
            cout << "Xep loai: XS";
            display(p);
        }
        p = p->pNext;
    }
}
int main()
{
    char a[40];
    list ds;
    node *p,*q;
    SV x;
    char chon;
    Create(ds);
    getInfo(ds); 
    cin>>chon;
        switch(chon)
        {
            case '2': { PrintList(ds); break;}
            case '3': { display(Search(ds,a)); break;}
            case '4': { cout<<RemoveX(ds,a); break;}
            case '5': { Filter(ds); break;}
            case '6': { XepLoai(ds); break;}
            case '7': { Arrange(ds);break;}
            case '8':
                    {
                        SV them;
                        cout<<"\nNhap thong tin sv can them: ";
                        getinfo(them);
                        node *t= CreateNode(them);
                        AddTail(ds,t);
                        Arrange(ds);
                        cout<<"DS sau khi them"<<endl;
                        PrintList(ds);
                        break;
                    }
    return 0;

}
}