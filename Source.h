


#include "stdafx.h"

using namespace std;

#ifndef SOURCE_H
#define SOURCE_H
const int NAME_SIZE = 20;
const int MAX_COMPANY_NUMBER = 20;
const int MAX_EMPLOYEE_NUMBER = 20;
const int MAX_ORDER_NUMBER = 30;
const int MAX_MATERIAL_SIZE = 30;
const int MAX_PRODUCT_SIZE = 30;
const int READLINE_LENGTH = 80;

class Company;
class Product;
class Material;
class Employee;
class Order;
class Customer;
class Time;
class UserInterface;


// Get current date/time, format is YYYY-MM-DD
class Time {
private:
	char* m_datetime;

public:
	// Default constructor
	Time() {
		m_datetime = new char[30];
		time_t now = time(0);
		struct tm* tstruct = new struct tm();
		localtime_s(tstruct, &now);
		strftime(m_datetime, 30, "%Y/%m/%d", tstruct);
	}
	~Time() {
		delete[] m_datetime;
		TRACE(_T("CALL TIME DESCONTRUCTOR"));
	}
	// getting function
	char* get_time() {
		return m_datetime;
	}
	// setting function
	void set_time(char* datetime) {
		strcpy_s(m_datetime, strlen(datetime) + 1, datetime);
	}
};

// Customer class
class Customer {
private:
	char* m_name;
	char* m_address;
public:
	// Default constructor
	Customer() {
		m_name = new char[NAME_SIZE]{0};
		m_address = new char[80]{0};
	}
	~Customer() {
		delete[] m_name;
		delete[] m_address;
		TRACE(_T("CALL CUSTOMER DELETE DESCONTRUCOTR"));
	}
	// setting function
	void set_name(char* name) {
		m_name = name;
	}
	void set_address(char* address) {
		m_address = address;
	}
	// getting function
	char* get_name() {
		return m_name;
	}
	char* get_address() {
		return m_address;
	}
	void printFile(FILE* ofp) {
		// output to the file
		fprintf_s(ofp, "Customer: %s\n\tAddress: %s\n", m_name, m_address);
	}
	void readFile(FILE* ifp, char* readline) {
		fscanf_s(ifp, "%s %s", readline, READLINE_LENGTH, m_name, NAME_SIZE);
		fscanf_s(ifp, "%s %s", readline, READLINE_LENGTH, m_address, 80);
	}
};
// Payable class
class Material {
private:
	char* m_name;
	int* m_number;
	int* m_price;
	Time* m_recordDate;
public:
	// Default constructor
	Material() {
		m_name = new char[NAME_SIZE]{0};
		m_number = new int{ 0 };
		m_price = new int{ 0 };
		m_recordDate = new Time();
	}
	~Material() {
		delete[] m_name;
		delete m_number;
		delete m_price;
		delete[] m_recordDate;
		TRACE(_T("Delete Material"));
	}
	// setting function
	void set_name(char* name) {
		m_name = name;
	}
	void set_number(int number) {
		*m_number = number;
	}
	void set_price(int price) {
		*m_price = price;
	}
	void set_material(char* name, int number, int price) {
		m_name = name;
		*m_number = number;
		*m_price = price;
	}
	// getting function
	char* get_name() {
		return m_name;
	}
	int* get_price() {
		return m_price;
	}
	int* get_number() {
		return m_number;
	}
	char* get_date() {
		return m_recordDate->get_time();
	}
	void printFile(FILE* ofp) {
		// output to the file
		fprintf_s(ofp, "Material: %s\t%d\t%d\t%s\n", m_name, *m_number, *m_price, m_recordDate->get_time());
	}
	void readFile(FILE* ifp, char* readline) {
		fscanf_s(ifp, "%s %d %d %s", m_name, NAME_SIZE, m_number, m_price, readline, READLINE_LENGTH);
		m_recordDate->set_time(readline);
	}
};
class Employee {
private:
	char* m_name;
	int* m_salary;
	Time* m_recordDate;
public:
	// default construtor
	Employee() {
		m_name = new char[NAME_SIZE]{0};
		m_salary = new int{ 0 };
		m_recordDate = new Time();
	}
	~Employee() {
		delete[] m_name;
		delete m_salary;
		delete[] m_recordDate;
		TRACE(_T("CALL EMPLOYEE DESCONTRUCTOR"));
	}
	// setting function
	void set_employee(char* name, int salary) {
		m_name = name;
		*m_salary = salary;
	}
		void set_name(char* name) {
			m_name = name;
		}
		void set_salary(int salary) {
			*m_salary = salary;
		}
		// getting function
		int* get_salary() {
			return m_salary;
		}
		char* get_name() {
			return m_name;
		}
		char* get_date() {
			return m_recordDate->get_time();
		}
		void printFile(FILE* ofp) {
			// output to the file
			fprintf_s(ofp, "Employee: %s\t%d\t%s\n", m_name, *m_salary, m_recordDate->get_time());
		}
		void readFile(FILE* ifp, char* readline) {
			fscanf_s(ifp, "%s %d %s", m_name, NAME_SIZE, m_salary, readline, READLINE_LENGTH);
			m_recordDate->set_time(readline);
		}

	};
	// Receivable class
	class Product {
	private:

		char* m_name;
		char* m_company_name;
		int* m_number;
		int* m_produced_number;
		int* m_price;
		Time* m_recordDate;

		/**
		* char* m_material_name: the material of the product needed
		* int* m_material_amount: the amount of material
		*/

		char** m_needed_material;
		int* m_needed_material_amount;
		int m_material_number;

	public:
		// Default constructor
		Product() {
			m_name = new char[NAME_SIZE]{0}; 
			m_company_name = new char[NAME_SIZE]{0};
			m_number = new int{ 0 };
			m_produced_number = new int{ -1 };
			m_price = new int{ 0 };
			m_recordDate = new Time();

			// initialize the material information
			m_needed_material = new char*[MAX_MATERIAL_SIZE];
			for (int i = 0; i < MAX_MATERIAL_SIZE; i++){
				*(m_needed_material + i) = new char[NAME_SIZE]{0};
			}
			m_needed_material_amount = new int[MAX_MATERIAL_SIZE]{0};
			m_material_number = 0;
		}
		~Product() {
			TRACE(_T("DELETE PRODUCT DESCONTRUCTOR"));
			delete[] m_name;
			delete[] m_company_name;
			delete m_number;
			delete m_produced_number;
			delete m_price;
			delete[] m_recordDate;
			for (int i = 0; i < MAX_MATERIAL_SIZE; i++) {
				delete[] m_needed_material[i];
			}
			delete[] m_needed_material;
			delete[] m_needed_material_amount;
		}
		Product& operator=(const Product& product) {
			// Product name Copy
			delete[] m_name;
			m_name = new char[NAME_SIZE]{0};
			strcpy_s(this->m_name, strlen(product.m_name) + 1, product.m_name);
			// Company name Copy
			delete[] m_company_name;
			m_company_name = new char[NAME_SIZE]{0};
			strcpy_s(this->m_company_name, strlen(product.m_company_name) + 1, product.m_company_name);
			// number Copy
			delete[] m_number;
			m_number = new int{ *product.m_number };
			// produced number Copy
			delete[] m_produced_number;
			m_produced_number = new int{ *product.m_produced_number };
			// price Copy
			delete[] m_price;
			m_price = new int{ *product.m_price };
			// record Date Copy
			delete[] m_recordDate;
			m_recordDate = new Time();
			m_recordDate->set_time(product.m_recordDate->get_time());
			// material number Copy
			m_material_number = product.m_material_number;
			// material Copy
			for (int i = 0; i < MAX_MATERIAL_SIZE; i++){
				delete[] m_needed_material[i];
			}
			delete[] m_needed_material;
			m_needed_material = new char*[MAX_MATERIAL_SIZE];
			for (int i = 0; i < MAX_MATERIAL_SIZE; i++){
				m_needed_material[i] = product.m_needed_material[i];
			}
			// material amount Copy
			delete[] m_needed_material_amount;
			m_needed_material_amount = new int[MAX_MATERIAL_SIZE]{0};
			for (int i = 0; i < m_material_number; i++){
				m_needed_material_amount[i] = product.m_needed_material_amount[i];
			}
			return *this;
		}

		// setting function
		void set_name(char* name) {
			m_name = name;
		}
		void set_number(int number) {
			*m_number = number;
		}
		void set_price(int price) {
			*m_price = price;
		}
		void set_produced_number(int number) {
			*m_produced_number = number;
		}
		void set_company(char* name) {
			m_company_name = name;
		}
		void set_material(char** material) {
			m_needed_material = material;
		}
		void set_material_number(int number) {
			m_material_number = number;
		}
		void set_material_amount(int* amount) {
			m_needed_material_amount = amount;
		}
		void set_product(char* name, int number, int price) {
			m_name = name;
			*m_number = number;
			*m_price = price;
		}

		// getting function
		char* get_name() {
			return m_name;
		}
		char* get_company() {
			return m_company_name;
		}
		int* get_number() {
			return m_number;
		}
		int* get_price() {
			return m_price;
		}
		char* get_date() {
			return m_recordDate->get_time();
		}
		int* get_produced_number() {
			return m_produced_number;
		}
		char** get_material() {
			return m_needed_material;
		}
		int* get_material_amount() {
			return m_needed_material_amount;
		}
		int get_material_number() {
			return m_material_number;
		}
		void calculate_produced_number(char** material, int* number, int size) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < m_material_number; j++) {
					if (!strcmp(*(material + i), *(m_needed_material + j))) {
						if (*m_produced_number == -1) {
							*m_produced_number = *(number + i) / *(m_needed_material_amount + j);
						}
						else {
							if (*(number + i) % *(m_needed_material_amount + j) < *m_produced_number)
								*m_produced_number = *(number + i) / *(m_needed_material_amount + j);
						}
					}
				}
			}

		}
		void printFile(FILE* ofp) {
			fprintf_s(ofp, "Product: %s\t%d\t%d\t%d\t%s\n", m_name, *m_number, *m_price, *m_produced_number, m_recordDate->get_time());
			// print the material the product need
			if (m_material_number > 0) {
				for (int i = 0; i < m_material_number; i++) {
					fprintf(ofp, "\tNeeded: %s\t%d\n", *(m_needed_material + i), *(m_needed_material_amount + i));
				}
			}
			//	End tag
			fprintf_s(ofp, "\tEnd\n");
		}
		void readFile(FILE* ifp, char* readline) {
			// read the basic info of the product
			fscanf_s(ifp, "%s %d %d %d %s", m_name, NAME_SIZE, m_number, m_price, m_produced_number, readline, READLINE_LENGTH);
			m_recordDate->set_time(readline);

			// read the materail the product need
			while (!feof(ifp)) {
				fscanf_s(ifp, "%s", readline, READLINE_LENGTH);
				if (!strcmp("End", readline)) {
					break;
				}
				int &next = m_material_number;
				fscanf_s(ifp, "%s %d", *(m_needed_material + next), NAME_SIZE, m_needed_material_amount + next);
				m_material_number++;
			}

		}
	};
	// Order class
	class Order {
	private:
		Customer* m_customer;
		char* m_company_name;
		char** m_ordered_product;
		int* m_ordered_product_amount;
		int m_product_number;

		Time* m_expectedDate;
	public:
		// Default Constructor
		Order() {
			m_customer = new Customer;
			m_expectedDate = new Time();

			m_ordered_product = new char*[MAX_PRODUCT_SIZE];
			for (int i = 0; i < MAX_PRODUCT_SIZE; i++) {
				*(m_ordered_product + i) = new char[NAME_SIZE]{0};
			}
			m_ordered_product_amount = new int{ 0 };
			m_product_number = 0;
		}
		~Order() {
			TRACE(_T("CALL ORDER DESCONTRUCTOR"));
			delete[] m_customer;
			delete[] m_company_name;
			for (int i = 0; i < MAX_ORDER_NUMBER; i++) {
				delete[] m_ordered_product[i];
			}
			delete[] m_ordered_product;
			delete[] m_ordered_product_amount;
			delete[] m_expectedDate;
		}
		// setting function
		void set_customer(char* name) {
			m_customer->set_name(name);
		}
		void set_address(char* address) {
			m_customer->set_address(address);
		}
		void set_expectedDate(char* date) {
			m_expectedDate->set_time(date);
		}
		void set_product_number(int number) {
			m_product_number = number;
		}
		void set_company(char* name) {
			m_company_name = name;
		}
		void set_product(char** product) {
			for (int i = 0; i < m_product_number; i++) {
				m_ordered_product[i] = product[i];
			}
		}
		void set_product_amount(int* amount) {
			m_ordered_product_amount = amount;
		}
		// getting functoin
		char* get_company() {
			return m_company_name;
		}
		char* get_customer() {
			return m_customer->get_name();
		}
		Customer* get_customer_object() {
			return m_customer;
		}
		char* get_address() {
			return m_customer->get_address();
		}
		char* get_expectedDate() {
			return m_expectedDate->get_time();
		}
		int get_product_number() {
			return m_product_number;
		}
		int* get_product_amount() {
			return m_ordered_product_amount;
		}
		char** get_product() {
			return m_ordered_product;
		}
		// change function
		void change_product_list() {
			int selected;
			int option;
			char* name = new char[NAME_SIZE]{0};
			int number = 0;
			for (int i = 0; i < m_product_number; i++) {
				cout << i + 1 << ". "
					<< *(m_ordered_product + i) << " x "
					<< *(m_ordered_product_amount + i) << endl;
			}
			cout << "Select a ordered product" << endl;
			cin >> selected;
			cout << "What do you want to modify?" << endl
				<< "1. Name" << endl
				<< "2. Number" << endl;
			cin >> option;
			switch (option) {
			case 1:
				cin >> name;
				*(m_ordered_product + selected - 1) = name;
				break;
			case 2:
				cin >> number;
				*(m_ordered_product_amount + selected - 1) = number;
				delete[] name;
				break;
			default:
				delete[] name;
				break;
			}
		}
		//void create_order(Company* company);
		void printFile(FILE *ofp) {
			fprintf(ofp, "Order: \n");
			fprintf(ofp, "\t");
			m_customer->printFile(ofp);
			fprintf(ofp, "\tExpectedDate: %s\n", m_expectedDate->get_time());
			for (int i = 0; i < m_product_number; i++) {
				fprintf(ofp, "\tPurchased: %s\t%d\n", *(m_ordered_product + i), *(m_ordered_product_amount + i));
			}
			fprintf_s(ofp, "\tEnd\n");
		}
		void readFile(FILE* ifp, char* readline) {
			// read customer and expected date
			m_customer->readFile(ifp, readline);
			fscanf_s(ifp, "%s %s", readline, READLINE_LENGTH, readline, READLINE_LENGTH);
			m_expectedDate->set_time(readline);
			// read ordered product
			while (!feof(ifp)) {
				fscanf_s(ifp, "%s", readline, READLINE_LENGTH);
				if (!strcmp("End", readline)) {
					break;
				}
				int &next = m_product_number;
				fscanf_s(ifp, "%s %d", *(m_ordered_product + next), NAME_SIZE, m_ordered_product_amount + next);
				m_product_number++;
			}
		}
	};
	class Company {
	private:
		/**
		* =============Basic INFO==============
		* char* m_company: the name of company
		* int* m_assets: the initial assets of company
		* int* m_liabilities: the initial liabilities of company
		* int* m_expesnes: the expenses of the company(accounts payable of material and employee)
		* int* m_revenue: the revenue of the company(product)
		*
		* =============Accounts payable========
		* Employee* m_employee: the employee of the company
		* Material* m_material: the material of the company
		*
		* =============Accounts receivable=====
		* Product* m_product: the product of the company
		*
		* =====================================
		* Order* m_order: the order of the company
		*/
		char* m_company;
		int* m_assets;
		int* m_liabilities;
		int* m_revenue;
		int* m_expenses;
		Employee* m_employee;
		Material* m_material;
		Product* m_product;
		Order* m_order;

		/**
		* int m_employee_number: the number of the employee in the company
		* int m_order_number: the number of the number in the company
		* int m_material_type_number: the types of the material
		* int m_product_number: the types of the number
		*/
		int m_employee_number;
		int m_order_number;
		int m_material_type_number;
		int m_product_type_number;


	public:
		// static int company_number: to count the number of all the companies
		// default constructor
		Company() {

			m_company = new char[NAME_SIZE]{0};
			m_assets = new int{ 0 };
			m_liabilities = new int{ 0 };
			m_revenue = new int{ -1 };
			m_expenses = new int{ -1 };

			m_employee = new Employee[MAX_EMPLOYEE_NUMBER]();
			m_order = new Order[MAX_ORDER_NUMBER]();
			m_material = new Material[MAX_MATERIAL_SIZE]();
			m_product = new Product[MAX_PRODUCT_SIZE]();

			m_employee_number = 0;
			m_order_number = 0;
			m_material_type_number = 0;
			m_product_type_number = 0;

		}
		// read company information from the file
		~Company() {
			TRACE(_T("CALL COMPANY DESCONTRUCTOR"));
			delete[] m_company;
			delete m_assets;
			delete m_liabilities;
			delete m_revenue;
			delete m_expenses;
			delete[] m_employee;
			delete[] m_material;
			delete[] m_product;
			delete[] m_order;


		}
		void readFile(FILE* ifp, char* readline) {
			// read basic information
			fscanf_s(ifp, "%s", m_company, READLINE_LENGTH);
			fscanf_s(ifp, "%s %d", readline, READLINE_LENGTH, m_assets);
			fscanf_s(ifp, "%s %d", readline, READLINE_LENGTH, m_liabilities);
			fscanf_s(ifp, "%s %d", readline, READLINE_LENGTH, m_revenue);
			fscanf_s(ifp, "%s %d", readline, READLINE_LENGTH, m_expenses);

			while (!feof(ifp)) {
				fscanf_s(ifp, "%s", readline, READLINE_LENGTH);
				if (!strcmp("Employee:", readline)) {
					(m_employee + m_employee_number++)->readFile(ifp, readline);
				}
				else if (!strcmp("Material:", readline)) {
					(m_material + m_material_type_number++)->readFile(ifp, readline);
				}
				else if (!strcmp("Product:", readline)) {
					(m_product + m_product_type_number++)->readFile(ifp, readline);
				}
				else if (!strcmp("Order:", readline)) {
					(m_order + m_order_number++)->readFile(ifp, readline);
				}
				else if (!strcmp("Complete", readline)) {
					return;
				}
			}
		}
		// print all information to the file;
		void printFile(FILE* ofp) {
			// basic information
			if (*m_revenue == -1) { calculate_revenue(); }
			if (*m_expenses == -1) { calculate_expenses(); }
			fprintf_s(ofp, "Company: %s\nAssets: %d\nLiabilities: %d\nRevenue: %d\nExpenses %d\n"
				, m_company
				, *m_assets
				, *m_liabilities
				, *m_revenue
				, *m_expenses
				);

			// detail information
			for (int i = 0; i < m_employee_number; i++) {
				(m_employee + i)->printFile(ofp);
			}
			for (int i = 0; i < m_material_type_number; i++) {
				(m_material + i)->printFile(ofp);
			}
			// when the printing time, we can calculate the produced product number, 
			// because we have all material information now
			for (int i = 0; i < m_product_type_number; i++) {
				// printing
				(m_product + i)->printFile(ofp);
			}
			for (int i = 0; i < m_order_number; i++) {
				(m_order + i)->printFile(ofp);
			}
			fprintf_s(ofp, "Complete\n");
		}
		// setting function
		void calculate_produced_number(Product* product) {
				char** all_material = new char*[m_material_type_number];
				for (int j = 0; j < m_material_type_number; j++) {
					*(all_material + j) = new char[NAME_SIZE];
				}
				int* material_number = new int[m_material_type_number];
				for (int j = 0; j < m_material_type_number; j++) {
					*(all_material + j) = (m_material + j)->get_name();
					*(material_number + j) = *(m_material + j)->get_number();
				}
				product->calculate_produced_number(all_material, material_number, m_material_type_number);

		}
		void calculate_revenue() {
			*m_revenue = 0;
			for (int i = 0; i < m_product_type_number; i++) {
				*m_revenue += *(m_product + i)->get_number() * *(m_product + i)->get_price();
			}
		}
		void calculate_expenses() {
			*m_expenses = 0;
			for (int i = 0; i < m_employee_number; i++) {
				*m_expenses += *(m_employee + i)->get_salary();
			}
			for (int i = 0; i < m_material_type_number; i++) {
				*m_expenses += *(m_material + i)->get_number() * *(m_material + i)->get_price();
			}
		}
		void set_employees(char* name, int salary) {
			(m_employee + (m_employee_number)++)->set_employee(name, salary);
		}
		void set_materials(char* name, int number, int price) {
			(m_material + (m_material_type_number)++)->set_material(name, number, price);
		}
		void set_products(char* name, int number, int price, char** material, int* material_amount, int material_number) {
			Product* product = (m_product + m_product_type_number++);
			product->set_product(name, number, price);
			product->set_material(material);
			product->set_material_number(material_number);
			product->set_material_amount(material_amount);
			calculate_produced_number(product);

		}
		void set_orders(char* customer, char* address, char* expectedDate, char**product, int* amount, int number) {
			Order* order = (m_order + m_order_number++);
			m_order->set_customer(customer);
			m_order->set_address(address);
			m_order->set_expectedDate(expectedDate);
			m_order->set_product_number(number);
			m_order->set_product_amount(amount);
			m_order->set_product(product);

		}
		void set_name(char* name) {
			m_company = name;
		}
		void set_assets(int assets) {
			*m_assets = assets;
		}
		void set_liabilities(int liabilities) {
			*m_liabilities = liabilities;
		}
		void set_expenses(int expenses) {
			*m_expenses = expenses;
		}
		void set_revenue(int revenue) {
			*m_revenue = revenue;
		}
		// changing function
		void change_product(int selected, int option) {
			char* name = new char[NAME_SIZE]{0};
			int number = 0;
			int price = 0;
			switch (option) {
			case 1:
				cin >> name;
				(m_product + selected)->set_name(name);
				break;
			case 2:
				cin >> number;
				(m_product + selected)->set_number(number);
				delete[] name;
				break;
			case 3:
				cin >> price;
				(m_product + selected)->set_price(price);
				delete[] name;
				break;
			default:
				delete[] name;
				return;
			}
		}
		void change_material(int selected, int option) {
			char* name = new char[NAME_SIZE]{0};
			int price = 0;
			int number = 0;
			switch (option) {
			case 1:
				cin >> name;
				(m_material + selected)->set_name(name);
				break;
			case 2:
				cin >> number;
				(m_material + selected)->set_number(number);
				delete[] name;
				break;
			case 3:
				cin >> price;
				(m_material + selected)->set_price(price);
				delete[] name;
				break;
			default:
				delete[] name;
				return;
			}
		}
		void change_inventory(int option) {
			int selected = 0;
			int item;
			char* name = new char[NAME_SIZE]{0};
			int number = 0;
			switch (option) {
			case 1:
				cout << "Select a material" << endl;
				cin >> selected;
				cout << "What do you want to modify?" << endl
					<< "1. Name" << endl
					<< "2. Number" << endl;
				cin >> item;
				if (item == 1) {
					cin >> name;
					(m_material + selected - 1)->set_name(name);
				}
				else if (item == 2) {
					cin >> number;
					(m_material + selected - 1)->set_number(number);
					delete[] name;
				}
				break;
			case 2:
				cout << "Select a product" << endl;
				cin >> selected;
				cout << "What do you want to modify?" << endl
					<< "1. Name" << endl
					<< "2. Number" << endl
					<< "3. Produced Nubmer" << endl;
				cin >> item;
				if (item == 1) {
					cin >> name;
					(m_product + selected - 1)->set_name(name);
				}
				else if (item == 2) {
					cin >> number;
					(m_product + selected - 1)->set_number(number);
					delete[] name;
				}
				else if (item == 3) {
					cin >> number;
					(m_product + selected - 1)->set_produced_number(number);
					delete[] name;
				}
			default:
				delete[] name;
				break;
			}
		}
		void change_order(int selected, int option) {
			char *readline = new char[READLINE_LENGTH]{0};
			switch (option) {
			case 1:
				cin >> readline;
				(m_order + selected)->set_customer(readline);
				break;
			case 2:
				cin >> readline;
				(m_order + selected)->set_address(readline);
				break;
			case 3:
				cin >> readline;
				(m_order + selected)->set_expectedDate(readline);
				break;
			case 4:
				(m_order + selected)->change_product_list();
				delete[] readline;
				break;
			}

		}
		void change_customer(int selected, int option) {
			char* readline = new char[READLINE_LENGTH]{0};
			switch (option) {
			case 1:
				cin >> readline;
				(m_order + selected)->set_customer(readline);
				break;
			case 2:
				cin >> readline;
				(m_order + selected)->set_address(readline);
				break;
			default:
				delete[] readline;
				break;
			}

		}
		void change_employee(int selected, int option) {
			char* name = new char[NAME_SIZE]{0};
			int salary = 0;
			switch (option) {
			case 1:
				cin >> name;
				(m_employee + selected)->set_name(name);
				break;
			case 2:
				cin >> salary;
				(m_employee + selected)->set_salary(salary);
				delete[] name;
				break;
			default:
				delete[] name;
				return;
			}
		}

		// getting function	
		char* get_name() {
			return m_company;
		}
		int* get_assets() {
			return m_assets;
		}
		int* get_liabilities() {
			return m_liabilities;
		}
		int* get_revenue() {
			return m_revenue;
		}
		int* get_expenses() {
			return m_expenses;
		}
		char* get_Date(char* selected) {
			if (selected == "Employee") {
				return (m_employee + m_employee_number)->get_date();
			}
			else if (selected == "Material") {
				return (m_material + m_material_type_number)->get_date();
			}
			else if (selected == "Product") {
				return (m_product + m_product_type_number)->get_date();
			}
			return "\0";
		}
		int get_product_type_number() {
			return m_product_type_number;
		}
		int get_material_type_number() {
			return m_material_type_number;
		}
		int get_employee_number() {
			return m_employee_number;
		}
		int get_order_number() {
			return m_order_number;
		}
		Order* get_order(int i) {
			return m_order + i;
		}
		Employee* get_employee(int i) {
			return m_employee + i;
		}
		Material* get_material(int i) {
			return m_material + i;
		}
		Material* get_all_material() {
			return m_material;
		}
		Product* get_product(int i) {
			return m_product + i;
		}
		Product* get_all_product() {
			return m_product;
		}
		// check if is empty
		bool empty_product() {
			if (m_product_type_number == 0) { return true; }
			return false;
		}
		bool empty_material() {
			if (m_material_type_number == 0) { return true; }
			return false;
		}
		bool empty_order() {
			if (m_order_number == 0) { return true; }
			return false;
		}
		bool empty_employee() {
			if (m_employee_number == 0) { return true; }
			return false;
		}
		// show list function
		// show all the orders of the company
		void show_inventory() {
			cout << "Material List:" << endl;
			for (int i = 0; i < m_material_type_number; i++) {
				cout << i + 1 << ". "
					<< (m_material + i)->get_name() << " x "
					<< *(m_material + i)->get_number() << endl;
			}
			cout << "Product List:" << endl;
			for (int i = 0; i < m_product_type_number; i++) {
				cout << i + 1 << ". "
					<< (m_product + i)->get_name() << " x "
					<< *(m_product + i)->get_number() << " ("
					<< *(m_product + i)->get_produced_number() << ")" << endl;
			}
		}

		// show all the customer of the company
		void show_customers() {
			for (int i = 0; i < m_order_number; i++) {
				cout << i + 1 << ". ";
				cout << (m_order + i)->get_customer() << endl;
			}
		}
		// return the product that customer ordered 
		char* order_product(int selected) {
			cout << (m_product + selected)->get_name() << endl;
			return (m_product + selected)->get_name();
		}
	};
#endif
/*	void Order::create_order(Company* company) {
		m_customer->set_customer();
		m_expectedDate->set_time();

		//=======================add the product information============================

		int selected = 0;
		int amount = 0;

		do {
			cout << "===========================" << endl;
			cout << "Select the product you want" << endl;
			cout << "Product\tNumber\tPrice" << endl;
			cout << "0. Go back" << endl;	// cancel the order
			company->show_products_details();
			cin >> selected;
			if (selected == 0) {
				break;
			}
			else if (selected < 0 || selected >(company->get_product_type_number())) {
				cout << "Failed input" << endl;
				break;
			}
			*(m_ordered_product + m_product_number) = company->order_product(selected - 1);	// assign the selected product to the order
			cout << "Enter the amount: ";
			cin >> amount;
			*(m_ordered_product_amount + m_product_number) = amount;
		} while (++m_product_number < MAX_PRODUCT_SIZE);
	}*/
	// The user interface provided choice to let user manipulate the program 
/*	class UserInterface {
	private:
		FILE* m_ifp;
		FILE* m_ofp;
		int m_option;

		// store all information of all the companies
		Company* m_company;
		int m_company_number;
	public:
		// Default constructor
		UserInterface() {

			// initialized the ifp pointer & ofp pointer 
			m_ifp = nullptr;
			m_ofp = nullptr;
			m_option = 0;
			main_menu();
		}
		void main_menu() {
		main_menu:
			cout << "Welcome to use our Accounting INFO System" << endl
				<< "=========================================" << endl
				<< "Main Menu" << endl
				<< "1. Add a new company information" << endl
				<< "2. Display the current company information" << endl
				<< "3. Exit" << endl;
			cin >> m_option;
			switch (m_option) {
			case 1:
				add();
				break;
			case 2:
				display();
				break;
			case 3:
				return;
			default:
				cout << "Failed Input!" << endl;
				break;
			}
			goto main_menu;
		}
		void add() {
			fopen_s(&m_ofp, "General Ledger.txt", "a");
			Company* company = new Company();
			company->set_basic_info();
		add_menu:
			cout << "====================================" << endl;
			cout << "What information do you want to add?" << endl
				<< "0. Go back" << endl
				<< "1. Employee" << endl
				<< "2. Material" << endl
				<< "3. Product" << endl
				<< "4. Order" << endl;
			cin >> m_option;
			switch (m_option) {
			case 0:
				company->printFile(m_ofp);
				fclose(m_ofp);
				return;
			case 1:
				company->set_employees();
				break;
			case 2:
				company->set_materials();
				break;
			case 3:
				company->set_products();
				break;
			case 4:
				company->set_orders();
				break;
			default:
				cout << "Failed Input!" << endl;
				break;
			}
			goto add_menu;
		}
		void modify() {

		}
		void display() {
			readFile();
		display_menu:
			cout << "====================================" << endl;
			cout << "Display " << endl
				<< "0. Go back" << endl
				<< "1. General Ledger" << endl
				<< "2. Billing" << endl
				<< "3. Inventory" << endl
				<< "4. Purchase Order" << endl
				<< "5. Customer" << endl
				<< "6. Employee" << endl;
			cin >> m_option;
			int selected = 0;
			int option = 0;
			switch (m_option) {
			case 0:
				return;
			case 1:	// change basic info
				if (modifiedAsking()) {
					cout << "What do you want to modify?" << endl
						<< "0. Cancel" << endl
						<< "1. Name: " << (m_company + m_option - 1)->get_name() << endl
						<< "2. Assets: " << *(m_company + m_option - 1)->get_assets() << endl
						<< "3. Liabilities: " << *(m_company + m_option - 1)->get_liabilities() << endl
						<< "4. Revenue: " << *(m_company + m_option - 1)->get_expenses() << endl
						<< "5. Expenses: " << *(m_company + m_option - 1)->get_revenue() << endl;
					cin >> option;
					if (option > 0 && option < 6)
						(m_company + m_option - 1)->change_basic_info(option);
				}
				break;
			case 2:	// change bill
				SortDisplayBill();
				if (modifiedAsking()) {
					if ((m_company + m_option - 1)->empty_product()) { cout << "There is no product" << endl; goto display_menu; }
					cout << "What product do you want to modify?" << endl;
					(m_company + m_option - 1)->show_products();
					cin >> selected;
					cout << "What do you want to modify?" << endl
						<< "0. Cancel" << endl
						<< "1. Name: " << endl
						<< "2. Number: " << endl
						<< "3. Price: " << endl;
					cin >> option;
					if (option < 4 && option > 0)
						(m_company + m_option - 1)->change_product(selected - 1, option);
				}
				break;
			case 3:	 // change inventory
				for (int i = 0; i < m_company_number; i++) {
					(m_company + i)->inventory();
				}
				if (modifiedAsking()) {
					if ((m_company + m_option - 1)->empty_material() && (m_company + m_option - 1)->empty_product()) {
						cout << "There is no material and product" << endl;
						return;
					}
					char* readline = new char[READLINE_LENGTH]{0};
					(m_company + m_option - 1)->show_inventory();
					cout << "Which information you want to modify?" << endl;
					cout << "1. Material" << endl
						<< "2. Product" << endl;
					cin >> option;
					if (option == 1 || option == 2)
						(m_company + m_option - 1)->change_inventory(option);
				}
				break;
			case 4:	// change order
				for (int i = 0; i < m_company_number; i++) {
					(m_company + i)->purchased_order();
				}
				if (modifiedAsking()) {
					if ((m_company + m_option - 1)->empty_order()) { cout << "There is no order" << endl; goto display_menu; }
					(m_company + m_option - 1)->show_orders();
					cout << "Select the order you want to modify" << endl;
					cin >> selected;
					cout << "What do you want to modify?" << endl
						<< "0. Cancel" << endl
						<< "1. Customer" << endl
						<< "2. Address" << endl
						<< "3. Expected Date" << endl
						<< "4. Product List" << endl;
					cin >> option;
					if (selected > 0 && selected << 5)
						(m_company + m_option - 1)->change_order(selected - 1, option);
				}
				break;
			case 5:	// change customer 
				for (int i = 0; i < m_company_number; i++) {
					(m_company + i)->customer();
				}
				if (modifiedAsking()) {
					if ((m_company + m_option - 1)->empty_order()) { cout << "There is no customer" << endl; goto display_menu; }
					cout << "Whose information you want to modify?" << endl;
					(m_company + m_option - 1)->show_customers();
					cin >> selected;
					cout << "What do you want to modify?" << endl
						<< "0. Cancel" << endl
						<< "1. Name" << endl
						<< "2. Address" << endl;
					cin >> option;
					if (option > 0 && option < 3)
						(m_company + m_option - 1)->change_customer(selected - 1, option);
				}
				break;
			case 6:	// change employee
				for (int i = 0; i < m_company_number; i++) {
					(m_company + i)->employee();
				}
				if (modifiedAsking()) {
					if ((m_company + m_option - 1)->empty_employee()) { cout << "There is no employee" << endl; goto display_menu; }
					cout << "Whoes information you want to modify?" << endl;
					(m_company + m_option - 1)->show_employees();
					cin >> selected;
					cout << "What do you want to modify?" << endl
						<< "0. Cancel" << endl
						<< "1. Name" << endl
						<< "2. Salary" << endl;
					cin >> option;
					if (option > 0 && option < 3)
						(m_company + m_option - 1)->change_employee(selected - 1, option);
				}
				break;
			default:
				break;
			}
			fopen_s(&m_ofp, "General Ledger.txt", "w");
			for (int i = 0; i < m_company_number; i++) {
				(m_company + i)->printFile(m_ofp);
			}
			fclose(m_ofp);
			goto display_menu;
		}
		void SortDisplayBill() {
			int option;
			int* list = new int[m_company_number]{0};
			int* SortedIndex = new int[m_company_number]{0};
			cout << "Sort by " << endl
				<< "1.Number\t2.Price\t3.Cancel" << endl;
			cin >> option;
			switch (option) {
			case 1:
			case 2:
			case 3:
				return;
			default:
				break;
			}
			for (int i = 0; i < m_company_number; i++) {
				(m_company + i)->billing();
			}
		}
		void readFile() {
			char* readline = new char[READLINE_LENGTH]{0};
			fopen_s(&m_ifp, "General Ledger.txt", "r");
			if (m_ifp == nullptr) {
				fprintf(stderr, "File Not Found.");
				return;
			}
			else {
				m_company_number = 0;
				m_company = new Company[MAX_COMPANY_NUMBER]();
				while (!feof(m_ifp)) {
					fscanf_s(m_ifp, "%s", readline, READLINE_LENGTH);
					if (!strcmp(readline, "Company:")) {
						(m_company + m_company_number++)->readFile(m_ifp, readline);
					}
				}
			}
			fclose(m_ifp);
		}
		bool modifiedAsking() {
		askinglabel:
			cout << "Do you want to modify the information? (y/n)" << endl;
			char* decision = new char{ 0 };
			cin >> decision;
			if (*decision == 'y' || *decision == 'Y') {
				cout << "What company do you want to modify?" << endl;
				for (int i = 0; i < m_company_number; i++) {
					cout << i + 1 << ". "
						<< (m_company + i)->get_name()
						<< endl;
				}
				cin >> m_option;
				return true;
			}
			else if (*decision == 'n' || *decision == 'N') {
				return false;
			}
			else {
				cout << "Failed input" << endl;
				goto askinglabel;
			}
		}
	};*/

