#include <iostream>
#include <math.h>
using namespace std;

class thisinh{
	private:
		string mats;
		string hoten;
		float dtoan;
		float dly;
		float dhoa;
	public:
		thisinh(){
			mats = "null";
			hoten = "null";
			dtoan = 0;
			dly = 0;
			dhoa = 0;
		}
		thisinh(string mts, string ht, float dt, float dl, float dh){
			mats = mts;
			hoten = ht;
			dtoan = dt;
			dly = dl;
			dhoa = dh;
		}
		~thisinh(){
		}
		
		void nhap(){
			cout << "Nhap ma thi sinh: "; cin >> mats;
			cout << "Nhap ho ten: "; 
			cin.ignore();
			getline (cin, hoten);
			cout << "Nhap diem toan ly hoa: "; cin >> dtoan >> dly >> dhoa;
		}
		void xuat(){
			cout << "Ma thi sinh: " << mats << endl;
			cout << "Ho Ten: " << hoten << endl;
			cout << "Diem toan: " << dtoan << "/Diem ly: " << dly << "/Diem hoa: " << dhoa;
		}
		float tongdiem(){
			return dtoan + dly + dhoa;
		}
};

int main (){
	int n;
	cout << "Nhap so thi sinh: ";
	cin >> n;
	
	thisinh* ts = new thisinh[n];
	
	for (int i = 0; i < n; i ++){
		ts[i].nhap();
	}
	
	thisinh* max = &ts[0];
	for (int i = 0; i < n; i ++){
		if (ts[i].tongdiem() > max->tongdiem()){
			max = &ts[i];
		}
	}
	cout << "Thi sinh co tong diem cao nhat: ";
	max->xuat();
	
	cout << endl << "Thi sinh co tong diem 21 " << endl;
	for (int i = 0; i < n; i ++){
		if (ts[i].tongdiem() > 21){
			ts[i].xuat();
			cout << endl;
		}
	}
	delete[] ts;
	
	return 0;
}