#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>

using namespace std;

//class SP1
class SP1{
    protected:
        int a,b;
    public:
        SP1();
        SP1(int a, int b);

        void input();
        void display();

        friend ostream& operator << (ostream& out, SP1& obj);
};

SP1::SP1(){
    a = 0;
    b = 0;
}

SP1::SP1(int a, int b){
    this -> a = a;
    this -> b = b;
}

void SP1::input(){
    cout << "So Thuc Co Dang a+bi.\n";
    cout << "Phan Thuc (a): ";
    cin >> a;
    cout << "Phan Ao (b): ";
    cin >> b;
}

void display_b(int b){
    if(b < 0){
        cout << b;
    }
    else{
        cout << "+" << b;
    }
}

void SP1::display(){
    cout << a;
    display_b(b);
    cout <<"i";
}

ostream& operator << (ostream& out, SP1& obj){
    out << obj.a;
    display_b(obj.b);
    out << "i";
    
    return out;
}


//class SP2
class SP2: public SP1{
    public:
        SP2();
        SP2(int a, int b);

        SP2 operator = (SP2& obj){
            this -> a = obj.a;
            this -> b = obj.b;
        }

        bool operator < (SP2 obj){
            double sp1 = sqrt(a*a + b*b);
            double sp2 = sqrt(obj.a*obj.a + obj.b*obj.b);

            return sp1 < sp2;
        }

        friend ostream& operator << (ostream& out, SP2& obj);
};

SP2::SP2(){
    a = 0;
    b = 0;
}

SP2::SP2(int a,int b):SP1(a,b){
    this -> a = a;
    this -> b = b;
}

ostream& operator << (ostream& out, SP2& obj){
    out << obj.a;
    display_b(obj.b);
    cout <<"i";
    
    return out;
}

SP2 find_max(SP2 obj[10], int n){
    SP2 obj_max = obj[0];
    for(int i=1; i<n; i++){
        if(obj_max < obj[i]){
            obj_max = obj[i];
        }
    }
    return obj_max;
};

int main(){
    int n;
    cout <<"Nhap N: ";
    cin >> n;

    SP2 a[10];
    for(int i=0; i<n; i++){
        cout << "Nhap SP "<< i <<" : ";
        a[i].input();
        cout << endl;
    }
    SP2 spMax = find_max(a,n);
    cout << "SP Lon Nhat: ";
	cout << spMax;

//    system("pause");
}
