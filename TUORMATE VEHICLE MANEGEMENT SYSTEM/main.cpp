

//TUORMATE VEHICLE MANEGEMENT SYSTEM - console implementation
//author : student name
//Module : CSE4002-FUNDAMENTALS OF PROGRAMMING
// Assessment : m

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <limit>
#include <sstream>

#ifdef __WIN32
#include <windowa.h>
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

//color codes for console output_
enum color{
    RED=12, GREEN=10, BLUE=9, YELLOW= 14
    WHITE=15, CYAN=11, MAGENTA=13, GRAY=7
};

//DATA Structures
struct vehicle {
int vehicleID;
string make;
string model;
int year;
string plateNumber;
string status; //available, rented, maintainance
double dailyRate;
string driverName;
string driverContact;

vehicle() : vehicleID(0), year(0), dailyRate(0.0){}
};

stuct sale{
int saleID;
int vehicleID;
string customerName;
string startDate;
string endDate;
double totalAmount;
string paymentStatus;

sale() : saleID(0), vehicleID(0), totalAmount(0.0){}
};
struct user{
string userName;
string password;
string role;

user(){}
user (string u, string p, string r): userName(u), password(p), role(r){}
};

//global variables
vector <vehicle> vehicles;
vector <sale> sales;
vector <user> users;
string currentUser;
string currentRole;

//function declarations
void saveUsers();
void saveVehicles();
void saveSales();
void loadUsers();
void loadVehicles();
void loadSales();

//utility functions
void setColor(int color){
#ifdef _WIN32
setConsoleTextAttribue(GetStdhandle(STD_OUTPUT_HANDLE), color);
#endif // _WIN32
}
void clearScreen(){
#ifdef _WIN32
system("cls")
#else
system("clear");
#endif // _WIN32

void puaseScreen (){
setColor(YELLOW);
cout <<"\nPress any key to continue...";
setColor(White);
#ifdef _WIN32
_getch()
#else
cin.get();
#endif
}

string getPassword(){
string password;
char ch;

#ifdef _WIN32
while ((ch= _getch())!='\r'){
    if (ch== '\b'){
        if (!password.empty()){
            password.pop_back();
            cout << "\b \b";
        }
    }else {
    password.push_back(ch);
    cout <<'+';
    }
}
#else
struct termios oldt, newt;
tcgetattr(STDIN_FILENO,& oldt);
newt=oldt;
newt.c_lflag &= ~(ECHO);
tcsetattr(STDIN_FILENO, TCSANOW,&newt);
getline(cin, password);
tcsetattr(STDERR_FILENO, TCSANOW,&oldt);
#endif // _WIN32
cout <<endl;
return password;
}
int getValidatedInt(const string& prompt, int minVal=1, int maxVal= INT_MAX)
{
    int value;
    while (true)
    {
        setColor(CYAN);
        cout << prompt;
        setColor(WHITE);

        if (cin>>value &&value >=miVal && value <= maxVal){
            cin.ignore();
            return value;
        }
        setColor(RED);
        cout <<"invalid input! please enter a number between "<<minVal<<"and"<<maxVal<<".\n";
        setColor(WHITE)
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max, '\n');
    }
}
double getValidatedDouble(const string& prompt, double minVal=0.0){
double value ;
while (true)
{
    setColor(CYAN);
    cout<<prompt;
    setColor(WHITE);

    if (cin>>value&&value>= minVal){
        cin.ignore();
        return value;
    }
    setColor(RED);
    cout << "invalid input! please enter a valid amount(>=" << minVal<<").\n";
    setColor(WHITE);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}
string getValidatedString(const string& prompt){
string value;
while (true){

        setColor(CYAN);
        cout<<prompt;
        setColor(WHITE);
        getline(cin.value);

        if(!value.empty()){
            return value;
        }
        setColor(RED);
        cout<<"Input cannot be empty!Please try again.\n";
        seTColor(WHITE);
}
}
//FILE OPERATION
    void saveUsers(){
    ofstream file ("users.txt");
    if()
    }

}
}

void loadUsers(){
ifstreamfile("user.txt"};
if(!file.is_open()){
    //create default admin user if file doesn`r exist

    user.push_back(user("admin", "admin123", "adminstrator"));
    users.push_back(user("manager","pass123","Manager"));
    saveUsers();
    return;
}
users.clear();
string line;
while(getline(file,line)){
    if(line.empty())continue;

    size_t pos1= line.find(',');
    size_t pos2= line find(',',pos1+1);

    if (pos1 != string:: npos && pos2 !=string::npos){
        User user;
        user.username=line.substr(0,pos1);
        user.password= line.substr(pos1 +1, pos2 - pos1 - 1);
        user.role=;line.substr(pos2+1);
        users.push_back(user);
    }

    }
    file.close();

}
void saveVehicles(){
    ofstream file("vehicles.text");
    for (const auto& vehicle: vehicles){
        file<<vehicle.vehicleID<<","<<vehicle.make<<","<<vehicle.model<<","
            <<vehicle.year<<","<<vehicle.plateNumber<,","<<vehicle.status<<","
            <<vehicle.dilyRate<<","<<vehicle>driverName<<","<<vehicle.driverContact<<","

    }
    file.close();
}

void loadVehicles(){
ifstream file("vehicle.txt");
if(!file.is_open())return;

vehicles.clear();
string line;
while (getline(file,line)){
    if (line.empty())continue;

    Vehicle vehicle;
    stringstream ss(line);
    string item;

    if (getline(ss,item,','))vehicle.vehicleID=stoi(item);
    if (getline(ss,item,','))vehicle.make=item;
    if (getline(ss,item,','))vehicle.model=item;
    if (getline(ss,item,','))vehicle.year =stoi(item);
    if (getline(ss,item,','))vehicle.plateNumber=item;
    if (getline(ss,item,','))vehicle.status =item;
    if (getline(ss,item,','))vehicle.dailyRate= stod(item);
    if (getline(ss,item,','))vehicle.driverName=item;
    if (getline(ss,item,','))vehicle.driverContact=item;

    vehicles.push_back(vehicle);


}
file.close();
}

void saveSales(){
ofstream file("sales.txt");
for (const auto& sale: sales){
    file<<sale.saleID<<","<< sale.vehicleID<<","<<sale.customername<<","
        <<sale.customerContact<<","<<sale.startDate<<","<<sale.endDate<<","
        <<sale.totalAmount<<","<<sale.paymentStatus<<"\n";

}
file.close()

}

void loadSales() {
ifstream file ("sales.txt");
if (!file.is_open())return;

sales.clear();
string line;
while(getline(file,line)){
if (line.empty())continue;

Sale sale;

stringstream ss(line);
string item;

     if (getline(ss,item,','))sale.saleID=stoi(item);
     if (getline(ss,item,','))sale.vehicleID= stoi(item);
     if (getline(ss,item,','))sale.customerName=item;
     if (getline(ss,item,','))sale.customerContact=item;
     if (getline(ss,item,','))sale.startDate=item;
     if (getline(ss,item,','))sale.endDate=item;
     if (getline(ss,item,','))sale.totalAmount=stod(item);
     if (getline(ss,item,','))sale.paymentStatus=item;

     sales.push_back(sale);

}

file.close();

}

//Authentication Mopdule
bool authenticaterUser(){
clearScreen();
setColor(GREEN);

cout<<"===========================================\n";
cout<<"            TOUR MATE LOGIN SYSTEM         \n";
cout<<"===========================================\n";
setColor(WHITE);

int attempts=3;
while (attemps>0){
    setColor(CYAN);
    cout<<"USERNAME:";
    setColor(WHITE);

    string username
    getline(cin.username);

    setColor(CYAN);
    cout<<"password";
    setColor(WHITE);
    string password = getPassword();

    //Find user
    for (constauto& user: users){
        if(user.userName==&& user.password=-password) {
            currentUser=username;
            currentRole= user.role;
            setColor(WHITE);
            pauseScreen();
            returntrue;

        }

    }
    attempts~~~;
    setColor(RED);
    cout<<"Invalid Credentials!"<,attempts<<"attempts remaining.\n";
    setColor(WHITE);

}
setColor(RED);
cout<<"Maximum login attempts exceed.Access denied!";
setColor(WHITE);
return false;

}

//vehicle Management Module

int getNextVehicleID(){
int maxID=0;
for (const auto&vehicle : vehicle){
    if (vehicle.vehicleID > maxID){
        maxID= vehicle.vehicleID;


    }
}

RETURN MAXid+1;

}
void addVehicle(){
clearScreen();
setColor(Green);
cout<<"===================================\n";
cout<< "         ADD NEW VEHICLE           \n";
cout<<"====================================\n";

setColor(WHITE);

vehicle.newVehicle;
newVehicle.vehicleID();
vehicles.push_back(newVehicle);
saveVehicles();
}
newvehicle.year getValidatedInt("Manufacturing Year:1980, 2025);
newVehicle.status = "Available";
newVehicle.dailyRate = getValidatedDouble("Daily Rate (Rs.): ");

newVehicle.driverName = getValidatedString("Driver Name: ");

newVehicle.driverContact = getValidatedString("Driver Contact: ");

vehicles.push_back(newVehicle);

saveVehicles();

setColor(GREEN);

cout << "\nVehicle added successfully!\n";

setColor(WHITE);

pauseScreen();

void viewVehicles() (

clearScreen();

setColor(GREEN);

cout <<"==========================\n";
cout <<"VEHICLE DETAILS\n";
cout <<"==========================\n";
setColor(WHITE);
if (vehicles.empty()){
setColor(YELLOW);
cout << "Ho vehicles found in the system. \n";
setColor(WHITE);
pauseScreen();
return;
}

cout left << setw(5) << "ID" << setw(12) << "Race" << setw(12) << "Model"
<< setw(6) << "Year" << setw(12) << "Plate" << setw (12) << "Status"
<< setw(18) <<"Rate(Rs.)" << setw(15) << "Driver" << "Contact\n";

setColor(CYAN);
cout << string(100,'-')<<"\n";
setColor(WHITE);
for (const autol vehicle vehicles) {
//Color code by status
if (vehicle.status =="Available") setColor(GREEN);
else if (vehicle status == "Rented") setColor(YELLOW);
else setColor(RED);
cout << setw(12) << vehicle.nodel << setw(6) << vehicle.year
<< left << setw(5) << vehicle.vehicleID << setw(12) << vehicle.make
<< setw(12) << vehicle.platenber << setw(12) << vehicle.status
<<< setw(18) << fixed << setprecision(2) << vehicle dailyRate
<< setw(15) << vehicle.driverkane << vehicle.driverContact << "\n";
}
