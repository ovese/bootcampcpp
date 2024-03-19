#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <iomanip>


using namespace std;

/*

*/

// fucntion decalration
vector<string> my_menu_list();
list<int> my_values_list();
list<float> my_menu_item_cost();
void my_store_database();

vector<string> my_menu_list()
{
	vector<string> menu_list = {"flour", "water", "sugar", "olive oil"};
	//vector<string> menu_list{"flour", "water", "sugar", "olive oil", "eggs", "milk", "spatula"};
	
	int m = menu_list.size();
	cout<<"Size of vector is: "<<m<<endl;	
	
	return menu_list;
}

list<int> my_values_list()
{	
	// Initialising the List 
    // with values
    list<int> num_list{23,14,56,32,45,89,60}; 
	int n = num_list.size();
	cout<<"Size of list is: "<<n<<endl;
	
	
	return num_list;
}

list<float> my_menu_item_cost()
{
	list<float> menu_item_cost{5.675, 2.58, 1.05, 6.789, 1.765, 0.85, 1.2576};
	
	return menu_item_cost;
}

// this works like a dictionary
// maps in c++ are pythons dictionary equivalent
void my_store_database()
{
	//declare the map that uses a person's name as a key, and looks
    //up a map that stores the person's weight and height
    // std::map< std::string, std::map<std::string,float> > database;
	map< string, map<string,float> > database;
	map<string, float> stock_value_database;
	map<string, float> stock_price_database;
	map<string, float> cafe_stock;
	

    //let's first put the data in three vectors
    vector<string> names = {"flour", "water", "sugar", "olive oil", "eggs", "milk", "spatula"};
    vector<float> stock_value = { 23, 14, 56, 32, 45, 89, 60};
    vector<float> cost = { 5.675, 2.58, 1.05, 6.789, 1.765, 0.85, 1.2576 };

    //now put all of the data into the database
    for (unsigned int i=0; i<names.size(); ++i)
    {
        map<string,float> data;
		map<string, float> stock;

        data["stock"] = stock_value[i];
        data["cost"] = cost[i];
        database[names[i]] = data;

		stock_value_database[names[i]] = stock_value[i];
		stock_price_database[names[i]] = cost[i];
		cafe_stock[names[i]] = stock_value[i] * cost[i];
    }

    //now print out the entire database
    for ( auto item : database )
    {
        //print out the name
        cout << item.first << " : ";

        //now print out all of the data about the person
        for ( auto data : item.second) // for ( auto data : item.second )
        {
            cout << data.first << "=" << data.second << " ";
        }

        cout << endl;
    }
	
	cout<<endl;
	//now print out the entire stock-value database
	cout<<"Stock \t\t Available stock"<<endl;
    for ( auto item : stock_value_database )
    {
        //print out the name
        cout << item.first << ":...................."<< item.second;
        cout << endl;
    }
	
	cout<<endl;
	//now print out the entire stock-price database
	cout<<"Stock \t\t Stock price($)"<<endl;
    for ( auto itr = stock_price_database.begin(); itr != stock_price_database.end(); ++itr)
    {
        //print out the name
        cout << itr->first << ":...................."<< fixed << setprecision(2) << itr->second;
        cout << endl;
    }
	
	cout<<endl;
	//now print out the entire stock-price database
	cout<<"Stock \t\t Stocked Capacity($)"<<endl;
    for ( auto itr = cafe_stock.begin(); itr != cafe_stock.end(); ++itr)
    {
        //print out the name
        cout << itr->first << ":...................."<<fixed << setprecision(2)<< itr->second;
        cout << endl;
    }
	
} // ends my_store_database


int main(int argc, char* argv[])
{
	// vector<string> ret_menu_vec = my_menu_list();
	// for (unsigned int i = 0; i!= ret_menu_vec.size(); ++i)
	// {
		// cout<<ret_menu_vec[i]<<",";
	// }
	// cout<<endl;
	
	// list<int> ret_value_list = my_values_list();
	// for (int x: ret_value_list)
	// {
		
		
		// cout<<x<<",";
	// }
	// cout<<endl;
	
	// list<float> ret_item_cost_list = my_menu_item_cost();
	// for (int x: ret_item_cost_list)
	// {
		// cout<<x<<",";
	// }
	// cout<<endl;
	
	my_store_database();

	return 0;
}