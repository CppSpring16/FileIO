#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include "dummycode.h"

using namespace std;

void SchedOpt::printSched(string classes[],int schedA) // printing current schedule(s)
{
	for (int i = 1 ; i <= schedA ; i++)
	{	
		cout << "Printing schedule #"<<i<<"."<<endl;
		cout <<"    "<< setw(15)<<"|M"<<setw(15)<<"|T"<<setw(15)<<"|W"<<setw(15)<<"|R"<<setw(15)<<"|F"<<endl;
		cout << "-----------------+--------------+--------------+--------------+--------------+----"<<endl;
		for (int k=1;k<=14;k++)
		{
			cout << "P";
			printf("%2d ",k);
			cout <<setw(15)<<"|1"<<setw(15)<<"|2"<<setw(15)<<"|3"<<setw(15)<<"|4"<<setw(15)<<"|5"<<endl;
			cout << "-----------------+--------------+--------------+--------------+--------------+----"<<endl;
		} cout << endl;
	}
}

void SchedOpt::saveWeekly(string classes[], string fileName) // opening csv file containing schedule
{
	int w =0;
	ofstream infoFile;
	string name =""; name.append(fileName);name.append(".txt");
	infoFile.open(name.c_str());
	infoFile <<"    "<< setw(15)<<"|M"<<setw(15)<<"|T"<<setw(15)<<"|W"<<setw(15)<<"|R"<<setw(15)<<"|F"<<endl;
	infoFile << "-----------------+--------------+--------------+--------------+--------------+----"<<endl;
	for (int k=1;k<=14;k++)
	{
		infoFile << "P"<<k;
		if (k>=10)
			w = 16;
		else
			w = 17;
		infoFile <<setw(w)<<"|1"<<setw(15)<<"|2"<<setw(15)<<"|3"<<setw(15)<<"|4"<<setw(15)<<"|5"<<endl;
		infoFile << "-----------------+--------------+--------------+--------------+--------------+----"<<endl;
	}	
	//infoFile << "Hello";
	infoFile.close();	
}

void SchedOpt::modStrings(string classes[]) //adding commas to strings for csv files
{
	int size = classes->size();
	for (int i =0; i<size;i++)
	{
		classes[i] = classes[i].append(",");
	}
}

void SchedOpt::saveSched(string classes[],string fileName) // saves desired schedule to text file 
{

}
void SchedOpt::exportCL(string classes[],string fileName) // exports desired schedule to a csv file 
{
	//int w =0;
	ofstream infoFile;
	string name =""; name.append(fileName);name.append(".csv");
	infoFile.open(name.c_str());
	infoFile << ",M,T,W,R,F"<<endl;
	for (int i =1;i<=14;i++)
	{
		infoFile << "P" <<i<<endl;
	}
	infoFile.close();

}

void menu()
{
	cout <<"1. Add classes"<<endl;
	cout <<"2. Edit classes"<<endl;
	cout <<"3. Print optimized schedule to text file"<<endl;
	cout <<"4. Print optimized schedule to csv file"<<endl;
	cout <<"5. Print current schedule(s)."<<endl;
	cout <<"6. Exit"<<endl; cout << endl;
	cout <<"Choice - ";
}
int main()
{
	string fileName = "";
	SchedOpt so; // initializing SchedOpt object for use of header functions  
	string words[4]={"hello,"," ,","after,","next,"};
	cout << "Welcome to the class schedule optimizer for the University of Florida."<<endl;
	cout << "Please enter the name of the file you wish to use: "; cin>>fileName;
	cout << "Using file \""<<fileName<<".txt\"."<<endl;
	int choice = 0; int schedAmount =0;
	while (true) // runs infinitely until exit is chosen 
	{
		menu();
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
		{
			cout << "Please enter a valid option: ";
			cin >> choice;
		} 
		if (choice == 1)
		{
			cout << "Adding Classes" << endl;
		}
		if (choice == 2)
		{
			cout << "Editing Classes" << endl;
		}
		if (choice == 3)
		{
			cout << "Writing to file" << endl;
			so.saveWeekly(words, fileName);
		}
		if (choice == 4)
		{
			cout <<"Exporting to a csv file."<<endl;
			so.exportCL(words,fileName);
		}
		if (choice == 5)
		{
			cout << "Amount of schedules: "; cin >> schedAmount;
			cout << "Printing current schedule(s)."<<endl;
			so.printSched(words, schedAmount);
		}
		if (choice == 6)
		{
			cout << "Exiting" << endl; return 0;
		}
	}
}
