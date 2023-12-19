#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

class SoPhuc{
    protected:
        int a, b;
        float moduleSP;
    
    public:
        SoPhuc();
        SoPhuc(int a, int b);
        
        void input();
        void output();

        int get_a();
        int get_b();
        int module();

        friend istream& operator >>(istream &in, SoPhuc& obj);
        friend ostream& operator <<(ostream &out, SoPhuc& obj);

};

SoPhuc::SoPhuc(){
    a=0;
    b=0;
}

SoPhuc::SoPhuc(int a, int b){
    this->a = a;
    this->b = b;
}

void SoPhuc::input(){
    cout << "So Phuc a + bi. \n Nhap gia tri cho a: ";
    cin >> a;
    cout << "Nhap gia tri cho b: ";
    cin >> b;
}

void SoPhuc::output(){
    cout << a <<" + "<< b << "i"<< endl;
}

int SoPhuc::get_a(){
    return a;
}

int SoPhuc::get_b(){
    return b;
}

int SoPhuc::module(){
    moduleSP = sqrt((a*a)+(b*b));
    return moduleSP;
}
istream& operator >>(istream &in, SoPhuc& obj){
    cout << "So Phuc a + bi. \nNhap gia tri cho a: ";
    in >> obj.a;
    cout << "Nhap gia tri cho b: ";
    in >> obj.b;
}

ostream& operator << (ostream &out, SoPhuc& obj){
    cout << obj.a <<" + "<< obj.b << "i"<< endl;
    return out;
}

class SoPhuc2 : public SoPhuc{
    public:

        SoPhuc2 operator + (SoPhuc2& obj){
         	SoPhuc2 total;
            total.a = a + obj.a;
            total.b = b + obj.b;
            return total;
        }

        bool operator > (SoPhuc2& obj){
            return moduleSP > obj.moduleSP;
        }
        bool operator < (SoPhuc2& obj){
            return moduleSP < obj.moduleSP;
        }

        bool operator == (SoPhuc2 &obj){
            return moduleSP == obj.moduleSP;
        }
};



int main(){
    SoPhuc2 obj1;
    SoPhuc2 obj2;

    cin >> obj1;
    cin >> obj2;

  	SoPhuc2 obj3 = (obj2 + obj1);
  	
  	cout << obj3.module();
  	
    
}
