/* Program For exception handling in C++. */
#include<iostream>
#include<exception>
using namespace std;

class MyNation : public exception{
    string sname;
    public:
    MyNation(string name){
        sname = name;
    }
    const char* what(){
        cout << "Invalid Argument" << endl;
    }
};

int main(){
    string name;
    cout << "\t\tDemostration of Exception Handling" << endl;
    cout << "Enter Name: ";
    getline(cin,name);
    try{
        if(name != "jai hind" && name != "JAI HIND"){
            MyNation n(name);
            throw  n;
        }
    }
    catch(MyNation n){
        n.what();
    }
    return 0;
}