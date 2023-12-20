#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int UCLN(int a, int b){
	while(b != 0){
		int r= a%b;
		a = b;
		b = r;
	}
	return a;
}

class PhanSo1{
	protected:
		int ts,ms;

	public:
		friend istream& operator >> (istream& in, PhanSo1& obj);
		friend ostream& operator << (ostream& out, PhanSo1 obj);

		void toi_gian();
};

void PhanSo1::toi_gian(){
	int uc = UCLN(ts,ms);
	ts = ts/uc;
	ms = ms/uc;
}

istream& operator >> (istream& in, PhanSo1&obj){
	cout<<"\n nhap tu so: "; in >> obj.ts;
	
	do{
		cout<<"\n nhap mau so:  ";
		in >> obj.ms;
		if(obj.ms<=0){
			cout << "Mau so khong the nho hon hoac bang 0";
		}
	}while(obj.ms <= 0);
}

ostream& operator << (ostream& out, PhanSo1 obj){
	out<<obj.ts<<"/"<<obj.ms;
	return out;
}

class PhanSo2:public PhanSo1{
	public:
		bool operator < (PhanSo2& obj){
			return ts * obj.ms < obj.ts * ms;
		}
		bool operator > (PhanSo2& obj){
			return ts * obj.ms > obj.ts * ms;
		}
};

int main(){
	PhanSo2 a,b;
	cin >> a;
	cin >> b;
	cout << (a<b);
}
