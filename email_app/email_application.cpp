#include "Email.h"


// functio stubs
int program_menu();
vector<Email> populate_inbox();
void list_emails(vector<Email>); // lists all emails by serial number and subject line
void list_emails_by(vector<Email>); // lists all emails by given criteria
void read_email(unsigned int, vector<Email>); // read a particular email
void unread_emails(vector<unsigned int>, vector<Email>);
Email em; // use this for has been read variable

// define program menu here
int program_menu()
{
	int user_prompt;
	cout<<"\nSelect an action to perform:\n1.\t Read an email\n2.\t View unread emails\n3.\t Quit application"<<endl;
	cin>>user_prompt;
	// add defensive logic here to error check user entry
	if( (user_prompt < 1) || (user_prompt > 3) )
	{
		cout<<"Wrong choice: options are either 1,2, or 3 "<<endl;
	}
	
	return user_prompt;
}// ends the program menu
	

// define populate inbox here
vector<Email> populate_inbox()
{
	Email mail1("oveseovese@gmail.com", "job applications", "Register with LinkedLn to get job updates");
	Email mail2("xyz@rocketmail.com", "games conference", "Build all the backend functionality for gamers console");
	Email mail3("stacyovie1@gmail.com", "Thesis completion", "Submit the draft report for the thesis on Post partum depression");
	
	Email dud;
	dud.inbox.push_back(mail1);
	dud.inbox.push_back(mail2);
	dud.inbox.push_back(mail3);
	unsigned int sz_inbox = dud.inbox.size();
	cout<<"Size of inbox: "<<sz_inbox<<endl;
	for( auto i = dud.inbox.begin(); i != dud.inbox.end(); ++i)
	{
		//cout<<dud.inbox.pop(i)<<endl;
	}
	
	for(unsigned int i =0 ; i!= sz_inbox; ++i)
	{
		// dud.inbox[i];
		vector<Email> *ptr_vec = nullptr;
		ptr_vec = &dud.inbox;
		cout<<&dud.inbox[i]<<"\t"<<ptr_vec<<"\t"<<&ptr_vec[i]<<endl;
	}
	
	cout<<endl;
	cout<<"ID \t Sender address \t Email subject \t Message"<<endl;
	cout<<"----------------------------------------------------------------------------------------------"<<endl;
	for(unsigned int i = 0 ; i!= sz_inbox; ++i)
	{
		cout<<i<<".\t"<<dud.inbox[i].email_address<<"\t"<<dud.inbox[i].subject_line<<"\t"<<dud.inbox[i].email_content<<endl;
	}
	
	return dud.inbox;
}// ends populate_inbox

void list_emails(vector<Email> inbox_list)
{
	// vector<Email> ret_inbox = populate_inbox();
	cout<<"ID \t Email subject"<<endl;
	cout<<"------------------------------------------------"<<endl;
	for(unsigned int i = 0 ; i!= inbox_list.size(); ++i)
	{
		cout<<i<<".\t"<<inbox_list[i].subject_line<<endl;
	}
}// ends list_emails

// defines function to view email by criteria given 
void list_emails_by(vector<Email> inbox_list)
{
	//vector<Email> ret_inbox = populate_inbox();
	unsigned int view_option;
	cout<<"View emails by:\n1.\t Sender email address\n2.\t Email subject\n3.\t Email content\n"<<endl; 
	cin>>view_option;
	if (view_option == 1)
	{
		cout<<"ID \t Sender address"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		for(unsigned int i = 0 ; i!= inbox_list.size(); ++i)
		{
			cout<<i<<".\t"<<inbox_list[i].email_address<<endl;
		}
	}
	else if(view_option == 2)
	{
		cout<<"ID \t Email subject"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		for(unsigned int i = 0 ; i!= inbox_list.size(); ++i)
		{
			cout<<i<<".\t"<<inbox_list[i].subject_line<<endl;
		}
	}
	else if(view_option == 3)
	{
		cout<<"ID \t Message"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		for(unsigned int i = 0 ; i!= inbox_list.size(); ++i)
		{
			cout<<i<<".\t"<<inbox_list[i].email_content<<endl;
		}
	}
}// ends list_emails


void read_email(unsigned int sel, vector<Email> inbox_list)
{
	//vector<Email> ret_inbox = populate_inbox();
	cout<<"ID \t Sender address \t Email subject \t Message"<<endl;
	cout<<"----------------------------------------------------------------------------------------------"<<endl;
	for(unsigned int i = 0 ; i!= inbox_list.size(); ++i)
	{
		if(sel == i)
		{
			cout<<i<<".\t"<<inbox_list[i].email_address<<"\t"<<inbox_list[i].subject_line<<"\t"<<inbox_list[i].email_content<<endl;
		}// end if
	}// end for
	
	// calls list_emails here
	cout<<endl;
	list_emails(inbox_list);
	
	// calls list_emails_by here
	cout<<endl;
	list_emails_by(inbox_list);
	
	// store the srial number of read email to list of read_email
	
}// ends read_email

// define unread emails functions here
void unread_emails(vector<unsigned int> read_list, vector<Email> inbox_list)
{
	for (unsigned int i = 0; i!= read_list.size(); ++i)
	{
		cout<<"Mail number: "<<read_list[i]<<" has been read"<<endl;
	}
	
	cout<<endl;
	
	cout<<"ID \t Sender address \t Email subject \t Message"<<endl;
	cout<<"----------------------------------------------------------------------------------------------"<<endl;
	
	// for(unsigned int i = 0 ; i!= inbox_list.size(); ++i)
	// {
		// if(i != read_list[i]) // this condition is not working right
		// {
			// string is_email_read = em.email_status[0];
			// cout<<i<<".\t"<<inbox_list[i].email_address<<"\t"<<inbox_list[i].subject_line<<"\t"<<inbox_list[i].email_content<<"\t"<<is_email_read<<endl;
		// }// end if
		// else
		// {
			// string is_email_read = em.email_status[1];
			// cout<<i<<".\t"<<inbox_list[i].email_address<<"\t"<<inbox_list[i].subject_line<<"\t"<<inbox_list[i].email_content<<"\t"<<is_email_read<<endl;
		// }
	// }// end for
	
	for (unsigned int j =0; j!=read_list.size(); ++j)
	{
		unsigned int pivot = read_list[j];
		for (unsigned int i = 0; i != inbox_list.size(); ++i)
		{
			if(pivot == i)
			{
				string is_email_read = em.email_status[1];
				; // do nothing
			}
			else
			{
				string is_email_read = em.email_status[0];
				cout<<i<<".\t"<<inbox_list[i].email_address<<"\t"<<inbox_list[i].subject_line<<"\t"<<inbox_list[i].email_content<<"\t"<<is_email_read<<endl;
			}
		}
	}		



} // ends the unread_mail function


int main(int argc, char* argv[])
{
	cout<<"Welcome to program"<<endl;
	// call populate_inbox function to initialize email objects
	vector<Email> ret_inbox = populate_inbox();
	// use while loop to ensure program keeps running until exit(0) command given
	while (1)
	{
		int ret_option = program_menu();
		if(ret_option == 1)
		{
			unsigned int email_id;
			cout<<"Select email ID to read: "<<endl;
			cin>>email_id;
			
			// store the id of read email in list
			em.read_email_index.push_back(email_id);
			
			// call the read_email function with params passed
			read_email(email_id, ret_inbox);
		}
		else if(ret_option == 2)
		{
			unread_emails(em.read_email_index, ret_inbox);
		}
		else if(ret_option == 3)
		{
			exit(0);
		}
		else
		{
			cout<<"Not a known menu option"<<endl;
		}
	}// ends the while loop
	
	cout<<"Cleaning up...\nBye from program"<<endl;
	return 0;	
}