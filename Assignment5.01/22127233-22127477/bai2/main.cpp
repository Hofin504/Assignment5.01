#include <iostream>

using namespace std;

struct Polygon {
	double dd_canh[(int)1e4];
	double perimeter_of_convex_polygon(const int &n) {
		double perimeter = 0;
		for (int i = 1; i <= n; i++) perimeter += dd_canh[i];
		return perimeter;
	}
};

int n;
Polygon a;

void Input() {
	cout << "Nhap so luong canh cua da giac : "; cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Nhap do dai canh thu " << i << " : "; cin >> a.dd_canh[i];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	Input();
	cout << "Chu vi cua da giac la : " << a.perimeter_of_convex_polygon(n);
}