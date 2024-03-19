#include "Email.h"

// define constructor here
Email::Email()
{
	//cout<<"Default constructor"<<endl;
	
}// ends default constructor


// define parameterized constructor that takes 3 arguments
Email::Email(string my_address, string my_email_subject, string my_subject)
{
	//cout<<"Inside the parameterized constructor"<<endl;
	this->email_address = my_address;
	this->subject_line = my_email_subject;
	this->email_content = my_subject;
	Email em1,em2,em3;
	this->inbox = {em1,em2,em3}; // having to initialize the inbox var with email objects
}// ends parameterized constructor

// define the mark_as_read method here
bool Email::mark_as_read()
{
	has_been_read = true;
	
	return has_been_read;
}// ends mark_as_read

// define the destructor. Handling RAII
Email::~Email()
{
	//cout<<"Cleaning up...\nBye from program"<<endl;
}// ends the destructor
