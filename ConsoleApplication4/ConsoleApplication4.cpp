// INFO450project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int tCount;

class Ticket
{
	static int idGen;
	int ID;
	string status;
	string type;
	string priority;
	string name;
	string description;
	int numberImpacted;
public:

	int generateID()
	{
		ID = idGen++;
		tCount++;
		return ID;

	}

	void CaptureTicket()
	{
		ID = generateID();
		status = "Open";
		char TypeInput;
		cout << "Please enter user name: ";
		getline(cin, name);
		cout << "Please select type of error: (S) Server, (A) Application, (C) Access" << endl;
		cin >> TypeInput;
		switch (TypeInput)
		{
		case 's':
		case 'S':
			type = "Server";
			break;
		case 'a':
		case 'A':
			type = "Application";
			break;
		case 'c':
		case 'C':
			type = "Access";
			break;
		default:
			type = "Error";
			break;
		}
		cin.clear();
		cin.ignore();
		cout << "Please enter error description: ";
		getline(cin, description);
		cout << "Please enter the number of users impacted: ";
		cin >> numberImpacted;
		cin.clear();
		cin.ignore();

		if (numberImpacted < 10)
		{
			priority = "Low";
		}
		else if (numberImpacted < 50)
		{
			priority = "Medium";
		}
		else
		{
			priority = "High";
		}






	}

	void ShowTicket()
	{
		cout << "______________________________" << endl;
		cout << "Ticket #: " << ID << "   Status: " << status << endl;
		cout << "Type: " << type << "   Priority: " << priority << endl;
		cout << "Name: " << name << endl;

		cout << "\nDescription: \n" << description << endl << endl;
	}
	void CloseTicket()
	{

		status = "Closed";
	}

};

int Ticket::idGen = 001;



int main()
{
	Ticket *tNumber[100];

	char oP;
	for (int i = 0; i < 100; i++)
	{
		cout << "Do you want to enter a ticket? Y/N " << endl;
		cin >> oP;
		cin.ignore();
		cin.clear();
		system("CLS");
		if (oP == 'Y' || oP == 'y')
		{
			tNumber[i] = new Ticket();
			tNumber[i]->CaptureTicket();


		}
		else if (oP == 'N' || oP == 'n')
		{
			break;
		}
		else
		{
			break;
		}


	}
	system("CLS");

	for (int i = 0; i < tCount; i++)
	{
		tNumber[i]->CloseTicket();
		tNumber[i]->ShowTicket();
	}

	system("PAUSE");
	return 0;
}



