#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void menu();

class ManagerMenu
{
    protected:
        string userName;
    public:
        ManagerMenu()
        {
            cout << "\n\n\n\n\n\n\t Enter your name as an Admin: ";
            cin >> userName;
            system("CLS");
            menu();
        }
        ~ManagerMenu(){}
};

class Customers
{
    public:
        string name, gender, address;
        int age, mobileNo;
        static int cusID;
        char all[999];

        void getDetails()
        {
            ofstream out("old-customers.txt",ios::app);
            {
                cout << "Enter Customer ID: ";
                cin >> cusID;
                cout << "Enter Customer Name: ";
                cin >> name;
                cout << "Enter Customer Gender: ";
                cin >> gender;
                cout << "Enter Customer Address: ";
                cin >> address;
                cout << "Enter Customer Age: ";
                cin >> age;
                cout << "Enter Customer mobileNo: ";
                cin >> mobileNo;
            }

            out << "\nCustomer ID: " << cusID << "\nName: " << "\nAge: " << age << "\nMobile Number" << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;            
            out.close();
            cout << "\nSAVED \nNOTE: We save your details record for future purposes\n" << endl;
        } 

        void showDetails()
        {
            ifstream in("old-customers.txt");
            {
                if(!in)
                {
                    cout<<"File Error!" << endl;
                }
                while(!(in.eof()))
                {
                    in.getline(all,999);
                    cout<<all<<endl;
                }
                in.close();
            }
        }
};

int Customers::cusID;

class Cabs
{
    public:
        int cabChoice;
        int kilometers;
        float cabCost;
        static float lastCabCost;

        void cabDetails()
        {
            cout << "We collaborated with fastest, safest, and smartest cab service around the country" << endl;
            cout << "------------ABC Cabs--------------";
            cout << "1. Rent a Standard Cab - Rs. 15 for 1 KM" << endl;
            cout << "2. Rent a Luxury Cab - Rs. 25 per 1 KM" << endl;
            cout << "\nTo calculate the cost for your journey:" << endl;
            cout << "Enter which kind of cab you need:";
            cin >> cabChoice;
            cout << "Enter kilometers you have to travel:";
            cin >> kilometers;

            int hireCab;

            if(cabChoice == 1)
            {
                cabCost = kilometers * 15;
                cout << "\nYour tour cost " << cabCost << " rupees for a Standard Cab " << endl;
                cout << "Press 1 to hire this cab: or";
                cout << "Press 2 to select another cab ";
                cin >> hireCab;

                system("CLS");

                if(hireCab == 1)
                {
                    lastCabCost = cabCost;
                    cout << "\nYou have successfully hired a standard cab" << endl;
                    cout << "Goto Menu and take the reciept" << endl;
                }
                else if(hireCab == 2)
                {
                    cabDetails();
                }
                else
                {
                    cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
                    //Sleep(999);
                    system("CLS");
                    cabDetails();
                }
            }
            else if(cabChoice == 2)
            {
                cabCost = kilometers * 25;
                cout << "\nYour tour cost " << cabCost << " rupees for a Standard Cab " << endl;
                cout << "Press 1 to hire this cab: or";
                cout << "Press 2 to select another cab ";
                cin >> hireCab;

                system("CLS");

                if(hireCab == 1)
                {
                    lastCabCost = cabCost;
                    cout << "\nYou have successfully hired a standard cab" << endl;
                    cout << "Goto Menu and take the reciept" << endl;
                }
                else if(hireCab == 2)
                {
                    cabDetails();
                }
                else
                {
                    cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
                    //Sleep(999);
                    system("CLS");
                    cabDetails();
                }
            }
            else
            {
                cout << "Invalid Input! Redirecting to main menu \nPlease Wait!" << endl;
                //Sleep(999);
                system("CLS");
                menu();
            }

            cout << "\nPress 1 to Redirect Main menu:";
            cin>>hireCab;
            system("CLS");
            if(hireCab == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
};

float Cabs::lastCabCost;

class Booking
{
    public:
        int choiceHotel;
        int packChoice;
        static float hotelCost;

        void hotels()
        {
            string hotelNo[] = {"Taj","JWMarriot","GreenLeaf"};
            for (int a = 0; a < 3; a++)
            {
                cout << (a+1) << ". Hotel" << hotelNo[a] << endl;
            }
            cout<<"\nCurrently we collaborated with above hotels!" << endl;
            cout << "Press any key to back or \n Enter number of hotel you want to book: ";
            cin >> choiceHotel;
            system("CLS");

            if(choiceHotel == 1)
            {
                cout << "--------WELCOME TO HOTEL TAJ---------\n"<<endl;
                cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
                cout << "Packages offered by Taj: \n" << endl;
                cout << "1. Standard Pack" << endl;
                cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
                cout << "2. Premium Pack" << endl;
                cout << "\tAll premium facilities you need just for: Rs.10000.00" << endl;
                cout << "3. Luxury Pack" << endl;
                cout << "\tAll luxury facilities you need just for: Rs.15000.00" << endl;
                cout << "\nPress another key to back or \nEnter package number you want to book: ";
                cin >> packChoice;

                if(packChoice == 1)
                {
                    hotelCost = 5000.00;
                    cout << "\nYou have successfully booked Standard Pack at Taj" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else if(packChoice == 2)
                {
                    hotelCost = 10000.00;
                    cout << "\nYou have successfully booked Premium Pack at Taj" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else if(packChoice == 3)
                {
                    hotelCost = 15000.00;
                    cout << "\nYou have successfully booked Luxury Pack at Taj" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                    system("CLS");
                    hotels();
                }


                int gotomenu;
                cout << "\nPress 1 to redirect main menu" << endl;
                cin >> gotomenu;
                if(gotomenu == 1)
                {
                    //menu();
                }
                else
                {
                    //menu();
                }
            }
            else if(choiceHotel == 2)
            {
                cout << "--------WELCOME TO HOTEL JWMarriot---------\n"<<endl;
                cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
                cout << "Packages offered by JWMarriot: \n" << endl;
                cout << "1. Standard Pack" << endl;
                cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
                cout << "2. Premium Pack" << endl;
                cout << "\tAll premium facilities you need just for: Rs.10000.00" << endl;
                cout << "3. Luxury Pack" << endl;
                cout << "\tAll luxury facilities you need just for: Rs.15000.00" << endl;
                cout << "\nPress another key to back or \nEnter package number you want to book: ";
                cin >> packChoice;

                if(packChoice == 1)
                {
                    hotelCost = 5000.00;
                    cout << "\nYou have successfully booked Standard Pack at JWMarriot" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else if(packChoice == 2)
                {
                    hotelCost = 10000.00;
                    cout << "\nYou have successfully booked Premium Pack at JWMarriot" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else if(packChoice == 3)
                {
                    hotelCost = 15000.00;
                    cout << "\nYou have successfully booked Luxury Pack at JWMarriot" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                    system("CLS");
                    hotels();
                }
                int gotomenu;
                cout << "\nPress 1 to redirect main menu" << endl;
                cin >> gotomenu;
                if(gotomenu == 1)
                {
                    menu();
                }
                else
                {
                    menu();
                }
            }
            else if(choiceHotel == 3)
            {
                cout << "--------WELCOME TO HOTEL GreenLeaf---------\n"<<endl;
                cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
                cout << "Packages offered by GreenLeaf: \n" << endl;
                cout << "1. Standard Pack" << endl;
                cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
                cout << "2. Premium Pack" << endl;
                cout << "\tAll premium facilities you need just for: Rs.10000.00" << endl;
                cout << "3. Luxury Pack" << endl;
                cout << "\tAll luxury facilities you need just for: Rs.15000.00" << endl;
                cout << "\nPress another key to back or \nEnter package number you want to book: ";
                cin >> packChoice;

                if(packChoice == 1)
                {
                    hotelCost = 5000.00;
                    cout << "\nYou have successfully booked Standard Pack at GreenLeaf" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else if(packChoice == 2)
                {
                    hotelCost = 10000.00;
                    cout << "\nYou have successfully booked Premium Pack at GreenLeaf" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else if(packChoice == 3)
                {
                    hotelCost = 15000.00;
                    cout << "\nYou have successfully booked Luxury Pack at GreenLeaf" << endl;
                    cout << "Goto menu and take the reciept" << endl;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                    system("CLS");
                    hotels();
                }
                int gotomenu;
                cout << "\nPress 1 to redirect main menu" << endl;
                cin >> gotomenu;
                if(gotomenu == 1)
                {
                    menu();
                }
                else
                {
                    menu();
                }
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous menu: " << endl;
                system("CLS");
                menu();
            }
        }
};

float Booking::hotelCost;

class Charges : public Booking, Cabs, Customers
{
    public:
        void printBill()
        {
            ofstream outf("reciept.txt");
            {
                outf << "----------------Travel Agency---------------" << endl;
                outf << "-------------------Reciept------------------" << endl;
                outf << "____________________________________________" << endl;

                outf << "Customer ID: " << Customers::cusID << endl << endl;
                outf << "Description\t\t Total" << endl;
                outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
                outf << "Travel cost:\t\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

                outf << "_____________________________________________" << endl;
                outf << "Total Cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::cabCost << endl;
                outf << "_____________________________________________" << endl;
                outf << "---------------------Thank You---------------" << endl;
            }   
            outf.close();
        }
        void showBill()
        {
            ifstream inf("reciept.txt");
            {
                if(!inf)
                {
                    cout << "File opening error!" << endl;
                }
                while(!(inf.eof()))
                {
                    inf.getline(all,999);
                    cout << all << endl;
                }
            }
            inf.close();
        }
};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t     *Travels*\n" << endl;
    cout << "\t---------Main Menu-----------------------" << endl;
    cout << "\t-----------------------------------------" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges and Bill    -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t----------------------------------------" << endl;

    cout << "\n Enter your choice: ";
    cin>>mainChoice;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice == 1) {
        cout << "---------Customers------------\n" << endl;
        cout << "1. Enter new Customer" << endl;
        cout << "2. See Old Customers" << endl;
        cout << "\nEnter Choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1)
        {
            a2.getDetails();
        }
        else if(inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input!" << endl;
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect main menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1)
            menu();
        else
            menu();
    }
    else if(mainChoice == 2) {
        a3.cabDetails();
    }
    else if(mainChoice == 3) {
        cout << "---> Book a luxury Hotel using the system <---" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4) {
        cout << "---> Get your reciept <---" << endl;
        a5.printBill();

        cout << "Your reciept is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;

        if(gotoMenu == 1) {
            system("CLS");
            a5.showBill();
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5)
    {
        cout << "--Good Bye--" << endl;
        system("CLS");
        menu();
    }
    else 
    {
        cout << "--Invalid Report--" << endl;
        system("CLS");
        menu();
    }
}

int main()
{
    ManagerMenu startObj;
    return 0;
}