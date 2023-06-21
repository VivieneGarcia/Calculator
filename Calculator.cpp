#include <iostream>
#include <limits>

using namespace std;

int ans;

int add(int n1, int n2)
{
    ans = n1 + n2;
    return ans;
}

int sub(int n1, int n2) 
{
    ans = n1 - n2;
    return ans;
}

int mult(int n1, int n2) 
{
    ans = n1 * n2;
    return ans;
}

int divi(int n1, int n2)
{
    ans = n1 / n2;
    return ans;
}

struct Calcu // structure
{
    int num1;
    int num2;
    char opt;
    int result;
    string eq;
};

void choice_menu()
{
	cout << "--------------------------------------" << endl;
	cout << "  [A]gain?  |  [H]istory?  |  [Q]uit?";
	cout << endl << "--------------------------------------" << endl;
	cout << "Choice: ";
}

void search_menu()
{
	cout << "+--------------+" << endl;
    cout << "|    HISTORY   |" << endl;
    cout << "+--------------+" << endl;
	cout << "[1] Num1" << endl;
	cout << "[2] Num2" << endl;
	cout << "[3] Operators" << endl;
	cout << "[4] Results" << endl;
	cout << "[5] Equations" << endl;
	cout << "+--------------+" << endl;
	cout << "Choice: ";
}

int main() 
{
    const int limit = 10000;
    Calcu All[limit]; // array for structure
    int size = 0;
    string choice;

    do
	{
		system ("CLS");
        cout << "+------------+" << endl;
        cout << "| CALCULATOR |" << endl;
        cout << "+------------+" << endl;
        cout << endl << "Type: ";
        
        cin >> All[size].num1 >> All[size].opt >> All[size].num2;

        while (cin.fail()||All[size].opt != '+' && All[size].opt != '-' && // error handling
               All[size].opt != '*' && All[size].opt != '/') 
		{
            cout << endl << " | Invalid Input";
            
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

            cout << endl << endl;
            cout << "Type: ";
            cin >> All[size].num1 >> All[size].opt >> All[size].num2;
        }

        cout << endl;
        
		bool zero = false;
		
        switch (All[size].opt) { 
            case '+':
                All[size].result = add(All[size].num1, All[size].num2);
                cout << "Result: " << ans;
                break;
            case '-':
                All[size].result = sub(All[size].num1, All[size].num2);
                cout << "Result: " << ans;
                break;
            case '*':
                All[size].result = mult(All[size].num1, All[size].num2);
                cout << "Result: " << ans;
                break;
            case '/':
                if (All[size].num2 == 0)
				{
					cout << "You divided by Zero. It's undefined";
                	zero = true; 
                } 
				else
				{
	                All[size].result = divi(All[size].num1, All[size].num2);
	                cout << "Result: " << ans;
            	}
                break;
            default:
                cout << "Invalid Input." << endl;
                return 0;
        }
        
		if (!zero)
		{
	        All[size].eq = to_string(All[size].num1) + All[size].opt + to_string(All[size].num2) + "=" + to_string(All[size].result);
			size++;
		}
		
		cout << endl << endl;
		choice_menu();
        cin >> choice;
        
        while (choice != "A" && choice != "a" && choice !="H" && choice != "h" && choice != "Q"&& choice != "q") // error handling
		{
			cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            
            cout << endl;
            cout << "| INVALID INPUT |" << endl;
            choice_menu();
	        cin >> choice;
		}
		   		
		if (choice == "Q" || choice == "q")
		{
			cout << endl << "Thank you!" << endl;
			return 0;
		}
        
	   	if (choice == "H" || choice == "h") 
		{
			system ("CLS");
            string find;
            bool repeatSearch = true;
            
            while (repeatSearch) {
            	
            	repeatSearch = false;
            	
	            cout << endl;
	            search_menu();
	            cin >> find;
	            
	            while (find != "1" && find != "2" && find !="3" && find != "4" && find != "5") // error handling
		        {
		            cout << endl << endl;
		            cout << "Invalid Input"<< endl;
		            search_menu();
		            cin >> find;
		   		}
		   		
		   		if (find == "1")
		   		{
		   			system ("CLS");
		   			cout << "------------------" << endl;
	   				cout << "| All Num1 input |" << endl;
	   				cout << "------------------";
		   			for (int i = 0; i < size ; i++)
		   			{
		   				int* num1_ptr = &All[i].num1; // pointer and address (num2)
		   				cout << endl << All[i].num1 << " | " << num1_ptr;
					}
				}
				
				if (find == "2")
		   		{
		   			system ("CLS");
		   			cout << "------------------" << endl;
	   				cout << "| All Num2 input |" << endl;
	   				cout << "------------------";
		   			for (int i = 0; i < size ; i++)
		   			{
		   				int* num2_ptr = &All[i].num2; // pointer and address (num2)
		   				cout << endl << All[i].num2 << " | " << num2_ptr;
					}
				}
				
				if (find == "3")
		   		{
		   			system ("CLS");
		   			cout << "-----------------------" << endl;
	   				cout << "| All Operations Used |" << endl;
	   				cout << "-----------------------";
		   			for (int i = 0; i < size ; i++)
		   			{
		   				char* opt_ptr = &All[i].opt; // pointer and address (operations)
		   				cout << endl << All[i].opt << " | " << opt_ptr;
					}
				}
				
				if (find == "4")
		   		{
		   			system("CLS");
		   			cout << "---------------" << endl;
	   				cout << "| All Results |" << endl;
	   				cout << "---------------";
		   			for (int i = 0; i < size ; i++)
		   			{
		   				int* result_ptr = &All[i].result; // pointer and address (results)
		   				cout << endl << All[i].result<< " | " << result_ptr ;
					}
				}
				if (find == "5")
		   		{
		   			system ("CLS");
		   			cout << "-----------------" << endl;
	   				cout << "| All Equations |" << endl;
	   				cout << "-----------------";
		   			for (int i = 0; i < size ; i++)
		   			{
		   				string *eq_ptr = &All[i].eq; // pointer and address (string equation)
		   				cout << endl << All[i].eq<< " | " << eq_ptr ;
					}
				}
		   		
	            cout << endl << endl;
				choice_menu();
		        cin >> choice;
		        
		        if (choice == "H" || choice == "h") // looping
				{
                    repeatSearch = true;
           		}
			}
        }

    } while (choice == "A" || choice == "a"); // looping

    return 0;
}

