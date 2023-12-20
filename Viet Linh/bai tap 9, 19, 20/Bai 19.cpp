#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

// 8-15 dung ham tim uoc chung lon nhat
int UCLN(int a, int b){
	while(b != 0){
		int r= a%b;
		a = b;
		b = r;
	}
	return a;
}

// 18-34 class phanso1
class PhanSo1{
	protected:
		//21 thuoc tinh cua class phanso1
		int ts,ms;

	public:
		//25-26 tao ham tao 
		PhanSo1();
		PhanSo1(int ts, int ms);

		//29-30 tạo phương thức nhập xuất nạp chồng toán tử 
		friend istream& operator >> (istream& in, PhanSo1& obj);
		friend ostream& operator << (ostream& out, PhanSo1 obj);

		//33 tạo phương thức tối giản của class PhanSo1
		void toi_gian();
};

//xây dựng các phương thức đã tạo của class PhanSo1
// 38-41 hàm tạo
PhanSo1::PhanSo1(){
	ts = 0;
	ms = 0;
}

// hàm tạo
PhanSo1::PhanSo1(int ts, int ms){
	this -> ts = ts;
	this -> ms = ms;
}

// xây dựng phương thức tối giản phân số
void PhanSo1::toi_gian(){
	int uc = UCLN(ts,ms);
	ts = ts/uc;
	ms = ms/uc;
}

// phương thức nhập bằng operator
istream& operator >> (istream& in, PhanSo1&obj){
	cout<<"Nhap tu so: "; in >> obj.ts;
	
	do{
		cout<<"Nhap mau so: ";
		in >> obj.ms;
		if(obj.ms<=0){
			cout << "Mau so khong the nho hon hoac bang 0\n";
		}
	}while(obj.ms <= 0);
}

// phương thức xuất bằng operator
ostream& operator << (ostream& out, PhanSo1 obj){
	out<<obj.ts<<"/"<<obj.ms;
	return out;
}

// class phân số 2 kế thừa của class phân số 1
class PhanSo2:public PhanSo1{
	public:
		//tạo hàm tạo
		PhanSo2();
		PhanSo2(int ts, int ms);

		bool operator < (PhanSo2& obj){
			return ts * obj.ms < obj.ts * ms;
		}
		bool operator > (PhanSo2& obj){
			return ts * obj.ms > obj.ts * ms;
		}

		PhanSo2 operator = (PhanSo2& obj){
			this -> ts = obj.ts;
			this -> ms = obj.ms;
		}
};

//xây dựng các phương thức đã tạo của class PhanSo2
//hàm tạo
PhanSo2::PhanSo2(){
	ts = 0;
	ms = 0;
}

//hàm tạo
PhanSo2::PhanSo2(int ts, int ms):PhanSo1(ts,ms){
	this -> ts = ts;
	this -> ms = ms;
}

int main(){
	int n;
	cout << "Nhap N: "; cin >> n;
	PhanSo2 a[n];

	for(int i=0; i<n; i++){
		cout << "Nhap phan so "<<i << ": \n";
		cin >> a[i];
	}
	PhanSo2 ps_max = a[0];
	for(int i=1; i<n; i++){
		if(a[i] > ps_max){
			ps_max = a[i];
		}
	}
	cout <<"Phan so lon nhat: "<< ps_max;
}
