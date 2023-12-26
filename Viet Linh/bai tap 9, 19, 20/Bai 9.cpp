#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//8-21 class Nhan vien
class NhanVien{
    private:
        //10-11 thuoc tinh class
        string hoTen, chucVu, gioiTinh, queQuan;
        int namSinh, namVao;

    public:
        //15-16 khoi tao nap chong toan tu nhap xuat
        friend istream& operator >> (istream& in, NhanVien& obj);
        friend ostream& operator << (ostream& out, NhanVien& obj);

        // 19 khoi tao get nam vao lam
        int get_namVao();
};

//24-50 xay dung toan tu nhap xuat
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

// 53-55 get nam vao lam
int NhanVien::get_namVao(){
    return namVao;
}

//58-61 ham tinh so nam vao lam
int sonam_vaolam(int namVao, int namHT){
    int soNam = namVao - namHT;
    return soNam;
}

// ham in ra list header
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
