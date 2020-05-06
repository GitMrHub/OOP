//#include "pch.h"
#include <string.h>
#include<iostream>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date()
	{
		time_t t = time(0);
		tm* ltm = localtime(&t);
		day = ltm->tm_mday;
		month = ltm->tm_mon + 1;
		year = ltm->tm_year + 1900;
	}
	Date(int day1, int month1, int year1)
	{
		day = day1;
		month = month1;
		year = year1;
	}
	Date(Date& a)
	{
		day = a.day;
		month = a.month;
		year = a.year;
	}
	Date& set_day(int day1)
	{
		day = day1;
		return *this;
	}

	Date& set_month(int month1)
	{
		month = month1;
		return *this;
	}

	Date& set_year(int year1)
	{
		year = year1;
		return *this;
	}
	~Date() {}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
	void print_date()
	{
		if (day < 10)
			cout << "0" << day << ".";
		else
			cout << day << ".";

		if (month < 10)
			cout << "0" << month << ".";
		else
			cout << getyear() << ".";

		cout << year % 100 << endl;

	}
};

enum Services
{
	Cleaning,
	Washingwindows,
	Babysitting,
	Mending,
	Mixed,
};

class Executant
{
private:
	char* name, * surname;
	Date date;
public:
	Executant()
	{
		name = new char[20];
		surname = new char[20];

		strcpy(name, "Carl");
		strcpy(surname, "Johnson");

	}

	Executant(char* new_name, char* new_surname, int db, int mb, int yb) : date(db, mb, yb)
	{
		name = new char[strlen(new_name) + 1];
		surname = new char[strlen(new_surname) + 1];

		strcpy(name, new_name);
		strcpy(surname, new_surname);
	}

	Executant(Executant& a)
	{
		name = new char[strlen(a.name) + 1];
		surname = new char[strlen(a.surname) + 1];

		strcpy(name, a.name);
		strcpy(surname, a.surname);
	}

	~Executant()
	{
		if (name)
			delete[] name;
		if (surname)
			delete[] surname;
	}

	char* get_Name()
	{
		return name;
	};

	char* get_Surname()
	{
		return surname;
	};

	Executant& set_date(int db, int mb, int yb) {
		date.set_day(db);
		date.set_month(mb);
		date.set_year(yb);
		return *this;
	}


	Date getdayb()
	{
		return date;
	}

	Executant& set_name(char* new_name) {

		if(name) delete[] name;
		name = new char[strlen(new_name) + 1];
		strcpy(name, new_name);
		return *this;
	}

	Executant& set_surname(char* new_surname) {
		if (surname) delete[] surname;
		surname = new char[strlen(new_surname) + 1];
		strcpy(surname, new_surname);
		return *this;
	}

	void print_executant() {
		cout << "Name: " << name << ". Surname: " << surname << endl;
	}
};

class Customer {
private:
	Services service;
	char* address;
public:
	Customer() {
		address = new char[50];
		strcpy(address, "Tyraspolska60");
		service = Services::Cleaning;

	}
	Customer(char* new_address, Services new_service) :service(new_service) {
		address = new char[strlen(new_address) + 1];
		strcpy(address, new_address);
		service = Services(new_service);
	}
	Customer(Customer& a):service(a.service) {
		address = new char[strlen(a.address) + 1];
		strcpy(address, a.address);
	}

	~Customer() {
		if (address) delete[] address;
	}

	char* get_address() {
		return address;
	}
	Customer& set_address(char* new_address) {
		if (address) delete[] address;
		address = new char[strlen(new_address) + 1];
		strcpy(address, new_address);
		return *this;
	}
	Customer& set_service(Services new_service) {
		service = Services(new_service);
		return *this;
	}

	void print_customer() {
		cout << ". Address: " << address << ". Service: " << service << endl;

	}

	Customer& set_customer(char* new_address, Services new_service) {
		set_address(new_address);
		set_service(new_service);
		return *this;
	}
	Services get_service() {
		return service;
	}

};
class Order {
private:
	Executant executant;
	Customer customer;
	Date date;
	int size;
	int pservice = 500;
	int arr[1];
public:

	Order() {
		size = 1;
		for (int i = 0; i < size; i++) {
				arr[i]=pservice;
		}
	}

	Order(int new_size, int new_pservice, char* new_name, char* new_surname, char *address, Services new_service,  int db, int mb, int yb ) :executant(new_name, new_surname, db, mb,yb) {
		pservice = new_pservice;
		for (int i = 0; i < size; i++) {
			arr[i] = pservice;
		}

	}

	Order(Order& a)  {
		pservice = a.pservice;
		for (int i = 0; i < size; i++) {
			arr[i] = pservice;
		}
	}
	~Order() {
	}

	int get_pservice() {
		return pservice;
	}
	int get_size() {
		return size;
	}

	char* get_Name() {
		return executant.get_Name();
	}

	char* get_Surname() {
		return executant.get_Surname();
	}

	Order& set_pservice(int new_pservice) {
		pservice = new_pservice;
		return *this;
	}


	Order& set_executant(char* new_name, char* new_surname) {
		executant.set_name(new_name);
		executant.set_surname(new_surname);
		return *this;
	}

	void print_order() {
		executant.print_executant();
		cout << "Price: " << pservice << ". Service: " << arr[0] << endl;

	}

	Order& set_order(int new_pservice, char* new_name, char* new_surname) {
		set_pservice(new_pservice);
		set_executant(new_name, new_surname);
		return *this;
	}
};


class ServiceOffice {
private:
	char* title;
	Order* order;
	int size;
public:
	ServiceOffice() {
		size = 1;
		order = new Order[size];

		for (int i = 0; i < size; i++) {
			order[i];
		}
	}

	ServiceOffice(int new_size, int new_pservice, char* new_name, char* new_surname) {

		size = new_size;
		order = new Order[size];

		for (int i = 1; i < size; i++) {
			order[i].set_order(new_pservice, new_name, new_surname);
		}

	}

	ServiceOffice(ServiceOffice& a) {
		size = a.size;
		order = new Order[3];

		for (int i = 0; i < size; i++) {
			order[i] = order[i].set_order(a.order[i].get_pservice(), a.order[i].get_Name(), a.order[i].get_Surname());
		}
	}

	~ServiceOffice() {
		if (order)  delete[] order;
	}

	int get_size() {
		return size;
	}

	ServiceOffice& set_size(int new_size) {
		size = new_size;
		order[size];
		return *this;
	}


	Order& operator[](int value) {

		if ((value < size) && (value >= 0)) {
			return this->order[value];
		}

		else {
			cout << "ERROR" << endl;
		}
	}

	void print_servoff_full() {


		for (int i = 0; i < size; i++) {
			if (i > 0)
				order[i].print_order();
		}
	}

	void print_servoff_short() {
		for (int i = 0; i < size; i++) {
			if (i > 0)
				cout << "Price: " << order[i].get_pservice() << endl;
		}
	}
};


int main()
{
	Date day1;
	cout << "Services: 0-cleaning, 1-washing windows, 2-babysitting, 3-mending, 4-mixed.\n" << endl;
	ServiceOffice servoff1;
	day1.print_date();
	servoff1.print_servoff_full();
	cout << endl;
	servoff1.print_servoff_short();

	char name[20], surname[20];
	char address[20];
	cout << "Enter name and surname of executant: " << endl;
	cin >> name >> surname;
	Executant ex2(name, surname, day1.getday(), day1.getmonth(), day1.getyear());
	int pservice;
	Services service;
	service = Cleaning;
	cout << "Enter price: " << endl;
	cin >> pservice;
	cout << "Enter address of customer: " << endl;
	cin >> address;
	Customer cust2(address, service);
	Order ord2(3, pservice, ex2.get_Name(), ex2.get_Surname(), cust2.get_address(), service, day1.getday(), day1.getmonth(), day1.getyear());

	ServiceOffice servoff2(3, ord2.get_pservice(), ex2.get_Name(), ex2.get_Surname());
	cout << "\n" << endl;
	servoff2.print_servoff_full();
	cout << endl;
	servoff2.print_servoff_short();
	cust2.print_customer();

	ServiceOffice servoff3 = servoff2;
	cout << "\n" << endl;
	servoff3.print_servoff_full();
	cout << endl;
	servoff3.print_servoff_short();

	char name2[20], surname2[20];
	char address2[20];

	cout << "Enter new name and new surname of executant: " << endl;
	cin >> name2 >> surname2;
	Executant ex3(name2, surname2, day1.getday(), day1.getmonth(), day1.getyear());
	service = Washingwindows;
	cout << "Enter price: " << endl;
	cin >> pservice;
	cout << "Enter address of customer: " << endl;
	cin >> address2;
	Customer cust3(address2, service);
	Order ord3(1, pservice, ex3.get_Name(), ex3.get_Surname(), cust2.get_address() , service, day1.getday(), day1.getmonth(), day1.getyear());
	servoff3.set_size(3);
	servoff3[2].set_order(ord3.get_pservice(), ord3.get_Name(), ord3.get_Surname());
	cout << endl;
	servoff3.print_servoff_full();
	cout << endl;
	servoff3.print_servoff_short();
	cust3.print_customer();
	return 0;
}