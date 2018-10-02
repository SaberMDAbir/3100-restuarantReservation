//MD Abir A. Choudhury
//030618
//CIS 3100 - A5
//Restuarant Renovation

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

int main()
{
	int choice = 0;
	int tableNum = 0; // user inputs desrired table number
	string customerName;
	string temp;
	bool available[20] = {}; // true = reserved, false = available
	string name[20] = {}; // For keeping the customers name

	//input
	do {
		cout << "Welcome to the restuarant reservation system!\n"
			<< "=============================================\n"
			<< "1 - Reserve a Table\n"
			<< "2 - Clear Reservation\n"
			<< "3 - Report\n"
			<< "0 - Exit\n"
			<< "Choose an option:\n";
		cin >> choice;

		if (choice < 0 || choice > 3) {
			cout << "Input a valid number. ";
			cin >> choice;
		}

		//processing
		//choice for reserving a table
		if (choice == 1) {
			cout << "Enter a desired table number <0 - 19>: ";
			cin >> tableNum;
			
			if (available[tableNum] == false) {
				cout << "The requested table is available.\n"
					<< "What is your first name: ";
				cin >> customerName;
				name[tableNum] = customerName;
				available[tableNum] = true;
				cout << "\n";
			}
			else if (available[tableNum] == true) {
				cout << "The requested table is currently reserved.\n\n";
			}
		}

		//choice for clearing a reservation
		else if (choice == 2) { 
			cout << "Enter a table number: ";
			cin >> tableNum;
			
			if (available[tableNum] == false) { //available
				cout << "That table is already available.\n\n";
			}
			else { //reserved turning to available
				available[tableNum] = false;
				name[tableNum] = "";
				cout << "That table is now available.\n\n";
			}
		}

		//choice for report
		else if (choice == 3) {
			cout << "The state of all the resturant tables:\n";
			for (int i = 0; i < 20; i++) {
				if (available[i] == true) { //reserved
					cout << "Table " << i << ": " << setw(10) << name[i] << "\n";
				}
				else if (available[i] == false) { //available
					cout << "Table " << i << ": " << setw(10);
					cout << "Available" << "\n";
				}
			}
			cout << endl;
		}
	} while (choice != 0);

	cout << "Thank you for using our service!\n";

	system("PAUSE");
	return 0;
}
