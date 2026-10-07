#include <bits/stdc++.h>
using namespace std;

struct khachhang {
    int makh;
    string tenkh, sdt;
    float tongtien;
};

void nhap(khachhang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap khach hang thu " << i + 1 << endl;

        cout << "Nhap ma khach hang: ";
        cin >> a[i].makh;
        cin.ignore();

        cout << "Nhap ten khach hang: ";
        getline(cin, a[i].tenkh);

        cout << "Nhap sdt: ";
        getline(cin, a[i].sdt);

        cout << "Nhap tong tien: ";
        cin >> a[i].tongtien;
        cin.ignore();
    }
}

void xuat(khachhang a[], int n) {
    cout << left
         << setw(20) << "Ma khach hang"
         << setw(25) << "Ten khach hang"
         << setw(20) << "SDT"
         << setw(20) << "Tong tien" << endl;

    cout << "-------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(20) << a[i].makh
             << setw(25) << a[i].tenkh
             << setw(20) << a[i].sdt
             << setw(20) << fixed << setprecision(0) << a[i].tongtien
             << endl;
    }
}

void in1kh(khachhang kh) {
    cout << left
         << setw(20) << kh.makh
         << setw(25) << kh.tenkh
         << setw(20) << kh.sdt
         << setw(20) << fixed << setprecision(0) << kh.tongtien
         << endl;
}

void insertionSort(khachhang a[], int n) {
    for (int i = 1; i < n; i++) {
        khachhang key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tongtien > key.tongtien) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void binarySearch(khachhang a[], int n, float x) {
    int left = 0;
    int right = n - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid].tongtien == x) {
            index = mid;
            break;
        }

        if (a[mid].tongtien < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (index == -1) {
        cout << "\nKhong co khach hang co tong tien la "
             << fixed << setprecision(0) << x << endl;
        return;
    }

    cout << "\nCac khach hang co tong tien la "
         << fixed << setprecision(0) << x << ":" << endl;

    cout << left
         << setw(20) << "Ma khach hang"
         << setw(25) << "Ten khach hang"
         << setw(20) << "SDT"
         << setw(20) << "Tong tien" << endl;

    cout << "-------------------------------------------------------------------------------" << endl;

    int i = index;

    while (i >= 0 && a[i].tongtien == x) {
        i--;
    }

    i++;

    while (i < n && a[i].tongtien == x) {
        in1kh(a[i]);
        i++;
    }
}

int main() {
    int n;

    do {
        cout << "Nhap so khach hang: ";
        cin >> n;
        cin.ignore();
    } while (n <= 0);

    khachhang* ds = new khachhang[n];

    cout << "\n========== CAU 1 ==========" << endl;
    nhap(ds, n);

    cout << "\n========== CAU 2 ==========" << endl;
    cout << "\nDanh sach khach hang:" << endl;
    xuat(ds, n);

    cout << "\n========== CAU 3 ==========" << endl;
    insertionSort(ds, n);

    cout << "\nDanh sach sau khi sap xep tang dan theo tong tien:" << endl;
    xuat(ds, n);

    cout << "\n========== CAU 4 ==========" << endl;

    float x;

    cout << "Nhap tong tien can tim: ";
    cin >> x;

    binarySearch(ds, n, x);

    delete[] ds;

    return 0;
}