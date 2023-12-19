#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class PS1{
    protected:
        int ts,ms;

    public:

        //constructor
        PS1();
        PS1(int ts, int ms);

        //operator overloader in/out
        
        //method
        void input();
        void output();

        void toigian();
};

//constructor
PS1::PS1(){
    ts = 0;
    ms = 0;
}

PS1::PS1(int ts, int ms){
    this->ts=ts;
    this->ms=ms;
}

//method
void PS1::input(){
    cout << "Nhap Tu So: ";
    cin >> ts;

    cout << "Nhap Mau So : " ;
    cin >> ms; 
    cout << "\n";
}

void PS1::output(){
    cout << "Phan So: ";
    if (ms==0){
        cout << "Mau so khong the bang 0.";
    }else{
        cout << ts <<"/"<<ms<<".\n";
    }
} 

int UCLN(int a,int b){
    while(b !=0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void PS1::toigian(){
    int uc = UCLN(ts,ms);
    ts = ts/ uc;
    ms = ms/ uc;

}

class PS2 : public PS1{
    private:
    public:
        PS2();
        PS2(int ts, int ms);
        bool operator >(PS2& p){
        	return ts* p.ms > p.ts *ms;
		}
		
		bool operator <(PS2& p){
            return ts* p.ms < p.ts *ms;
        }

        friend istream& operator >>(istream &in, PS2& obj);
        friend ostream& operator <<(ostream &out, PS2& obj);
};

istream& operator >>(istream &in, PS2& obj){
    cout <<"TS: ";
    in >> obj.ts;

    cout <<"MS: ";
    in >> obj.ms;
}

ostream& operator <<(ostream &out, PS2& obj){
    cout << obj.ts <<"/"<< obj.ms;
}

PS2::PS2 (int ts, int ms): PS1(ts,ms){

}

int main(){
    PS2 obj1(6,7);
    PS2 obj2(3,7);

    if(obj1 > obj2){
        cout << obj1 <<" > "<< obj2;
    }
    if(obj1 < obj2){
        cout << obj1 <<" < "<< obj2;
    }

}
