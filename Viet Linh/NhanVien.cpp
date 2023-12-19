#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

class NhanVien{
    private:
        string hoTen, chucVu, gioiTinh, queQuan;
        int namSinh, namVao;

    public:
        friend istream& operator >> (istream& in, NhanVien& obj);
        friend ostream& operator << (ostream& out, NhanVien& obj);

};

istream& operator >> (istream& in, NhanVien& obj){
    cout << "Ho Ten: "; //in.ignore();
    getline(in, obj.hoTen);

    cout << "Nam Sinh: "; in >> obj.namSinh;
    cout << "Gioi Tinh: "; in.ignore();
    getline(in, obj.gioiTinh);

    cout << "Que Quan: "; //in.ignore();
    getline(in, obj.queQuan);

    cout << "Nam Vao: ";in >> obj.namVao;

    cout << "Chuc Vu: ";in.ignore();
    getline(in, obj.chucVu);

    return in;
}

ostream& operator << (ostream& out, NhanVien& obj){
    cout <<"|"<< left<< setw(14)<< obj.hoTen;
    cout <<"|"<< left<< setw(10)<< obj.namSinh;
    cout <<"|"<< left<< setw(10)<< obj.gioiTinh;
    cout <<"|"<< left<< setw(14)<< obj.queQuan;
    cout <<"|"<< left<< setw(10)<< obj.namVao;
    cout <<"|"<< left<< setw(10)<< obj.chucVu<<"|";
}

main(){
    NhanVien a;
    cin >> a;
    cout << a;
}
