#ifndef _EMAIL_H_
#define _EMAIL_H_

#include <iostream>

// add core libraries for task here
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// If i place these fucntions here, will they be visible
// void populate_inbox();

class Email{
private:
	int num{20};
	// I was unable to access these variables as i got 
	// the prompt varaibales were private
	// string email_address;
	// string subject_line;
	// string email_content;
	
public:
	Email();
	Email(string, string, string);
	bool mark_as_read();
	~Email();
	// these variables were moved here to allow me avoid 
	// the access denial due to their being private
	string email_address;
	string subject_line;
	string email_content;
	bool has_been_read = false;
	vector<Email> inbox;
	vector<unsigned int> read_email_index; // will push read email index into this variable
	vector<string> email_status{"Unread", "Read"};
};


#endif
