/* 
 * File:   main.cpp
 * Author: Tay
 *
 * Created on May 28, 2014, 1:08 PM
 */

#include "Checking.h"
#include "HashFunctions.h"
#include <cmath>
#include <iomanip>
#include <fstream>

void login();
void loginDemo();
void accountDetails(const Checking<float>&);
void projectedGrowth(const Checking<float>&);
void newEntry(Checking<float>&);
void printEntry(const Checking<float>&);
void changeEntry(Checking<float>&);
void accountMenu(Checking<float>&);
void balance(const Checking<float>&);
void deposit(Checking<float>&);
void withdraw(Checking<float>&);
void accounts(Checking<float>&,Checking<float>&,Checking<float>&,Checking<float>&);
void search();
int *createBitVector(int);
unsigned int modHash(unsigned int, int);
void test(int *, int);

using namespace std;
//main function
int main(int argc, char** argv) {
    cout<<"******Welcome to Mr. Spock Banking******"<<endl;
    int choice;
    do
    {
        login();
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
            case 1: loginDemo();
                break;
            case 2: search();
                break;
            case 3: cout<<"Program closing.\n";
                return 0;
                break;
            default: cout<<"Invalid Selection. Please try entering a valid command.\n\n";
                break;
         }
    }while(choice!=3);
    return 0;
}
//first menu
void login()
{
    cout<<"\nYou have the following options:"<<endl;
    cout<<"1. Accounts Demo\n";
    cout<<"2. Account Search Demo\n";
    cout<<"3. Exit\n";
}
//login using fstream
void loginExisting()
{
    cout<<"Option currently unavailabe\n";
}
//demo for class
void loginDemo()
{   
    Checking<float> checkings(1000,0,1);
    Checking<float> savings(2000,.02,2);
    Checking<float> premSavings(2000,.07,4);
    Checking<float> mutualFund(2000,.12,1);
    newEntry(checkings);
    cout<<"\nAccess granted. Welcome Mr. "<<checkings.getLastName()<<". You have the following options:"<<endl;
                
                int choice;
                do
                {
                    cout<<"\n1. Access Banking and Investment Accounts\n";
                    cout<<"2. View Personal Information\n";
                    cout<<"3. Change Personal Information\n";
                    cout<<"4. Return to Previous Menu\n";
                    cin>>choice;
                    cin.ignore(); 
                    switch (choice)
                    {
                        case 1: accounts(checkings,savings,premSavings,mutualFund);
                            break;
                        case 2: printEntry(checkings);
                            break;
                        case 3:changeEntry(checkings);
                            break;
                        case 4: cout<<"Demo accounts have been reset to default values.\n";
                            return;
                            break;
                        default: cout<<"Invalid Selection. Please try entering a valid command.\n\n";
                                break;        
                    }
                }while(choice!=4);
}
//changes record data
void changeEntry(Checking<float>& c)
{
    int choice;
    string temp;
    do
    {
        cout<<"\n1. Change First Name"<<endl;
        cout<<"2. Change Last Name"<<endl;
        cout<<"3. Change Address"<<endl;
        cout<<"4. Change Zip"<<endl;
        cout<<"5. Change Phone Number"<<endl;
        cout<<"6. Change Password"<<endl;
        cout<<"7. Return to Previous Menu\n";
        cin>>choice;
        cin.ignore(); 
        switch (choice)
        {   
            case 1: cout<<"Enter New Last Name: ";
                    getline(cin, temp);
                    c.setFirstName(temp);
                    break;
            case 2: cout<<"Enter New First Name: ";
                    getline(cin, temp);
                    c.setLastName(temp);
                    break;
            case 3: cout<<"Enter New Adress: ";
                    getline(cin, temp);
                    c.setAddress(temp);
                    break;        
            case 4: cout<<"Enter New Zip: ";
                    getline(cin, temp);
                    c.setZip(temp);
                    break;        
            case 5: cout<<"Enter New Phone Number: ";
                    getline(cin, temp);
                    c.setPhone(temp);
                    break;
            case 6: cout<<"Enter New Password: ";
                    getline(cin, temp);
                    c.setPassword(temp);
                    break;        
            case 7: return;
                    break;
            default:
                    cout<<"Invalid Selection. Please try entering a valid command.\n\n";
                    break;
        }
    }while(choice!=7);
}
//opens the account menu
void accounts(Checking<float>& checkings,Checking<float>& savings,Checking<float>& premSavings,Checking<float>& mutualFund)
{
    int choice;
     cout<<"\nWhich account would you like to access?\n";
                do
                {       cout << setprecision(2) << fixed;
                    cout<<"1. Checking Account\n";
                    cout<<"2. Savings Account\n";
                    cout<<"3. High Yield Savings Account\n";
                    cout<<"4. Mutual Fund Account\n";
                    cout<<"5. Sum Total of Accounts\n";
                    cout<<"6. Return to Previous Menu\n";
                        cin>>choice;
                        cin.ignore(); 
                        switch (choice)
                        {
                            case 1: 
                                accountMenu(checkings);
                                break;
                            case 2:
                                accountMenu(savings);
                                break;
                            case 3:
                                accountMenu(premSavings);
                                    break;
                            case 4:accountMenu(mutualFund);
                                    break;
                            case 5:  
                                float total;
                                total=checkings.getBalance()+savings.getBalance()+premSavings.getBalance()+mutualFund.getBalance();
                                cout<<"Sum Total: $"<<total<<endl;
                                return;
                            case 6:  
                                return;
                                break;
                            default: cout<<"Invalid Selection. Please try entering a valid command.\n\n";
                                break;    
                         }
                }while(choice!=6);
}
//creates a new account
void createID()
{
    cout<<"Option currently unavailabe\n";
}
//sets new information for a records
void newEntry(Checking<float>& c)
{
    string temp;
    cout<<"Okay, let's set up a new account."<<endl;
    cout<<"Enter your credentials and a new account under your name will be created."<<endl;
    cout<<"First Name: ";
    getline(cin, temp);
    c.setFirstName(temp);
    cout<<"Last Name: ";
    getline(cin, temp);
    c.setLastName(temp);
    cout<<"Address: ";
    getline(cin, temp);
    c.setAddress(temp);
    cout<<"Zip: ";
    getline(cin, temp);
    c.setZip(temp);
    cout<<"Phone Number: ";
    getline(cin, temp);
    c.setPhone(temp);
    cout<<"Password: ";
    getline(cin, temp);
    c.setPassword(temp);
}
//prints record information
void printEntry(const Checking<float>& c)
{
    cout<<"\nFirst Name: "<<c.getFirstName()<<endl;
    cout<<"Last Name: "<<c.getLastName()<<endl;
    cout<<"Address: "<< c.getAddress()<<endl;
    cout<<"Zip: "<<c.getZip()<<endl;
    cout<<"Phone Number: "<<c.getPhone()<<endl;
    cout<<"Password: "<<c.getPassword()<<endl;
}
//account menu
void accountMenu(Checking<float>& c)
{
    int choice;
    do
    {
        cout<<"\n1. View Account Balance\n";
        cout<<"2. Make a Deposit\n";
        cout<<"3. Make a Withdrawal\n";
        cout<<"4. View Transaction History\n";
        cout<<"5. Search by Transaction Number\n";
        cout<<"6. View Account Details\n";
        cout<<"7. Projected Growth\n";
        cout<<"8. Return to Previous Menu\n";
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
        case 1: balance(c);
                break;
        case 2: deposit(c);
                break;
        case 3: withdraw(c);
                break;
        case 4: c.printTransactions();
                cout<<"Remaining Balance: $"<<c.getBalance()<<endl;
                break;         
        case 5: 
                cout<<"Which transaction number would you like to view?"<<endl;
                int view;
                cin>>view;
                cin.ignore();
                // the next is a use of the overloaded [] operator as defined in Account.h
                if(c[view-1]>=0)
                    cout<<"The value of transaction "<<view<<" is $" <<c[view-1]<<"."<<endl;
                else
                    cout<<"The value of transaction "<<view<<" is -$" <<-c[view-1]<<"."<<endl;
                break;
        case 6: accountDetails(c);
                break;
        case 7: projectedGrowth(c);
                break;            
        case 8:
                break;
        default: cout<<"Invalid Selection. Please try entering a valid command.\n\n";
                break;    
        }
   }while(choice!=8);
}
//prints account details
void accountDetails(const Checking<float>& c)
{   
    cout<<"\nBalance: $"<<c.getBalance()<<endl;
    cout<<"Interest: "<<100*c.getInterest()<<"%"<<endl;
    cout<<"Times Compounded Per Year: "<<c.getCompound()<<endl;
}
//prints compounded interest formula result
void projectedGrowth(const Checking<float>& c)
{
    float years;
    float amount;
    float base;
    float power;
    cout<<"For how many years will it be invested?"<<endl;
    cin>>years;
    cin.ignore();
    while(years<0)
    {
        cout<<"Year amount must be positive. Try again."<<endl;
        cin>>years;
        cin.ignore();
    }
    base=(1+(c.getInterest()/c.getCompound()));
    power=c.getCompound()*years;
    cout<<"Based upon a principle amount of $"<<c.getBalance()<<" compounded "<<c.getCompound()<<" times a year at an interest rate of "<<100*c.getInterest()<<" % for "<<years<<" years..."<<endl;
    amount=c.getBalance()*pow(base, power);
    cout<<"You can expect to have a balance of $"<<amount<<"."<<endl;
}
//prints current balance
void balance(const Checking<float>& c)
{
    cout<<"Current Balance: $"<<c.getBalance()<<endl;
}
//adds money to the account
void deposit(Checking<float>& c)
{
    float amount;
    cout<<"How much would you like to deposit?\n";
    cin>>amount;
    cin.ignore();
    c.deposit(amount);
    c.inputData(amount);
    cout<<"New Balance: $"<<c.getBalance()<<endl;
}
//substracts money from the account
void withdraw(Checking<float>& c)
{
    float amount;
    cout<<"How much would you like to withdraw?\n";
    cin>>amount;
    cin.ignore();
    c.withdraw(amount);
    c.inputData(-amount);
    cout<<"New Balance: $"<<c.getBalance()<<endl;
}
//searches record array for account existence using BLOOM FILTER
void search()
{   int size=1000;
    const int numOfAccount=10;
    unsigned int hash1, hash2;
    //create vector array
    int *vector=createBitVector(size);
    //instantiate classes
    Checking<float> account[]={ Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0),
                                Checking<float>(0,0,0)};
    //set names to store in vector array
    account[0].setLastName("Nesby");
    account[1].setLastName("Smith");
    account[2].setLastName("Red");
    account[3].setLastName("Lehr");
    account[4].setLastName("Garcia");
    account[5].setLastName("Obama");
    account[6].setLastName("Clinton");
    account[7].setLastName("Lincoln");
    account[8].setLastName("Park");
    account[9].setLastName("Lee");
    //store strings as hashes in vector array
    for(int i=0;i<numOfAccount;i++)
    {
        //hash the keys
        hash1=PJWHash(account[i].getLastName());
        hash2=DJBHash(account[i].getLastName());
        //mod the hash until it fits in the vector
        hash1=modHash(hash1, size);
        hash2=modHash(hash2, size);
        //save the results into the vector
        vector[hash1]=1;
        vector[hash2]=1;
    }
    //search to see if it is possibly in the bit vector
   char choice;
   do
   {
       if(toupper(choice)=='N')
       {
            break;
       }
       test(vector, size);
       cout<<"Enter Y to run again? ";
       cin>>choice;
       cin.ignore();
   }while(toupper(choice)=='Y');
   float falsePositive=1-exp(2*500/size);
   falsePositive=falsePositive*falsePositive;
   cout<<"False Positive Rate: "<<falsePositive<<endl;
   delete [] vector;
}
//tests for existence
void test(int *a, int s)
{
    string test;
    bool found=false;
    cout<<"Input the last name of the account to test for membership: ";
    getline(cin,test);
    cout<<"Searching account by last name...."<<endl;
    unsigned int test1=PJWHash(test);
    unsigned int test2=DJBHash(test);
    test1=modHash(test1,s);
    test2=modHash(test2,s);
    for(int i=0;i<s;i++)
    {
        if((a[i]==1) && (i==test1 || i==test2))
        {
            found=true;
        }
    }
    if(found)
    {
        cout<<"Possible Match."<<endl;
    }
    else 
    {
        cout<<"Unable to Locate."<<endl;
    }
}
//creates bit vector array
int *createBitVector(int n)
{
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        a[i]=0;
    }
    return a;
}
//modifies the original hash to fit inside bit vector
unsigned int modHash(unsigned int h, int size)
{
    while(h>=size)
    {
        h=h%size;
    }
    return h;
}