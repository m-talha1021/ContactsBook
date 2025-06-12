#pragma once
#include "Contact.h"
#include <iostream>
#include <string>

class ContactsBook {
private:
	Contact *contacts_list;
	int size_of_contacts;
	int contacts_count;

public:
	ContactsBook(int size_of_list);
	~ContactsBook();

	void add_contact(const Contact& contact);
	int total_contacts();

	Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address& address);

	void print_contacts_sorted(std::string choice);
	void merge_duplicates();
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);

private:
	bool full();
	void resize_list();
	void print_contact(const Contact& contact);
	void sort_contacts_list(Contact *contacts_list, std::string choice);
};
