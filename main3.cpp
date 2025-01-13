#include <iostream>
#include <math.h>
using namespace std;

class dathuc{
	protected:
		int bacdt;
		int a[10] = {0};
	public:
		dathuc(){
			bacdt = 0;
			a[bacdt] = 0;
		}
		dathuc(int n, int b[10]){
			bacdt = n;
			for (int i = 0; i < n; i ++){
				a[i] = b[i];
			}
		}
		~dathuc(){			
		}
		friend istream &operator >> (istream &is, dathuc &b){
			cout << "Nhap bac da thuc: "; is >> b.bacdt;
			cout << "Nhap he so: ";
			for (int i = 0; i <= b.bacdt; i++){
				cout << "Nhap hs bac " << i + 1 <<": ";
				is >> b.a[i];
			}
			return is;
		}
		friend ostream &operator << (ostream &os, dathuc &b){
			if (b.bacdt >= 0){
				os << b.a[b.bacdt] << "x^" << b.bacdt;
				for (int i = b.bacdt - 1; i > 0; i--){
					if (b.a[i] < 0) os << " - " << -b.a[i] << "x^" << i;
					if (b.a[i] > 0) os << " + " << b.a[i] << "x^" << i;
				}
				if (b.a[0] >= 0) {
					if (b.a[0] < 0) os << " - " << -b.a[0];
					else if (b.a[0] > 0) os << " + " << b.a[0];
				}
			}
			else os << "0";
			return os;
		}
		dathuc operator +(const dathuc dt1){
			dathuc sum;
			sum.bacdt = max(bacdt, dt1.bacdt);
			for (int i = 0; i <= sum.bacdt; i ++){
				sum.a[i] = a[i] + dt1.a[i];
			}
			return sum;
		}
		dathuc operator -(const dathuc dt1){
			dathuc hieu;
			hieu.bacdt = max(bacdt, dt1.bacdt);
			for (int i = 0; i <= hieu.bacdt; i ++){
				hieu.a[i] = a[i] - dt1.a[i];
			}
			return hieu;
		}
};

int main (){
	dathuc dthuc1, dthuc2;
	cout << "Nhap da thuc 1: " << endl; cin >> dthuc1;
	cout << "Nhap da thuc 2: " << endl; cin >> dthuc2;
	
	cout << "Hai da thuc: "<< endl << dthuc1 << endl << dthuc2 << endl;
	
	dathuc tong = dthuc1 + dthuc2;
	dathuc hieu = dthuc1 - dthuc2;
	
	cout << "Tong 2 da thuc: " << tong << endl;
	cout << "Hieu 2 da thuc: " << hieu << endl;
	
	return 0;
}