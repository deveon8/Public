#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> bignum_vec;

void fix(bignum_vec &number)
{

    number.push_back(0);

    for (int i = 0; i < number.size() - 1; ++i)
    {
        number[i + 1] += (number[i] / 10); // Hàng trước cộng thêm nhớ của hàng sau.
        number[i] %= 10;                   // Hàng hiện tại chỉ lưu chữ số cuối cùng của tổng hàng.

        if (number[i] < 0) // Nếu hàng hiện tại bị âm thì mượn thêm từ hàng sau.
        {
            number[i] += 10;
            --number[i - 1];
        }
    }

    // Xóa chữ số 0 vô nghĩa ở đầu kết quả phép toán.
    while (number.size() > 1 && number.back() == 0)
        number.pop_back();
}

istream &operator>>(istream &cin, bignum_vec &number)
{
    string s;
    cin >> s;

    number.clear();
    for (int i = s.size() - 1; i >= 0; --i)
        number.push_back(s[i] - '0');

    return number, cin;
}

ostream &operator<<(ostream &cout, bignum_vec &number)
{
    cout << number.back();

    for (int i = number.size() - 2; i >= 0; --i)
        cout << number[i];

    return cout;
}
// cong 2 so
bignum_vec operator+(bignum_vec a, bignum_vec b)
{
    // Kết quả phép cộng sẽ gán thẳng vào số a, ta resize trước cho nó.
    a.resize(max(a.size(), b.size()), 0);

    for (int i = 0; i < b.size(); ++i)
        a[i] += b[i];

    fix(a);

    return a;
}
bignum_vec operator-(bignum_vec a, bignum_vec b)
{
    for (int i = 0; i < b.size(); ++i)
        a[i] -= b[i];

    fix(a);

    return a;
}
bignum_vec operator*(bignum_vec a, bignum_vec b)
{
    bignum_vec product(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
        {
            product[i + j] += (a[i] * b[j]);
            product[i + j + 1] += (product[i + j] / 10);
            product[i + j] %= 10;
        }

    fix(product);

    return product;
}
bignum_vec operator/(bignum_vec a, long long b)
{
    long long r = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        r = r * 10 + a[i];
        a[i] = r / b;
        r %= b;
    }

    fix(a);

    return a;
}

int main()
{

    bignum_vec a, b, c;
    cin >> a >> b;

    cout << a << endl
         << b;
    c = a + b;
    cout << c;
}
