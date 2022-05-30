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
    BST *Delete(BST *, int);
    int Search(BST *, int);
    int ChieuCaoCay(BST *);
    void Xuat(BST *);
    int Dem1(BST *);
    int Dem2(BST *);
    void XuatTheoTangK(BST *, int);
    void Inorder(BST *, int, int);
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
int BST::Search(BST *root, int value)
{
    // Cây rỗng
    if (root == NULL)
        return 0;
    // nút tìm là nút gốc
    if (root->data == value)
    {
        return 1;
    }
    // Nút cần tìm > nút gốc
    if (root->data < value)
        return Search(root->right, value);

    // Nút cần tìm bé hơn nút gốc
    return Search(root->left, value);
}
BST *BST::Delete(BST *root, int value)
{
    if (!root)
        return root;

    if (value < root->data)
        root->left = Delete(root->left, value); // xóa 1 nút nửa cây bên trái

    else if (value > root->data)
        root->right = Delete(root->right, value); // xóa 1 nút nửa cây bên phải

    // xóa nút cha (xóa được nút gốc)
    else
    {
        // nút không có nút lá
        if (root->left == NULL && root->right == NULL)
            return NULL;

        // nút có 1 lá hoặc không có lá nào (bản thân là nút lá)
        else if (root->left == NULL)
        {
            BST *temp = root->right;
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            return temp;
        }

        // nút với 2 nút lá
        // sử dụng nút nhỏ nhất ở phía cây bên phải làm nút thay thế cho nút cha
        BST *temp = new BST(root->right->data);

        // con bên phải -> nút cha
        root->data = temp->data;

        // xóa nút thay thế
        root->right = Delete(root->right, temp->data);
    }
    return root;
}

void BST::Inorder(BST *root, int a, int b)
{
    if (!root) // nếu chưa có nút gốc => không tồn tại cây
        return;
    Inorder(root->left, a, b);
    if (root->data >= a && root->data <= b)
        cout << root->data << endl;
    Inorder(root->right, a, b);
}
int BST::Dem1(BST *root)
{
    if (root != NULL)
    {
        int a = Dem1(root->left);
        int b = Dem1(root->right);
        if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))

            return root->data + a + b;

        return a + b;
    }
    return 0;
}
int BST::Dem2(BST *root)
{
    if (root != NULL)
    {
        int a = Dem2(root->left);
        int b = Dem2(root->right);
        if (root->left != NULL && root->right != NULL)

            return root->data + a + b;

        return a + b;
    }
    return 0;
}

int main()
{
    int x, temp;
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
    cout << "Nhap so can xoa: ";
    cin >> x;
    temp = b.Search(root, x);
    if (temp == 1)
        b.Delete(root, x);
    cout << "Nhap khoang a,b: ";
    int y;
    cin >> x >> y;
    b.Inorder(root, x, y);
    cout << b.Dem1(root) << " " << b.Dem2(root);

    return 0;
}
