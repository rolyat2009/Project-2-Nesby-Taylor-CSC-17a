/* 
 * File:   Account.h
 * Author: Tay
 *
 * Created on May 28, 2014, 1:09 PM
 */

#ifndef ACCOUNT_H
#define	ACCOUNT_H
#include <iostream>
#include <cstdlib>
#include <new>
#include "Record.h"

// abstract base class template for all accounts
template <class T>
class Account : public Record<T> 
{
private:
    float balance, interest, startBal;    //account balance and interest rate
    int compound;               //number of times compounded               
    T *transactions;            //to hold allocated array
    int arraySize;              //the size of the array
    bool transactionLimit;//limits the number of transation in one session .
    int index;                  //the index to fill the array
    float sum;                  //sum of the transaction amounts
 public:
    //default constructors
    Account()
    {
        balance=0;arraySize = 100;transactionLimit=false;index=0;startBal=0;
    }
    //constructor
    Account(float b, float i, float c);
    //destructor deletes previously allocated array
    ~Account()
    {   
        if (arraySize > 0 && transactions)
        {   
            //cout<<"deleting array..\n";
            delete [] transactions;
            //cout<<"deleted array..\n";
        }
    }
    //sets the balance
    void setBalance(float a)
    {if(a>=0)balance=a;}
    //sets the interst
    void setInterest(float a)
    {interest=a;}
    //set compound variable
    void setCompound(int a)
    {compound=a;}
    //returns current balance
    float getBalance()const
    {return balance;}
    //returns the interest rate
    float getInterest() const
    {return interest;}
    //returns the number of times compounded
    int getCompound() const
    {return compound;}
    //adds money to the account
    virtual void deposit(float)=0;
    //subtracts money from the account
    virtual void withdraw(float)=0;
    //handles memory allocation errors
     void memError()
    {
        cout << "ERROR:Cannot allocate memory.\n";
        exit(EXIT_FAILURE);
    }
    //handles subscripts out of range
    void subError()
    {
        cout << "ERROR: Subscript out of range.\n";
        exit(EXIT_FAILURE);
    }
    //accessor to return the array size
    int size() const
    { return arraySize; }
    //copy constructor
    Account(const Account &);
    //accessor to return a specific element
    T getElementAt(int position);
    //overloaded [] operator
    T &operator[](const int &);
    //input data into array
    void inputData(float a);
    void printTransactions();
 };

//constructor. sets the size of the array and allocates memory for it
template <class T>
Account<T>::Account(float b, float i, float c)
{
        balance=b;
        interest =i;
        compound =c;
        arraySize = 100;
        index=0;
        transactionLimit=false;
        sum=0;
        startBal=b;
        //allocate memory for the array
        try
        {
            transactions = new T [arraySize];
        }
            catch (bad_alloc)
        {
            memError();
        }
        //initialize array
        for (int count = 0; count < arraySize; count++)
            *(transactions + count) = 0;
}

//copy constructor
template <class T>
Account<T>::Account(const Account &obj)
{
        //copy the array size
        arraySize = obj.arraySize;
        //allocate memory for the array
        transactions = new T [arraySize];
        if (transactions == 0)
            memError();
        //copy the elements of obj's array
        for(int count = 0; count < arraySize; count++)
            *(transactions + count) = *(obj.aptr + count);
}

//this function returns the value stored at the subcript in the array
template <class T>
T Account<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return transactions[sub];
}

//this function returns a reference to the element in the array indexed by the subscript
template <class T>
T &Account<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return transactions[sub];
}

//input balance into array
template <class T>
void Account<T>::inputData(float a)
{   
        if(index<arraySize)
        {
            *(transactions + index) = a;
            index++;
        }
        else
        { 
            cout<<"The maximum number of transaction recordings allowed per session has been reached.\n";
            cout<<"Any futher transactions will not be recorded but will be processed.\n.";
            cout<<"Please go back to the main menu in order to reset the banking accounts to continue recording transactions.\n";
        }
}

//print transaction list
template <class T>
void Account<T>::printTransactions()
{   
        sum=0;
        cout<<endl;
        cout<<"Transactions:"<<endl;
        for(int i=0;i<arraySize;i++)
        {   
            if(transactions[i]!=0)
            {
                if(transactions[i]>0)
                {
                    cout<<i+1<<". "<<"$"<<*(transactions + i)<<" Deposit"<<endl;
                    sum=sum+*(transactions + i);
                }
                if(transactions[i]<0)
                {
                    cout<<i+1<<". "<<"$"<<-*(transactions + i)<<" Withdrawal or Transfer"<<endl;
                    sum=sum+*(transactions + i);
                }
            }
        }
        if(sum>=0)
        {
            cout<<"Transactions Total: $"<<sum<<endl;
            cout<<"Starting Balance: $"<<startBal<<endl;
        }
        else
        {
            cout<<"Total Value of Transactions: "<<"-$"<<-sum<<endl;
            cout<<"Starting Balance: $"<<startBal<<endl;
        }
}
#endif	/* ACCOUNT_H */