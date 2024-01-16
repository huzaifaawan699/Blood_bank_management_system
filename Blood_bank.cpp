#include <iostream>
#include "System.h"
#include <string>
#include <cctype>
using namespace std;

int donorCount=0;
int recipientCount=0;
int bloodTypeCount=0;

const int maxCount=100;
bloodBankManagment donor[maxCount],recipient[maxCount];

void menu()
{
    char ch='Y';
    int choice;

    do{
        cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        cout<<"\n\t   1. Add Donor                ";
        cout<<"\n\t   2. Add Recipient            ";
        cout<<"\n\t   3. Donate Blood             ";
        cout<<"\n\t   4. Check Blood Availibilty  ";
        cout<<"\n\t   5. Search Specific Blood    ";
        cout<<"\n\t   6. Blood Transfusion        ";
        cout<<"\n\t   7. Report of a Person       ";
        cout<<"\n\t   8. Display Inventory        ";
        cout<<"\n\t   9. Exit                     ";
        cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout<<"\nEnter a choice from above: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                string name,bloodType,contact;
                int age;

                inputInfo(name,bloodType,contact,age);

                donor[0].addDonor(name, bloodType, contact, age);

                cout<<"\nDonor is added successfully...";

                diplayDonor();
                donorCount++;
                break;
            }
            case 2:
            {
                string name,bloodType,contact;
                int age;

                inputInfo(name,bloodType,contact,age);

                recipient[recipientCount].addRecipient(name, bloodType, contact, age);
                cout<<"Recipient is added successfully"<<endl;

                displayRecipeint();

                recipientCount++;
                break;
            }
            case 3:
            {
                string name,bloodType,contact;
                int age;

                inputInfo(name,bloodType,contact,age);

                donor[0].addDonor(name, bloodType, contact, age);

                cout<<"Donor is added successfully"<<endl;

                diplayDonor();
                donorCount++;
                break;
            }
            case 4:
            {
                donor[0].checkAvailability();
                break;
            }
            case 5:
            {
                cout<<"This feature is not available yet"<<endl;
                break;
            }
            case 6:
            {
                    donor[0].donateBlood();
                    donorCount--;
                    recipientCount--;
                break;
            }
            case 7:
            {
                string id;
                cout<<"Enter the id of person:"<<endl;
                cin>>id;

                donor[0].personReport(id);
                break;
            }
            case 8:
            {
                donor[0].displayInventory();
                break;
            }
            case 9:
            {
                cout<<"Exiting"<<endl;
                exit(0);
                break;
            }
            default:
                cout<<"Invalid choice"<<endl;
        }
        cout<<"Do you want to repeat the process? Press Y: "<<endl;
        cin>>ch;

    }while(ch== 'y' || ch=='Y');
}

bloodBankManagment::bloodBankManagment()
{

}

void bloodBankManagment::setName(string n)
{
    name=n;
}
string bloodBankManagment::getName()const
{
    return name;
}

void bloodBankManagment::setID(string id)
{
    Id=id;
}
string bloodBankManagment::getID()const
{
    return Id;
}

void bloodBankManagment::setAge(int a)
{
    age=a;
}
int bloodBankManagment::getAge()const
{
    return age;
}

void bloodBankManagment::setContact(string c)
{
    contact=c;
}
string bloodBankManagment::getContact()const
{
    return contact;
}

void bloodBankManagment::setBloodType(string b)
{
    bloodType=b;
}
string bloodBankManagment::getBloodType()const
{
    return bloodType;
}

void inputInfo(string& name, string& bloodType, string& contact, int &age)
{
    cin.ignore();
    cout<<"Enter your name:"<<endl;
    getline(cin,name);
    cout<<"Enter your contact number: "<<endl;
    cin>>contact;
    cout<<"Enter your age: "<<endl;
    cin>>age;
    cout<<"Enter your blood type:"<<endl;
    cin>>bloodType;
}

void bloodBankManagment::addDonor(string name, string bloodType, string contact, int age)
{
    donor[donorCount].setName(name);
    donor[donorCount].setAge(age);
    donor[donorCount].setID("#"+to_string(rand()+100));
    donor[donorCount].setContact(contact);
    donor[donorCount].setBloodType(bloodType);
}

void bloodBankManagment::addRecipient(string name, string bloodType, string contact, int age)
{
    recipient[recipientCount].setName(name);
    recipient[recipientCount].setAge(age);
    recipient[recipientCount].setID("*"+to_string(rand()+100));
    recipient[recipientCount].setContact(contact);
    recipient[recipientCount].setBloodType(bloodType);
}

void bloodBankManagment::personReport(string id)
{
    bool check=false;
    if(id.find("*")==0)
    {
        cout<<"The person is in our recipient list."<<endl;
        for(int i=0; i<recipientCount; i++)
        {
            if(recipient[i].getID()==id)
            {
                cout<<"Name:"<<recipient[i].getName()<<endl;
                cout<<"ID: "<<recipient[i].getID()<<endl;
                cout<<"Blood Type: "<<recipient[i].getBloodType()<<endl;
                cout<<"Age: "<<recipient[i].getAge()<<endl;
                cout<<"Contact: "<<recipient[i].getContact()<<endl;
                check=true;
            }
        }
    }
    else
    {
        cout<<"The person is in our donor list: "<<endl;
        for(int i=0; i<donorCount; i++)
        {
            if(donor[i].getID()==id)
            {
                cout<<"Name: "<<donor[i].getName()<<endl;
                cout<<"ID: "<<donor[i].getID()<<endl;
                cout<<"Blood type: "<<donor[i].getBloodType()<<endl;
                cout<<"Age: "<<donor[i].getAge()<<endl;
                cout<<"Contact: "<<donor[i].getContact()<<endl;
                check=true;
            }
        }
    }
    if(!check)
        cout<<"The required person is not found."<<endl;
}

void diplayDonor()
{
    cout<<"Name: "<<donor[donorCount].getName()<<endl;
    cout<<"ID: "<<donor[donorCount].getID()<<endl;
    cout<<"Blood type: "<<donor[donorCount].getBloodType()<<endl;
    cout<<"Age: "<<donor[donorCount].getAge()<<endl;
    cout<<"Contact: "<<donor[donorCount].getContact()<<endl;
}

void displayRecipeint()
{
    cout<<"Name: "<<recipient[recipientCount].getName()<<endl;
    cout<<"ID: "<<recipient[recipientCount].getID()<<endl;
    cout<<"Blood Type: "<<recipient[recipientCount].getBloodType()<<endl;
    cout<<"Age: "<<recipient[recipientCount].getAge()<<endl;
    cout<<"Contact: "<<recipient[recipientCount].getContact()<<endl;
}

void bloodBankManagment::displayInventory()
{
    cout<<" DONORS "<<endl;

    cout<<"Total donors are: "<<donorCount<<endl;
    for(int i=0; i<donorCount; i++)
    {
        cout<<"---Donor "<<1+i<<" ---"<<endl;
        cout<<"Name: "<<donor[i].getName()<<endl;
        cout<<"ID: "<<donor[i].getID()<<endl;
        cout<<"Blood type: "<<donor[i].getBloodType()<<endl;
        cout<<"Age: "<<donor[i].getAge()<<endl;
        cout<<"Contact: "<<donor[i].getContact()<<endl;
    }


    cout<<"RECIPIENTS "<<endl;

    cout<<"Total recipient are: "<<recipientCount<<endl;
    for(int i=0; i<recipientCount; i++)
{
    cout<<"Recipient "<<1+i<<" ---"<<endl;
    cout<<"Name: "<<recipient[i].getName()<<endl;
    cout<<"ID: "<<recipient[i].getID()<<endl;
    cout<<"Blood Type: "<<recipient[i].getBloodType()<<endl;
    cout<<"Age: "<<recipient[i].getAge()<<endl;
    cout<<"Contact: "<<recipient[i].getContact()<<endl;
}

    int Apositive=0,Anegetive=0,Bpositive=0,Bnegative=0,ABpositive=0,ABnegative=0,Opositive=0,Onegative=0;
    cout<<" TOTAL QUANTITY OF BLOOD "<<endl;

    for(int i=0; i<donorCount; i++)
    {
        if(donor[i].getBloodType()=="A+")
            Apositive++;
        else if(donor[i].getBloodType()=="A-")
            Anegetive++;
        else if(donor[i].getBloodType()=="B+")
            Bpositive++;
        else if(donor[i].getBloodType()=="B-")
            Bnegative++;
        else if(donor[i].getBloodType()=="AB+")
            ABpositive++;
        else if(donor[i].getBloodType()=="AB-")
            ABnegative++;
        else if(donor[i].getBloodType()=="O+")
            Opositive++;
        else if(donor[i].getBloodType()=="O-")
            Onegative++;
    }
    cout<<"A+: "<<Apositive<<endl;
    cout<<"A-: "<<Anegetive<<endl;
    cout<<"B+: "<<Bpositive<<endl;
    cout<<"B-: "<<Bnegative<<endl;
    cout<<"AB+: "<<ABpositive<<endl;
    cout<<"AB-: "<<ABnegative<<endl;
    cout<<"O+: "<<Opositive<<endl;
    cout<<"O-: "<<Onegative<<endl;
}

void bloodBankManagment::checkAvailability()
{
    cout<<"CHECK BLOOD AVAILABILTY "<<endl;

    string bloodtype;
    cout<<"Enter the type of the blood: "<<endl;
    cin>>bloodtype;

    bool check=false;
    int typeCount=0;
    for(int i=0; i<donorCount; i++)
    {
        if(donor[i].getBloodType()==bloodtype)
        {
            typeCount++;
            check=true;
        }
    }
    if(check)
    {
        cout<<"Units available of "<<bloodtype<<": "<<typeCount<<endl;
    }
    else
        cout<<"No unit available of this blood type."<<endl;
}

void bloodBankManagment::donateBlood()
{
    string recipientID;
    cout<<"Enter recipient ID: "<<endl;
    cin>>recipientID;

    bool check=false;
    for(int i=0; i<donorCount; i++)
    {
        if(recipientID==donor[i].getID())
        {
            for (int j = i; i < donorCount - 1; ++i)
                  {
                      recipient[j] = recipient[j + 1];
                      check=true;
                  }
                  --donorCount;
        }
    }

    if(check)
    {
        check=false;
        for(int i=0; i<donorCount; i++)
        {
            if(recipientID==donor[i].getID())
            {
                for (int j = i; i < donorCount - 1; ++i)
                {
                    donor[j] = donor[j + 1];
                    check=true;
                }
                --donorCount;
            }
        }
    }
    cout<<"The blood is donated successfully."<<endl;

}

