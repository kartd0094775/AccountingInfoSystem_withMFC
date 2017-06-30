#include"stdafx.h"

class Date {
private: 
	char* m_date;

public:
	// Constructor
	Date();

	// Destructor
	~Date();

	// setting function
	void set_time(char* date);

	// getting function
	char* get_time();
};