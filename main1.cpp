#include <iostream>
#include <math.h>
using namespace std;

class phanso{
	protected:
		int ts;
		int ms;
	public:
		phanso(){
			ts = 0;
			ms = 1;
		}
		phanso(int tuso, int mauso){
			ts = tuso;
			ms = mauso;
		}
		friend istream &operator >> (istream &is, phanso &a){
			cout << "Nhap tu so: "; is >> a.ts;
			
			do{
				cout << "Nhap mau so: "; is >> a.ms;
				if (a.ms == 0){
					cout <<"Mau so khoong hop le! Vui long nhap lai.";
				}
			} while (a.ms == 0);
			return is;
		}
		friend ostream &operator << (ostream &os, phanso a){
			os << a.ts << "/" << a.ms;
			return os;
		}
		phanso operator +(phanso a){
			phanso ps1;
			ps1.ts = ts*a.ms + a.ts*ms;
			ps1.ms = ms*a.ms;
			return ps1;				
		}
		phanso operator -(phanso a){
			phanso ps1;
			ps1.ts = ts*a.ms - a.ts*ms;
			ps1.ms = ms*a.ms;
			return ps1;	
		}
		phanso operator *(phanso a){
			phanso ps1;
			ps1.ts = ts*a.ts;
			ps1.ms = ms*a.ms;
			return ps1;
		}
		phanso operator /(phanso a){
			phanso ps1;
			ps1.ts = ts*a.ms;
			ps1.ms = ms*a.ts;
			return ps1;
		}
		int ucln(int a, int b){
			if (a == b){
				return a;
			}
			else{
				while (b != 0){
					int temp = b;
					b = a%b;
					a = temp;
				}
				return abs(a);
			}
		}
		
		phanso rutgon(){
			phanso ps1;
			ps1.ts = ts/ucln(ts, ms);
			ps1.ms = ms/ucln(ts, ms);
			return ps1;
		}
		
};

class phanso2: public phanso{
	public: 
		phanso2 operator = (phanso2 a){
			this->ts = a.ts;
			this->ms = a.ms;
			return *this;
		}
		
		bool operator > (const phanso2 &a) const{
			return (ts*a.ms > a.ts*ms);
		}
		
		bool operator < (const phanso2 &a) const{
			return (ts*a.ms < a.ts*ms);
		}
};

int main (){
	phanso2 ps[10];
	cout << "Nhap so phan tu: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++ ){
		cout << "Phan so thu " << i + 1 << endl;
		cin >> ps[i];
	}
	
	cout << "Danh sach phan so: " << endl;
	for (int i = 0; i < n; i ++ ){
		cout << "Phan so thu " << i + 1 << ": " << ps[i].rutgon() << endl;
	}
	
	phanso tong = ps[0];
	for (int i =1; i <n; i++){
		tong = tong + ps[i];
	}
	cout << "Tong cua cac phan so: " << tong.rutgon() << endl;
	
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			if (ps[i] < ps[j]){
				phanso2 temp = ps[j];
				ps[j] = ps[i];
				ps[i] = temp;
			}
		}
	}
	
	phanso2 max = ps[0];
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			if (ps[i] > ps[j]){
				max = ps[i];
			}
		}
	}
	cout << "Phan so lon nhat: " << max << endl;
	cout << "Danh sach phan so sau khi sap xep theo thu tu tang dan: " << endl;
	for (int i = 0; i < n; i ++ ){
		cout << "Phan so thu " << i + 1 << ": " << ps[i].rutgon() << endl;
	}
	return 0;
}
