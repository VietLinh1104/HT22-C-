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

		//29-30 tao phuong thuc nhap xuat nap chong toan tu 
		friend istream& operator >> (istream& in, PhanSo1& obj);
		friend ostream& operator << (ostream& out, PhanSo1 obj);

		//33 tao phuong thuc toi gian cua phanso1
		void toi_gian();
};

//xay dung cac phuong thuc da tao cua class
// 38-41 ham tao
PhanSo1::PhanSo1(){
	ts = 0;
	ms = 0;
}

// 44-47 ham tao
PhanSo1::PhanSo1(int ts, int ms){
	this -> ts = ts;
	this -> ms = ms;
}

// 50-54 xay dung phuong thuc toi gian phan so
void PhanSo1::toi_gian(){
	int uc = UCLN(ts,ms);
	ts = ts/uc;
	ms = ms/uc;
}

// 57-67 phuong thuc nhap bang operator
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

// 70-73 phuong thuc xuat bang operator
ostream& operator << (ostream& out, PhanSo1 obj){
	out<<obj.ts<<"/"<<obj.ms;
	return out;
}

// 76-93 class phanso2 ke thua cua class phanso1
class PhanSo2:public PhanSo1{
	public:
		//79-80 tao ham tao
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

//xay dung phuong thuc da tao trong class
// 97-100 ham tao
PhanSo2::PhanSo2(){
	ts = 0;
	ms = 0;
}

// 103-106 ham tao
PhanSo2::PhanSo2(int ts, int ms):PhanSo1(ts,ms){
	this -> ts = ts;
	this -> ms = ms;
}

// ham main
int main(){
	// 111-112 nhap n
	int n;
	cout << "Nhap N: "; cin >> n;

	//115 khai bao DOI TUONG thuoc class phanso2
	PhanSo2 a[n];

	//118-122 dung ham for de nhap n DOI TUONG a
	for(int i=0; i<n; i++){
		cout << "Nhap phan so "<<i << ": \n";
		cin >> a[i];
		cout << endl;
	}

	//125 doi tuong "ps_max" va gan gia tri cua doi tuong "a[0]"
	PhanSo2 ps_max = a[0];

	//128-132 dung for de tim ps nho nhat
	for(int i=1; i<n; i++){
		if(a[i] > ps_max){
			ps_max = a[i];
		}
	}

	cout <<"Phan so lon nhat: "<< ps_max;
	cout << endl;
	system("pause");
}
