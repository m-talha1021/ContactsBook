#include <iostream>
#include<string>
#include "ContactBook.h"
using namespace std;
// Function to create a reusable function that takes input and returns an Address object
Address create_address() {
	string house, street, city, country;
	cout << "Enter house number: ";
	getline(cin, house);
	cout << "Enter street: ";
	getline(cin, street);
	cout << "Enter city: ";
	getline(cin, city);
	cout << "Enter country: ";
	getline(cin, country);
	return Address(house, street, city, country);
}

int main() 
{
	cout << "======>ContactsBook Project<======" << endl;
	ContactsBook contactsBook(5); // ContactsBook object,size 5
	// Scenario 1
	cout << "Scenario 1:" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << "Contact " << i + 1 << ":" << endl;
		string first_name, last_name, mobile_number, email_address;
		cout << "Enter first name: ";
		getline(cin, first_name);
		cout << "Enter last name: ";
		getline(cin, last_name);
		cout << "Enter mobile number: ";
		getline(cin, mobile_number);
		cout << "Enter email address: ";
		getline(cin, email_address);
		Address address = create_address();
		Contact contact(first_name, last_name, mobile_number, email_address, &address);
		contactsBook.add_contact(contact);
	}
	// Print sorted contacts by First Name
	contactsBook.print_contacts_sorted("first_name");

	// Print unsorted contacts
	contactsBook.print_contacts_sorted("");
	// Scenario 2
	cout << "Scenario 2:" << endl;
	// Display no. of contacts
    cout << "Total contacts: " << contactsBook.total_contacts() << endl;
	// Add two more contacts
	for (int j = 0; j < 2; j++) 
	{
		cout << "Contact " << j + 1 << ":" << endl;
		string first_name, last_name, mobile_number, email_address;
		cout << "Enter first name: ";
		getline(cin, first_name);
		cout << "Enter last name: ";
		getline( cin, last_name);
		cout << "Enter mobile number: ";
		getline( cin, mobile_number);
		cout << "Enter email address: ";
		getline(cin, email_address);
		Address address = create_address();
		Contact contact(first_name, last_name, mobile_number, email_address, &address);
		contactsBook.add_contact(contact);
	}
	cout << "Total contacts after more contacts: " << contactsBook.total_contacts() <<endl;
	// Scenario 3: Add 5 contacts with 1 duplicate, display all the contacts sorted
	cout << "Scenario 3:" << endl;
	for (int i = 0; i < 5; ++i) {
		string first_name, last_name, mobile_number, email_address;
		cout << "Enter first name: ";
		getline(std::cin >> std::ws, first_name);
		cout << "Enter last name: ";
		getline(std::cin >> std::ws, last_name);
		cout << "Enter mobile number: ";
		getline(std::cin >> std::ws, mobile_number);
		cout << "Enter email address: ";
		getline(std::cin >> std::ws, email_address);
		Address address = create_address();
		Contact contact(first_name, last_name, mobile_number, email_address, &address);
		contactsBook.add_contact(contact);
	}
	// Print contacts sorted
	contactsBook.print_contacts_sorted("first_name");
	// Run duplicate merge
	contactsBook.merge_duplicates();

	// contacts after merging duplicates
	cout << "Contacts after merging duplicates:" << endl;
	contactsBook.print_contacts_sorted("first_name");

	// Scenario 4: Show the working of store contacts and load contacts
	cout << "Scenario 4:" << endl;
	// Store contacts to file
	contactsBook.save_to_file("Contacts.txt");
	// Load contacts from file
	ContactsBook loadedContactsBook(5); // Create a new ContactsBook object
	loadedContactsBook.load_from_file("Contacts.txt");
	// Print loaded contacts
	cout << "Loaded contacts:" << endl;
	loadedContactsBook.print_contacts_sorted("first_name");
	system("pause");
	return 0;
}