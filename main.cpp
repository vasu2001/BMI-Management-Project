#include <fstream>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

float avgbmi,lastsno=0;
int c;

class user
{
public:
    int age,sno;
    float height,weight,bmi=0,inch,foot;
    char sex,name[30],result[8];
    void getdata();

};

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void intro()
{
    system("clear");
    string str = "BMI_MANAGEMENT_PROGRAM";
    for(int a=0 ; a<22 ; a++)
    {

        for(int i=0 ; i<11 ; i++)
        {
            gotoxy(20+a,i);
            cout<<str[a];
            usleep(6500 - 500*i);
            if(i<10)
            {
                cout<<"\b\b"<<"  ";
            }
        }
    }
    cout<<"\n\n\n\n\n                 ";
    cout<<"\n\nPress any key to continue...";
    int wait = getchar();
}

void information()
{
    cout<<"\t\t\tBMI_MANAGEMENT_PROGRAM\n\n";
    cout<<"Salient features of the program :\n\n";
    cout<<"1\tIt calculates your BMI and gives you list of probable threats you could\n\tface if you will not give you health a good thought\n";
    cout<<"\n2\tIt shows you an average BMI based on our previous users just like you, \n\tso that you can get a brief idea of where you stand in the crowd\n\n";
    cout<<"3\tIf you are one of our previous users then you can search for your \n\tprevious record easily from our database\n\n\n\t\t";
    cout<<"\n\nPress any key to continue...";
    int wait = getchar();
}

vector<user> ary;

class file
{
private:
    ofstream rep;
public:
    file(user &currentuser)
    {
        rep.open("Report.txt");
        rep<<"\tBMI REPORT\n\nName : "<<currentuser.name<<"\nAge : "<<currentuser.age<<" yrs\nSex : "<<((currentuser.sex=='f')?"Female":"Male")<<"\nHeight : "<<currentuser.foot<<" feet "<<currentuser.inch<<" inches\nWeight : "<<currentuser.weight<<" kg\nBMI : "<<currentuser.bmi<<"\n\n";
    }

    void chigh(char abc[15])
    {
        rep<<"You are "<<abc<<endl;
        rep<<"\nCONSEQUENCES:\nThere is risk of cardiovascular diseases\n80% chance of staying obese\nType 2 Diabetes\nAsthama\nsleep Apnea\nPsychological Stress\nLow Self Esteem";
    }

    void ahigh(char abc[15])
    {
        rep<<"You are "<<abc<<endl;
        rep<<"\nCONSEQUENCES:\nHyper Tension\nDyslipidemia\ntype 2 Diabetes\nCoronary Heart Diseases\nStroke\nGall Bladder Disease\nOsteoarthritis\nsleep Apnea\nRespiratory Problems\nSome CANCERS(endometrial, breast, colon)";
    }

    void clow(char abc[15])
    {
        rep<<"You are "<<abc<<endl;
        rep<<"\nCONSEQUENCES:\nDelayed Growth and Development\nFragile Bones\nWeakened Imune System\nAnemia";
    }

    void alow(char abc[15])
    {
        rep<<"You are "<<abc<<endl;
        rep<<"\nCONSEQUENCES:\nFragile Bones\nWeakened Imune System\nAnemia\nFertility Issues\nHair Loss";
    }

    void healthy()
    {
        rep<<"You are in healthy BMI range\n\nYOU COULD ESCAPE FROM MANY DISEASES EASILY JUST KEEP IT UP!";
    }

    ~file()
    {
        rep.close();
    }
};

class console
{
public:
    void chigh(char abc[15])
    {
        cout<<"\nYou are "<<abc<<endl;
        cout<<"\nCONSEQUENCES:\nThere is risk of cardiovascular diseases\n80% chance of staying obese\nType 2 Diabetes\nAsthama\nsleep Apnea\nPsychological Stress\nLow Self Esteem";
    }

    void ahigh(char abc[15])
    {
        cout<<"\nYou are "<<abc<<endl;
        cout<<"\nCONSEQUENCES:\nHyper Tension\nDyslipidemia\ntype 2 Diabetes\nCoronary Heart Diseases\nStroke\nGall Bladder Disease\nOsteoarthritis\nsleep Apnea\nRespiratory Problems\nSome CANCERS(endometrial, breast, colon)";
    }

    void clow(char abc[15])
    {
        cout<<"\nYou are "<<abc<<endl;
        cout<<"\nCONSEQUENCES:\nDelayed Growth and Development\nFragile Bones\nWeakened Imune System\nAnemia";
    }

    void alow(char abc[15])
    {
        cout<<"\nYou are "<<abc<<endl;
        cout<<"\nCONSEQUENCES:\nFragile Bones\nWeakened Imune System\nAnemia\nFertility Issues\nHair Loss";
    }

    void healthy()
    {
        cout<<"\nYou are in healthy BMI range\n\nYOU COULD ESCAPE FROM MANY DISEASES EASILY JUST KEEP IT UP!";
    }
};

void display(user &currentuser)
{
    cout<<"\n\nThe average BMI is: "<<avgbmi<<"\nYour bmi is :"<<currentuser.bmi;
    file print(currentuser);
    console terminal;
    if(currentuser.age>20)
    {
        if(currentuser.bmi<=18.5)
        {
            terminal.alow("Underweight");
            print.alow("Underweight");
        }
        else if(currentuser.bmi>18.5 && currentuser.bmi<=25)
        {
            terminal.healthy();
            print.healthy();
        }
        else if(currentuser.bmi>25 && currentuser.bmi<=30)
        {
            terminal.ahigh("Overweight");
            print.ahigh("Overweight");
        }
        else if(currentuser.bmi>20 && currentuser.bmi<=35)
        {
            terminal.ahigh("Obese");
            print.ahigh("Obese");
        }
        else if(currentuser.bmi>35)
        {
            terminal.ahigh("Severely Obese");
            print.ahigh("Severely Obese");
        }
    }
    else if(currentuser.age<20 && currentuser.age>=2)
    {
        if(currentuser.bmi<=18.5)
        {
            terminal.clow("Underweight");
            print.clow("Underweight");
        }
        else if(currentuser.bmi>18.5 && currentuser.bmi<=25)
        {
            terminal.healthy();
            print.healthy();
        }
        else if(currentuser.bmi>25 && currentuser.bmi<=30)
        {
            terminal.chigh("Overweight");
            print.chigh("Overweight");
        }
        else if(currentuser.bmi>20 && currentuser.bmi<=35)
        {
            terminal.chigh("Obese");
            print.chigh("Obese");
        }
        else if(currentuser.bmi>35)
        {
            terminal.chigh("Severely Obese");
            print.chigh("Severely Obese");
        }
    }


}

void calcavgbmi()
{
    float sumbmi=0;
    user temp;
    ary.clear();
    ifstream obj("Database.dat",ios::binary);
    while(obj.read((char*)&temp,sizeof(temp)))
    {
        lastsno=temp.sno;
        ary.push_back(temp);
        sumbmi+=temp.bmi;
    }
    if(lastsno==0)avgbmi=0;
    else avgbmi=sumbmi/lastsno;
    obj.close();
}

void newuser()
{
    user cuser;
    cuser.getdata();
    ofstream obj;
    if(lastsno!=0)
        obj.open("Database.dat",ios::binary|ios::app);
    else obj.open("Database.dat",ios::binary);
    obj.write((char*)&cuser,sizeof(cuser));
    display(cuser);
}

void displayrec(int no)
{
    cout<<ary[no].sno<<"\t"<<ary[no].name<<"\n";
}

void existinguser()
{
    int age=0,usersno=-1,choice;
    char name[20];
    cout<<"Do you want to find yourself by your name or your age. Press \n[1] for age \n[2] for name\n------>  ";
    cin>>choice;
    do
    {
        if(choice==1)
        {
            cout<<"Enter your age?  ";
            cin>>age;
            cout<<"\n Following is the list of records for the specified age.\n\nSNo\t   Name\n";
            for(int i=0 ; i<ary.size() ; i++)
            {
                if(ary[i].age==age)displayrec(i);
            }
            break;
        }
        else if (choice == 2)
        {
            cout<<"Enter your first name :  ";
            cin>>name;
            cout<<"\n Following is the list of records for the specified name.\n\nSNo\t   Name\n";
            for(int i=0 ; i<ary.size() ; i++)
            {
                if(strcmp(ary[i].name,name)==0)displayrec(i);
            }
            break;
        }
        else
        {
            cout<<"Wrong choice. Re-enter :  ";
            cin>>choice;
        }
    }
    while(1);
    cout<<"\nEnter the SNo for your entry and if it is not in the list then press 0\n\t:  ";
    cin>>usersno;
    while(usersno>ary.size())
    {
        cout<<"Invalid SNo entered\nPlease re-enter:  ";
        cin>>usersno;
    }
    if(usersno==0)cout<<"Sorry your record does not exist in our database.";
    else
    {
        display(ary[usersno-1]);
    }
}

int main()
{
    char con;
    intro();
    system("clear");
    information();
    do
    {
        system("clear");
        calcavgbmi();
        int choice;
        cout<<"\n\t\tBMI Management Program\n\nWhat do you want to do??\n\n  1\tFor new entry\n  2\tFor searching previous entries\n\nEnter:  ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            newuser();
            break;
        case 2:
            existinguser();
            break;
        }
        cout<<endl<<endl;
        while ((c = getchar()) != '\n' && c != EOF);
        cout<<"\n\nPress any key to continue...";
        int wait = getchar();
        system("clear");
        cout<<"\nDo you want to continue? <y/n>  ";
        cin>>con;
    }
    while(con=='y'||con=='Y');

    return 0;
}

void user::getdata()
{
    system("clear");
    cout<<"\n\t\t\tBMI REPORT\n\n";
    while ((c = getchar()) != '\n' && c != EOF);
    cout<<"Enter Your name:  ";
    cin.getline(name,30);
    //while ((c = getchar()) != '\n' && c != EOF);
    cout<<"Enter your age:  ";
    cin>>age;
    cout<<"Enter your sex<m/f>:  ";
    cin>>sex;
    cout<<"Enter your Height : \n\tFeet : ";
    cin>>foot;
    cout<<"\tInches : ";
    cin>>inch;
    cout<<"Enter your weight(kg):  ";
    cin>>weight;
    height=2.6*(inch+(12*foot));
    name[0]=toupper(name[0]);
    bmi=weight/(height*height/10000);
    sno=++lastsno;
}
