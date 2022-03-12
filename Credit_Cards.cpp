/*Write a program that prompts the user to enter a credit card number as a long integer and Display whether that card is valid or invalid.
Credit card numbers follow certain patterns. 
A credit card number must have between 13 and 16 digits. It must start with:
 
4 for Visa cards
5 for Master cards
37 for American Express cards
*/

#include<iostream>
#include<cstring>
using namespace std;

class Card{
    public:
    virtual void valid(string num) = 0; 
};

class Master_Card : public Card{
    public:
    void valid(string num){
        if(num.length() != 16){
            cout << "Master card Number length is Invalid" << endl;
            return;
        }
        char f[] = {'1','2','3','4'};
        if(num[0] != '5'){
            cout << "Invalid Card Number!!!!" << endl;
            return;
        }
        for(int i=0;i<4;i++){
            if(f[i] == num[1]){
                cout << "Validating Master Card......." << endl;
                cout << "Card Accepted" << endl;
            }
        }    
    }
};

class Visa : public Card{
    public:
    void valid(string num){
        if(num.length() != 16 && num.length() != 13){
            cout << "Visa card length is not valid" << endl;
            return;
        }
        if(num[0] != '4'){
            cout << "Invalid Card Number!!!!" << endl;
            return;
        } 
        cout << "Validating Visa Card......." << endl;
        cout << "Card Accepted" << endl;
    }
};

class American_Express : public Card{
    public:
    void valid(string num){
        if(num.length() != 15){
            cout << "American express Card length is Invalid" << endl;
            return;
        }

        if((num[0] != '3') && (num[1] != '4' || num[1] != '7')){
            cout << "Invalid Card Number!!!!" << endl;
            return;
        }
        cout << "Validating American Express Card......." << endl;
        cout << "Card Accepted" << endl;
    }
};

int main(){
    cout << "\t\tDemostration of Run-Time Polymorphism" << endl;
    Card *S;
    Master_Card M;
    Visa V;
    American_Express A;
    cout << "\t\t------ Card Entry Details ------" << endl;
    cout << "Enter 1 for Master Card" << endl;
    cout << "Enter 2 for Visa Card" << endl;
    cout << "Enter 3 for American Express" << endl;
    string card;
    int choice;
    cout << endl;
    cout << "Enter the choice from Above: ";
    cin >> choice;
    
    if(choice == 1){
        fflush(stdin);
        cout << "Enter Card number: ";
        getline(cin,card);
        cout << "Validating Master Card using c->valid()\n" << endl;
        S = &M;
        S->valid(card);
    }

    else if(choice == 2){
        fflush(stdin);
        cout << "Enter Card Number: ";
        getline(cin,card);
        cout << "Validating Visa Card using c->valid()\n" << endl;
        S = &V;
        S->valid(card);
    }

    else if(choice == 3){
        fflush(stdin);
        cout << "Enter Card Number: ";
        getline(cin,card);
        cout << "Validating American Express Card using c->valid()\n" << endl;
        S = &A;
        S->valid(card);
    }

    else{
        cout << "Invalid Choice!!!!" << endl;
    }

    return 0;
}