#include <iostream>
#include <math.h>
using namespace std;

class date{
	private:
		int d;
		int m;
		int y;
	public:
		date(){
			d = 1;
			m = 1;
			y = 1999;
		}
		date(int ngay, int thang, int nam){
			d = ngay;
			m = thang;
			y = nam;
		}
		~date(){}
		
		bool namnhuan(int y){
			if ((y % 4 == 0 && y != 100) || (y % 400 == 0)){
				return true;
			}
			else return false;
		}
		void nhap(){
			cout << "Nhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
			chuanhoa();
		}
		void xuat(){
			if (d < 10) cout << "0";
			cout << d << "/";
			
			if (m < 10) cout << "0";
			cout << m << "/";
			
			cout << y;
		}
		int ngaythang(int m, int y){
			switch(m){
				case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
				case 4: case 6: case 9: case 11: return 30;
				case 2:
					if (namnhuan(y) == true){
						return 29;
					}
					else return 28;
			}
		}
		void chuanhoa(){
			while (d > ngaythang(m, y)){
				d = d - ngaythang(m, y);
				m++;
				if (m > 12){
					m = 1;
					y++;
				}
			}
			
			while (d < 1){
				m--;
				if (m < 1){
					m = 12;
					y--;
				}
				d = d + ngaythang(m, y);
			}
		}
		
		date operator ++ (){
			d++;
			chuanhoa();
			return *this;
		}
		
		date operator -- (){
			d--;
			chuanhoa();
			return *this;
		}
};

int main (){
	date dt;
	cout << "Nhap ngay thang nam: ";
	dt.nhap();
	cout << endl;
	
	cout << "Ngay thang nam(dd/mm/yyyy): "; dt.xuat();
	cout << endl;
	
	++dt;
	cout << "Tang 1 ngay: "; dt.xuat();
	cout << endl;
	--dt;
	--dt;
	cout << "Giam 1 ngay: "; dt.xuat();
	return 0;
}