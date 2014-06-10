/* 
 * File:   Record.h
 * Author: Tay
 *
 * Created on June 7, 2014, 2:48 AM
 */

#ifndef RECORD_H
#define	RECORD_H
using namespace std;

//base class for a person's record
template <class T>
class Record
{
private:
    string fName;
    string lName;
    string address;
    string zip;
    string phone;
    string accountNum;
    string password;
public:
    Record()
    {
        fName="";
        lName="";
        address="";
        zip="";
        phone="";
        accountNum="";
        password="";
    }
    ~Record()
    {}
    void setFirstName(string f)
    {fName=f;}
    void setLastName(string l)
    {lName=l;}
    void setAddress(string a)
    {address=a;}
    void setZip(string z)
    {zip=z;}
    void setPhone(string p)
    {phone=p;}
    void setAccountNum(string num)
    {accountNum=num;}
    void setPassword(string pi)
    {password=pi;}
    string getFirstName() const
    {return fName;}
    string getLastName()const
    {return lName;}
    string getAddress()const
    {return address;}
    string getZip()const
    {return zip;}
    string getPhone()const
    {return phone;}
    string getAccountNum()const
    {return accountNum;}
    string getPassword()const
    {return password;}
};
#endif	/* RECORD_H */