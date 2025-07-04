#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
void menu();
class ManageMenu
{
protected:
    string username;

public:
    ManageMenu()
    {
        system("color 0A");
        cout << "\n\n\n\n\n\t Enter your name to Continue as Admin: ";
        cin >> username;
        system("CLS");
        menu();
    }
    ~ManageMenu() {}
};

class Customers
{
public:
    string name, gender, address;
    int age, mobileno;
    static int cusid;
    char all[1258];

    void getdetails()
    {
        ofstream out("old-customer.txt", ios::app);
        {
            cout << "Enter Customer id - " << endl;
            cin >> cusid;
            cout << "Enter Name -  " << endl;
            cin >> name;
            cout << "Enter Age - " << endl;
            cin >> age;
            cout << "Enter Mobile No - " << endl;
            cin >> mobileno;
            cout << "Enter Address - " << endl;
            cin >> address;
            cout << "Enter Gender - " << endl;
            cin >> gender;

            out << "\nCustomer ID-" << cusid << "\nName-" << name << "\nAge-" << age << "\nMobile No-" << mobileno << "\nAddress-" << address << "\nGender" << gender << endl;
            out.close();
            cout << "\nSAVED\nNOTE: we have save your details for future pourpose";
        }
    }
    void showdetails()
    {
        ifstream in("old-customer.txt");
        {
            if (!in)
            {
                cout << "File Error!" << endl;
            }
            while (!(in.eof()))
            {
                in.getline(all, 1258);
                cout << all << endl;
            }
            in.close();
        }
    }
};
int Customers::cusid;

class Guide
{
public:
    int Guideservice;
    float charges;
    static float lastcharge;
    void guidedetails()
    {
        cout << "we are providing you the best accompanied guide within or outside country" << endl;
        cout << "-------Floralguides---------\n"
             << endl;
        cout << "1.Rent a Guide for a day in India - Rs 500 per Day" << endl;
        cout << "2.Rent a Guide for a day outside India - Rs 2000 per Day" << endl;
        cout << "\nthe total coast of your journey " << endl;
        cout << "Enter  which kind of pakage do you need:" << endl;
        cin >> Guideservice;
        int hireguide;
        int gst = 0.1;
        if (Guideservice == 1)
        {

            charges = 500 + (500 * gst);
            cout << "\nyour total coast " << charges << "rupees for a standard guide service " << endl;
            cout << "press 1 to hire this guide: or " << endl;
            cout << "press 2 to select the other guide: ";
            cin >> hireguide;

            system("CLS");
            if (hireguide == 1)
            {
                lastcharge = charges;
                cout << "\nyou have succesfuly hired a standard guide" << endl;
                cout << " Go to the menu to take the receipt" << endl;
            }
            else if (hireguide == 2)
            {
                guidedetails();
            }
            else
            {
                cout << "Invalid input! Rderecting to previous menu \nPlease wait! " << endl;
                Sleep(999);
                system("CLS");
                guidedetails();
            }
        }
        else if (Guideservice == 2)
        {
            charges = 2000 + (2000 * gst);
            cout << "\nyour total coast " << charges << "rupees for a standard guide service " << endl;
            cout << "press 1 to hire this guide: or " << endl;
            cout << "press 2 to select the other guide: ";
            cin >> hireguide;

            system("CLS");
            if (hireguide == 1)
            {
                lastcharge = charges;
                cout << "\nyou have succesfuly hired a standard guide" << endl;
                cout << " Go to the menu to take the receipt" << endl;
            }
            else if (hireguide == 2)
            {
                guidedetails();
            }
            else
            {
                cout << "Invalid input! Rderecting to previous menu \nPlease wait! " << endl;
                Sleep(1100);
                system("CLS");
                guidedetails();
            }
        }
        else
        {

            cout << "Invalid input! Rderecting to Main menu \nPlease wait! " << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "\npress 1 to redirect to Main menu:" << endl;
        cin >> hireguide;
        system("CLS");
        if (hireguide == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
};
float Guide::lastcharge;

class Bokings
{
public:
    int choicehotel;
    int packchoice;
    static float hotelcoast;
    void hotels()
    {
        string hotelno[] = {"Avendra", "Oyo", "Elephant Bay"};
        for (int i = 0; i < 3; i++)
        {
            cout << (i + 1) << ".Hotel" << hotelno[i] << endl;
            cout << "\ncurrently we colaborated with above  hotels!" << endl;
            cout << "Press any key to back or\nEnter number of hotel you want to book: ";
            cin >> choicehotel;

            system("CLS");
            if (choicehotel == 1)
            {
                cout << "........WELCOME TO HOTEL AVENDRA........\n"
                     << endl;
                cout << "The Garden ,Food and Breverages.Enjoy all you can drink ,Stay colled and chill in the summer day " << endl;
                cout << "Pacages are offered by Avendra:\n"
                     << endl;
                cout << "1.Standard Pac-" << endl;
                cout << "\tAll basic fascilities you can have for- Rs 5000 " << endl;
                cout << "2.Premium Pack-" << endl;
                cout << "\tEnjoy Premium: Rs 10000" << endl;
                cout << "3.Luxury Pack- " << endl;
                cout << "\tEnjoy Luxury: Rs 15000" << endl;

                cout << "Press any key to back or\nEnter Pacage no you want to book: ";
                cin >> packchoice;
                if (packchoice == 1)
                {
                    hotelcoast = 5000.00;
                    cout << "\nYou have succesfully bookrd the Standard pack at Avendra" << endl;
                    cout << "Go to the menu to take the recipt " << endl;
                }
                else if (packchoice == 2)
                {
                    hotelcoast = 10000.00;
                    cout << "\nYou have succesfully bookrd the Premiumn pack at Avendra" << endl;
                    cout << "Go to the menu to take the recipt " << endl;
                }
                else if (packchoice == 3)
                {
                    hotelcoast = 15000.00;
                    cout << "\nYou have succesfully bookrd the Luxuary pack at Avendra" << endl;
                    cout << "Go to the menu to take the recipt " << endl;
                }
                else
                {
                    cout << "Invalid input! Rderecting to Main menu \nPlease wait! " << endl;
                    Sleep(1100);
                    system("CLS");
                    hotels();
                }
                int gotomenu;
                cout << "Press 1 to redirect to menu: ";
                cin >> gotomenu;
                if (gotomenu == 1)
                {
                    menu();
                }

                else
                {
                    menu();
                }
            }
            cout << "Invalid input! Rderecting to Main menu \nPlease wait! " << endl;
            Sleep(1100);
            system("CLS");
            hotels();
        }
    }
};
float Bokings::hotelcoast;

class Expenses : public Bokings, Guide, Customers
{
public:
    void Printbill()
    {
        ofstream outf("reciept.txt");
        {
            outf << "--------ABC Travel Agency------ " << endl;
            outf << "---------Receipt----------" << endl
                 << endl;
            outf << "Customer ID: " << Customers::cusid << endl
                 << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost: \t\t" << fixed << setprecision(2) << Bokings::hotelcoast << endl;
            outf << "Guide  cost: \t" << fixed << setprecision(2) << Guide::lastcharge << endl
                 << endl;
            outf << "Total Charge: \t\t" << fixed << setprecision(2) << Bokings::hotelcoast + Guide::lastcharge << endl
                 << endl;
            outf << "-----------THANK YOU--------------" << endl;
        }
        outf.close();
    }
    void Showbill()
    {
        ifstream inf("reciept.txt");
        {
            if (!inf)
            {
                cout << "File opening Error !" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 1258);
                cout << all << endl;
            }
        }
        inf.close();
    }
};
void menu()
{

    int mainchoice;
    int inchoice;
    int gotoMenu;

    cout << "\t\t       * ABC Travels*\n"
         << endl;
    cout << "------------Main Menu-------------" << endl;

    cout << "\t------------------------" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management  ->1\t|" << endl;
    cout << "\t|\tGuides Management    ->2\t|" << endl;
    cout << "\t|\tBoking Management    ->3\t|" << endl;
    cout << "\t|\tCharges & Bill       ->4\t|" << endl;
    cout << "\t|\tExit                 ->5\t|" << endl;
    cout << "\t|----------------------------|" << endl;

    cout << "\nEnter your choice: ";
    cin >> mainchoice;

    system("CLS");
    Customers a2;
    Guide a3;
    Bokings a4;
    Expenses a5;

    if (mainchoice == 1)
    {
        cout << "------Customers-----\n"
             << endl;
        cout << "1. Enter New Customers " << endl;
        cout << "2. See Old Customers " << endl;

        cout << "\nEnter Choice" << endl;
        cin >> inchoice;
        system("CLS");
        if (inchoice == 1)
        {
            a2.getdetails();
        }
        else if (inchoice == 2)
        {
            a2.showdetails();
        }
        else
        {
            cout << "Invalid input! Rderecting to Main menu \nPlease wait! " << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "\nPress 1 to redirect to main menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainchoice == 2)
    {
        a3.guidedetails();
    }
    else if (mainchoice == 3)
    {
        cout << "-->Book a Luxuries Hotel using the System<---" << endl;
        a4.hotels();
    }
    else if (mainchoice == 4)
    {
        cout << "-->Get the Reciept<--" << endl;
        a5.Printbill();
        cout << "The reciept is already printed you can get it fromthe file path\n"
             << endl;
        cout << "to display your reciept in the screen press 1: or enter any key to back to main menu: " << endl;
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            a5.Showbill();
            cout << "\nPress 1 to redirect to menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (mainchoice == 5)
        {
            cout << "-->GOOD BYE<---" << endl;
            Sleep(999);
            system("CLS");
            menu();
        }
        else
        {
            cout << "Invalid input! Rderecting to Main menu \nPlease wait! " << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    }
}

int main()
{
    ManageMenu startobj;

    return 0;
}