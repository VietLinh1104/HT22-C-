#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class MonHoc{                           //7-11 class MonHoc
    protected:
        string tenMon;                  //9-10 thuoc tinh mon hoc
        float diemCC,diemKT,diemThi;
};

class SinhVien: public MonHoc{          //13-25 class SinhVien Ke thua MonHoc
    private:
        string hoTen, tenLop, maSV;     //15-16 thuoc tinh nhan vien
        float GPA;
    public:
        void input();                   //18-19 khoi tao phuong thuc nhap xuat
        void display();

        float getGPA();                 //21-23 khoi tao phuong thuc get
        float getDiemCC();
        float getDiemKT();

};

void SinhVien::input(){                 //27-50 xay dung phuong thuc nhap
	
    cout << "Ho Ten: "; cin.ignore();
    getline(cin,hoTen);

    cout <<"Lop: ";
    cin >> tenLop;

    cout <<"Ma SV: "; cin.ignore();
    getline(cin,maSV);

    cout <<"Mon Hoc: ";cin.ignore();
    getline(cin, tenMon);

    cout <<"Diem Chuyen Can: ";
    cin >> diemCC;

    cout <<"Diem Kiem Tra: ";
    cin >> diemKT;
     
    cout <<"Diem Thi: ";
    cin >> diemThi;
    
}

void SinhVien::display(){                          //52-60 xay dung phuong thuc xuat
    cout <<"|"<<left <<setw(20) << hoTen <<"|";
    cout << left << setw(7)<< tenLop << "|";
    cout << left << setw(7)<< maSV << "|";
    cout << left << setw(7)<< diemCC << "|";
    cout << left << setw(7)<< diemKT << "|";
    cout << left << setw(8)<< diemThi << "|";
    cout << left << setw(8)<< getGPA() << "|";
}

float SinhVien::getGPA(){                           //62-72 xay dung phuong thuc get
    GPA = ((diemCC*10)+(diemKT*30)+(diemThi*60))/100;
    return (GPA/10)*4;
}

float SinhVien::getDiemCC(){
    return diemCC;
}
float SinhVien::getDiemKT(){
    return diemKT;
}

void list_header(){                                 //74-82 xay dung phuong thuc in ra header list
    cout <<"|"<<left <<setw(20) << "Ho Ten" <<"|";
    cout << left << setw(7)<< "Lop" << "|";
    cout << left << setw(7)<< "Ma SV" << "|";
    cout << left << setw(7)<< "Diem CC" << "|";
    cout << left << setw(7)<< "Diem KT" << "|";
    cout << left << setw(8)<< "Diem Thi" << "|";
    cout << left << setw(8)<< "GPA" << "|";
}

int main(){
    int n;
    cout << "Nhap N: "; cin >> n;

    SinhVien a[n];
    for(int i=0; i<n; i++){
        cout << "Nhap SV "<< i << " : \n";
        a[i].input();
        cout << endl;
    }

    cout << endl;

    cout << "Danh Sach Sinh Vien: \n";
    list_header();
    for(int i=0; i<n; i++){
        a[i].display();
        cout << endl;
    }

    cout << endl;

    cout << "Danh Sach Sinh Vien Cam Thi: \n";
    list_header();
    for(int i=0; i<n; i++){
        if(a[i].getDiemCC() < 5 || a[i].getDiemKT() == 0){
            a[i].display();
        }
        cout << endl;
    }

}
