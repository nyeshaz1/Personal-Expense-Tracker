#include<iostream>
#include<cstring>
#include<cctype>
#include<fstream>
using namespace std;
class User {
	string password;
public:
	string username;
	int totalbalance = 0;
	int amount;
	int totalspentis = { 0 };
	string list[15] = { "" };
	int spent[15] = { 0 };
	int listcount = 0;
	int remainingamount = 0;
	int index;
	int max;




	void signup(User users[], int usercount) {
		while (true) {//unless user enter a correct username 
			cout << "USERNAME : ";
			cin >> username;
			for (int i = 0; i < username.length(); i++) {// only lowercase will be used in username 
				username[i] = tolower(username[i]);// tolower only convert one character at a time to lowercase 
			}
			bool exit = false;// it is to check if username alreay exis 
			for (int i = 0;i < usercount;i++) {

				if (users[i].username == username) {
					cout << "This username already exist try another ." << endl;
					exit = true;// yup , if it exists user have to choose another 
					break;
				}
			}
			if (exit)
				//and continue using different usernames until its unique
				continue;


			// checking username validation 
			//if its only lowercase, numbers or hyphen
			bool valid = true;
			for (int j = 0; j < username.length(); j++) {
				char ch = username[j];
				if (!((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '_')) {
					valid = false;
					//false means its not valid so try again 
					break;
				}
			}
			if (valid) {
				// if username is valid now its time for password 
				cout << "PASSWORD : ";
				cin >> password;
				//after password is entered just jump to  main interface 
				maininterface();
				break;
			}
			else {
				cout << "You can only use lowercase letter , numbers or underscore (_).Please try again." << endl;

			}
		}
	}

	int login(string id, string pass) {
		// to check if the valid udername matches to corresponding password 
		if (username == id && password == pass) {
			cout << "Login successfully! " << endl;
			return 1;
			//return 1 means it matched now jump to main interface 

		}
		else
		{
			cout << "Incorrect password.";
			return 0;
			//0 means incorrect password now user have to again enter the password 

		}

	}
	void deposit() {
		cout << "Enter the amount :";
		cin >> amount;
		totalbalance += amount;
		//total balance will show the actual total amount user have now 

	}
	void checkbalance() {
		cout << "Your currecnt balance is " << totalbalance;
		// just to print the cuurent balance 
	}
	void makelist() {
		int deleteitem; // to delete any item from list (if it exit)
		int operation; //which operation user wanna do? , add , delete , view , or exit(nothing - why you entered?)
		while (true) {
			cout << endl;
			cout << "Select operation : " << endl;
			cout << "1. View List\n2. Add into list\n3. Delete item\n4. Break : ";
			cout << endl;
			cout << "Operation : ";
			cin >> operation;

			switch (operation) {
			case 1: {
				cout << "Your list include :" << endl;
				// this loop will only show non empty index (not all 15)

				for (int i = 0; i < 15;i++) {
					if (list[i] != "")

						cout << i + 1 << "." << list[i] << endl;

					//as index of loop starts from 0 so just to give valid 
					//output its i+1 (e.g 0+1=1 )

				}
				break;
			}
			case 2: {
				//following bool flag is used to indicate if the list
				// is already full or if there's any empty space

				bool added = false;

				// its very important to add this loop to avoid overwriting 
				//and only add new item if theres empty seat in the bus (i mean list) 

				for (int i = 0; i < 15;i++) {
					if (list[i] == "") {
						cout << "Enter you new item : ";
						cin >> list[i];
						listcount++;
						//list count is used just to have a track of how many items are added till now 

						added = true;
						break;
					}


				}
				if (!added) {
					cout << "List is full." << endl;
				}

				break;
			}
			case 3: {
				cout << "Enter the number of list item you want to delete : ";
				cin >> deleteitem;
				//the following special if condition is used to check is the entered 
				//index number is within range , and ofcourse if use enter index 1 
				//its 0 in looping index so minus it 
				if (deleteitem >= 1 && deleteitem <= 15 && list[deleteitem - 1] != "") {

					list[deleteitem - 1] = "";//maing the list empty and 
					listcount--;//subtracting from list count to keep track
					cout << "Item deleted successfully.";
				}
				else
				{
					cout << "Invalid item number " << endl;
				}
				break;
			}
			case 4: {
				cout << endl;
				cout << "Existing this menu..." << endl;
				return;
			}
			default: {
				cout << "Invalid input. " << endl;
				break;
			}





			}

		}
	}
	void spenton() {
		//spenton function
		cout << "Your list include :" << endl;
		for (int i = 0; i < 15;i++) {
			if (list[i] != "")

				cout << i + 1 << "." << list[i] << endl;

		}
		cout << endl;
		cout << "Select the index number and add amount to it." << endl;
		cout << "index : ";
		cin >> index;
		cout << endl;
		if (list[index - 1] != "") {

			cout << "Enter the amount :";
			cin >> spent[index];
			if (totalbalance >= spent[index]) {

				totalspentis += spent[index];
				remainingamount = totalbalance - spent[index];
				totalbalance -= spent[index];
			}
			else
			{
				cout << "Not Enough Balance " << endl;
			}
		}

	}
	void totalspent() {
		//totalspenton function
		cout << "\nTotal spent amount : " << totalspentis << endl;
	}
	void remaining() {
		//remaining function
		remainingamount = totalbalance - totalspentis;
		cout << "Total remaining balance is " << remainingamount << endl;
	}
	void mostspenton() {
		//mostspenton function
		int maxind = 0;
		int max = spent[0]; //intentionally set first as most spent item 
		// now to check across all the list 
		for (int i = 1; i < 15;i++) {
			if (spent[i] > max)
			{

				max = spent[i];
				maxind = i;

			}

		}
		cout << "Most amount is spent on " << list[maxind] << " and the amount is " << max;



	}

	void maininterface() {
		int option;
		while (true) {
			cout << endl;
			cout << "                           Main Interface\n";
			cout << "What to do next ? " << endl;
			cout << endl;
			// this will show the menue
			cout << "1. Deposit\n2. Check Balance\n3. Make/Edit list\n4. Spent on\n5. Total spent\n6. Remaining\n7. Most spent on\n8.Logout " << endl;
			cout << endl;
			cout << "Option : ";
			cin >> option;
			cout << endl;
			if (option == 1)
				deposit();
			else if (option == 2)
				checkbalance();
			else if (option == 3)
				makelist();
			else if (option == 4)
				spenton();
			else if (option == 5)
				totalspent();
			else if (option == 6)
				remaining();
			else if (option == 7)
				mostspenton();
			else if (option == 8)
				return;
			else
				cout << "Wrong option entered." << endl;



		}
	}











};

int main() {
	cout << "____                          YOUR PERSONAL EXPENSE TRACKER                          ____";
	cout << endl;
	const int maxusers = 100; // maximum users 
	User users[maxusers]; // objects 
	int usercount = 0;// to keep record of users 

	char choose;
	while (true) {//unless user enter a correct choice option 
		cout << endl;
		cout << "            Welcome Interface " << endl;
		cout << "Do you want to \n1. Sign up\n2. Login" << endl;
		cout << "Choose 1 or 2 : ";
		cin >> choose;
		cout << endl;
		if (choose == '1') {
			if (usercount < maxusers) {
				//to check if there is space for any other user 

				users[usercount].signup(users, usercount); // jumps to member function
				// now to keep track of how many users have signup 
				usercount++;



			}

		}
		else if (choose == '2') {
			string pass, id;
			cout << "USERNAME : ";
			cin >> id;
			for (int i = 0; i < id.length();i++)
			{
				id[i] = tolower(id[i]);

			}


			bool match = false; // this flag is to check if the username already exist 
			for (int i = 0;i < usercount;i++) {

				if (users[i].username == id) { //if condition used to clearify if username exist 
					cout << "PASSWORD : ";
					cin >> pass;
					// if yes , so call login function to check if 
					//corressponding password matches 
					int success = users[i].login(id, pass);
					if (success) {

						users[i].maininterface(); // if matches so jumps to main interface 
						match = true;
						break;
					}
				}
			}

			if (!match) {

				cout << "User not found." << endl;
			}

		}
		else {
			cout << "You entered a wrong number.Please try again." << endl;
			// after this automatically jumps to welcome interface, if  corrrect option is not  selected

		}

	}
	return 0;
}



