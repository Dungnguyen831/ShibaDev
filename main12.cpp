#include <iostream>
#include <math.h>
using namespace std;

class sinhvien{
	private:
		string hoten;
		string namsinh;
		int d1, d2, d3, d4, d5;
	public:
		sinhvien(){
			hoten = "null";
			namsinh = "null";
			d1 = 0; d2 = 0; d3 = 0; d4 = 0; d5 = 0;
		}
		sinhvien(string ht, string ns, int d1, int d2, int d3, int d4, int d5){
			hoten = ht;
			namsinh = ns;
			this->d1 = d1;
			this->d2 = d2;
			this->d3 = d3;
			this->d4 = d4;
			this->d5 = d5;
		}
		float dtb(){
			return (d1 + d2 + d3 + d4 + d5) / 5;
		}
		string quydoidiem(float a){
			if (a < 3.9 ) return "F"; // F
			if (a >= 4.0 && a < 4.9) return "D"; // D
			if (a >= 5.0 && a < 5.9) return "C"; // C
			if (a >= 6.0 && a < 6.9) return "C+"; // C+
			if (a >= 7.0 && a < 7.9) return "B"; // B
			if (a >= 8.0 && a < 8.4) return "B+"; // B+
			if (a >= 8.5 ) return "A"; //A
		}
		int ktratn(){
			if (dtb() < 7 && (d1 >= 5) && (d2 >= 5) && (d3 >= 5) && (d4 >= 5) && (d5 >= 5)) return 1;
			if (dtb() >= 7 && (d1 >= 5) && (d2 >= 5) && (d3 >= 5) && (d4 >= 5) && (d5 >= 5)) return 2;
		}
		void nhap(){
			cout << "Nhap ho ten: "; 
			cin.ignore();
			getline (cin, hoten);
			cout << "Nhap nam sinh: ";
			cin >> namsinh;
			cout << "Nhap diem 5 mon: ";
			cin >> d1 >> d2 >> d3 >> d4 >> d5;
		}
		void xuat (){
			cout << "Ho ten: " << hoten << endl;
			cout << "Nam sinh: " << namsinh << endl;
			cout << "Diem 5 mon " << d1 << "/" << d2 << "/" << d3 << "/" << d4 << "/" << d5 << endl;
		}
		bool ktrathilai(){
			bool thilai = false;
			if (d1 < 5){
				cout << "Thi lai mon d1!";
				thilai = true;	
			}
			if (d2 < 5){
				cout << "Thi lai mon d2!";
				thilai = true;	
			}
			if (d3 < 5){
				cout << "Thi lai mon d3!";
				thilai = true;	
			}
			if (d4 < 5){
				cout << "Thi lai mon d4!";
				thilai = true;	
			}
			if (d5 < 5){
				cout << "Thi lai mon d5!";
				thilai = true;	
			}
			return thilai;
		}
		void diemcacmon(){
			cout << "d1= " << d1 << "->"<< quydoidiem(d1) << endl;
			cout << "d2= " << d2 << "->"<< quydoidiem(d2) << endl;
			cout << "d3= " << d3 << "->"<< quydoidiem(d3) << endl;
			cout << "d4= " << d4 << "->"<< quydoidiem(d4) << endl;
			cout << "d5= " << d5 << "->"<< quydoidiem(d5) << endl;
		}
};

int main (){
	int n;
	cout << "Nhap so sinh vien: "; cin >> n;
	sinhvien* sv = new sinhvien[n];
	
	for (int i = 0; i < n; i ++){
		sv[i].nhap();
	}
	
	cout << "Danh sach sinh vien phai thi lai: " << endl;
	for (int i = 0; i < n; i ++){
		if (sv[i].ktrathilai() == true){
			sv[i].xuat();
			cout << endl;
		}
	}
	
	cout << "Danh sach sinh vien phai thi tot nghiep: " << endl;
	for (int i = 0; i < n; i ++){
		if (sv[i].ktratn() == 1){
			sv[i].xuat();
			cout << endl;
		}
	}
	
	cout << "Danh sach sinh vien du dieu kien la do an tot nghiep: " << endl;
	for (int i = 0; i < n; i ++){
		if (sv[i].ktratn() == 2){
			sv[i].xuat();
			cout << endl;
		}
	}
	
	cout << "Quy doi diem cac mon cua tung sinh vien: " << endl;
	for (int i = 0; i < n; i ++){
		sv[i].xuat(); 
		sv[i].diemcacmon();
		cout << endl;
	}
	
	delete[] sv;
	return 0;
}