#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class NhanVien{
    private:
        string hoTen, chucVu, gioiTinh, queQuan;
        int namSinh, namVao;

    public:
        friend istream& operator >> (istream& in, NhanVien& obj);
        friend ostream& operator << (ostream& out, NhanVien& obj);

        int get_namVao();

};

istream& operator >> (istream& in, NhanVien& obj){
    cout << "Ho Ten: "; in.ignore();
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

int NhanVien::get_namVao(){
    return namVao;
}

int sonam_vaolam(int namVao, int namHT){
    int soNam = namVao - namHT;
    return soNam;
}

void list_header(){
    cout <<"|"<< left<< setw(14)<< "Ho Ten";
    cout <<"|"<< left<< setw(10)<< "Nam Sinh";
    cout <<"|"<< left<< setw(10)<< "GT";
    cout <<"|"<< left<< setw(14)<< "Que Quan";
    cout <<"|"<< left<< setw(10)<< "Nam Vao";
    cout <<"|"<< left<< setw(10)<< "Chuc Vu"<<"|";
}

int main(){
    int n,ynow;
    cout << "Nhap N: ";
    cin >> n;
    cout << "Nam Hien Tai: ";
    cin >> ynow;

    NhanVien a[n];
    for(int i=0; i<n; i++){
        cout <<"Nhap NV So "<<i<<" : \n";
        cin >> a[i];
        cout << endl;
    }

    cout << "Danh Sach Nhan Vien: \n";
    list_header();cout << endl;
    for(int i=0; i<n; i++){
        cout << a[i]<< endl;
    }

    cout << "Danh Sach Nhan Vien Tren 20 Nam: \n";
    list_header();cout << endl;
    for(int i=0; i<n; i++){
        if(sonam_vaolam(a[i].get_namVao(),ynow )>20){
            cout << a[i];
        }
    }
    



}
