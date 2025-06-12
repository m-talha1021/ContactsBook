#include<iostream>
#include "ContactBook.h"
#include <algorithm>
#include <fstream>
using namespace std;
ContactsBook::ContactsBook(int size_of_list) : size_of_contacts(size_of_list), contacts_count(0) {
	contacts_list = new Contact[size_of_list]; // Allocate memory 
}
ContactsBook::~ContactsBook() {
	delete[] contacts_list;
}
void ContactsBook::add_contact(const Contact& contact)
{
	if (full()) 
	{
		resize_list();
	}
	contacts_list[contacts_count++] = contact; // contact add end of the array
}
int ContactsBook::total_contacts() 
{
	return contacts_count; 
}

bool ContactsBook::full()
{
	return (contacts_count == size_of_contacts);
}
void ContactsBook::resize_list() 
{
	int new_size = size_of_contacts * 2;
	Contact *new_contacts_list = new Contact[new_size]; 
    // Copy contacts from the old list to the new list
	for (int i = 0; i < size_of_contacts; ++i) 
	{
		new_contacts_list[i] = contacts_list[i];
	}

	delete[] contacts_list; 
	contacts_list = new_contacts_list; //assign new list
	size_of_contacts = new_size; //  size update
}
void ContactsBook::print_contact(const Contact& contact)
{
	cout << contact.get_first_name() << " " << contact.get_last_name() << " " << contact.get_mobile_number() << " " << contact.get_email_address() << std::endl;
	contact.get_address()->print_address();
}
Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	for (int i = 0; i < contacts_count; ++i)
	{
		if (contacts_list[i].get_first_name() == first_name && contacts_list[i].get_last_name() == last_name)
		{
			return &contacts_list[i]; // pointer of contact
		}
	}
	return nullptr;
}
Contact* ContactsBook::search_contact(string phone)
{
	for (int i = 0; i < contacts_count; ++i)
	{
		if (contacts_list[i].get_mobile_number() == phone)
		{
			return &contacts_list[i]; // pointer of contact(found)
		}
	}
	return nullptr; // Contact not found
}
Contact* ContactsBook::search_contact(const Address& address)
{
	for (int i = 0; i < contacts_count; ++i) 
	{
		if (contacts_list[i].get_address()->equals(address))
		{ // Dereference the pointer to access the equals function
			return &contacts_list[i]; // Return a pointer to the found contact
		}
	}
	return nullptr; 
}

void ContactsBook::print_contacts_sorted(string choice)
{
	Contact *sorted_contacts = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; ++i)
	{
		sorted_contacts[i] = contacts_list[i];
	}
	sort_contacts_list(sorted_contacts, choice);

	for (int i = 0; i < contacts_count; ++i) 
	{
		print_contact(sorted_contacts[i]);
	}

	delete[] sorted_contacts;
}

void ContactsBook::sort_contacts_list(Contact *contacts_list, string choice)
{
	if (choice == "first_name") {
		std::sort(contacts_list, contacts_list + contacts_count, [](const Contact& c1, const Contact& c2)
		{
			return c1.get_first_name() < c2.get_first_name();
		});
	}
	else if (choice == "last_name") {
		std::sort(contacts_list, contacts_list + contacts_count, [](const Contact& c1, const Contact& c2)
		{
			return c1.get_last_name() < c2.get_last_name();
		});
	}
}
void ContactsBook::merge_duplicates() 
{
	for (int i = 0; i < contacts_count; ++i) 
	{
		for (int j = i + 1; j < contacts_count; ++j) {
			if (contacts_list[i].equals(contacts_list[j]))
			{
				// duplicate, remove
				contacts_list[j] = contacts_list[contacts_count - 1]; // Replace duplicate with the last contact
				contacts_count--; // Decrement the count to remove the duplicate
				j--; // Adjust index for the next iteration
			}
		}
	}
}

void ContactsBook::load_from_file(string Contacts) 
{
	std::ifstream fin("Contacts.txt"); // Use the passed filename
	if (!fin.is_open())
	{
		std::cerr << "Error: Unable to open file for reading: " << Contacts << endl;
		return;
	}
	int count;
	fin >> count;
	fin.ignore(); 
	for (int i = 0; i < count; ++i)
	{
		string first_name, last_name, mobile_number, email_address;
		string house, street, city, country;
		getline(fin, first_name);
		getline(fin, last_name);
		getline(fin, mobile_number);
		getline(fin, email_address,'\n');
		getline(fin, house);
		getline(fin, street);
		getline(fin, city);
		getline(fin, country, '\n');
		Address address(house, street, city, country);
		Contact contact(first_name, last_name, mobile_number, email_address, &address);
		add_contact(contact);
	}
	fin.close();
}


void ContactsBook::save_to_file(std::string Contacts) {
	std::ofstream fout(Contacts); // Open the file with the provided file name
	if (!fout.is_open()) {
		std::cerr << "Unable to open file for writing: " << Contacts << endl;
		return;
	}

	fout << contacts_count << std::endl; // Write the total number of contacts to the file
	for (int i = 0; i < contacts_count; ++i) {
		Contact* contact = &contacts_list[i]; // Get a pointer to the current contact

											  // Write contact details to the file
		fout << contact->get_first_name() << "," << contact->get_last_name() << "," << contact->get_mobile_number() << "," << contact->get_email_address() << endl;
		fout << contact->get_address()->get_house() << "," << contact->get_address()->get_street() << "," << contact->get_address()->get_city() << "," << contact->get_address()->get_country() << endl;
	}

	fout.close(); // Close the file
}

