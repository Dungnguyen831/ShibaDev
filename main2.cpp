#include <iostream>
#include <math.h>
using namespace std;

class sophuc{
	protected:
		int pt;
		int pa;
	public: 
		sophuc(){
			pt = 0;
			pa = 0;
		}
		sophuc(int pthuc, int pao){
			pt = pthuc;
			pa = pao;
		}
		~sophuc(){
		}
		
		friend istream &operator >> (istream &is, sophuc &a){
			cout << "Nhap phan thuc: "; is >> a.pt;
			cout << "Nhap phan ao: "; is >> a.pa;
			return is;
		}
		friend ostream &operator << (ostream &os, sophuc a){
			cout << a.pt << " + " << a.pa << "*i";
			return os;
		}
		float md() const{
			return sqrt(pt*pt + pa*pa);
		}
		sophuc operator + (const sophuc &a){
			sophuc tong;
			tong.pt = pt + a.pt;
			tong.pa = pa + a.pa;
			return tong;
		}
		sophuc operator - (const sophuc &a){
			sophuc hieu;
			hieu.pt = pt - a.pt;
			hieu.pa = pa - a.pa;
			return hieu;
		}
		sophuc operator * (const sophuc &a){
			sophuc tich;
			tich.pt = (pt*a.pt - a.pa*pa);
			tich.pa = (pt*a.pa + a.pt*pa);
			return tich;
		}
		sophuc operator / (const sophuc &a){
			sophuc thuong;
			thuong.pt = (pt*a.pt + pa*a.pa)/(a.pa * a.pa + a.pt * a.pt);
			thuong.pa = (pa*a.pt - pt*a.pa)/(a.pa * a.pa + a.pt * a.pt);
			return thuong;
		}
};

class sophuc2: public sophuc{
	
	public:
		sophuc2 operator = (const sophuc2 &a){
			this->pt = a.pt;
			this->pa = a.pa;
			return *this;
		}
		
		bool operator > (const sophuc2 &a){
			return this->md() > a.md();
		}
		
		bool operator < (const sophuc2 &a){
			return this->md() < a.md();
		}
		
		bool operator == (const sophuc2 &a){
			return this->pt == a.pt && this->pa == a.pa; 
		}
};

int main (){
	sophuc2 sp[10];
	cout << "Nhap so phan tu: ";
	int n; cin >> n;
	
	for (int i = 0; i < n; i++){
		cout << "Nhap so phuc thu " << i + 1 << endl;
		cin >> sp[i];
	}
	
	for (int i = 0; i < n; i++){
		cout << "Nhap so phuc thu " << i + 1 << ": ";
		cout << sp[i] << endl;
	}
	
	for (int i = 0; i < n; i ++){
		for (int j = i + 1; j < n; j ++){
			if (sp[i].md() > sp[j].md()){
				sophuc2 temp = sp[j];
				sp[j] = sp[i];
				sp[i] = temp;
			}
		}
	}	
	cout << "Danh sach so phuc theo thu tu tang dan: " << endl;
	for (int i = 0; i < n; i++){
		cout << sp[i] << endl;
	}
}