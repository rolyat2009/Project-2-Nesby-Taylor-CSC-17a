/* 
 * File:   Checking.h
 * Author: Tay
 *
 * Created on May 28, 2014, 1:30 PM
 */
#ifndef CHECKING_H
#define	CHECKING_H
#include "Account.h"
//class temeplate and inheritance
template <class T>
class Checking : public Account<T> 
{
private:
    float balance;              //balance of the acount
public:
    //default constructor
    Checking() 
    {balance=0;}
    //constructor
    Checking(float b, float i, float c):Account<T>( b,  i,  c)
    {   
        balance=b;
    }
    ~Checking()
    {}   
    //copy constructor
    Checking(const Checking &);
    T getElementAt(int position);
    //accessor to find an item
    int findItem(const T);
    //over-loaded function to return new balance
    float getBalance()const
    {return balance;} 
    //declared withdraw as it was previously virtual
    void withdraw(float);
    //declared withdraw as it was previously virtual
    void deposit(float);
    void negDepAmount()
    {
        cout<<"Illogical Action: Deposit amount must be greater than $0.00"<<endl;
    }
    void belowBalance()
    {
        cout<<"Illogical Action: Cannot withdraw more than you own."<<endl;
    }
    void negWithAmount()
    {
        cout<<"Illogical Action: Withdrawal amount must be greater than $0.00"<<endl;
    }
};

//finditem. This function searches for item. If found then the subscript is returned else -1 is returned
template <class T>
int Checking<T>::findItem(const T item)
{
    for (int count = 0; count <= this->size(); count++)
    {
        if (getElementAt(count) == item)
            return count;
    }
    return -1;
}

//deposit
template <class T>
void Checking<T>::deposit(float a)
{
    if(a>0)
    {
        balance=balance+a;
    }
    else negDepAmount();
}

//withdrawl
template <class T>
void Checking<T>::withdraw(float a)
{
    float temp;
        if (a>0)
        {
            temp=balance-a;
            if(temp<0)
                 belowBalance();
            else
            {
                balance=balance-a;
            }
        }
        else
            negWithAmount();
}
#endif