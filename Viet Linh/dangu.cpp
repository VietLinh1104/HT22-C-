#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

// test 

char abc(int n){
    switch (n)
    {
    case 0:
        return 'A';
        break;

    case 1:
        return 'B';
        break;
        
    case 2:
        return 'C';
        break;
        
    case 3:
        return 'D';
        break;
        
    case 4:
        return 'E';
        break;
        
    case 5:
        return 'F';
        break;
        
    case 6:
        return 'J';
        break;
    
    case 7:
        return 'H';
        break;
        
    case 8:
        return 'I';
        break;
        
    case 9:
        return 'J';
        break;
        
    default:
        break;
    }
}

class DaThuc{
    private:
        int n;
        int heSo[100];

    public:
        void input();
        void display();

        int getHeSo(int n);
        int getN();

        friend DaThuc operator + (DaThuc & obj1, DaThuc & obj2);
        friend DaThuc operator - (DaThuc & obj1, DaThuc & obj2);

        friend istream& operator >> (istream& in, DaThuc& obj);
        friend ostream& operator << (ostream& out, DaThuc& obj);

};

void DaThuc::input(){
    cout << "Nhap bac: "; cin >> n;
    for(int i=0; i<n; i++){
    	cout << "he so:";
        cin >> heSo[i];
    }
}

void DaThuc::display(){
    cout << "Da thuc: ";
    cout << "P(x)= ";
    for(int i=0; i<n; i++){
        if(i != 0 && heSo[i] > 0){
            cout << "+";
        }
        cout << heSo[i];
	
	    int j;

        if(i==0){
            j = n;
        }

        if(j>0){
            cout << "(x"<<j<<")";
            j--;
        }
    }
}

int DaThuc::getHeSo(int n){
    return heSo[n];
}

int DaThuc::getN(){
    return n;
}

DaThuc operator + (DaThuc & obj1, DaThuc & obj2){
    DaThuc result;

    for(int i=0; i< obj1.n; i++){
        result.heSo[i] = obj1.heSo[i] + obj2.heSo[i];
    }
    result.n = obj1.n;
    cout << "(n = " <<obj1.n <<")"<< endl;
    return result;
}

DaThuc operator - (DaThuc & obj1, DaThuc & obj2){
    DaThuc result;

    for(int i=0; i< obj1.n; i++){
        result.heSo[i] = obj1.heSo[i] - obj2.heSo[i];
    }
    result.n = obj1.n;
    return result;
}

istream& operator >> (istream& in, DaThuc& obj){
    cout << "Nhap bac: "; cin >> obj.n;
    cout <<"Da thuc co dang: ";
    cout << "P(x)= ";
    for(int i=0; i< obj.n ; i++){
        if(i != 0 && obj.heSo[i] > 0){
            cout << "+";
        }
        cout << abc(i);

	    int j;

        if(i==0){
            j = obj.n;
        }

        if(j>0){
            cout << "(x"<<j<<")";
            j--;   
        }
    }

    cout << endl;

    for(int i=0; i<obj.n; i++){
    	cout << "He so " <<abc(i) << ": ";
        in >> obj.heSo[i];
    }
    return in;
    
}

ostream& operator << (ostream& out, DaThuc& obj){
    cout << "P(x)= ";
    for(int i=0; i< obj.n ; i++){
        if(i != 0 && obj.heSo[i] > 0){
            cout << "+";
        }
        cout << obj.heSo[i];
	
	    int j;

        if(i==0){
            j = obj.n;
        }

        if(j>0){
            cout << "(x"<<j<<")";
            j--;
        }
    }

    return out;
}

int main(){
    DaThuc a,b,c;
    cin >> a;
    cin >> b;
    c=a-b;
    cout << "c= a-b = "<<c;
}