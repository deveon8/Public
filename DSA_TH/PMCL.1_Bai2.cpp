#include <iostream>
#include <string.h>
using namespace std;
// câu 1
struct PHONG
{
	char ma[5];
	char tenphong[30];
	float donGia;
	int soGiuong;
	int tinhTrang;
};
struct Node
{
	PHONG Info;
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
Node *CreateNode(PHONG x)
{
	Node *p;
	p = new Node;

	p->Info = x;
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
	cout << "Nhap so luong phong: ";
	cin >> n;
	cout << "Nhap thong tin phong\n";
	while (n != 0)
	{
		PHONG x;
		cin.ignore();
		cout << "Nhap ma phong : ";
		cin.getline(x.ma, sizeof x.ma);
		cout << "Nhap ten phong : ";
		cin.ignore();
		cin.getline(x.tenphong, sizeof x.tenphong);

		cout << "Nhap don gia : ";
		cin >> x.donGia;
		cout << "Nhap so giuong : ";
		cin >> x.soGiuong;
		cout << "Nhap trang thai : ";
		cin >> x.tinhTrang;

		Node *p = new Node;
		p = CreateNode(x);
		AddTail(ds, p);
		n--;
	}
}
void emptyRoom(List ds)
{
	Node *p;
	p = ds.pHead;
	while (p != NULL)
	{
		if (p->Info.tinhTrang == 0)
		{
			cout << "Ma Phong trong: " << p->Info.ma << endl;
		}
		p = p->pNext;
	}
}
int sumBed(List ds)
{
	int sum = 0;
	Node *p = ds.pHead;
	while (p != NULL)
	{
		sum += p->Info.soGiuong;
		p = p->pNext;
	}
	return sum;
}
void Arrange(List ds)
{
	Node *p, *q;
	for (p = ds.pHead; p != ds.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->Info.donGia > q->Info.donGia)
				swap(p->Info, q->Info);
		}
	for (p = ds.pHead; p != NULL; p = p->pNext)
	{
		cout << "Ten phong: " << p->Info.tenphong << endl;
		cout << "Don Gia:" << p->Info.donGia << endl;
		cout << "So giuong: " << p->Info.soGiuong << endl;
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
	while (p != NULL && strcmp(p->Info.ma, a) != 0)
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return;
	if (q != NULL)
	{
		DeleteAfterQ(ds, q);
		cout << "Da xoa";
	}
	else
	{
		RemoveHead(ds);
		cout << "Da xoa";
	}
}
int main()
{
	char a[5];
	List ds;
	CreateList(ds);
	getInfo(ds);
	emptyRoom(ds);

	cout << "Tong so giuong: " << sumBed(ds) << endl;
	Arrange(ds);
	cout << "Nhap phong can xoa: ";
	cin >> a;
	Delete(ds, a);
}
