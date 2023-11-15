//
//  bankAccount.h
//  bankAccountt
//
//  Created by Kaan Şengün on 14.11.2023.
//
#include <iostream>
using namespace std;

class bankAccount{
private:
    float accountBalance;
    string personName,personSurname,personPhone;
public:
    bankAccount(string name,string surname, float balance=0, string phone_number="0");
    bankAccount(const bankAccount &oth);
    ~bankAccount();
    bool controlNameSurname(const string &nameOrSurname);//A-Z ye kadar olmalı
    bool controlPhoneNumber(const string &phone_number);//11 haneli bir ifade olmalı
    void displayProfile();
    void credit(float);
    void withdraw(float);
    void sendMoney(bankAccount &othAccount, float amount);
    void setPersonName(string name){
        personName=name;
    }
    void setPersonSurname(string surname){
        personSurname=surname;
    }
    void setPersonPhone(string number){
        personPhone=number;
    }
    void setPersonBalance(string amount){
        accountBalance=stof(amount);//string to float
    }
    float getPersonBalance() const{
        return accountBalance;
    }
    string getPersonName() const{
        return personName;
    }
    string getPersonSurname() const{
        return personSurname;
    }
    string getPersonPhone() const{
        return personPhone;
    }
};
bankAccount::bankAccount(string name,string surname,float balance,string phone_number){
    cout<<"Constructor worked"<<endl;
    personName=name;
    personSurname=surname;
    personPhone=phone_number;
    accountBalance=balance;
}
bankAccount::bankAccount(const bankAccount &oth){
    personName=oth.personName;
    personSurname=oth.personSurname;
    personPhone=oth.personPhone;
}
bankAccount::~bankAccount(){
    cout<<"Deconstructure worked."<<endl;
}
bool bankAccount::controlNameSurname(const string &nameOrSurname){
    for(unsigned i=0;i<nameOrSurname.length();i++){
        if(!((nameOrSurname.at(i)>='A')&&(nameOrSurname.at(i)<='Z'))||((nameOrSurname.at(i)>='a')&&(nameOrSurname.at(i)<='z'))){
            return false;
        }
    }
    return true;
}
bool bankAccount::controlPhoneNumber(const string &phone_number){
    if(phone_number.empty()){
        return true;
    }
    if(!(phone_number.length()==11)){
        return false;
    }
    for(unsigned i=0;i<phone_number.length();i++){
        if(!((phone_number.at(i)>='0')&&(phone_number.at(i)<='9')))
            return false;
    }
    return true;
}
void bankAccount::displayProfile() {
    if (personName.empty() || personSurname.empty()) {
        cout << "Profile information is incomplete." << endl;
    } else if((controlNameSurname(personName)==false)||(controlNameSurname(personSurname)==false)){
        cout << "Enter valid characters." << endl;
    }
    else{
        cout << personName << " " << personSurname << " balance=" << accountBalance << " phone number:" << personPhone << endl;
    }
}

void bankAccount::credit(float c){
    accountBalance+=c;
    cout<<"New balance is:"<<accountBalance<<endl;
}
void bankAccount::withdraw(float c){
    if(accountBalance==0){
        cout<<"Current balance is empty."<<endl;
    }
    if(accountBalance<c){
        cout<<"You do not have enough funds to withdraw money."<<endl;
    }
    if(c==0){
        cout<<"Withdrawal amount is invalid."<<endl;
    }
    else{
        accountBalance-=c;
    }
}
void bankAccount::sendMoney(bankAccount &othAccount, float amount){
    if(accountBalance==0){
        cout<<"Current balance is empty. You couldn't send money."<<endl;
    }
    if(accountBalance<amount){
        cout<<"You do not have enough funds to send money."<<endl;
    }
    if(amount==0){
        cout<<"You would send amount is invalid."<<endl;
    }
    else{
        accountBalance-=amount;
        othAccount.accountBalance+=amount;
    }
}
