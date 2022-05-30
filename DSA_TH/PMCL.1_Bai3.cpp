#include <iostream>
using namespace std;

// 1. tạo 1 cây nhị phân tìm kiếm sử dụng Class
class BST
{
    int data;
    BST *left, *right;

public:
    BST();
    BST(int value);
    BST *Insert(BST *, int);
    int ChieuCaoCay(BST *);
    void Xuat(BST *);
    int Dem(BST *);
    void XuatTheoTangK(BST *, int);
    bool SoChinhPhuong(int);
    int doLech(BST *);
};

BST::BST()
{
    data = 0;
    left = NULL;
    right = NULL;
}

BST::BST(int value)
{
    data = value;
    left = right = NULL;
}
// 2. Thêm 1 phần tử mới vào cây
BST *BST::Insert(BST *root, int value)
{
    if (!root)
        return new BST(value); // nếu chưa có nút gốc insert nút mới

    if (value > root->data)
        root->right = Insert(root->right, value); // insert phải

    else
        root->left = Insert(root->left, value); // insert trái

    return root;
}
int BST::ChieuCaoCay(BST *root)
{
    if (root == NULL)
        return 0;
    int a = ChieuCaoCay(root->left);
    int b = ChieuCaoCay(root->right);
    int max = (a > b) ? a : b;
    return 1 + max;
}

void BST::XuatTheoTangK(BST *root, int k)
{
    if (root != NULL)
    {
        k--;
        if (root->left != NULL)
            XuatTheoTangK(root->left, k);
        if (k == 0)
            cout << root->data << " ";
        if (root->right != NULL)
            XuatTheoTangK(root->right, k);
    }
}
void BST::Xuat(BST *root)
{
    int h = ChieuCaoCay(root);
    cout << "Chieu cao cay: " << h << endl;
    for (int i = 0; i <= h - 1; i++)
    {
        cout << "Tang " << i << ": ";
        XuatTheoTangK(root, i + 1);
        cout << endl;
    }
}
bool BST::SoChinhPhuong(int n)
{
    if (n <= 0)
        return 0;
    int s = sqrt((double)n);
    if (s * s == n)
        return 1;
    return 0;
}
int BST::Dem(BST *root)
{
    if (root != NULL)
    {
        int a = Dem(root->left);
        int b = Dem(root->right);
        if (SoChinhPhuong(root->data))
            if (root->left != NULL && root->right != NULL)
                return 1 + a + b;

        return a + b;
    }
    return 0;
}
int BST::doLech(BST *root)
{
    if (root == NULL)
        return 0;
    int a = ChieuCaoCay(root->left);
    int b = ChieuCaoCay(root->right);
    return abs(a - b);
}

int main()
{
    int x;
    BST b, *root = NULL;
    cout << "Nhap phan tu lam goc: ";
    cin >> x;
    root = b.Insert(root, x);
    cout << "Nhap cac phan tu tiep theo. Nhap '-1' de dung viec nhap.\n";
    do
    {
        cin >> x;
        if (x != -1)
            b.Insert(root, x);
    } while (x != -1);
    cout << "Cat nut tren cay tu can 0 den tang h-1 (h=chieu cao cay) \n";
    b.Xuat(root);
    cout << endl;
    cout << "So luong nut co dung 2 con ma nut do la so chinh phuong: ";
    cout << b.Dem(root) << endl;
    cout << "Do lech: ";
    cout << b.doLech(root);

    return 0;
}
