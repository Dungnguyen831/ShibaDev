#include <iostream>
#include <math.h>
using namespace std;

class arr{
	private:
		int m; //so hang
		int n; //so cot
		int a[10][10];
	public:
		arr(){
			m = 0;
			n = 0;
			a[10][10] = {0};
		}
		arr(int hang, int cot, int b[10][10]){
			m = hang;
			n = cot;
			for (int i = 0; i < hang; i ++){
				for (int j = 0; j < cot; j ++){
					a[i][j] = b[i][j];
				}
			}
		}
		~arr(){}	
		int hang(){
			return m;
		}
		int cot(){
			return n;
		}	
		void nhap(){
			cout << "Nhap so hang: "; cin >> m;
			cout << "Nhap so cot: "; cin >> n;
			for (int i = 0; i < m; i ++){
				for (int j = 0; j < n; j ++){
					cout << "a[" << i << "][ " << j << "]= ";
					cin >> a[i][j]; 
				}
			}
		}
		void xuat(){
			for (int i = 0; i < m; i ++){
				for (int j = 0; j < n; j ++){
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
		}
		void tonghang(){
			int k, tong = 0;
			do{
				cout << "Nhap hang: "; cin >> k;
				if (k < 0 || k > hang()){
					cout << "Vui long nhap lai!";
				}
			}while (k < 0 || k > hang());
			
			for (int i = 0; i < hang(); i++){
				tong += a[k-1][i];
			}
			cout << tong;
		}
		void tongcot(){
			int k, tong = 0;
			do{
				cout << "Nhap cot: "; cin >> k;
				if (k < 0 || k > cot()){
					cout << "Vui long nhap lai!";
				}
			}while (k < 0 || k > cot());
			
			for (int i = 0; i < cot(); i++){
				tong += a[i][k-1];
			}
			cout << tong;
		}
		
		void tong4vien(){
			int tong = 0;
			for (int i = 0; i < n; i ++){
				tong += a[0][i];
			}
			for (int j = 0; j < n; j ++){
				tong += a[m-1][j];
			}
			for (int i = 1; i < m - 1; i ++){
				tong += a[i][0];
			}
			for (int j = 1; j < m - 1; j ++){
				tong += a[j][n-1];
			}
			cout << tong;
		}
		
		void cheophu(){
			int sum = 0;
			for (int i = 0; i < m; i ++){
				sum += a[i][n - i - 1];
			}
			cout << sum;
		}
		
		void cheochinh(){
			int sum = 0;
			for (int i = 0; i < n; i ++){
				sum += a[i][i];
			}
			cout << sum;
		}
		
		arr tong(const arr &a1){
			arr b;
			b.m = m;
			b.n = n;
			for (int i = 0; i < m; i++){
				for (int j = 0; j < n; j++){
					b.a[i][j] = a[i][j] + a1.a[i][j];
				}
			}
			return b;
		}
};

int main (){
	arr a1, a2;
	int k;
	cout << "Nhap ma tran 1: "; a1.nhap(); cout << endl;
	cout << "Nhap ma tran 2: "; a2.nhap(); cout << endl;
	
	cout << "Ma tran 1: " << endl; a1.xuat(); cout << endl;
	cout << "Ma tran 2: " << endl; a2.xuat(); cout << endl;
	
	cout << "Tong hang mt1: " << endl; a1.tonghang(); cout << endl;
	cout << "Tong cot mt1: " << endl; a1.tongcot(); cout << endl;
	cout << endl;
	
	cout << "Tong hang mt2: " << endl; a2.tonghang(); cout << endl;
	cout << "Tong cot mt2: " << endl; a2.tongcot(); cout << endl;
	
	cout << "Tong 4 vien mt1: "; a1.tong4vien(); cout << endl;
	cout << "Tong 4 vien mt2: "; a2.tong4vien(); cout << endl;
	
	cout << "Tong duong cheo chinh cua mt1: "; a1.cheochinh(); cout << endl;
	cout << "Tong duong cheo phu cua mt1: "; a1.cheophu(); cout << endl;
	
	cout << "Tong duong cheo chinh cua mt2: "; a2.cheochinh(); cout << endl;
	cout << "Tong duong cheo phu cua mt2: "; a2.cheophu(); cout << endl;
	
	cout << "Tong cua 2 ma tran: " << endl;
	arr res = a1.tong(a2);
	res.xuat();
	
	return 0; 
}