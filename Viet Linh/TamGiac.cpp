#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

class Diem{
    protected:
        int x,y;
    public:
        void input();
        void display();

        friend Diem operator - (Diem& obj);
};

void Diem::input(){
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
}

void Diem::display(){
    cout<< "A("<<x <<","<<y <<")"; 
}

main(){
    Diem a;
    a.input();
    a.display();
}
