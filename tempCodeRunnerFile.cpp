#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <thread>
#include <chrono>
//#include <conio.h>
//#include <pdcurses/curses.h>

using namespace std;

//MARK:- Interface Functions Here =>
void intro() {
    cout << "\n\n\t            ";
    cout << "     C++ Project On Hotel Management System";
    cout << "\n\n\t\t\t\t     MADE BY";
    cout << "\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\tDaljeet Singh Chhabra\t\t\t        ||";
    cout << "||\t\t\t\t\t\t\t\t\t      ||";
    cout << "||\t\t\t\t\t  \t\t\t\t      ||";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void head() {
    system("cls");
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
    cout << "\n\t\t\t\t    XYZ Group of Hotels";
    cout << "\n\n\n";
}

void time() {
    int i = 0;
    long long j;
    cout << "\n\n\n\t\t\tConnecting to Server\n\t\t\tSyncing Data";
    while (i < 10) {
        for (j = 5; j > 4; j++) {
            if (j == 99999) {
                cout << ".";
                break;
            }
        }
        ++i;
    }
}

//MARK:- Hotel Class Here =>
class hotel {
private:
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    int days;
    float fare;
public:
    void main_menu();        //to display the main menu
    void add();                //to book a room
    void display();         //to display the customer record
    void rooms();            //to display allotted rooms
    void edit();            //to edit the customer record
    int check(int);          //to check room status
    void modify(int);        //to modify the record
    void delete_rec(int);    //to delete the record
};

void hotel::main_menu() {
    int choice;
    while (choice != 5) {
        head();
        cout << "\n\t\t\t\t*************";
        cout << "\n\t\t\t\t* MAIN MENU *";
        cout << "\n\t\t\t\t*************";
        cout << "\n\n\n\t\t\t\t1.Book A Room";
        cout << "\n\t\t2.Customer Record";
        cout << "\n\t\t3.Rooms Allotted";
        cout << "\n\t\t4.Edit Record";
        cout << "\n\t\t5.Exit";
        cout << "\n\n\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            rooms();
            break;
        case 4:
            edit();
            break;
        case 5:
            break;
        default: {
            cout << "\n\n\t\t\tWrong choice.....!!!";
            cout << "\n\t\t\tPress any key to continue....!!";
            //getch();
        }
        }
    }
}

void hotel::add() {
    head();
    int r, flag;
    ofstream fout("Record.dat", ios::app);
    cout << "\n Enter Customer Details";
    cout << "\n ----------------------";
    cout << "\n\n Room no: ";
    cin >> r;
    flag = check(r);
    if (flag)
        cout << "\n Sorry..!!!Room is already booked";
    else {
        room_no = r;
        cout << " Name: ";
        fflush(stdin);
        cin.ignore(); // Add this line to clear the input buffer
        getline(cin, name);
        cout << " Address: ";
        fflush(stdin);
        getline(cin, address);
        cout << " Phone No: ";
        fflush(stdin);
        getline(cin, phone);

        cout << " No of Days to Checkout: ";
        cin >> days;
        fare = days * 900;    //900 is currently set as the default price per day
        fout.write((char*)this, sizeof(hotel));
        cout << "\n Room is booked...!!!";
    }
    cout << "\n Press any key to continue.....!!";
    //getch();
    fout.close();
}

void hotel::display() {
    head();
    ifstream fin("Record.dat", ios::in);
    int r, flag;
    cout << "\n Enter room no: ";
    cin >> r;
    while (!fin.eof()) {
        fin.read((char*)this, sizeof(hotel));
        if (room_no == r) {
            head();
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone no: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total Fare: " << fare;
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\n Sorry Room no. not found or vacant....!!";
    cout << "\n\n Press any key to continue....!!";
    //// getch();
    fin.close();
}

void hotel::rooms() {
    head();
    ifstream fin("Record.dat", ios::in);
    cout << "\n\t\t\t    List Of Rooms Allotted";
    cout << "\n\t\t\t    ----------------------";
    while (!fin.eof()) {
        fin.read((char*)this, sizeof(hotel));
        cout << "\n Room no: " << room_no << "\n Name: " << name;
        cout << "\n Address: " << address << "\n Phone: " << phone;
        cout << "\n Days: " << days << "\n Total: " << fare;
        cout << "\n**********************************";
    }
    cout << "\n\n\n\t\t\tPress any key to continue.....!!";
    // getch();
    fin.close();
}

void hotel::edit() {
    head();
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1.Modify Customer Record";
    cout << "\n 2.Delete Customer Record";
    cout << "\n Enter your choice: ";
    cin >> choice;
    head();
    cout << "\n Enter room no: ";
    cin >> r;
    switch (choice) {
    case 1:
        modify(r);
        break;
    case 2:
        delete_rec(r);
        break;
    default: cout << "\n Wrong Choice.....!!";
    }
    cout << "\n Press any key to continue....!!!";
    // getch();
}

int hotel::check(int r) {
    int flag = 0;
    ifstream fin("Record.dat", ios::in);
    while (!fin.eof()) {
        fin.read((char*)this, sizeof(hotel));
        if (room_no == r) {
            flag = 1;
            break;
        }
    }
    fin.close();
    return(flag);
}

void hotel::modify(int r) {
    head();
    long pos;
    int flag = 0;
    fstream file("Record.dat", ios::in | ios::out | ios::binary);
    while (!file.eof()) {
        pos = file.tellg();
        file.read((char*)this, sizeof(hotel));
        if (room_no == r) {
            cout << "\n Enter New Details";
            cout << "\n -----------------";
            cout << "\n Name: ";
            fflush(stdin);
            getline(name);
            cout << " Address: ";
            fflush(stdin);
            getline(address);
            cout << " Phone no: ";
            fflush(stdin);
            getline(phone);
            cout << " Days: ";
            cin >> days;
            fare = days * 900;
            file.seekg(pos);
            file.write((char*)this, sizeof(hotel));
            cout << "\n Record is modified....!!";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry Room no. not found or vacant...!!";
    file.close();
}

void hotel::delete_rec(int r) {
    head();
    int flag = 0;
    char ch;
    ifstream fin("Record.dat", ios::in);
    ofstream fout("temp.dat", ios::out);
    while (!fin.eof()) {
        fin.read((char*)this, sizeof(hotel));
        if (room_no == r) {
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone No: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total Fare: " << fare;
            cout << "\n\n Do you want to delete this record(y/n): ";
            cin >> ch;
            if (ch == 'n')
                fout.write((char*)this, sizeof(hotel));
            flag = 1;
            break;
        }
        else
            fout.write((char*)this, sizeof(hotel));
    }
    fin.close();
    fout.close();
    if (flag == 0)
        cout << "\n Sorry room no. not found or vacant...!!";
    else {
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
    }
}

//MARK:- Main() Function Here =>
int main() {
    textbackground(RED);
    textcolor(0);
    hotel h;
    system("cls");
    cout << "\n\n\n";
    intro();
    time();
    cout << "\n\n\n\t\t\tPress any key to continue....!!";
    // getch();
    system("cls");
    head();
    char id[5], pass[7];
    cout << "\n\n\t\t\t\tusername => ";
    cin >> id;
    cout << "\n\t\t\t\tpassword => ";
    cin >> pass;
    cout << "\n\n\t";
    time();
    cout << "\t";
    if (strcmp(id, "admin") == 0 && strcmp(pass, "******") == 0)
        cout << "\n\n\t\t\t  !!!Login Successful!!!";
    else {
        cout << "\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
        // getch();
        exit(-1);
    }
    system("cls");
    h.main_menu();
    // getch();
    return 0;
}


