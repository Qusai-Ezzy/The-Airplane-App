#include<iostream>
#include <bits/stdc++.h>
#include<windows.h>
#include<vector>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iomanip>

using namespace std;
COORD c;
void printAllPaths(int adj[14][14], int s, int d);
void switchcase(int);
void dijkstra(int[14][14], int, int);
void searchFlight();
void book(string s, string d, int def, int fno);
void Delete();
void display();
void line();
void line2();
int no_of_paths = 0;
void Sleep(DWORD dwMilliseconds);
long int flightNo = 672832;

string cities[14] = {"Mumbai", "Delhi", "Gandhinagar", "Kolkata", "Shahpur", "Vishakapatnam", "Lucknow", "Madurai", "Manipur", "Jaipur", "Ooty", "Chandigarh", "Patna", "Banglore"};

int adjMatrixTime[14][14] = {{0, 2, 5, 0, 0, 0, 0, 0, 8, 3, 0, 0, 0, 0},
                             {2, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0},
                             {0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
                             {0, 0, 0, 0, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0},
                             {11, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 7, 8, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                             {0, 6, 0, 0, 0, 5, 0, 7, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
                             {0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 10, 0, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 4},
                             {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 4, 0}};
                             
int adjMatrixCost[14][14] = {{0, 40, 100, 0, 0, 0, 0, 0, 45, 60, 0, 0, 0, 0},
                             {55, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0},
                             {0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80},
                             {0, 0, 0, 0, 15, 65, 0, 0, 0, 0, 0, 0, 0, 0},
                             {10, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 50, 75, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
                             {0, 25, 0, 0, 0, 30, 0, 10, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                             {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0},
                             {0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 60, 0, 45, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0, 50},
                             {0, 0, 0, 0, 0, 35, 0, 0, 0, 0, 0, 0, 15, 0}};
                             
int adjMatrixSeats[14][14] = {{0, 40, 100, 0, 0, 0, 0, 0, 45, 60, 0, 0, 0, 0},
                             {55, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0},
                             {0, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80},
                             {0, 0, 0, 0, 15, 65, 0, 0, 0, 0, 0, 0, 0, 0},
                             {10, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 50, 75, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
                             {0, 25, 0, 0, 0, 30, 0, 10, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                             {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0},
                             {0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 60, 0, 45, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0, 50},
                             {0, 0, 0, 0, 0, 35, 0, 0, 0, 0, 0, 0, 15, 0}};
                             
int visited[14];
int path[14];
int path_index = 0;
vector<vector<int>> pathcost(14);
struct node
{
    string s, d, name, pass, age, date;
    int ticket_id;
    struct node *next;
} *booked = NULL;

#define I 32767

void gotoxy(int x, int y)
{
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void addFlight()
{
	int i, j, l = 0;
    int source, destination;
    do
    {
        cout << " * Enter source city : " <<endl;
        for (i = 0; i < 14; i++)
        {
            for (j = i; j < i + 3; j++)
            {
                cout<<"    ";
                if (j <= 13)
                {
                    cout <<"Press " << j + 1 << "." << cities[j] << "\t\t";
                }
                
                else
                {
                    break;
                }
            }
            
            i = j - 1;
            cout << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> source;
        source--;
        if (source < 0 || source > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> destination;
        destination--;
        if (destination < 0 || destination > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        if (destination == source)
        {
            cout << "PLEASE ENTER A VALID DESTINATION OTHER THAN THE SOURCE" << endl;
        }
        system("cls");
    } while ((source < 0 || source > 14 || destination < 0 || destination >= 14) || destination == source);
    
    cout << "PLEASE ENTER THE PRICE FOR THE FLIGHT: ";
    cin >> adjMatrixCost[source][destination];
    cout << "PLEASE ENTER THE NUMBER OF SEATS AVAILABLE FOR THE FLIGHT: ";
    cin >> adjMatrixSeats[source][destination];
    cout << "PLEASE ENTER THE TIME TO REACH FROM SOURCE TO DESTINATION: ";
    cin >> adjMatrixTime[source][destination];
    
    cout << "\n	FLIGHT BETWEEN " << cities[source] << " TO " << cities[destination] << "SUCCESSFULLY!!" << endl;
}

int getMinDist(int distance[], int visited[])
{
    int V = 14;
    int min = I, i, vertex = 0;
    for (i = 0; i < V; i++)
    {
        if (visited[i] == 0 && distance[i] <= min)
        {
            min = distance[i];
            vertex = i;
        }
    }
    return vertex;
}

int getLoop(int visited[])
{
    int V = 14;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
            return 1;
    }
    return 0;
}




void updateFlight()
{
	int i, j, l = 0;
    int source, destination;
    do
    {
        cout << " * Enter source city : " <<endl;
        for (i = 0; i < 14; i++)
        {
            for (j = i; j < i + 3; j++)
            {
                cout<<"    ";
                if (j <= 13)
                {
                    cout <<"Press " << j + 1 << "." << cities[j] << "\t\t";
                }
                
                else
                {
                    break;
                }
            }
            
            i = j - 1;
            cout << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> source;
        source--;
        if (source < 0 || source > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> destination;
        destination--;
        if (destination < 0 || destination > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        if (destination == source)
        {
            cout << "PLEASE ENTER A VALID DESTINATION OTHER THAN THE SOURCE" << endl;
        }
        system("cls");
    } while ((source < 0 || source > 14 || destination < 0 || destination >= 14) || destination == source);

    if(!adjMatrixCost[source][destination])
    {
    	int choice;
    	cout << ""; // menu 1) time 2) cost 3)seats
    	cout << "ENTER WHAT YOU WANT TO CHANGE: "; cin >> choice;
    	int num;
    	switch(choice)
    	{
    		case1:
    			cout << "Enter new time: "; cin >>num;
    			adjMatrixTime[source][destination] = num;
    			break;
    			
    		case2:
    			cout << "Enter new cost: "; cin >>num;
    			adjMatrixCost[source][destination] = num;
    			break;
    		case3:
    			cout << "Enter New Seats: "; cin >>num;
    			adjMatrixSeats[source][destination] = num;
    			break;
    			
    			default:
    				cout << "ENter correct option !!" << endl;
		}
    	cout << "FLIGHT DETAILS UPDATED SUCCESFULLY" << endl;
    	return;
	}
	
	cout << "NO SUCH FLIGHT EXISTS :(" << endl;
}

void DeleteFlight()
{int i, j, l = 0;
    int source, destination;
    do
    {
        cout << " * Enter source city : " <<endl;
        for (i = 0; i < 14; i++)
        {
            for (j = i; j < i + 3; j++)
            {
                cout<<"    ";
                if (j <= 13)
                {
                    cout <<"Press " << j + 1 << "." << cities[j] << "\t\t";
                }
                
                else
                {
                    break;
                }
            }
            
            i = j - 1;
            cout << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> source;
        source--;
        if (source < 0 || source > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> destination;
        destination--;
        if (destination < 0 || destination > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        if (destination == source)
        {
            cout << "PLEASE ENTER A VALID DESTINATION OTHER THAN THE SOURCE" << endl;
        }
        system("cls");
    } while ((source < 0 || source > 14 || destination < 0 || destination >= 14) || destination == source);

    if(!adjMatrixCost[source][destination])
    {
    	adjMatrixCost[source][destination] = 0;
    	adjMatrixTime[source][destination] = 0;
    	adjMatrixSeats[source][destination] = 0;
    	cout << "FLIGHT DETAILS DELETED SUCCESFULLY" << endl;
    	return;
	}
	
	cout << "NO SUCH FLIGHT EXISTS :(" << endl;
}

void printAllPathsUntil(int adj[14][14], int u, int d)
{
    visited[u] = 1;
    path[path_index] = u;
    path_index++;
    int pathcost = 0, pathTime = 0;
    if (u == d)
    {
        if(path_index<=7)
        {
        flightNo++;
        for (int i = 0; i < path_index - 1; i++)
        {
            pathcost += adjMatrixCost[path[i]][path[i + 1]];
            pathTime += adjMatrixTime[path[i]][path[i + 1]];
        }

        cout<<setw(5)<<flightNo<<setw(15)<<pathTime<<" hrs"<<setw(15)<<"Rs."<<pathcost
        <<setw(20);
        for (int i = 0; i < path_index - 1; i++)
        {

            cout << cities[path[i]] << " -> ";
        }
        cout << cities[path[path_index - 1]] << endl;
        line();
        no_of_paths++;
        cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < 14; ++i)
        {
            if (!visited[i] && adj[u][i])
                printAllPathsUntil(adj, i, d);
        }
    }
    path_index--;
    visited[u] = 0;
}


class Node
{
	public:
		string name,phone_no,pp,cnic,address,login_email,login_pw;
		Node* next;
		Node(string name,string phone_no,string pp)
		{
			this->name=name;
			this->login_pw=phone_no;
			this->login_email=pp;
			this->next = NULL;
			//sn++;
		}
};

fstream file;
void Customer_login();
void Register_customer()
{
	system("cls");
	cout << "\n\t\t\t     ================= REGISTRATION ================= \n\n";
	file.open("Login_Details.txt", file.app);
	string Username, Email, Pass = "", ConPass = "", Address, cnic,phone_no,pp;
	bool UserNotFound = true, userNameCorrect = false;
	int myCount;
	cout << "\n\n\t\t\tPlease enter your Username: ";
user:
	getchar();
	getline(cin, Username);
	myCount = 0;
	for (int i = 0; i < Username.length(); i++) 
	{
		if (Username[i] >= 'a' && Username[i] <= 'z' || Username[i] >= 'A' && Username[i] <= 'Z' || Username[i] >= '0' && Username[i] <= '9' || Username[i] == '@' || Username[i] == '.' || Username[i] == '_' || Username[i] == '-') 
		{
			userNameCorrect = true;
			myCount++;
			continue;
		}
		else if (Username[i] == ' ') 
		{
			userNameCorrect = true;
			myCount++;
			continue;
		}
		else 
		{
			userNameCorrect = false;
			break;
		}
	}
	if (userNameCorrect == false) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tSpecial characters are not allowed! You can only use \'-\' and \'_\'\n";
		cout << "\n\n\t\t\tPlease Re-enter Your UserName:\t";
		goto user;
	}
	else 
	{
		userNameCorrect = false;
	}
	if (myCount <= 2) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYour Username must be atleast 3 characters long!\n";
		cout << "\n\n\t\t\tPlease Re-enter Your UserName:\t";
		goto user;
	}
	else 
	{
		userNameCorrect = false;
	}
	fflush(stdin);
	xxx:
		
	string phone;
	cout<< "\n\n\t\t\tPlease enter Phone number (xxxx-xxxxxxx) : ";
	cin>>phone;
	if(phone[4] != '-')
		goto xxx;
	if(phone.length() != 12)
		goto xxx;
	fflush(stdin);
	xxy:
	cout<< "\n\n\t\t\tPlease enter your Passport No. (xxxxxxxxx): ";
	getline(cin , pp);
	if (pp.length() != 9)
		goto xxy;
	fflush(stdin);
	xxz:	
	cout<<"\n\n\t\t\tPlease enter Your CNIC (xxxxx-xxxxxxxxx-x) : ";
	getline(cin ,cnic );
	if(cnic[5] != '-')
		goto xxz;
	if(cnic[15] != '-')
		goto xxz;
	if (cnic.length() != 17)
		goto xxz;
	
	
	fflush(stdin);
	cout << "\n\n\t\t\tPlease enter a valid Email ID: ";
start:
	getline(cin, Email);
	int addretNo, dotNo;
	bool emailCorrect = false;
	for (int i = 0; i <= Email.length(); i++) 
	{
		if (Email[i] == ' ')
		{
			emailCorrect = false;
			break;
		}
		else 
		{
			emailCorrect = true;
			continue;
		}
	}
	if (emailCorrect == false) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tSpace is not allowed in e-mail.\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) 
	{
		emailCorrect == false;
	}
	for (int i = 0; i < Email.length(); i++) 
	{
		if (Email[i] >= 'a' && Email[i] <= 'z' || Email[i] >= 'A' && Email[i] <= 'Z' || Email[i] >= '0' && Email[i] <= '9' || Email[i] == '@' || Email[i] == '.' || Email[i] == '_' || Email[i] == '-') 
		{
			emailCorrect = true;
			continue;
		}
		else 
		{
			emailCorrect = false;
			break;
		}
	}
	if (emailCorrect == false) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tSpecial characters are not allowed! You can only use \'-\' and \'_\'\n";
		cout << "\n\n\t\t\tPlease Re-enter Your Email:\t";
		goto start;
	}
	else if (emailCorrect == true)
	{
		emailCorrect = false;
	}
	for (int i = 0; i <= Email.length(); i++) 
	{
		if (Email[i] == '@') 
		{
			emailCorrect = true;
			addretNo = i;
			break;
		}
		else 
		{
			emailCorrect = false;
			continue;
		}
	}
	if (emailCorrect == false) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYour email is invalid! \'@\' is must in an E-mail Address.\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) 
	{
		emailCorrect == false;
	}
	int myCounVar = 0;
	for (int i = 0; i <= Email.length(); i++) 
	{
		if (Email[i] == '@') 
		{
			break;
		}
		else 
		{
			myCounVar = myCounVar + 1;
		}
	}
	if (myCounVar++ <= 2) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYou must have at least three characters in your E-mail before \'@\'.\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) 
	{
		emailCorrect == false;
	}
	for (int i = addretNo + 1; i <= Email.length(); i++) 
	{
		if (Email[i] == '@') 
		{
			emailCorrect = true;
			break;
		}
		else 
		{
			emailCorrect = false;
			continue;
		}
	}
	if (emailCorrect == true) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYour email is invalid! You cannot use more than one \'@\'.\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		emailCorrect == false;
		goto start;
	}
	dotNo = 0;
	for (int i = 0; i <= Email.length(); i++) 
	{
		if (Email[i] == '.') 
		{
			emailCorrect = true;
			dotNo = i;
			break;
		}
		else 
		{
			emailCorrect = false;
			continue;
		}
	}
	if (emailCorrect == false) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYou havent follow the email rules \'.\' is must!\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true)
	{
		emailCorrect == false;
	}
	for (int i = dotNo + 1; i <= Email.length(); i++) 
	{
		if (Email[i] == '.') 
		{
			emailCorrect = false;
			break;
		}
		else 
		{
			emailCorrect = true;
			continue;
		}
	}
	if (emailCorrect == false) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYou cannot use more than one \'.\'!\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) 
	{
		emailCorrect == false;
	}
	int count = 0;
	for (int i = addretNo + 1; i < dotNo; i++) 
	{
		count = count + 1;
	}
	if (count <= 2) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tyou must have atleast three characters after \'@\'!\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		emailCorrect = false;
		goto start;
	}
	int anotherCount = 0;
	for (int i = dotNo + 1; i <= Email.length(); i++) 
	{
		anotherCount++;
	}
	if (anotherCount <= 2) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYour E-mail must have an high level definition of domain having at least \'3\' characters\n";
		cout << "\n\n\t\t\ttPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (anotherCount >= 6) 
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\tYour E-mail must have an high level definition of domain having at max \'5\' characters\n";
		cout << "\n\n\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	check6:
	cout << "\n\n\t\t\tPlease enter the password that you will use to login: ";
	for (int i = 0; i > -1; i++)
	{
		char temp;
		temp = _getch();
		if (temp != 13 && temp != 8)
		{
			_putch('*');
		}
		if (temp == 13)
		{
			break;
		}
		if (temp == 8 || temp == 127 && !Pass.empty())
		{
			cout << "\b \b";
			Pass.erase(Pass.size() - 1);
		}
		else
			Pass += temp;
	}
	cout << "\n\n\t\t\tPlease enter your password again for confirmation: ";
	for (int i = 0; i > -1; i++)
	{
		char temp;
		temp = _getch();
		if (temp != 13 && temp != 8)
		{
			_putch('*');
		}
		if (temp == 13)
		{
			break;
		}
		if (temp == 8 || temp == 127 && !ConPass.empty())
		{
			cout << "\b \b";
			ConPass.erase(ConPass.size() - 1);
		}
		else
			ConPass += temp;
	}
	cout << "\n\n";
	if (Pass != ConPass)
	{
		cout << "\n\n\t\t\tPassword do not match, please try again! ";
		Pass = "";
		ConPass = "";
		goto check6;
	}
	else
	{
		cout << "\n\n\t\t\tRegistration successful! \n";
		file << Email << "|" << Pass << "|" << Username << "|" << cnic << "|" << phone <<"|" << pp <<"|" <<"\n";
		file.close();
		cout << "\n\n\t\t\tLoading"; Sleep(200);
		cout << "."; Sleep(200);
		cout << "."; Sleep(400);
		cout << "."; Sleep(200);
		cout << "."; Sleep(200);
		cout << "."; Sleep(200);
		Sleep(1000);
		Customer_login();
	}
}
void Display_Admin()
{
	char choice;
	do
	{
		system("cls");
		cout<<"Welcome Administrator!!";
		cout<<"\n\n";
		system("color 11");
		cout << "\n\n\t\t\t         Airline Ticket Management System\n";
		cout << "\n\n\t\t\t       ============= MAIN MENU =============\n";
		cout << "\n\n\t\t\t       01. Create New Flight.\n";
		cout << "\n\n\t\t\t       02. Delete Flight.\n";
		cout << "\n\n\t\t\t       03. Update Flight.\n";
		cout << "\n\n\t\t\t       04. Print/Display Booked Ticket.\n";
		cout << "\n\n\t\t\t       05. Exit.\n";
		cout << "\n\n\t\t\t       Select Your Option (1 - 5): ";
		cin >> choice;
		system("cls");
		if (choice == '1')
		{
			addFlight();
		}
		else if (choice == '2')
		{
			DeleteFlight();
		}
		else if (choice == '3')
		{
			updateFlight();
		}
		else if (choice == '4')
		{
			for(int i =0 ; i<14 ; i++)
			{
				for (int j = i+1 ; j<14 ; j++)
				{
					printAllPaths( adjMatrixCost , i , j);
				}
			}
		}
		else if (choice == '5')
		{
			cout << "\n\n\t\t\t\t\t\t\t\tThe program will now exit!";
			cout << "\n\n\t\t\t\t\t\t\t\t";
			break;
		}	

	} while (choice != '5');
}

void searchFlight()
{
    int i, j, l = 0;
    int source, destination;
    do
    {
        cout << " * Enter source city : " <<endl;
        for (i = 0; i < 14; i++)
        {
            for (j = i; j < i + 3; j++)
            {
                cout<<"    ";
                if (j <= 13)
                {
                    cout <<"Press " << j + 1 << "." << cities[j] << "\t\t";
                }
                
                else
                {
                    break;
                }
            }
            
            i = j - 1;
            cout << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> source;
        source--;
        if (source < 0 || source > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> destination;
        destination--;
        if (destination < 0 || destination > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        if (destination == source)
        {
            cout << "PLEASE ENTER A VALID DESTINATION OTHER THAN THE SOURCE" << endl;
        }
        system("cls");
    } while ((source < 0 || source > 14 || destination < 0 || destination >= 14) || destination == source);

    cout << "       Searching all flights ";
    for(int wait=0;wait<5;wait++)
    {
        cout<<"./";
        Sleep(500);
    }
    cout<<"\n\n";
    cout<<setw(55)<<"~ FLIGHT TABLE ~\n";
    line();
    cout<<setw(5)<<"FlightNo"<<setw(15)<<"Time"<<setw(25)<<"Cost of ticket"
     <<setw(20)<<"Route"<<endl;
    line();
    printAllPaths(adjMatrixCost, source, destination);
    cout<<"+------------------------------------+"<<endl;
    cout<<"| The most time efficient route is : | ";
    dijkstra(adjMatrixTime, source, destination);
    cout<<"+------------------------------------+"<<endl;

    cout<<"+-------------------------------------+"<<endl;
    cout<<"| The most pocket friendly route is : | ";
    dijkstra(adjMatrixCost, source, destination);
    cout<<"+-------------------------------------+"<<endl;
    Sleep(3000);
}

void printAllPaths(int adj[14][14], int s, int d)
{

    for (int i = 0; i < 14; i++)
        visited[i] = 0;
    Sleep(1000);
    printAllPathsUntil(adj, s, d);
}

void display(string id)
{	
	string email, source, dest, date;
	system("cls");
	int count = 0;
	int delimit = 0;
	file.open("Bookings.txt");
	string line;
	while (getline(file, line)) //dynamic 
	{
		count++;
	}
	cout << count;
	file.close();
	bool flag =  false;
	file.open("Bookings.txt");
	for (int j = 0; j < count; j++) //dynamic needed here
	{
		email = "", source = "", dest = "", date = "";
		string line;
		getline(file, line);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			email += temp;
		}
		
		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			source += temp;
		}
		
		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			dest += temp;
		}
		
		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			date += temp;
		}
		
		cout << email << source << dest << date;
		cin >> source;
		
		if(email == id)
		{
			flag = true;
			cout<<setw(45)<<"~ BOOKED TICKETS ~\n";
	        line2();
	        cout<<setw(5)<<"Date"<<setw(15)<<"Name"<<setw(20)<<"Route"<<endl;
	        line2();
			cout<<setw(5)<< source <<setw(20)<<dest<<setw(15)<<date<<endl;
			sleep(3);
		}
	}

        if(flag == false)
        cout << "  * Oops! No tickets booked till now !" << endl;
}

void Delete()
{
    int id;
    cout <<" ~ Welcome aboard Flier ! ~" << endl;
    cout << " * Enter ticket id to be canceled :";
    cin >> id;
    struct node *p = booked, *q;
    while (p != NULL)
    {
        q = p;
        if (p->ticket_id == id)
        {
            if (p == booked)
            {
                booked = booked->next;
                delete p;
                cout << "   The given ticket was canceled ! " << endl;
                cout<<"    *Thank You "<<endl;
                return;
            }
            else
            {
                q->next = p->next;
                cout << "   The given ticket was canceled ! " << endl;
                cout<<"    *Thank You "<<endl;
                delete p;
                return;
            }
        }
    }
    cout << "   --> No such ticket with the given id found ! " << endl;
}

void book(string id, string password, int def, int fno)
{
	int i, j, l = 0;
    int source, destination;
    do
    {
        cout << " * Enter source city : " <<endl;
        for (i = 0; i < 14; i++)
        {
            for (j = i; j < i + 3; j++)
            {
                cout<<"    ";
                if (j <= 13)
                {
                    cout <<"Press " << j + 1 << "." << cities[j] << "\t\t";
                }
                
                else
                {
                    break;
                }
            }
            
            i = j - 1;
            cout << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> source;
        source--;
        if (source < 0 || source > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        cout << "Enter your choice : ";
        cin >> destination;
        destination--;
        if (destination < 0 || destination > 14)
        {
            cout << "PLEASE ENTER A VALID OPTION" << endl;
        }
        
        if (destination == source)
        {
            cout << "PLEASE ENTER A VALID DESTINATION OTHER THAN THE SOURCE" << endl;
        }
        system("cls");
    } while ((source < 0 || source > 14 || destination < 0 || destination >= 14) || destination == source);
    Sleep(1000);
    if(!adjMatrixSeats[source][destination])
    {
    	cout << "NO SEATS AVAILABLE!!" << endl;
    	return;
	}
	Sleep(1000);
    string name, pass, age, date;
    struct node *t, *p;
    time_t now = time(0);
    cout << " ~ Welcome aboard Flier ! ~" << endl;
    cout << " * Enter your name: ";
    cin >> name;
    fflush(stdin);
    cout << " * Enter passport id: ";
    cin >> pass;
    fflush(stdin);
    cout << " * Enter your age : ";
    cin >> age;
    cout << " * Enter date of travel (dd/mm/yyyy): ";
    cin >> date;
    string s= cities[source], d = cities[destination];
    adjMatrixSeats[source][destination]--;
    cout << " * Enter flight No : ";
    cin >> fno;
    fflush(stdin);
        t = new node;
        t->s = s;
        t->d = d;
        t->name = name;
        t->age = age;
        t->date = date;
        t->pass = pass;
        t->ticket_id = now;
        t->next = NULL;
        booked = t;
        cout<<"Booking your flight ";
        for(int wait=0;wait<5;wait++)
        {
	        cout<<"..";
	        Sleep(500);
        }
        cout <<endl<< "   Your seat is booked for flight " << fno << " from " << s << " to " << d << " with TicketId " << now << " on " << date <<"." <<endl;
        cout << "   Thank you !!" << endl;
        cout<<endl;
    
    ofstream fout;
    fout.open("Bookings.txt" , ios::app); fout<<endl;
    fout << id << "|" << s << "|"  << d << "|" << date << "|";
    fout.close();
}

void intro() 
{
	cout << endl << endl << endl << endl << "\t\t\t\t\t"; Sleep(900);
	cout << "\n\t\t\t\t\t\t\t  |||||||||      ||||    	|||||||||       ||||||||||  "; Sleep(200);
	cout << "\n\t\t\t\t\t\t\t  |||  		||  ||    	||||            ||||||||||  "; Sleep(200);
	cout << "\n\t\t\t\t\t\t\t  |||||||||    |||  |||   	|||||||||  	   ||||  "; Sleep(200);
	cout << "\n\t\t\t\t\t\t\t  |||         ||||||||||  	|||||||||   	   ||||  "; Sleep(200);
	cout << "\n\t\t\t\t\t\t\t  |||        |||      |||   	     ||||          |||| "; Sleep(200);
	cout << "\n\t\t\t\t\t\t\t  |||  	    ||||      ||||      |||||||||         ||||||"; Sleep(200);
	cout << endl << endl << "\t\t\t"; Sleep(300);
	cout << "\n\t\t\t\t\t         ||||       ||||||| ||||||||||  ||||      ||||||| ||||||||||  |||| |||||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t        ||  ||      ||||||| |||    |||  ||||      ||||||| ||||  ||||  |||| |||| "; Sleep(200);
	cout << "\n\t\t\t\t\t       |||  |||       |||   ||||||||||  ||||        |||   ||||  ||||  |||| ||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t      ||||||||||      |||   |||||||     ||||        |||   ||||  ||||  |||| ||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t     |||      |||   ||||||| ||| ||||    ||||||||| ||||||| ||||  ||||  |||| |||| "; Sleep(200);
	cout << "\n\t\t\t\t\t    ||||      ||||  ||||||| |||  |||||  ||||||||| ||||||| ||||  |||||||||| ||||||||||"; Sleep(200);
	cout << endl << endl << "\t\t\t"; Sleep(300);
	cout << "\n\t\t\t        |||||||||| ||||||| ||||||||| ||||  |||| ||||||||||  ||||||||| |||||||||| ||||||||||  |||| |||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t        |||||||||| ||||||| ||||||||| |||| |||   ||||        ||||||||| |||||||||| ||||  ||||  |||| ||||       ||||"; Sleep(200);
	cout << "\n\t\t\t           ||||      |||   |||       |||||||    |||||||     |||          ||||    ||||  ||||  |||| ||||           "; Sleep(200);
	cout << "\n\t\t\t           ||||      |||   |||       |||||||    |||||||     |||          ||||    ||||  ||||  |||| ||||  |||||||||"; Sleep(200);
	cout << "\n\t\t\t           ||||    ||||||| ||||||||| |||| |||   ||||        |||||||||    ||||    ||||  ||||  |||| ||||  |||  ||||"; Sleep(200);
	cout << "\n\t\t\t          ||||||   ||||||| ||||||||| ||||  |||| ||||||||||  |||||||||   ||||||   ||||  |||||||||| |||||||||  ||||"; Sleep(200);
	cout << endl << endl << "\t\t\t\t\t"; Sleep(300);
	cout << "\n\t\t\t\t\t         ||||||||| ||||   |||| ||||||||| |||||||||| ||||||||||  ||||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||      ||||   |||| ||||      |||||||||| ||||        ||||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||||||| ||||||||||| |||||||||    ||||    |||||||     ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         |||||||||        |||| |||||||||    ||||    |||||||     ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t              |||| ||||   ||||      ||||    ||||    ||||        ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||||||| ||||||||||| |||||||||   ||||||   ||||||||||  ||||  ||||  ||||"; Sleep(200);
	cout << endl << endl << endl << endl << endl << "\t\t\t\t\t\t\t"; Sleep(100);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\tProject Prepared by:"; Sleep(400);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t--------------------"; Sleep(100);
	cout << "\n\n\t\t\t\t\t\t\t\t  Qussai Ezzy       21K-4866"; Sleep(100);
	cout << "\n\n\t\t\t\t\t\t\t\t  Muhammad Mushtaq  21K-3273"; Sleep(100);
	cout << "\n\n\t\t\t\t\t\t\t\t  Abbas Mustafa     21K-3271"; 
	Sleep(350);
	system("cls");
}

void line()
{
    for(int i=1;i<70;i++)
        cout<<"--";
    cout<<"+";
    cout<<"\n";
}
void line2()
{
    for(int i=1;i<50;i++)
        cout<<"--";
    cout<<"+";
    cout<<"\n";
}

void dijkstra(int adjMatrix[14][14], int startVertex, int destination)
{
    int V = 14;
    int source = startVertex,  i;
    
    vector<vector<int>> paths(14);
    
    int prev[14] = {0};
    int distance[V];
    int visited[V];
    
    for (i = 0; i < V; i++)
    {
        if (adjMatrix[startVertex][i] != 0)
        {
			distance[i] = adjMatrix[startVertex][i];
            prev[i]=source;
        }
        
        else
            distance[i] = I;
        	visited[i] = 0;
    }
    
    distance[startVertex] = 0;
    visited[startVertex] = 1;
    prev[source] = -1;
    
    while (getLoop(visited))
    {
        startVertex = getMinDist(distance, visited);
        visited[startVertex] = 1;

        for (i = 0; i < V; i++)
        {
            if (i == startVertex || i == source)
                continue;
                
            if (adjMatrix[startVertex][i] != 0 && visited[i] == 0)
            {
                if (distance[startVertex] + adjMatrix[startVertex][i] < distance[i])
                {
                    distance[i] = distance[startVertex] + adjMatrix[startVertex][i];
                    prev[i] = startVertex;
                }
            }
        }
    }
    
    for (i = 0; i < V; i++)
    {
        paths[i].push_back(i);
        if(i!=source)
        {
	        int d = prev[i];
	        while (d != -1)
	        {
	            paths[i].push_back(d);
	            d = prev[d];
	        }
        }
    }
    
    i = destination;
    int u = paths[i].size() - 1, flag = 0;
    cout << cities[paths[i][u]];
    
    for (u = paths[i].size() - 2; u >= 0; u--)
    {
        flag = 1;
        cout << " -> " << cities[paths[i][u]];
    }
    
    if (!flag)
    {
        cout << "No flights available.";
    }
    
    cout << endl;
}


void Display_Customer(string id,string pass)
{
	ifstream obj("adjMatrixTime.txt", ios::in);
	if ( !obj )
	{
		cout << "adjMatrixTime.txt " << " failed to open\n";
	}
	
	else
	{	
	    bool empty = ( obj.get(), obj.eof() );
	    if(empty != 0)
	    {
	    	for(int i = 0; i < 14; i++)
			{
				for(int j = 0; j < 14; j++)
				{
					obj >> adjMatrixTime[i][j]; 
				}
			}
		}
		obj.close();
	}
	
	obj.open("adjMatrixCost.txt", ios::in);
	if( !obj )
	{
		cout << "adjMatrixCost.txt " << " failed to open\n";
		
	}
	
	else
	{
		bool empty = ( obj.get(), obj.eof() );
    if(empty != 0)
    {
    	for(int i = 0; i < 14; i++)
		{
			for(int j = 0; j < 14; j++)
			{
				obj >> adjMatrixCost[i][j]; 
			}
		}
	}
	}
		
	obj.close();
	
	obj.open("adjMatrixSeats.txt", ios::in);
	if( !obj )
	{
		cout << "adjMatrixSeats.txt " << " failed to open\n";
	}
	
	bool empty = ( obj.get(), obj.eof() );
    if(empty != 0)
    {
    	for(int i = 0; i < 14; i++)
		{
			for(int j = 0; j < 14; j++)
			{
				obj >> adjMatrixSeats[i][j]; 
			}
		}
	}
	
	string name, login_email, login_pw;
	int count = 0;
	int delimit = 0;
	file.open("Login_Details.txt");
	string line;
	while (getline(file, line)) //dynamic 
	{
		count++;
	}
	file.close();
	file.open("Login_Details.txt");
	for (int j = 0; j < count; j++) //dynamic needed here
	{
		name = "", login_pw = "", login_email = "";
		string line;
		getline(file, line);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			name += temp;
		}
		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			login_pw += temp;
		}
		if(id == name && login_pw == pass)
		{
			name = id;
			break;
		}
	}
	
	char choice;
	do
	{
		system("cls");
		cout<<"\t\t\t\tWelcome " << name <<"!!";
		cout<<"\n\n";
		system("color 11");
		cout << "\n\n\t\t\t         Airline Ticket Management System\n";
		cout << "\n\n\t\t\t       ============= MAIN MENU =============\n";
		cout << "\n\n\t\t\t       01. Search Flight.\n";
		cout << "\n\n\t\t\t       02. Book Flight.\n";
		cout << "\n\n\t\t\t       03. Cancel Flight.\n";
		cout << "\n\n\t\t\t       04. View your Bookings.\n";
		cout << "\n\n\t\t\t       05. Exit.\n";
		cout << "\n\n\t\t\t       Select Your Option (1 - 5): ";
		cin >> choice;
		system("cls");
		if (choice == '1')
		{
			searchFlight();
		}
		else if (choice == '2')
		{
			book(id, pass, 0 , 0);
		}
		else if (choice == '3')
		{
			Delete();
		}
		else if (choice == '4')
		{
			display(id);
			sleep(5);
		}
		else if (choice == '5')
		{
			cout << "\n\n\t\t\t\t\t\t\t\tThe program will now exit!";
			cout << "\n\n\t\t\t\t\t\t\t\t";
			break;
		}	

	} while (choice != '5');
	
	 cout<<"\t\t\t\t Exiting ";
    for(int wait=0;wait<5;wait++)
    {
        cout<<"..";
        Sleep(50);
    }  
    ofstream OBJ("adjMatrixTime.txt", ios::out);
	for(int i = 0; i < 14; i++)
	{
		for(int j = 0; j < 14; j++)
		{
			OBJ << adjMatrixTime[i][j] << " "; 
		}
		OBJ << endl;
	}
	
	OBJ.close();
	
	OBJ.open("adjMatrixCost.txt", ios::out);
	for(int i = 0; i < 14; i++)
	{
		for(int j = 0; j < 14; j++)
		{
			OBJ << adjMatrixCost[i][j] << " "; 
		}
		OBJ << endl;
	}
	
	OBJ.close();
    
    OBJ.open("adjMatrixSeats.txt", ios::out);
	for(int i = 0; i < 14; i++)
	{
		for(int j = 0; j < 14; j++)
		{
			OBJ << adjMatrixSeats[i][j] << " "; 
		}
		OBJ << endl;
	}
	
	OBJ.close();
	
    cout<<"\n\t\t\t\t Thank You, Have a Nice day ! :D"<<endl;
}

void Customer_login()
{
	bool flag =0;
cout << "\n\n\t\t\t\t\t\t\t\t    ===================== LOGIN ===================== \n\n";
	string user, pass;
	check:
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Username: ";
	fflush(stdin);
	getline(cin, user);
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Password: ";
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = _getch();
			if (temp != 13 && temp != 8)
			{
				_putch('*');
			}
			if (temp == 13)
			{
				break;
			}
			if (temp == 8 || temp == 127 && !pass.empty())
			{
				cout << "\b \b";
				pass.erase(pass.size() - 1);
			}
			else
				pass += temp;
		}
		cout << "\n";
			
	string name, login_email, login_pw;
	system("cls");
	int count = 0;
	int delimit = 0;
	file.open("Login_Details.txt");
	string line;
	while (getline(file, line)) //dynamic 
	{
		count++;
	}
	file.close();
	file.open("Login_Details.txt");
	for (int j = 0; j < count; j++) //dynamic needed here
	{
		name = "", login_pw = "", login_email = "";
		string line;
		getline(file, line);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			name += temp;
		}
		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '|')
			{
				delimit = i;
				break;
			}
			login_pw += temp;
		}
		if(user == name && login_pw == pass)
		{
			flag = 1;
			cout << "\n\n\t\t\tLogged in! \n";
			cout << "\n\n\t\t\t\tLoading"; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(400);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			Sleep(200);
			file.close();
			Display_Customer(user,pass);
		}
		
	}	
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\t\tInvalid login credentials, please try again! \n";
		user = "";
		pass = "";
		file.close();
		goto check;
}
void Admin_login()
{
	string name = "Legend";
	string login_pw = "Jatt";
	cout << "\n\n\t\t\t\t\t\t\t\t    ===================== LOGIN ===================== \n\n";
	string user, pass;
	check:
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Username: ";
	fflush(stdin);
	getline(cin, user);
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Password: ";
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = _getch();
			if (temp != 13 && temp != 8)
			{
				_putch('*');
			}
			if (temp == 13)
			{
				break;
			}
			if (temp == 8 || temp == 127 && !pass.empty())
			{
				cout << "\b \b";
				pass.erase(pass.size() - 1);
			}
			else
				pass += temp;
		}
		cout << "\n";	
		if(user == name && login_pw == pass)
		{
			system("cls");
			cout << "\n\n\t\t\tLogged in! \n";
			cout << "\n\n\t\t\t\tLoading"; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(400);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			Sleep(200);
			Display_Admin();
			exit(1);
		}		
			Beep(1000, 600);
			cout << "\n\n\t\t\t\t\t\t\t\tInvalid login credentials, please try again! \n";
			user = "";
			pass = "";
			file.close();
			goto check;
}
void Main_menu()
{
	int choice;
	do
	{
		x:
		gotoxy(45,1); cout<<"------------------------------"<<endl;
	    gotoxy(45,2); cout<<"| AIRLINE RESERVATION SYSTEM |"<<endl;
	    gotoxy(45,3); cout<<"------------------------------"<<endl;
		gotoxy(0,5); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"1. Register a Customer\n2. Customer Login\n3. Administrator Login\nOption :- ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Register_customer();
				break;
			case 2:
				Customer_login();
				break;
			case 3:
				Admin_login();
			default:
				cout << "ENTER VALID CHOICE!!";
				system("cls");
				goto x; 
		}
	system("cls");
	} while(choice!=4);
}

int main()
{
	//intro();
	Main_menu();
	return 0;
}
