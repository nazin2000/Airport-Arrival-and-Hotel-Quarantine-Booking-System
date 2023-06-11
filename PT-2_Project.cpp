#include<bits/stdc++.h>

using namespace std;




class Payment
{ private:
          float total_amount;

  public:
    Payment(float total_amount)
    {
        this->total_amount=total_amount;


    }
    float getAmount()
    {
        return total_amount;
    }
    string Payment_choice()
    {

        return "1.Online 2.Card 3.Cash\n";
    }

   string getPayment_info()
   {
       if(total_amount!=0)
       {
           return "Payment Successful\n";
       }
   }
};

class Online:public Payment
{
  private:

    long bank_accoutn_no;
    float total_amount;
  public:

    Online(long bank_account_no,float total_amount):Payment(total_amount)
    {

        this->bank_accoutn_no=bank_accoutn_no;


    }

    string getPayment_info()
    {

           cout<<Payment::getPayment_info();
            return "Completed by Online Transaction\n";


    }

};

class Card:public Payment
{
  private:
    string card_type;
    string expdate;
    int cvv;

  public:
    Card(float total_amount,string card_type,string expdate,int cvv):Payment(total_amount)
    {
        this->card_type=card_type;
        this->expdate=expdate;
        this->cvv=cvv;

    }

    string getPayment_info()
    {

            cout<<Payment::getPayment_info();
            return "Completed by Card Transaction\n";


    }
};


class Cash:public Payment
{


  public:
    Cash(float total_amount):Payment(total_amount)
    {

    }

   string getPayment_info()
    {

            cout<<Payment::getPayment_info();
            return "Completed by Cash Payment System\n";


    }

};

class Passenger
{
private:
    string name,passport_no,flight_no,arrived_from,corona_cert;
    int age;
    char gender;

public:


    Passenger()
    {
        this->name=" ";
        this->age=0;
        this->gender='n';
    }

    void setBasicInfo(string name,int age,char gender)
    {
        this->name=name;
        this->age=age;
        this->gender=gender;
    }



     void setPassport(string passport)
    {
        passport_no=passport;
    }
    void setFlight(string flight)
    {
        flight_no=flight;
    }
    void setArrival(string arrival)
    {
        arrived_from=arrival;
    }
    void setCoronaCert(string corona_cert)
    {
        this->corona_cert=corona_cert;
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    char getGender()
    {
        return gender;
    }
    string getPassport()
    {
        return passport_no;
    }
    string getFlight()
    {
        return flight_no;
    }
    string getArrival()
    {
        return arrived_from;
    }
    string getCoronaCert()
    {
        return corona_cert;
    }





};




class Hotel
{private:
   string hotel_name;

   string package;

public:
    Passenger* pa1;
    Payment p1;
    Hotel( string hotel_name,string package,float total_amount):p1(total_amount)
    {
        this->hotel_name=hotel_name;
        this->package=package;


    }
    string getHotelName()
    {
        return hotel_name;
    }
    string getPackage()
    {
        return package;
    }
    void setPassenger(Passenger p)
    {
        pa1=&p;
    }
    Passenger* getPassenger()
    {
        return pa1;
    }
    string getPayment()
    {
        return p1.Payment_choice();
    }

};





int main()
{
    string  p_name,corona_cert,passport_no,arrived_from,flight_no;
    char p_gender;
    int p_age;
    long bankAccount;
    string card_type;
    string expdate;
    int cvv;

    int a=0,selectHotel,choice;
    Passenger p[5];




    string hnames,h_names[5];
    string packages[]={"7 days","10 days","14 days","21 days","21 days"};
    float amount[]={7000,10000,14000,18000,19000};

    ifstream Readfile;



    Readfile.open("Hotel_Names.txt");



   while(getline(Readfile,hnames))
    {
        h_names[a]=hnames;
        a++;

    }


    Readfile.close();

    Hotel h1(h_names[0],packages[0],amount[0]);
    Hotel h2(h_names[1],packages[1],amount[1]);
    Hotel h3(h_names[2],packages[2],amount[2]);
    Hotel h4(h_names[3],packages[3],amount[3]);
    Hotel h5(h_names[4],packages[4],amount[4]);

    for(int i=0;i<5;i++)
    {
        cout<<"Enter Passenger's name,age & gender:";
        getline(cin,p_name);
        cin>>p_age;
        cin>>p_gender;
        cout<<"Enter Passenger's passport number:"<<endl;
        cin>>passport_no;
        cout<<"Arrived from:"<<endl;
        cin>>arrived_from;
        cout<<"Flight number:"<<endl;
        cin>>flight_no;
        cout<<"Corona Certificate:"<<endl;
        cin>>corona_cert;

        p[i].setBasicInfo(p_name,p_age,p_gender);
        p[i].setPassport(passport_no);
        p[i].setArrival(arrived_from);
        p[i].setFlight(flight_no);
        p[i].setCoronaCert(corona_cert);

        cout<<"No.   "<<setw(10)<<"Hotel names"<<setw(30)<<"Packages"<<setw(20)<<"Amount"<<endl;

    for(int j=0;j<5;j++)
    {
        cout<<j+1<<"\t"<<setw(10)<<h_names[j]<<" "<<setw(30)<<packages[j]<<setw(20)<<amount[j]<<endl;
    }

    cout<<"Select a hotel and package"<<endl;
    cin>>selectHotel;

    if(selectHotel==1)
    {
        h1.setPassenger(p[i]);
        cout<<h1.getPayment();
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter your bank account number"<<endl;
            cin>>bankAccount;
            Online online(bankAccount,amount[0]);
            cout<<online.getPayment_info();
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"Enter your card information"<<endl;
            cin>>card_type>>expdate>>cvv;
            Card card(amount[0],card_type,expdate,cvv);
            cout<<card.getPayment_info();
            cout<<endl;
        }
        else if(choice==3)
        {
            Cash cash(amount[0]);
            cout<<cash.getPayment_info();
            cout<<endl;
        }
    }
    else if(selectHotel==2)
    {
        h2.setPassenger(p[i]);
        cout<<h2.getPayment();
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter your bank account number"<<endl;
            cin>>bankAccount;
            Online online(bankAccount,amount[1]);
            cout<<online.getPayment_info();
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"Enter your card information"<<endl;
            cin>>card_type>>expdate>>cvv;
            Card card(amount[1],card_type,expdate,cvv);
            cout<<card.getPayment_info();
            cout<<endl;
        }
        else if(choice==3)
        {
            Cash cash(amount[1]);
            cout<<cash.getPayment_info();
            cout<<endl;
        }
    }
    else if(selectHotel==3)
    {
        h3.setPassenger(p[i]);
        cout<<h3.getPayment();
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter your bank account number"<<endl;
            cin>>bankAccount;
            Online online(bankAccount,amount[2]);
            cout<<online.getPayment_info();
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"Enter your card information"<<endl;
            cin>>card_type>>expdate>>cvv;
            Card card(amount[2],card_type,expdate,cvv);
            cout<<card.getPayment_info();
            cout<<endl;
        }
        else if(choice==3)
        {
            Cash cash(amount[2]);
            cout<<cash.getPayment_info();
            cout<<endl;
        }
    }
    else if(selectHotel==4)
    {
        h4.setPassenger(p[i]);
        cout<<h4.getPayment();
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter your bank account number"<<endl;
            cin>>bankAccount;
            Online online(bankAccount,amount[3]);
            cout<<online.getPayment_info();
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"Enter your card information"<<endl;
            cin>>card_type>>expdate>>cvv;
            Card card(amount[3],card_type,expdate,cvv);
            cout<<card.getPayment_info();
            cout<<endl;
        }
        else if(choice==3)
        {
            Cash cash(amount[3]);
            cout<<cash.getPayment_info();
            cout<<endl;
        }
    }
    else if(selectHotel==5)
    {
        h5.setPassenger(p[i]);
        cout<<h5.getPayment();
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter your bank account number"<<endl;
            cin>>bankAccount;
            Online online(bankAccount,amount[4]);
            cout<<online.getPayment_info();
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"Enter your card information"<<endl;
            cin>>card_type>>expdate>>cvv;
            Card card(amount[4],card_type,expdate,cvv);
            cout<<card.getPayment_info();
            cout<<endl;
        }
        else if(choice==3)
        {
            Cash cash(amount[4]);
            cout<<cash.getPayment_info();
            cout<<endl;
        }
    }




    }


}

