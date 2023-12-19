#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

//class MonHoc
class MonHoc{
    protected:
        string tenMH;
        float diemCC, diemKT, diemThi, GPA;
        
    public:
        //contructor
        MonHoc();
        MonHoc(string tenMH,float diemCC,float diemKT,float diemThi);
};

//contructor MonHoc
MonHoc::MonHoc(){
	tenMH="";
    diemCC=0;
    diemKT=0;
    diemThi=0;
}
MonHoc::MonHoc(string tenMH,float diemCC,float diemKT,float diemThi){
    this-> tenMH=tenMH;
    this-> diemCC=diemCC;
    this-> diemKT=diemKT;
    this-> diemThi=diemThi;
    
}

//class SinhVien
class SinhVien: public MonHoc{
    private:
        string ho_ten, lop, maSV;
        float GPA;
    public:
        //contructor
        SinhVien();
        SinhVien(string ho_ten, string lop, string maSV, string tenMH, float diemCC, float diemKT, float diemThi);

        //get method
        float getDiemKT();
        float getDiemCC();
        float getGPA();

        //operator overloader
        friend istream& operator >> (istream &in, SinhVien& obj);
        friend ostream& operator << (ostream &out, SinhVien& obj);
};

//constructor SinhVien
SinhVien::SinhVien(){
    ho_ten="";
    lop="";
    maSV="";
}
SinhVien::SinhVien(string ho_ten, string lop, string maSV, string tenMH, float diemCC, float diemKT, float diemThi): MonHoc(tenMH,diemCC,diemKT,diemThi){
    this->ho_ten=ho_ten;
    this->lop=lop;
    this->maSV=maSV;
}

//operator overloader in/out
istream& operator >> (istream &in, SinhVien& obj){
    cout << "Ho Ten: "; in.ignore();
    getline(in,obj.ho_ten);

    cout <<"Lop: ";
    in >> obj.lop;

    cout <<"Ma SV: ";
    in >> obj.maSV;

    cout <<"Mon Hoc: ";in.ignore();
    getline(in,obj.tenMH);

    cout <<"Diem Chuyen Can: ";
    in >> obj.diemCC;

    cout <<"Diem Kiem Tra: ";
    in >> obj.diemKT;
     
    cout <<"Diem Thi: ";
    in >>obj.diemThi;

    return in;
}
ostream& operator << (ostream &out, SinhVien &obj){
    cout <<"|"<<left <<setw(20) << obj.ho_ten <<"|";
    cout << left << setw(7)<< obj.lop << "|";
    cout << left << setw(7)<< obj.maSV << "|";
    cout << left << setw(14)<< obj.tenMH << "|";
    cout << left << setw(7)<< obj.diemCC << "|";
    cout << left << setw(7)<< obj.diemKT << "|";
    cout << left << setw(8)<< obj.diemThi << "|";
    cout << left << setw(8)<< obj.getGPA() << "|";
    cout <<"\n";

    return out;
}

//get GPA
float SinhVien::getGPA(){
    GPA = ((diemCC*10) + (diemKT*40) +(diemThi*60))/100;
    return GPA;
}

float SinhVien::getDiemCC(){
    return diemCC;
}

float SinhVien::getDiemKT(){
    return diemKT;
}

void Table(){
    cout <<"|"<<left <<setw(20) << "Ho Ten" <<"|";
    cout << left << setw(7)<< "Lop" << "|";
    cout << left << setw(7)<< "Ma SV" << "|";
    cout << left << setw(14)<< "Mon Hoc" << "|";
    cout << left << setw(7)<< "Diem CC" << "|";
    cout << left << setw(7)<< "Diem KT" << "|";
    cout << left << setw(8)<< "Diem Thi" << "|";
    cout << left << setw(8)<< "GPA" << "|";
    cout <<"\n";
}

int main(){
    int n;
    cout << "Nhap N: ";
    cin >> n;
    SinhVien obj[n];
	
    cout << obj[0];
	
    for (int i=0; i<n; i++){
        cin >> obj[i];
        cout << "\n";
    }

    Table();
    for (int i=0; i<n; i++){
        cout << obj[i];
    }

    cout <<"Cam Thi \n";
    Table();
    for (int i=0; i<n; i++){
        if(obj[i].getDiemCC() <5 || obj[i].getDiemKT() == 0){
            cout << obj[i];
        }
    }
}
