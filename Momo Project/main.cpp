#include <iostream>
#include <ctime>


using namespace std;

int main() {
    const string DEFAULT_PIN = "0000";
    const double DEFAULT_BALANCE = 1000;
    string pin;
    double balance = DEFAULT_BALANCE;
    int attempts = 0;
    int menuSelection;
    double amount;
    string Mobile_number = "number";
    string Confirm_number;
    string newPin;
    string Reference_number;
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string time = asctime(localTime);
    bool isAuthenticated = false;


    // Ask user for pin code
    cout<<"***************** WELCOME TO DOMINIC MOMO PROJECT ****************** "<<endl;
    cout<<endl;
    while(!isAuthenticated && attempts < 3){
    	cout << "Please enter your PIN: ";
    	cin >> pin;

    if(pin == DEFAULT_PIN) {
    isAuthenticated = true;
    }else{
        cout << "Wrong pin, please try again." << endl;
        attempts++;
    }
}

    // Menu is displayed only if user is authenticated
    if(isAuthenticated){
        do{
    cout<<"1.Check balance"<<endl;
    cout<<"2.Send money"<<endl;
    cout<<"3.Change/rest pin"<<endl;
    cout<<"4.Exit"<<endl;

    cout << "Select an option: ";
    cin >> menuSelection;


	 switch(menuSelection){
    // Checking balance
    case 1:
    cout << "Your current balance is $" << balance<<endl;
     cout<<time<<endl;
    break;

    // Sending money
    case 2:
    cout<<"Enter Mobile number: ";
    cin >> Mobile_number;
    cout<<"Confirm number: ";
    cin>>Confirm_number;
    while(Mobile_number.size() != 10){
        cout<<"Invalid Mobile number"<<endl;
        cout<<"Re-enter Mobile number: ";
        cin>>Mobile_number;
        cout<<"Enter Reference number: ";
        cin>>Reference_number;
    }

    cout << "Enter amount to send: ";
    cin >> amount;
    cout<<"Enter Reference number: ";
    cin>>Reference_number;
    if(amount <= balance){
    	cout<<"Transfer Successfully made to "<< Mobile_number <<" Reference No. "<< Reference_number <<endl;
        cout<<time<<endl;
    	balance = balance - amount;
    	cout<<"Current balance is $"<<balance<<endl;
    }

 	else {
    cout << "Insufficient funds." << endl;
    }
    cout << "**************************************"<<endl;
    break;

    // Changing/resetting PIN
    case 3:
    cout << "Enter new PIN: ";
    cin >> newPin;
    for(int i = 0; i < 2; i++){
        if(newPin.size() != 4){
            cout << "Invalid pin" << endl;
            cout << "Re-enter pin: ";
            cin >> newPin;
        } else{
            pin = newPin;
            cout << "Your PIN has been successfully reset." << endl;
            cout << "**************************************"<<endl;
            break;
        }
    }


    // Exiting the program
    case 4:
    cout << "Program Exited..." << endl;
    break;

    // Invalid selection
    default:
    cout << "Invalid selection." << endl;

    }
	  } while (menuSelection != 4);

	  // Exit program if user is not authenticated after 3 attempts
    } else {
        cout << "Too many attempts. Exiting program..." << endl;
    }

    return 0;
}


