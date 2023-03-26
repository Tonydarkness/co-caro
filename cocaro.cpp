#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int n;
int **a;
int y;
bool chienthangX, chienthangO;

void Giatridefault(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 3;
        }
    }
}

void Xuatmang(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0 || a[i][j] == 1)
                cout << setw(7) << a[i][j] << "   ";
            else
                cout << setw(5) << "(" << i << " " << j << ")"
                     << " ";
        }
        cout << endl;
    }
}

int Trave (int dem, int value)
{
    if (dem == y)
    switch (value)
    {
        case 1:
        return 1;
        case 0:
        return 2;
    }
    return 0;
}

int checkngang(int dong, int cot, int value)
{
    int dem = 0;
    for (int i = max(cot - 4, 0); i <= min(cot + 4, n); i++)
    {
        if (a[dong][i] == value)
            dem += 1;
        else dem = 0;
    }
    return Trave(dem, value);
}

int checkdoc(int dong, int cot, int value)
{
    int dem = 0;
    for (int i = max(dong - 4, 0); i <= min(dong + 4, n); i++)
    {
        if (a[i][cot] == value)
            dem += 1;
        else dem = 0;
    }
    return Trave (dem, value);
}

int checkcheotrai(int dong, int cot, int value)
{
    int dem = 0;
    for (int i = -4; i <= 4; i++)
    {
        int dong_i = dong + i;
        int cot_i = cot + i;
        if (dong_i >= 0 && cot_i >= 0 && dong_i < n && cot_i < n)
        {
            if (a[dong_i][cot_i] == value)
                dem += 1;
            else dem = 0;
        }
    }
    return Trave (dem, value);
}

int checkcheophai (int dong, int cot, int value)
{
    int dem = 0;
    for (int i = 4; i >= - 4; i--)
    {
        int dong_i = dong - i;
        int cot_i = cot + i;
        if (dong_i >= 0 && cot_i >= 0 && dong_i < n && cot_i <n)
        {
              if (a[dong_i][cot_i] == value)
                dem += 1;
            else dem = 0;
        }
    }
    return Trave (dem, value);
}

// int checkcheotrainguoc(int dong, int cot, int value)
// {
//     int dem = 0;
//     return 0;
// }

int Check(int dong, int cot, int value)
{
    int check_ngang = checkngang(dong, cot, value);
    int check_doc = checkdoc(dong, cot, value);
    int check_cheo_trai = checkcheotrai(dong, cot, value);
    int check_cheo_phai = checkcheophai(dong, cot, value);
    if(check_doc != 0) return check_doc;
    if(check_ngang != 0) return check_ngang;
    if(check_cheo_trai != 0) return check_cheo_trai;
    if(check_cheo_phai != 0) return check_cheo_phai;
    return 0;
}

bool Chienthang(int a)
{
    switch(a)
    {
        case 1:
        cout << "X chien thang." << endl;
        return true;
        case 2:
        cout << "O chien thang." << endl;
        return true;
    }
    return false;
}

bool danh(int dong, int cot, int value)
{
    if (a[dong][cot] == 1 || a[dong][cot] == 0)
        cout << "Loi!" << endl;
    if (a[dong][cot] == 3)
    {
        a[dong][cot] = value;
    }
    return true;
}

int main()
{
    system("cls");
    do 
    {
    cout << "Nhap n: ";
    cin >> n;
    } while (n <= 2);
    switch (n)
    {
        case 3:
        case 4: 
            y = 3;
            break;
        default:
            y = 5;
    }
    a = new int*[n];
    for (int i = 0; i<n; i++)
    {
        a[i] = new int[n];
    }
    int dong, cot;
    Giatridefault(a, n);
    Xuatmang(a, n);
    do 
    {    
        cout << "Vi tri danh X: ";
        cin >> dong >> cot;
        danh(dong, cot, 1);
        chienthangX = Chienthang(Check(dong, cot, 1));
        cout << "Vi tri danh O: ";
        cin >> dong >> cot;
        danh(dong, cot, 0);
        chienthangO = Chienthang(Check(dong, cot, 0));
        Xuatmang(a, n);
    } while (chienthangX == false && chienthangO == false);
    system("pause");
    return 0;
}