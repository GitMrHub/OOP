#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

enum Types { bus, walk, horse, transport };

class Date {
private:
	int day, month, year;

public:
	Date() {
		time_t t = time(0);
		tm* ltm =localtime(&t);
		day = ltm->tm_mday;
		month = ltm->tm_mon + 1;
		year = ltm->tm_year + 1900;
	}

	Date(int new_day, int new_month, int new_year) {
		day = new_day;
		month = new_month;
		year = new_year;
	}

	Date(Date& a) {
		day = a.day;
		month = a.month;
		year = a.year;
	}

	~Date() {}

	int get_day() {
		return day;
	}

	int get_month() {
		return month;
	}

	int get_year() {
		return year;
	}

	Date& set_day(int new_day) {
		day = new_day;
		return *this;
	}

	Date& set_month(int new_month) {
		month = new_month;
		return *this;
	}

	Date& set_year(int new_year) {
		year = new_year;
		return *this;
	}

	void print_date() {
		if (day < 10) cout << "0" << day<<".";
		else cout << day << ".";

		if (month < 10) cout << "0" << month << ".";
		else cout << get_month() << ".";
		
		cout << year % 100 << endl;
	}
};


class Organizer {
private:
	char *name, *surname;

public:
	Organizer() {
		name = new char[20];
		surname = new char[20];

		strcpy(name, "Valery");
		strcpy(surname, "Selikhov");

	}

	Organizer(char *new_name, char *new_surname) {
		name = new char[strlen(new_name) + 1];
		surname = new char[strlen(new_surname) + 1];

		strcpy(name, new_name);
		strcpy(surname, new_surname);
	}

	Organizer(Organizer& a) {
		name = new char[strlen(a.name) +1];
		surname = new char[strlen(a.surname) + 1];

		strcpy(name, a.name);
		strcpy(surname, a.surname);
	}

	~Organizer() {
		if (name) delete[] name;
		if (surname) delete[] surname;
	}

	char* get_name() {
		return name;
	}

	char* get_surname() {
		return surname;
	}

	Organizer& set_name(char* new_name) {
		if(name) delete[] name; 
		name = new char[strlen(new_name) + 1];
		strcpy(name, new_name);
		return *this;
	}

	Organizer& set_surname(char* new_surname) {
		if(surname) delete[] surname;
		surname = new char[strlen(new_surname) + 1];
		strcpy(surname, new_surname);
		return *this;
	}

	void print_organizer() {
		cout << "Name: " << name << ". Surname: " << surname <<endl;
	}
};


class Excursion {
private:
	int price;
	Organizer organizer;
	Types type;
	char* place;

public:

	Excursion() {
		price = 1500;
		place = new char[50];
		strcpy(place, "Kiyv");
		type = Types :: bus;

	}

	Excursion(int new_price, char* new_place, char *new_name,  char* new_surname, Types new_type):organizer(new_name, new_surname){
		price = new_price;
		place = new char[strlen(new_place) + 1];
		strcpy(place, new_place);
		type = Types(new_type);
	}

	
	Excursion(Excursion& a) :organizer(a.organizer.get_name(), a.organizer.get_surname()){
		price = a.price;
		place = new char[strlen(a.place) + 1];

		strcpy(place, a.place);
		type = a.type;
	}
	
	~Excursion() {
		if(place) delete[] place;
	}

	char* get_place() {
		return place;
	}

	int get_price() {
		return price;
	}

	Types get_type() {
		return type;
	}

	char* get_name() {
		return organizer.get_name();
	}

	char* get_surname() {
		return organizer.get_surname();
	}

	Excursion& set_place(char* new_place) {
		if(place) delete[] place;
		place = new char[strlen(new_place) + 1];
		strcpy(place, new_place);
		return *this;
	}

	Excursion& set_price(int new_price) {
		price = new_price;
		return *this;
	}

	Excursion& set_organizer(char* new_name, char* new_surname) {
		organizer.set_name(new_name);
		organizer.set_surname(new_surname);
		return *this;
	}

	Excursion& set_type(Types new_type) {
		type = Types(new_type);
		return *this;
	}

	void print_excursion() {
		organizer.print_organizer();
		cout << "Price: " << price << ". Place: " << place << ". Type: " << Types(type) << endl;

	}

	Excursion& set_excursion(int new_price, char* new_place, char* new_name, char* new_surname, Types new_type){
		set_price(new_price);
		set_place(new_place);
		set_organizer(new_name, new_surname);
		set_type(new_type);
		return *this;
	}
};


class Tour {
private:
	Date begin;
	Excursion* excursion;
	int size;

public:

	Tour() {
		size = 1;
		excursion = new Excursion[3];
		
		for (int i = 0; i < size; i++) {
			excursion[i];
		}
	}

	Tour(int new_size, int new_day, int new_month, int new_year, int new_price,  char* new_place, char *new_name, char* new_surname, Types new_type) 
		:begin(new_day, new_month, new_year) {

		size = new_size;
		excursion = new Excursion[3];

		for (int i = 1; i < size; i++) {
			excursion[i].set_excursion(new_price, new_place, new_name,  new_surname, new_type);
		}

	}

	Tour(Tour& a) : begin(a.begin.get_day(), a.begin.get_month(), a.begin.get_year()) {
		size = a.size;

		excursion = new Excursion[3];

		for (int i = 0; i < size; i++) {
			excursion[i] = excursion[i].set_excursion(a.excursion[i].get_price(), a.excursion[i].get_place(), a.excursion[i].get_name(), a.excursion[i].get_surname(), a.excursion[i].get_type());
		}
	}

	~Tour() {
		if (excursion)  delete[] excursion;
	}

	int get_size() {
		return size;
	}

	Tour& set_size(int new_size) {
		size = new_size;
		excursion[size];
		return *this;
	}

	Excursion& operator[](int value) {

		if ((value < size) && (value >= 0)) {
			return this->excursion[value];
		}

		else {
			cout << "ERROR" << endl;
		}
	}

	void print_tour_full() {
		
		for (int i = 0; i < size; i++) {
			if (i > 0) begin.print_date();
			excursion[i].print_excursion();
		}
	}

	void print_tour_short() {

		for (int i = 0; i < size; i++) {
			if (i > 0) begin.print_date();
			cout << "Price: " << excursion[i].get_price() << endl;
		}
	}

	Tour& set_date(int new_date, int new_month, int new_year) {
		begin.set_day(new_date);
		begin.set_month(new_month);
		begin.set_year(new_year);
		return *this;
	}
};


int main() {
	
	Date day1;
	cout << "Types of excursion: 0-bus, 1-walk, 2-horse, 3-transport.\n" << endl;
	Tour tour1;
	cout << "FULL INFORMATION" << endl;
	day1.print_date();
	tour1.print_tour_full(); 
	cout << endl;
	cout << "SHORT INFORMATION" << endl;
	day1.print_date();
	tour1.print_tour_short();

	int day, month, year, price;
	cout << "\nEnter time of tour(xx xx xxxx): " << endl;
	cin >> day >> month >> year;
	Date day2(day, month, year);

	char name[20], surname[20], place[50];
	cout << "Enter name and surname of organizer: " << endl;
	cin >> name >> surname;
	Organizer org2(name, surname);

	Types type;
	type = walk;
	cout << "Enter price: " << endl;
	cin >> price;
	cout << "Enter place: " << endl;
	cin >> place;
	Excursion exc2(price, place, org2.get_name(), org2.get_surname(), type);

	Tour tour2(2, day2.get_day(), day2.get_month(), day2.get_year(), exc2.get_price(), exc2.get_place(), org2.get_name(), org2.get_surname(), exc2.get_type());
	cout << "\n" << endl;
	
	cout << "FULL INFORMATION" << endl;
	day1.print_date();
	tour2.print_tour_full();
	cout << endl;
	cout << "SHORT INFORMATION" << endl;
	day1.print_date();
	tour2.print_tour_short();

	system("pause");
	Tour tour3 = tour2;
	cout << "\n" << endl;

	cout << "FULL INFORMATION" << endl;
	day1.print_date();
	tour3.print_tour_full();
	cout << endl;
	cout << "SHORT INFORMATION" << endl;
	day1.print_date();
	tour3.print_tour_short();

	char name2[20], surname2[20], place2[50];
	cout << "\nEnter new time of tour(xx xx xxxx): " << endl;
	cin >> day >> month >> year;
	Date day3(day, month, year);

	cout << "Enter new name and new surname of organizer: " << endl;
	cin >> name2 >> surname2;
	Organizer org3(name2, surname2);

	type = horse;
	cout << "Enter price: " << endl;
	cin >> price;
	cout << "Enter place: " << endl;
	cin >> place2;
	Excursion exc3(price, place2, org3.get_name(), org3.get_surname(), type);

	tour3.set_size(3);
	tour3.set_date(day3.get_day(), day3.get_month(), day3.get_year());
	tour3[2].set_excursion(exc3.get_price(), exc3.get_place(), exc3.get_name(), exc3.get_surname(), exc3.get_type());

	cout << endl;
	cout << "FULL INFORMATION" << endl;
	day1.print_date();
	tour3.print_tour_full();
	cout << endl;
	cout << "SHORT INFORMATION" << endl;
	day1.print_date();
	tour3.print_tour_short();

	return 0;
}