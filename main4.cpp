#include <iostream>
#include <math.h>
using namespace std;

class time {
	private:
		int h;
		int m;
		int s;
	public:
		time(){
			h = 0;
			m = 0;
			s = 0;
		}
		time(int gio, int phut, int giay){
			h = gio;
			m = phut;
			s = giay;
			chuanhoa();
		}
		~time(){
		}
		friend istream &operator >> (istream &is, time &a){
			cout << "Nhap gio: "; is >> a.h;
			cout << "Nhap phut: "; is >> a.m;
			cout << "Nhap giay: "; is >> a.s;
			a.chuanhoa();
			return is;
		}
		friend ostream &operator << (ostream &os, time &a){
			if (a.h < 10) os << "0";
			os << a.h << ":";
			
			if (a.m < 10) os << "0";
			os << a.m << ":";
			
			if (a.s < 10) os << "0";
			os << a.s ;
		}
		void chuanhoa(){
			if (s >= 60){
				m = m + s / 60;
				s = s % 60;
			}
			if (m >= 60){
				h = h + m / 60;
				m = m % 60;
			}
			if (s < 0){
				m = m - (s / 60) - 1;
				s = 60 + (s % 60);
			}
			if (m < 0){
				h = h - (m / 60) - 1;
				m = 60 + (m % 60);
			}
			if (h >= 24){
				h = h % 24;
			}
			if (h < 0){
				h = (h + 24) % 24;
			}
		}
		void tang1giay(){
			s++;
			if (s >= 60){
				s -= 60;
				m++;
				if (m >= 60){
					m -= 60;
					h = (h+1) % 24;
				}
			}
		}
		
		void giam1giay(){
			s--;
			if (s < 0){
				s = s + 60;
				m--;
				if (m < 0){
					m = m + 60;
					h = (h + 23) % 24;
				}
			}
		}
};

int main (){
	time t1;
	cout << "Nhap gio, phut, giay: " << endl;
	cin >> t1;
	cout << "Gio phut giay: " << t1 << endl;
	t1.giam1giay();
	cout << "Giam 1 giay: " << t1 << endl;
	t1.tang1giay();
	t1.tang1giay();
	cout << "Tang 1 giay: " << t1; 
}