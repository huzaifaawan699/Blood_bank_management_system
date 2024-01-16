#ifndef System_hpp
#define System_hpp
#include<string>
using namespace std;

void menu();

class bloodBankManagment
{
private:
    string name;
    string Id;
    int age;
    string bloodType;
    string contact;
public:
    bloodBankManagment();
    void setName(string);
    string getName()const;
    void setID(string);
    string getID()const;
    void setAge(int);
    int getAge()const;
    void setBloodType(string);
    string getBloodType()const;
    void setContact(string);
    string getContact()const;
    void addRecipient(string, string, string, int);
    void addDonor(string, string, string, int);
    void donateBlood();
    void checkAvailability();
    int searchDonor();
    void bloodTransfusion();
    void personReport(string);
    void displayInventory();

};
void diplayDonor();
void inputInfo(string&, string&, string&, int&);
void displayRecipeint();
#endif

