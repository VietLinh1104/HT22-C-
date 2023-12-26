#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>

using namespace std;

// 8-22 class SP1
class SP1{
    //thuoc tinh class
    protected:
        int a,b;
    public:
        //14-15 tao ham tao
        SP1();
        SP1(int a, int b);

        void input();
        void display();

        friend ostream& operator << (ostream& out, SP1& obj);   //khoi tao in ra so phuc
};

//24-64 xay dung cac ham da tao
SP1::SP1(){     //ham khoi tao
    a = 0;
    b = 0;
}

SP1::SP1(int a, int b){     //ham khoi tao
    this -> a = a;
    this -> b = b;
}

void SP1::input(){                      //ham nhap
    cout << "So Thuc Co Dang a+bi.\n";
    cout << "Phan Thuc (a): ";
    cin >> a;
    cout << "Phan Ao (b): ";
    cin >> b;
}

void display_b(int b){      //ham in ra phan ao
    if(b < 0){
        cout << b;
    }
    else{
        cout << "+" << b;
    }
}

void SP1::display(){        //ham in ra so phuc
    cout << a;
    display_b(b);
    cout <<"i";
}

ostream& operator << (ostream& out, SP1& obj){      //toan tu in ra so phuc
    out << obj.a;
    display_b(obj.b);
    out << "i";
    
    return out;
}


//68 - 85 class SP2
class SP2: public SP1{
    public:
        SP2();
        SP2(int a, int b);

        // 74-84 2 toan tu gan va so sanh
        SP2 operator = (SP2& obj){          //ham gan so phuc
            this -> a = obj.a;
            this -> b = obj.b;
        }

        bool operator < (SP2 obj){          //so sanh so phuc
            double sp1 = sqrt(a*a + b*b);
            double sp2 = sqrt(obj.a*obj.a + obj.b*obj.b);

            return sp1 < sp2;
        }
};


//89-97 xay dung 2 ham tao
SP2::SP2(){
    a = 0;
    b = 0;
}

SP2::SP2(int a,int b):SP1(a,b){
    this -> a = a;
    this -> b = b;
}

//function tim sp lon nhat
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
