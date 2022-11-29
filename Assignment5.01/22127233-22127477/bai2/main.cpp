//Chuong trinh nhap canh va tinh chu vi da giac
#include <iostream>
using namespace std;
//Kieu du lieu Side(canh da giac) co thuoc tinh la length(do dai canh)
struct Side {
	double length;
};
//Khai bao mang gom 1e4 phan tu co kieu du lieu la Side
Side s[(int)1e4];
//Kieu du lieu Polygon chua thuoc tinh side
struct Polygon {
	int side;
	//Phuong thuc nhap so luong canh cua da giac
	void Input_side() {
		cout << "Input number of polygon sides: ";
		cin >> side;
		while (side < 3) {
			cout << "Input number of polygon sides greater than 2:";
			cin >> side;
		}
	}
	//Phuong thuc nhap do dai tung canh cua da giac
	void set_polygon()
	{
		for (int i = 1; i <= side; i++)
		{
			cout << "Input length of side[" << i << "]: ";
			cin >> s[i].length;
			if (s[i].length <= 0) {
				cout << "Error: Side ["<<i<<"] doesn't exist => ";
				break;
			}
		}
	}
	//Phuong thuc tim do dai canh lon nhat 
	double Max_length() {
		double max = 0;
		for (int i = 1; i <= side; i++)
		{
			if (max < s[i].length)
				max = s[i].length;
		}
		return max;
	}
	/*Phuong thuc xet tinh ton tai cua da giac
	Tim ra do dai cua canh lon nhat. 
	Neu tong do dai cac canh con lai lon hon do dai canh lon nhat
	thi da giac co ton tai(tra ve true) va nguoc lai(tra ve false)*/
	bool ExistingPossibility() {
		double max = Max_length();
		double sum = 0;
		for (int i = 1; i <= side; i++)
		{
			sum += s[i].length;
		}
		sum -= max;
		if (sum > max) return true;
		else return false;
	}
	//Phuong thuc tinh chu vi da giac
	double Perimeter() {
		double perimeter = 0;
		for (int i = 1; i <= side; i++)
		{
			perimeter += s[i].length;
		}
		return perimeter;
	}
};
int main(){
	Polygon p;
	cout << "Program: Caculating the perimeter of a polygon\n";
	p.Input_side();
	p.set_polygon();
	p.Max_length();
	//Neu da giac ton tai thi tinh chu vi 
	if (p.ExistingPossibility() == 0)cout << "Polygon doesn't exist";
	else cout <<"Polygon perimeter: "<< p.Perimeter();
	return 0;
}
