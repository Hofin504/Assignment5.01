#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b) { // GCD(|a|,|b|) != GCD(a,b) (a < 0 or b < 0) 
	if (a == 0) return b;
	return GCD(b % a, a);
}

int LCM(const int& a, const int& b) {
	return a / GCD(abs(a), abs(b)) * b; 
}

struct PhanSo {
	int tu{}, mau{};
	PhanSo() {}; 
	PhanSo(const int &tu, const int &mau) { 
		this->tu = tu;
		this->mau = mau;
	}
	void rutgon() { // toi gian phan so 
		int UCLN = GCD(abs(tu), abs(mau)); 
		tu /= UCLN;
		mau /= UCLN;
	} 

	void Input() { // Nhap phan so 
		char dau;
		cin >> tu >> dau >> mau;
		if (!mau) {
			cout << "Error !\n";
			exit(0);
		}
	} 

	PhanSo& operator += (const PhanSo& Number) { // them toan tu += cho phan so 
		int BCNN = LCM(Number.mau, this->mau);
		this->tu *= (BCNN / this->mau);
		this->tu += Number.tu * (this->mau / Number.mau);
		this->mau = BCNN;
		return *this;
	}

	bool operator < (const PhanSo& Number) const { // so sanh phan so <
		int BCNN = LCM(Number.mau, this->mau);
		return Number.tu * (BCNN / Number.mau) > tu * (BCNN / mau);
	}

	friend ostream& operator << (ostream& cout, const PhanSo& Number) {
		cout << Number.tu << "/" << Number.mau;
		return cout;
	}
};


void TotalSum_of_Array(PhanSo* arr, const int &n) { // tinh tong day phan so S = a/b + c/d + .... + e/f 
	PhanSo Calc_sum = arr[1];
	for (int i = 2; i <= n; i++) Calc_sum += arr[i];
	Calc_sum.rutgon();
	cout << "Sum Of Array = " << Calc_sum.tu << "/" << Calc_sum.mau << '\n';
}

PhanSo a[(int)1e4];
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cout << "Nhap n : "; cin >> n;
	cout << "Yeu cau nhap phan tu theo dang a/b\n";
	for (int i = 1; i <= n; i++) {
		cout << "Nhap Phan So Thu " << i << " : "; 
		a[i].Input();
	}
	cout << "Mang sau khi sap xep :\n";
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) cout << a[i] << '\n';
	for (int i = 1; i <= n; i++) a[i].rutgon();
	TotalSum_of_Array(a, n); 
}
