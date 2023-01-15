//libraries we have worked with.
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;
//objects to work with text file.
fstream file, file1, file2, file3;
//boolean variable if a specific record is found, initially set to 'false'.
bool found = false;
//structure of product.
struct product {
	int pno, price, qty;
	string name;
}p;

//prototypes of functions used.
void admin();
void write();
void display();
void search();
void del();
void modify();
void menu();
void icon();
void order();
bool login();
void AccessGranted();

//Main Function.
int main() {
	int choose;
	icon();
	while (1) {
		system("cls");
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                                                           |" << endl;
		cout << "|                   - W E L C O M E   T O   T H E   S T O P   &   S H O P   S T O R E -                     |" << endl;
		cout << "|                                                                                                           |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------" << endl << endl;

		cout << "\n\nPlease Choose an appropriate option : ";
		cout << "\n=======================================";

		cout << "\n\n1. For Admin";
		cout << "\n\n2. For Customer";
		cout << "\n\n0. Exit";
		cout << "\n\nPlease Pick any one option: ";
		cin >> choose;

		switch (choose) {

		case 1:
			system("cls");
			login();
			break;

		case 2:
			system("cls");
			order();
			break;

		case 0:
			system("cls");
			icon();
			exit(0);
			break;
		}

	}
}
// void function that doesn't returns
// anything but shows the shop logo animation.
void icon() {
	cout << "\n\n\n\n\n\n\n";
	cout << "\n                        ������������                                        ";
	cout << "\n                        ������������                                        ";
	cout << "\n                        ����          ��������    �����    ������           ";
	cout << "\n                        ����             ��     ��     ��  ��    ��         ";
	cout << "\n                        ����             ��     ��     ��  ������           ";
	cout << "\n                        ����             ��     ��     ��  ��               ";
	cout << "\n                        ������������     ��       �����    ��               ";
	cout << "\n                        ������������                                 &   ";
	cout << "\n                                ����   ��   ��    �����    �������          ";
	cout << "\n                                ����   ��   ��  ��     ��  ��     ��        ";
	cout << "\n                                ����   �������  ��     ��  �������          ";
	cout << "\n                                ����   ��   ��  ��     ��  ��               ";
	cout << "\n                        ������������   ��   ��    �����    ��                ";
	cout << "\n                        ������������                                         ";
	Sleep(3000);
	system("cls");
}
// void function that doesn't returns
// anything but shows the menu to shop admin.
void admin() {
	int pick;
	while (1) {
		system("cls");
		cout << "\n=========> Welcome Admin <=========\n";
		cout << "\n1. Add a new Product.";
		cout << "\n\n2. Delete a Product.";
		cout << "\n\n3. Modify a Product.";
		cout << "\n\n4. Search a Product.";
		cout << "\n\n5. Display all Products.";
		cout << "\n\n0. Back to main menu.";
		cout << "\n\nPick one option: ";
		cin >> pick;
		system("cls");

		switch (pick) {

		case 1:
			system("cls");
			write();
			break;
		case 2:
			system("cls");
			del();
			break;
		case 3:
			system("cls");
			modify();
			break;
		case 4:
			system("cls");
			search();
			break;
		case 5:
			system("cls");
			display();
			break;
		case 0:
			system("cls");
			main();
			break;
		}
	}
}
// void function that doesn't returns
// anything but adds a record in file.
void write() {
	cout << "------------------------------\n";
	cout << "       ADD PRODUCT MODULE     \n";
	cout << "------------------------------\n";
	char new_product;
	file.open("shop.txt", ios::app);
	do {
		cout << "Product no : ";
		cin >> p.pno;
		cout << "Name       : ";
		cin >> p.name;
		cout << "Quantity   : ";
		cin >> p.qty;
		cout << "Price      : ";
		cin >> p.price;
		file << endl << p.pno << "\t " << p.name << "\t " << p.qty << "\t " << p.price;
		cout << "\nProduct successfully added! ";
		cout << "\n\nYou want to add another product?  ";
		cin >> new_product;
	} while (new_product == 'y');
	file.close();
	cout << "\n\n\n";
	system("pause");
}
// void function that doesn't returns
// anything but Displays all records from file.
void display() {
	cout << "----------------------------\n";
	cout << "       DISPLAY MODULE        \n";
	cout << "----------------------------\n";
	string temp;
	file.open("shop.txt", ios::in);
	cout << "ID\tName\tQuantity  Price\n";
	while (getline(file, temp)) {
		cout << temp << endl;
	}
	file.close();
	cout << endl << endl << endl;
	system("pause");

}
// void function that doesn't returns
// anything but searches for a record in file.
void search() {
	cout << "----------------------------\n";
	cout << "       SEARCH MODULE        \n";
	cout << "----------------------------\n";
	string iid, n, line, s;
	char choice;
	found = false;
try_again:
	cout << "\nEnter Product ID: ";
	cin >> s;

	file.open("shop.txt", ios::in);
	while (getline(file, line)) {
		iid = line.substr(0, 1);
		if (iid == s) {
			found = true;
			break;
		}
		else {
			found = false;
		}
	}
	if (found) {
		n = line.substr(1, line.length() - 1);
		cout << "ID found : " << iid << endl;
		cout << n;
		found = true;
	}
	file.close();
	if (!found) {
		cout << " \nNo Record Found!\n Press 1 to Try Again OR Press 0 for main menu : ";
		cin >> choice;
		cout << endl << endl;
		if (choice == '1') {
			goto try_again;
		}
		else
			admin();
	}
	cout << endl << endl << endl;
	system("pause");
	system("cls");
}
// void function that doesn't returns
// anything but modifies a desired record in file.
void modify() {
	cout << "--------------------------------\n";
	cout << "       MODIFY PRODUCT MODULE     \n";
	cout << "--------------------------------\n";
	int counter = 0, rec;
	char choice;
	string iid, n, line, s;
	string line_arr[100];
	found = false;
try_again:
	cout << "Enter Product ID to search : ";
	cin >> s;
	file.open("shop.txt", ios::in);
	while (getline(file, line)) {
		iid = line.substr(0, 1);
		if (iid == s) {
			found = true;
			break;
		}
		else {
			found = false;
		}
	}
	file1.open("shop.txt", ios::in);
	while (getline(file1, line)) {
		line_arr[counter] = line;
		iid = line.substr(0, 1);
		if (iid == s) {
			rec = counter;
		}
		counter++;
	}
	file1.close();
	if (found) {
		cout << "Record : " << line_arr[rec] << endl;
		cout << "Enter Updated Details : \n";
		cout << "Product no ";
		cin >> p.pno;
		cout << "Name ";
		cin >> p.name;
		cout << "Quantity: ";
		cin >> p.qty;
		cout << "Price ";
		cin >> p.price;
		line_arr[rec] = to_string(p.pno) + "\t" + p.name + "\t" + to_string(p.qty) + "\t" + to_string(p.price);
		file2.open("shop.txt", ios::out);
		for (int i = 0; i < counter; i++) {
			file2 << line_arr[i] << endl;

		}
		file2.close();
	}
	else {
		cout << " \nNo Record Found!\n Press 1 to Try Again OR Press 0 for main menu : ";
		cin >> choice;
		cout << endl << endl;
		if (choice == '1') {
			goto try_again;
		}
		else
			admin();
	}
	file.close();
	cout << "\n\n\n";
	system("pause");
}
// void function that doesn't returns
// anything but deletes a record from file.
void del() {
	cout << "--------------------------------\n";
	cout << "       DELETE PRODUCT MODULE     \n";
	cout << "--------------------------------\n";
	char choice;
	string line, id, line_arr[100], iid[100], pname[100], pquan[100], pprice[100];
	int no = 0, rec1 = 0, no1 = 0, dno, no2, pid[100];
	fstream file4, file5;
try_again:
	cout << "Delete item no : ";
	cin >> dno;
	file4.open("shop.txt", ios::in);
	while (!file4.eof()) {
		file4 >> pid[no] >> pname[no] >> pquan[no] >> pprice[no];
		if (pid[no] == dno) {
			rec1 = no;
			found = true;
		}
		no++;
		no2 = no;
	}
	if (!found) {
		cout << " \nNo Record Found!\n Press 1 to Try Again OR Press 0 for main menu : ";
		cin >> choice;
		cout << endl << endl;
		if (choice == '1') {
			goto try_again;
		}
		else
			admin();
	}
	no1 = dno - 1;
	file4.close();
	for (int j = 0; j < no1; j++) {
		line_arr[j] = to_string(j + 1) + "\t" + pname[j] + "\t" + pquan[j] + "\t" + pprice[j] + "\n";
	}
	for (int i = no1; i < no2 - 2; i++) {
		line_arr[i] = to_string(i + 1) + "\t" + pname[i + 1] + "\t" + pquan[i + 1] + "\t" + pprice[i + 1] + "\n";

	}
	file5.open("shop.txt", ios::out);
	for (int i = 0; i < no; i++) {
		file5 << line_arr[i] << endl;

	}
	cout << "\nProduct deleted.";
	cout << "\n\n\n";
	file5.close();
	system("pause");
}
// void function that doesn't returns
// anything but shows menu to customer.
void menu() {
	string temp;
	cout << "\nPRODUCT# NAME \tQUANTITY PRICE \n" << endl;
	file.open("shop.txt", ios::in);
	while (getline(file, temp)) {
		cout << temp << endl;
	}
	file.close();
}
// void function that doesn't returns
// anything but takes order from customer.
void order() {
	string  cname, cnum;
	cout << "--------------------------------------------------------------------------------------------------------------\n";
	cout << "                                               ORDER MODULE     \n";
	cout << "--------------------------------------------------------------------------------------------------------------\n";
	cout << "Enter Customer Name : ";
	//getline(cin, cname, '.');
	cin >> cname;
	cout << endl;
	cout << "Enter Customer Phone Number : ";
	cin >> cnum;
	cout << endl;
	cout << "* M E N U *";
	menu();
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	string pname, line1, bname[100];
	char new_order;
	int order_arr[50], quan[50], index_id = 0, num = 0, amt = 0, total = 0, pprice = 0, pquan = 0, t = 0, q = 0, bprice[100],bnum[100];
	do {
	try_again:
		cout << "Enter Product Number : ";
		cin >> order_arr[index_id];
		cout << "Quantity : ";
		cin >> quan[index_id];
		index_id++;
		cout << "You want to add another product? ";
		cin >> new_order;
	} while (new_order == 'y');
	for (int i = 0; i <= index_id; i++) {
		file.open("shop.txt", ios::in);
		while (getline(file, line1)) {
			file >> num >> pname >> pquan >> pprice;
			if (num == order_arr[i]) {
				bnum[i] = num;
				bname[i] = pname;
				bprice[i] = pprice;
				amt = pprice * quan[i];
				t = quan[i];
				total = total + amt;
				found = true;
				break;
			}
		}
		file >> num >> pname >> pquan >> pprice;
		file.close();
	}
	if (!found) {
		cout << "\nNo Record Found, Try Again \n";
		goto try_again;
	}
	system("cls");
	cout << "==================================================================================================";
	cout << "                                       B I L L                                             ";
	cout << "\n\n";

	cout << "Customer Name : " << cname << endl;
	cout << "Customer Number : "<<cnum << endl;
	cout << endl;
	for (int j = 0; j < index_id; j++) {
		cout << "\n Product Name : " << bname[j];
		cout << "\n Quantity     : " << quan[j];
		cout << "\n Price        : " << bprice[j];
	}
	bool dis = false;
	int total1;
	if (total > 1000) {
		total1 = total * (0.1);
		total = total - total1;
		dis = true;
	}
	cout << "\n-------------------------------------------------------------------------------------------------\n";
	if (dis == true) {
		cout << "\n\nYou got discount of " << total1 <<" rupees. "<< endl;
	}
	cout << "\n\tTOTAL       : " << total << endl;
	
	cout << "==================================================================================================";
	int counter = 0, rec = 0;
	string iid, n, line, s;
	string line_arr[100];
	found = false;
	for (int n = 0; n < index_id; n++) {
		file.open("shop.txt", ios::in);
		while (getline(file, line)) {
			iid = line.substr(0, 1);
			if (iid == to_string(bnum[n])) {
				found = true;
				break;
			}
			else {
				found = false;
			}
		}
		file.close();
		int e = 0;
		file1.open("shop.txt", ios::in);
		while (getline(file1, line)) {
			line_arr[e] = line;
			iid = line.substr(0, 1);
			if (iid == to_string(bnum[n])) {
				rec = e;
			}
			e++;
		}
		file1.close();
		if (found) {
			q = pquan - quan[n];
			line_arr[rec] = to_string(bnum[n]) + "\t" + bname[n] + "\t" + to_string(q) + "\t" + to_string(bprice[n]);
			file2.open("shop.txt", ios::out);
			for (int i = 0; i < e; i++) {
				file2 << line_arr[i] << endl;
			}
			file2.close();
		}
		//file.close();
	}
	cout << endl;
	system("pause");
}
// bool function that takes username and password
// to login the shop admin.
//returns 1 if given correct credentials and 0 if given wrong.
bool login() {
	string pass1 ;
	string username = "admin";
	string password = "admin";
	char ch;
	for (int i = 1; i < 4; i++)
	{
		system("cls");
		string id, pass;
		cout << "\t\t\t-----------------------------------------------------" << endl;
		cout << "\t\t\t|                                                   |" << endl;
		cout << "\t\t\t|                    LOGIN FORM                     |" << endl;
		cout << "\t\t\t|                                                   |" << endl;
		cout << "\t\t\t-----------------------------------------------------" << endl;
		cout << "\t\t\t            Username : ";
		cin >> id;
		cout << "\t\t\t            Password : ";
		ch = _getch();
		while (ch != 13) {
			pass1.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		// If-statement to verify the entered username.
		if (id == username)
		{
			// If-statement to verify the entered password.
			if (pass1 == password)
			{
				system("CLS");
				AccessGranted();
				admin();
				return 1;
				abort();
			}
			// Else statement that'll prompt error if user enters wrong password.
			else
			{
				cout << "\n\t\t\t            Error : Invalid Password" << endl;
				cout << "\t\t\t            You have " << 3 - i << " tries left." << endl;
				_getch();

			}
		}
		// Else statement that'll prompt error if user enters wrong username.
		else
		{
			cout << "\n\t\t\t            Error : Invalid Username" << endl;
			cout << "\t\t\t            You have " << 3 - i << " tries left." << endl;
			_getch();
		}
	}
	return 0;
}
// void function that doesn't returns
// anything but shows the access granted animation.
void AccessGranted()
{
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bA   " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAc   " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAcc   " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAcce   " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAcces   " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess   " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess    " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess G  " << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Gr" << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Gra" << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Gran" << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Grant" << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Grante" << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Granted" << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Granted." << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Granted.." << std::flush;
	Sleep(100);
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bAccess Granted..." << std::flush;
	Sleep(100);
}
