#include <iostream>
#include <math.h>
using namespace std;

class diem{
	private:
		float x;
		float y;
	public:
		void nhap(){
			cout << "Nhap toa do x, y:"; cin >> x >> y;
		}
		void xuat(){
			cout << "(" << x << ", " << y << ")";
		}
		friend float kc(const diem a, const diem b){
			return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
		}
};

class tamgiac{
	private:
		diem a, b, c;
		float d1, d2, d3;
	public:
		void dodai(){
			d1 = kc(a, b);
			d2 = kc(b, c);
			d3 = kc(c, a);
		}
		void nhap(){
			cout << "Nhap dinh A: " << endl;
			a.nhap();
			cout << "Nhap dinh B: " << endl;
			b.nhap();
			cout << "Nhap dinh C: " << endl;
			c.nhap();
			dodai();
		}	
		void xuat (){
			cout << "Dinh A: "; a.xuat();
			cout << "\nDinh B: "; b.xuat(); 
			cout << "\nDinh C: "; c.xuat();
			cout << "\nDo dai 3 canh cua tam giac abc la: " << endl;
			cout << "AB= " << d1 << endl;
			cout << "BC= " << d2 << endl;
			cout << "AC= " << d3 << endl;
		}
		
		bool ktra(){
			if ((d1 > 0 && d2 > 0 && d3 > 0) && (d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1))
			return true;
			else return false;
		}
		
		int type(){
			if (d1 == d2 && d2 == d3 && d3 == d1 ) return 1;
			else if (d1 == d2 || d1 == d3 || d2 == d3 ) return 2;
			else if (d1*d1 + d2*d2 == d3*d3 || d1*d1 + d3*d3 == d2*d2 || d2*d2 + d3*d3 == d1*d1) return 3;	
		}
};

int main (){
	tamgiac tg;
	cout << "Nhap tam giac: " << endl;
	do {
		tg.nhap();
		if (tg.ktra() == false){
			cout << "Tam giac khong hop le! Vui long nhap lai." << endl;
		}
	} while (tg.ktra() == false);
	tg.xuat();
	cout << endl;
	
	switch (tg.type()){
		case 1: cout << "Tam giac deu!";
		case 2: cout << "Tam giac can";
		case 3: cout << "Tam giac vuong";
	}
	return 0;
}