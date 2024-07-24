#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int pcode,employeeid;
float price, dis;
string pname;

class project{
public:


void regismenu();
void login();
void registration();
void menu();
void admin();
void create();
void customer();
void rem();
void modify();
void receipt();
void show();
void display();
void search();
void productmenu();
};


void project::menu()
{
m:
    int choice;
    //string email, password;
    system("cls");
    cout << "\n\t\t\t\t________________________________";
    cout << "\n\t\t\t\t                                ";
    cout << "\n\t\t\t\t      SUPERMARKET MAIN MENU     ";
    cout << "\n\t\t\t\t                                ";
    cout << "\n\t\t\t\t________________________________";
    cout << "\n\t\t\t\t                                \n";

    cout << "\n\t\t\t | 1) ADMINISTRATOR  |";
    cout << "\n\t\t\t |                   |";
    cout << "\n\t\t\t | 2) BUYER/CUSTOMER |";
    cout << "\n\t\t\t |                   |";
    cout << "\n\t\t\t | 3) EXIT           |";
    cout << "\n\t\t\t |                   |";
    cout << "\n\n\t\t Please Select the Option : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
		regismenu();
        break;
    }
    case 2:
    {
        customer();
        break;
    }
    case 3:
        exit(0);

    default:
        cout << "\tInvalid Input Option.\n\tPlease Select from the given Options . ";

    }
    goto m;
}

void project::admin()
{
m:
    int choice;
//    system("cls");
    cout << "\n\n\t\t\t\t  ****ADMINISTRATOR MENU****  \n\n";

    cout << "\n\t\t\t  ******************************** ";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---1) ADD THE PRODUCT ----     |";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---2) MODIFY THE PRODUCT ----  |";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---3) DELETE THE PRODUCT ----  |";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---4) DISPLAY THE PRODUCTS ----|";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---5) SEARCH THE PRODUCTS ---- |";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---6) VIEW PRODUCT MENU ----   |";
    cout << "\n\t\t\t |                                |";
	cout << "\n\t\t\t | ---7) BACK TO MAIN MENU ----   |";

    cout << "\n\t\t\t  ******************************** ";
    cout << "\n\n\t\t Please Select the Option : ";
    cin >> choice;

    switch (choice)
    {

    case 1:
//    	system("cls");
        create();
        break;

    case 2:
//    	system("cls");
        modify();
        break;

    case 3:
//    	system("cls");
        rem();
        break;

    case 4:
//    	system("cls");
        display();
        break;

	case 5:
//		system("cls");
		search();
		break;
	
	case 6 : 
//		system("cls");
		productmenu();
		break;
		
	case 7 : 
//		system("cls");
		menu();
    default:
        cout << "\tInvalid Input Option.\n\tPlease Select from the given Options. ";
    }

    goto m;
}

void project::customer()
{
m:
    int choice;

    cout << "\n\n\t\t\t\t  ****CUSTOMER/BUYER MENU****  \n";

    cout << "\n\t\t\t  ******************************** ";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---1) BUY THE PRODUCT ----     |";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t | ---2) GO BACK ----             |";
    cout << "\n\t\t\t |                                |";
    cout << "\n\t\t\t  ******************************** ";
    cout << "\n\n\t\t Please Select the Option : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
//    	system("cls");
        receipt();
        break;

    case 2:
//    	system("cls");
        menu();
        break;

    default:
        cout << "\tInvalid Input Option.\n\tPlease Select from the given Options. ";
    }
    goto m;
}

void project:: create()
{
m:
    fstream data;
    int code;
    int token = 0;
    float cost, disc;
    string name;

    cout << "\n\n\t\t\t ||||**** ADDING A NEW PRODUCT ****||||\n\n";
    cout << "\t\t Enter the Product Code of your product : ";
    cin >> pcode;
    cout << "\t\t Enter the Name of your Product : ";
    cin >> pname;
    cout << "\t\t Enter the Price of your Product : ";
    cin >> price;
    cout << "\t\t Enter the Discount on the Product : ";
    cin >> dis;

    data.open("record.txt", ios::in);

    if(!data)
    {
        data.open("record.txt", ios::app | ios::out);
        data << "  " << pcode << "  " << pname << "  " << price << "  " << dis << " \n ";
        data.close();
    }
    else
    {
        data >> code >> name >> cost >> disc;
        while (!data.eof())
        {
            if (code == pcode)
            {
                token = token + 1;
            }
            data >> code >> name >> cost >> disc;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("record.txt", ios::app | ios::out);
            data << "  " << pcode << "  " << pname << "  " << price << "  " << dis << " \n ";
            data.close();
        }
    }
    cout << "\n\n\t\t\t !!!! YOUR RECORD IS SUCCESSFULLY INSERTED !!!! ";
}

void project::modify()
{
    fstream data, data1;
    int code, product_key;
    int token = 0;
    float cost, disc;
    string name;

    cout << "\n\n\t\t\t ||||**** MODIFYING AN EXISTING PRODUCT ****||||\n\n";
    cout << "\t\t Enter the Product Code of Product which you want to Modify : ";
    cin >> product_key;

    data.open("record.txt", ios::in);
    if (!data)
    {
        cout << "\n\t\t FILE DOES NOT EXIST .";
    }
    else
    {
        data1.open("record1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (product_key == pcode)
            {
                cout << "\t\t Enter the Product Code of New Product : ";
                cin >> code;
                cout << "\t\t Enter the Name of New Product : ";
                cin >> name;
                cout << "\t\t Enter the Price of New Product : ";
                cin >> cost;
                cout << "\t\t Enter the Discount on the New Product : ";
                cin >> disc;
                data1 << "  " << code << "  " << name << "  " << cost << "  " << disc << "\n";
                cout << "\n\n\t\t\t !!!! YOUR RECORD IS SUCCESSFULLY MODIFIED !!!! ";
                token = token + 1;
            }
            else
            {
                data1 << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("record.txt");
        rename("record1.txt", "record.txt");

        if (token == 0)
        {
            cout << "SORRY !!! RECORD NOT FOUND .";
        }
    }
}

void project::rem()
{
    fstream data, data1;
    int product_key;
    int token = 0;

    cout << "\n\n\t\t\t ||||**** DELETING AN EXISTING PRODUCT ****||||\n\n";
    cout << "\t\t Enter the Product Code of Product which you want to Delete : ";
    cin >> product_key;

    data.open("record.txt", ios::in);

    if (!data)
    {
        cout << "\n\t\t FILE DOES NOT EXIST .";
    }
    else
    {
        data1.open("record1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == product_key)
            {
                cout << "\n\n\t\t\t !!!! YOUR RECORD IS SUCCESSFULLY DELETED !!!! ";
                token = token + 1;
            }
            else
            {
                data1 << "  " << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("record.txt");
        rename("record1.txt", "record.txt");

        if (token == 0)
        {
            cout << "SORRY !!! RECORD NOT FOUND .";
        }
    }
}


void project::receipt()
{
	

    fstream data;
    int arr_code[100];
    int arr_quantity[100];
    int c = 0;
    char choice;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t *************** RECEIPT *****************\n";
    data.open("record.txt", ios::in);
    if (!data)
    {
        cout << "\n\t\t YOUR DATABASE IS EMPTY . ";
    }
    else
    {
        data.close();

        productmenu();
        cout<<endl;
        cout << "\n\t\t\t\t**************************************";
        cout << "\n\t\t\t\t                                      ";
        cout << "\n\t\t\t\t         PLACE YOUR ORDER             ";
        cout << "\n\t\t\t\t                                      ";
        cout << "\n\t\t\t\t**************************************";
        cout << "\n\t\t\t\t                                      ";
        do
        {
        	m:
            cout << "\n\t\t Enter the Product Code : ";
            cin >> arr_code[c];
            cout << "\n\t\t Enter the Quantity of Product : ";
            cin >> arr_quantity[c];
            for (int i = 0; i < c; i++)
            {
                if (arr_code[c] == arr_code[i])
                {
                    cout << "\n\t\t Duplicate Product Code. Please Try Again !!";
                    goto m;
                }
            }
            c++;
            cout << "\n\t\t Do you want to Buy another Product ?\n Press y for Yes and n for No : ";
            cin >> choice;
        } 
		while (choice == 'y' || choice == 'Y');

        cout << "\n\t\t\t\t|********************************|";
        cout << "\n\t\t\t\t|                                |";
        cout << "\n\t\t\t\t|           INVOICE              |";
        cout << "\n\t\t\t\t|                                |";
        cout << "\n\t\t\t\t|********************************|";
		
		cout<<endl<<"\n";
        cout<<"Product No \t Product Name \t Product Quantity \t Product Price \t\t Amount \t Amount with Discount\n";

        for (int x = 0; x <= c; x++)
        {
            data.open("record.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while (!data.eof())
            {
                if (pcode == arr_code[x])
                {
                    amount = price * arr_quantity[x];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t\t"<<arr_quantity[x]<<"\t\t\t"<<price<<"\t\t"<<amount<<"\t\t\t"<<dis;
                }
            
                data>>pcode>>pname>>price>>dis;
            }
             data.close();
        }
        cout <<"\n\n________________________________________________";
    cout <<"\nTotal Amount : " << total;
	cout<<"\n\n\n\t\t\t ^^^Thanks for Successfully Placing Your Order^^^.";

    }
    
    

}

void project::display()
{
m:
fstream data;
cout<<"\n\n\t\t DISPLAY ALL RECORDS !!!! \n";
data.open("record.txt",ios::in);
if(!data)
{
	goto m;
}
data>>pcode>>pname>>price>>dis;
while(!data.eof())
{
	show();
	cout<<"\n\n================================================================\n";
	data>>pcode>>pname>>price>>dis;
}
data.close();
}

void project::show(){
	cout<<"\n\t Product Number of the Product : "<<pcode;
	cout<<"\n\t Name of the Product : "<<pname;
	cout<<"\n\t Price of the Product : "<<price;
	cout<<"\n\t Discount on the Product : "<<dis;
}

void project::search(){
	m:
	fstream data;
	int found=0;
	int pkey;
	cout<<"\n\n\t\t ******** FINDING A SPECIFIC RECORD **********";
	cout<<"\n\t\t Enter the Product Code of the Product which you want to search specifically : ";
	cin>>pkey;
	data.open("record.txt",ios::in);
	if(!data)
	{
		goto m;
	}
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		if(pcode==pkey)
		{
			show();
			found=1;
		}
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
	if(found==0)
	{
		cout<<"\n\t\t RECORD DOES NOT EXIST !!!!";
	}
}

void project::productmenu()
{
	
	fstream data;
	data.open("record.txt",ios::in)	;
	cout<<"\n\n\t\t PRODUCT MENU \n\n";
	cout<<"=====================================================================\n";
	cout<<"\nPRODUCT NO. \t NAME \t\tPRICE\n";
	cout<<"\n====================================================================\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
	 cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
	 data>>pcode>>pname>>price>>dis;	
	}
	data.close();
	}

void project::regismenu(){
	 int op;
 cout<<"\n\t\t\t    ________________________________________________________________    \n";
 cout<<"\n\t\t\t        WELCOME TO LOGIN/REGISTRATION PAGE FOR ADMINISTRATORS           \n";
 cout<<"\n\t\t\t             ------------------MENU------------------                   \n";
 cout<<"                                                                                \n";
 cout<<"\t\t | Please LOGIN / REGISTER  \t\t\n";
 cout<<"\t\t | Press 1 to LOGIN : \t\t\n";
 cout<<"\t\t | Press 2 to REGISTER : \t\t\n";
 cout<<"\t\t | Press 3 to EXIT : \t\t\n";
cout<<endl;
 cout<<"Please select the choice : ";
 cin>>op;
 cout<<endl;
 
 switch(op){
 	case 1: 
	      login();
 	break;
 	case 2:
 		 cout<<"\n\n\t\t\tEnter Your Employee ID for Registration as Administrator : ";
 		 cin>>employeeid;
 		 if(employeeid == 2004 || employeeid == 2005 || employeeid == 2003 || employeeid==2002){
 		 	cout<<"\n\n\t\tYou are Elligible for making an Administrator Account.\n\n";
	      	registration();
	      }
	      else{
	      	cout<<"Invalid Employee ID.";
	      	regismenu();
		  }
	      
 	break;
 	case 3: 
	      cout<<"\t\t\t |-|-|-|  Thank You |-|-|-| \n\n";
 	break;
 	default:  
 	      system("cls");
	      cout<<"Please select from above choice : ";
 	      regismenu();
 	break;
 }
}



void project::login(){
	int count;
	string userid,password,id,pass,name;
//	system("cls");
	cout<<"\t\t\t  Please Enter the EMAIL and PASSWORD  \n\n";
	cout<<"\t\t\t  EMAIL : ";
	cin>>userid;
	cout<<"\t\t\t  PASSWORD : ";
	cin>>password;
	
	ifstream read("data.txt");
	while(read>>name>>id>>pass){
		if(id==userid && pass==password){
			count=1;
//			system("cls");
		}
	}
	read.close();
	if(count==1){
		cout<<"LOGIN Successfully...";
		admin();
	}
	else{
		cout<<"LOGIN ERROR \n Please check your USERNAME and PASSWORD...\n";
		login();
		
	}
	}
	
void project::registration(){
	
	
	string rname,ruserid,rpassword,rid,rpass;
//	system("cls");
	cout<<"\t\t\t Enter your NAME : ";
	cin>>rname;
	cout<<"\t\t\t Enter the EMAIL : ";
	cin>>ruserid;
	cout<<"\t\t\t Enter the PASSWORD : ";
	cin>>rpassword;
   if(rpassword.size()<8){
   	  cout<<"\t\t\n\n  Password must contain 8 Letters...\t\t \n\n";
	  cout<<"\t\t\t Enter the PASSWORD : ";
	  cin>>rpassword;   	  
   }
	
	ofstream f1("data.txt",ios::app);
	f1<<rname<<' '<<ruserid<<' '<<rpassword<<endl;
	system("cls");
	cout<<"\t\t\t Registration is Successfull..\t\t";
	regismenu();
	
}




int main()
{
    project p1;
    p1.menu();
}

