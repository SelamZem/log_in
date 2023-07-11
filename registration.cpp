#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
void addStuds();
void emails();
void pass_word();
void stud_age();

struct Students{
	string fName,Lname, sEmail;
	int age;
	char passwords[15];

};

Students student[50];
int counter = 0;//counts number of students






int main(){
	
	addStuds();
	
	return 0;
}


void addStuds() //adds students to the system
{
	
	fstream myFile;
	 
	 myFile.open("Student_Data.txt", ios::app);
	 
	 if(myFile.is_open())
	
	 {
	 
	
		cout<<"\n\t\t\tFIRST NAME: ";
		cin>>student[counter].fName;
		cout<<"\n\t\t\tLAST NAME: ";
		cin>>student[counter].Lname;
		
		stud_age();
		pass_word();
		emails();
		
		
		myFile<<endl<<student[counter].sEmail<<" "<<student[counter].fName<<" "<<student[counter].Lname<<" "<<student[counter].age<<" "<<student[counter].passwords;
		myFile.close();	
	}

	else
	 {
	 	cout<<"File doesnt exist";
	 	exit(1);
	 }



	counter++;
}
void stud_age()//accepts values only b/n 4 and 25
{
	int ageS;//age of student
	
	cout<<"\n\t\t\tAGE: ";
	cin>>ageS;
	
	if(ageS>3 and ageS<26)
	student[counter].age=ageS;
	
	else
	{
		cout<<"\n\t\t\tPlease enter a valid age.";
		stud_age();
	 } 
}
void pass_word()
{
//	

	int special = 0;//increases when you use special character
	char pwd[15];
	
	cout<<"\n\t\t\tPASSWORD: ";
	cin.getline(pwd, 15);

	
	
		if(strlen(pwd)>7)
		{
	
			for(int i=0;i<strlen(pwd);i++)
			{
				if((pwd[i]>32 && pwd[i]<48)||(pwd[i]>57 and pwd[i]<65))
				special++;
			}
			
			if(special>0)
			{
				strcpy(student[counter].passwords,pwd);
			}
			else
			{
				cout<<"\n\t\t\tYour password must have at least one special character.";
				pass_word();
					
			}
		}
		
		else
		{
			cout<<"\n\t\t\tInvalid password length.Please input atleast 8 characters.";
			pass_word();
		}

}

void emails()
{
	
	string emailss;
	cout<<"\n\t\t\tEmail Address: ";
	cin>>emailss;
	
	string line;
    fstream read_file;
    read_file.open("Student_Data.txt", ios::in);

    while(read_file.eof())
    {
        getline(read_file,line);

        for(int i=0;i<line.length();i++)
        {
            if(line[i]==' ')
            {
                break;
            }
		}
		
			if(strcmp(line.c_str(),emailss.c_str())==0)
			{
				cout<<"\n\t\t\tThe Email address already exist.Please Enter a valid email address.";
				system("pause");
				emails();
			}
			else
			{
				student[counter].sEmail=emailss;
			}
        
  	 }

	read_file.close(); 
	
	
	
}
