#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <iomanip>

using namespace std;


// my exception classes

class incorrectinputexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} iiex;

class FinancialCalculator
{
	private:
		double principal; // amount of money
		double rate; // interest rate in %
		int tenure;	// duration in years or months
	public:
		FinancialCalculator(); // constructor
		string select_option(); // switches between investment or bond computation
		int investment_option(string); // switches between simple or compound interest
		double simple_interest(double, double, int);
		double compound_interest(double, double, int);
		double mortgage(double, double, int);
		double calculate_interest_by_type(int);
		double calculate_mortgage_repayment(string);
		~FinancialCalculator(); // class destructor
	
};

FinancialCalculator::FinancialCalculator()
{
	this->principal = 1000;
	this->rate = 8;
	this->tenure = 5;
}

string FinancialCalculator::select_option()
{
	string option;
	string correct_selection;
	string l_option;
	string u_option;
	cout<<"Investment- to calculate the amount of interest you will earn on your investment"<<endl;
	cout<<"Bond-       to calculate the amount you will have to pay on a home loan"<<endl;
	cout<<"Select from the options given ( type investment or bond ): "<<endl;
	cin>>option;
	for(auto x:option) // iterator x through the string option
		{
			l_option = (char)tolower(x); 
			u_option = (char)toupper(x);
		}	
	try
	{
		if(option == "investment" || option == "bond")
		{
			correct_selection = option;
		}
		else if(l_option == "investment" || l_option == "bond")
		{
			correct_selection = l_option;
		}
		else if(u_option == "INVESTMENT" || u_option == "BOND")
		{
			correct_selection = u_option;
		}
		else
		{
			throw iiex;
		}
			
	}
	catch(exception& e)
	{
		cout<<e.what()<<endl;
	}
		
	
	// check correctness of input
	
	return correct_selection;
}

int FinancialCalculator::investment_option(string calc_sel)
{
	int num_option;
	bool is_correct_option = false;
	try
	{
		if(calc_sel == "investment")
		{
			cout<<"Select from the options below:\n"
				  "1..........:Simple interest\n"
				  "2..........:Compound interest"<<endl;
				  
			cin>>num_option;
			// validate the number entered
			if(num_option != 1 || num_option != 2)
			{
				//is_correct_option = false; // is this necessary here
				while(is_correct_option == false)
				{
					cout<<"Select the right option please: "<<endl;
					cin>>num_option;
					if(num_option == 1 || num_option == 2)
					{
						is_correct_option = true;
						break;
					}
				} // end while
				
			}
			else if(num_option == 1)
			{
				cout<<"Simple interest calculation selected"<<endl;
			}
			else if(num_option == 2)
			{
				cout<<"Compound interest calculation selected"<<endl;
			}
		} // ends if
		else if(calc_sel == "bond")
		{
			cout<<"Mortgage or bond repayment selected"<<endl;
			num_option = 3; // this is the mortgage option
		}
		else
		{
			cout<<"Not a known investment option!!!"<<endl;
		}
	}//end try
	catch(exception& e)
	{
		cout<<e.what()<<endl;
	}
	
	return num_option;
	
}// ends the function

double FinancialCalculator::simple_interest(double principal, double rate, int tenure)
{
	cout<<"Computing Simple interest: \n"
	      "Principal:.........."<<principal<<"\n"
		  "Interest rate:......"<<rate<<"\n"
		  "Tenure(years):......"<<tenure<<endl;
	rate = rate/100;
	double si = principal*(1+(rate*tenure));
	
	return si;
}

double FinancialCalculator::compound_interest(double principal, double rate, int tenure)
{
	cout<<"Computing Compound interest: \n"
		  "Principal:.........."<<principal<<"\n"
	      "Interest rate:......"<<rate<<"\n"
	      "Tenure(years):......"<<tenure<<endl;
	rate = rate/100;
	double ci = principal*pow((1+rate),tenure);
	
	return ci;
}

double FinancialCalculator::mortgage(double principal, double rate, int tenure)
{
	cout<<"Computing Mortgage repayment: \n"
	      "Principal:..................."<<principal<<"\n"
	      "Interest rate:..............."<<rate<<"\n"
	      "Tenure (months):............."<<tenure<<endl;	  
	rate= rate/(12*100);	  
	double repayment = (rate*principal)/ (1-pow((1+rate),-tenure) );
	
	return repayment;
}

double FinancialCalculator::calculate_interest_by_type(int val)
{
	cout<<"Enter the values for the parameters: principal, interest, tenure"<<endl;
	cin>>this->principal;
	cin>>this->rate;
	cin>>this->tenure;
	double p = this->principal;
	double r = this->rate;
	double t = this->tenure;
	double ret_interest;
	if(val == 1)
	{
		double ret_si = this->simple_interest(p,r,t);
		ret_interest = ret_si;
	}
	else if(val == 2)
	{
		double ret_ci = this->compound_interest(p,r,t);
		ret_interest = ret_ci;
	}		
	
	return ret_interest;	
}

double FinancialCalculator::calculate_mortgage_repayment(string calc_sel)
{
	double ret_repayment;	
	if(calc_sel == "bond")
	{
		cout<<"Enter the values for the parameters: principal, interest, tenure"<<endl;
		cin>>this->principal;
		cin>>this->rate;
		cin>>this->tenure;
		double p = this->principal;
		double r = this->rate;
		double t = this->tenure;
		
		ret_repayment = this->mortgage(p,r,t);
	}
	
	
	return ret_repayment;
	
}

// the program destructor
FinancialCalculator::~FinancialCalculator()
{
	cout<<"Cleaning up and housekeeping"<<endl;
	cout<<"Bye from the program"<<endl;
}

int main(int argc, char** argv) // could also use char *[]argv
{
	cout<<"Starting the financial calculator task"<<endl;
	// create instance of the calculator
	FinancialCalculator fc;
	string pick_option = fc.select_option();
	cout<<"Debug......Calculator option selected is: "<<pick_option<<endl;

	if(pick_option == "investment")
	{
		int ret_inv_option = fc.investment_option(pick_option);
		cout<<"Debug......Investment option selected is:"<<ret_inv_option<<endl;
	
		double ret_inv_interest = fc.calculate_interest_by_type(ret_inv_option);
		cout<<"Debug......Interest returned on the investment: "<<fixed<<setprecision(3)<<ret_inv_interest<<endl;
	
	
		cout<<"Summary of the calculation:\n"
			  "Investment option:.............."<<pick_option<<"\n"
			  "Interest type computation:......"<<ret_inv_option<<"\n"
			  "Returned interest:.............."<<fixed<<setprecision(3)<<ret_inv_interest<<endl;
		  
	}
	else if(pick_option == "bond")
	{
		//
		double ret_mortgage_repayment = fc.calculate_mortgage_repayment(pick_option);
		cout<<"Summary of the calculation:\n"
			  "Investment option:.............."<<pick_option<<"\n"
			  "Returned repayment:............."<<fixed<<setprecision(3)<<ret_mortgage_repayment<<endl;
	}
	
	
	return 0;
	
}
