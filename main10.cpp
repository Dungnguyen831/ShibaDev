#include <iostream>
#include <math.h>
using namespace std;

class tamgiac{
	private:
		float a, b, c;
	public:
		tamgiac(){
			a = 0;
			b = 0;
			c = 0;
		}
		tamgiac (int da, int db, int dc){
			a = da;
			b = db;
			c = dc;
		}
		~tamgiac(){
			
		}
		
		void nhap(){
			cout << "Nhap tam giac: " << endl;
			cout << "Nhap canh a: "; cin >> a;
			cout << "Nhap canh b: "; cin >> b;
			cout << "Nhap canh c: "; cin >> c;
		}
		void xuat(){
			cout << "Tam giac (" << a << ", " << b << ", " << c << ")" << endl;
		}
		bool ktra(){
			if ((a > 0) && (b > 0) && (c > 0) && (a + b > c) && (a + c > b) && (b + c > a))
			return true;
			else return false;
		}
		float cv(){
			return a + b + c;
		}
		float dt(){
			float ncv = cv() / 2;
			return sqrt(ncv * (ncv - a) * (ncv - b) * (ncv - c));
		}
};

int main (){
	int n;
	cout << "Nhap so tam giac: "; cin >> n;
	tamgiac* tg = new tamgiac[n];
	
	for ( int i = 0; i < n; i ++){
		do {
			tg[i].nhap();
			if (tg[i].ktra() == false)
				cout << "Vui long nhap lai!" << endl;
		} while (tg[i].ktra() == false);
	}
	
	for (int i = 0; i < n; i ++){
		for (int j = i + 1; j < n - i - 1; j ++){
			if (tg[i].dt() > tg[j].dt()){
				tamgiac temp = tg[i];
				tg[i] = tg[j];
				tg[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i ++){
		tg[i].xuat();
		cout << "Dien tich= "<< tg[i].dt();
		cout << "\nChu vi= "<< tg[i].cv();
		cout << endl;
	}
}