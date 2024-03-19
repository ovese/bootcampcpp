#include <iostream>
#include <string>
#include <exception>
#include <cmath>

using namespace std;

map<string, string> my_pantry();
void value_precision();
void is_found_at();


struct responsable
{
	string first_name;
	string last_name;
	string email;
	int age;	
};

struct coder {
  long id;
  string name; //char name[30];
  string username; //char username[15];
  struct DOB {
    int month;
    int day;
    int year;
  } d;
} bjarne;

map<string, string> my_pantry()
{
	   //initialising the map
   map <string, string> mmap = {{"Fruit", "Litchi"}, {"Tree", "Birch"}, {"Vegetable", "Potato"}};

   //copy the elements using the copy constructor
   map <string, string> copyMap(mmap);


   return copyMap;
   
}

void value_precision()
{
  // initialize a floating-point 

  float num = 2.71828;
  cout << "Original number is: " << num;
  cout << "\n";

  // print 3 significant figures
  cout << "The number with 3 significant figures is: ";
  cout << setprecision(3) <<num << endl;

  // print 3 decimal places
  cout << "The number with 3 decimal places is: ";
  cout << fixed << setprecision(3) << num;
  cout << "\n\n";
  
}


void is_found_at()
{
	std::vector<int> numbers = {10, 20, 30, 40, 50};

	// Find the element 30 in the vector
	auto it = std::find(numbers.begin(), numbers.end(), 30);

	// Check if the element was found
	if (it != numbers.end()) {
		std::cout << "Element found at index: " << std::distance(numbers.begin(), it) << std::endl;
	} 
	else 
	{
		std::cout << "Element not found." << std::endl;
	}

}

// acces the above struct using var1.var2.member1 
// e.g. bjarne.d.month = 4; for april

int main(int argc, char* argv[])
{
	cout<<"Welcome to core concept practice"<<endl;
	cout<<"Essence of this project to demonstrate\n"
		  "some basic C++ concepts using a real\n"
		  "project task.\n\n"
		  "The task requirements are given in a file\n"
		  "which can be read by running the program option \n"
		  "that allows printing requirements"<<endl;
		  
	struct responsable rp1;
	rp1.first_name = "Ese";
	rp1.last_name = "Ovie";
	rp1.email = "oveseovese@gmail.com";
	rp1.age = 41;
	
	cout<<"First name is "<<rp1.first_name<<endl;
	cout<<"Last name is "<<rp1.last_name<<endl;
	cout<<"Email address is "<<rp1.email<<endl;
	cout<<"Age is "<<rp1.age<<endl;
	
	struct responsable rp2 = {"Kevwe","Idiagi","kevwe@gmail.com", 36};
	cout<<"First name is "<<rp2.first_name<<endl;
	cout<<"Last name is "<<rp2.last_name<<endl;
	cout<<"Email address is "<<rp2.email<<endl;
	cout<<"Age is "<<rp2.age<<endl;
	
	bjarne.id = 3452;
	cout<<"Enter full name e.g. Ese Tobore Ovie: "<<endl;
	cin>>bjarne.name; //cin.get(bjarne.name, 30);
	cout<<"Enter username e.g. tekkaboki: "<<endl;
	cin>>bjarne.username; //cin.get(bjarne.username, 15);
	bjarne.d.month = 1;
	bjarne.d.day = 19;
	bjarne.d.year = 1983;
	
	cout<<"UserID: "<<bjarne.id<<endl;
	cout<<"Full name: "<<bjarne.name<<endl;
	cout<<"User name: "<<bjarne.username<<endl;
	cout<<"DOB dd: "<<bjarne.d.day<<endl;
	cout<<"DOB mm: "<<bjarne.d.month<<endl;
	cout<<"DOB yyyy: "<<bjarne.d.year<<endl;
	
	map<string, string> ret_val = my_pantry();
	for (auto i : ret_val)
	{
		cout<<i.first<<":"<<i.second<<endl;
	}
	
	return 0;
	
}