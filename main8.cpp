#include <iostream>
#include <math.h>
using namespace std;

class hv{
	protected:
		float a;
	public:
		hv(){
			a = 0;
		}
		hv(int canha){
			a = canha;
		}
		~hv(){
		}
		void nhap(){
			cout << "Nhap canh a:";
			cin >> a;
		}
		void xuat(){
			cout << "Hinh vuong canh a= "<<a;
		}
		float cv(){
			return 4*a;
		}
		float dt(){
			return a*a;
		}
};

class hcn: public hv{
	private:
		float b;
	public:
		hcn(){
			b = 0;
		}
		hcn(int canhb){
			b = canhb;
		}
		~hcn(){
		}
		void nhap(){
			cout << "Nhap canh a: "; cin >> a;
			cout << "Nhap canh b: "; cin >> b; 
		}
		void xuat(){
			cout << "Hinh chu nhat canh a= " << a << " va canh b= " << b;
		}
		float cv(){
			return (a+b)*2;
		}
		float dt(){
			return a*b;
		}
};

int main (){
	int n;
	cout << "Nhap vao so hinh vuong: "; cin >> n;
	hv* a = new hv[n];
	hv* max1 = &a[0];
	int tt = 0;
	for (int i = 0; i < n; i++){
		a[i].nhap();
	}
	
	for (int i = 0; i < n; i++){
		if(a[i].dt() > max1->dt()){
			max1 = &a[i];
			tt = i;
		}
	}
	
	cout << "Hinh vuong thu " << tt << " co dien tich lon nhat la " << max1->dt();
	;
	
	int m;
	cout << "Nhap vao so hinh chu nhat: "; cin >> m;
	hcn* b = new hcn[m];
	
	for (int i = 0; i < m; i++){
		b[i].nhap();
	}
	
	for (int i = 0; i < m; i++){
		for (int j = i + 1; j < m - i - 1; j++){
			if (b[i].cv() < b[j].cv()){
				hcn temp = b[j];
				b[j] = b[i];
				b[i] = temp;
			}
		}
	}
	
	for (int i = 0; i < m; i++){
		b[i].xuat();
		cout << endl;
	}
	
	
	delete[] a;
	return 0;
}