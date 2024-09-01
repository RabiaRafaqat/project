#include <iostream>
#include <fstream> //For file handling
#include <string>

using namespace std;

// Forward declaration of the mainMenu function
void mainMenu();

// Class to store common customer information
class Detail
{
public:
    static string name, gender;
    int phoneNo;
    int age;
    string add;
    static int cId;
    char arr[100];

    // Function to input customer information
    void information()
    {
        cout << "\nEnter customer ID: ";
        cin >> cId;
        cout << "\nEnter the name: ";
        cin >> name;
        cout << "\nEnter the age: ";
        cin >> age;
        cout << "\nEnter the address: ";
        cin.ignore(); // Ignore newline character left in the buffer
        getline(cin, add);
        cout << "\nGender: ";
        cin >> gender;
        cout << "YOUR DETAILS ARE SAVED WITH US...THANKS FOR COOPERATION!";
    }
};

// Initializing static variables of the Detail class
int Detail::cId;
string Detail::name;
string Detail::gender;

// Class for staff handling
class Staff
{
public:
    string staffName;
    int staffId;
    // Array to store available flights
    string availableFlights[6] = {"Dubai", "Canada", "Uk", "Usa", "Australia", "Qatar"};

    // Function to input staff information
    void staffInformation()
    {
        cout << "\nEnter staff ID: ";
        cin >> staffId;
        cout << "\nEnter the name: ";
         cin.ignore();
        getline(cin, staffName);
        cout << "\nStaff details saved successfully!" << endl;
    }

    // Function to manage flights (new functionality)
    void manageFlights()
    {
        cout << "Available flights: " << endl;
        displayFlights();

        int addNewFlightChoice;
        cout << "Do you want to add a new flight? (1 for yes, 0 for no): ";
        cin >> addNewFlightChoice;

        if (addNewFlightChoice == 1)
        {
            addNewFlight();
            cout << "New flight added successfully!" << endl;
            cout << "Updated available flights: " << endl;
            displayFlights();
        }
        else
        {
            cout << "No new flight added." << endl;
        }
    }

    // Function to display available flights
    void displayFlights()
    {
        for (int i = 0; i < 6; ++i)
        {
            cout << (i + 1) << ". Flight to " << availableFlights[i] << endl;
        }
    }

    // Function to add a new flight
    void addNewFlight()
    {
        string newFlightName;
        cout << "Enter the name of the new flight: ";
        cin.ignore();
        getline(cin, newFlightName);

        // Check if there's space to add a new flight
        if (sizeof(availableFlights) / sizeof(availableFlights[0]) < 6)
        {
            availableFlights[sizeof(availableFlights) / sizeof(availableFlights[0])] = newFlightName;
        }
        else
        {
            cout << "Cannot add more flights. The limit is reached." << endl;
        }
    }
};
// Function to display the staff menu
void staffMenu()
{
    Staff staff;

    int staffChoice;
    int back;

    cout << "\t_STAFF MENU_" << endl;

    cout << "\t_" << endl;
    cout << "\t|\t\t\t\t\t\t|" << endl;
    cout << "\t|\t Press 1 To Add Staff Details.       \t|" << endl;
    cout << "\t|\t Press 2 To Manage Flights.          \t|" << endl;
    cout << "\t|\t Press 3 To Go Back to Main Menu.    \t|" << endl;
    cout << "\t|\t\t\t\t\t\t|" << endl;
    cout << "\t__" << endl;

    cout << "Enter the choice : ";
    cin >> staffChoice;

    // Switch case to handle staff's choice
    switch (staffChoice)
    {
    case 1:
        cout << "Staff Details\n"
             << endl;
        staff.staffInformation();
        cout << "Press any key to go back to the staff menu ";
        cin >> back;
        staffMenu();
        break;

    case 2:
        cout << "Manage Flights\n"
             << endl;
        staff.manageFlights();
        cout << "Press any key to go back to the staff menu: ";
        cin >> back;
        staffMenu();
        break;

    case 3:
        cout << "Going back to the main menu." << endl;
        mainMenu();
        break;

    default:
        cout << "Invalid input, Please try again! \n"
             << endl;
        staffMenu();
    }
}

// Class for flight registration and seat reservation
class Registration
{
public:
    static int choice;
    int choice1;
    int back;
    static float charges;
    int a;

    // Function to get flight details and book a flight
    void flightDetails(string destination, int numFlights, float cost1, float cost2, float cost3)
    {
        cout << "WELCOME TO " << destination << " AIRWAYS" << endl;
        cout << "Your comfort is our priority. Enjoy the Journey!" << endl;

        cout << "Following are the flights \n" << endl;

        // Displaying available flights and their details
        for (int i = 1; i <= numFlights; i++)
        {
            cout << i << ". " << destination << " - " << i << endl;
            cout << "\tDate: " << (i + 7) << "-12-2023  " << (i + 6) << ":00 AM   Duration: " << (i + 3) << "hours   Rs. " << (i * 10000) << endl;
        }

        cout << "\nSelect the flight you want to book : ";
        cin >> choice1;

        // Validating user input for flight selection
        if (choice1 >= 1 && choice1 <= numFlights)
        {
            charges = (choice1 == 1) ? cost1 : ((choice1 == 2) ? cost2 : cost3);
            cout << "\nYou have successfully booked the flight " << destination << " - " << choice1 << endl;
            cout << "You can go to the main menu and collect your ticket" << endl;
        }
        else
        {
            cout << "INVALID INPUT, SHIFTING TO THE PREVIOUS MENU" << endl;
            flight();
        }

        cout << "Press any key to go back to the main menu :";
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }
        else
        {
            mainMenu();
        }
    }

    // Function to display available flights and take user input
   void flight()
    {
        // Access the Staff class to get the available flights
        Staff staff;

        // Displaying the list of available flights
        for (int a = 0; a < 6; a++)
        {
            cout << (a + 1) << ". Flight to " << staff.availableFlights[a] << endl;
        }

        cout << "\nWELCOME TO AIRLINES!" << endl;
        cout << "\n PRESS THE NUMBER OF COUNTRY FOR WHICH YOU WANT TO BOOK A FLIGHT:  " << endl;
        cin >> choice;

        // Switch case to determine the selected destination and call flightDetails
        switch (Registration::choice)
        {
        case 1:
            flightDetails("Dubai", 3, 20000, 14000, 10000);
            break;
        case 2:
            flightDetails("Canada", 3, 34000, 30000, 17000);
            break;
        case 3:
            flightDetails("Uk", 3, 40000, 36000, 34000);
            break;
        case 4:
            flightDetails("Usa", 3, 41000, 45000, 39000);
            break;
        case 5:
            flightDetails("Australia", 3, 25000, 23000, 21000);
            break;
        case 6:
            flightDetails("Qatar", 3, 28000, 25000, 23000);
            break;
        case 7:
            // Handle the case for the newly added flight
            if (staff.availableFlights[6] != "")
            {
                flightDetails(staff.availableFlights[6], 3, 30000, 27000, 25000);
            }
            else
            {
                cout << "INVALID INPUT...RETURNING BACK TO MAIN MENU! " << endl;
            }
            break;
        default:
            cout << "INVALID INPUT...RETURNING BACK TO MAIN MENU! " << endl;
            break;
        }
    }

    // Function to cancel a booked flight
    void cancelFlight()
    {
        cout << "Enter the customer ID to cancel the flight: ";
        int cancelId;
        cin >> cancelId;

        if (cancelId == Detail::cId)
        {
            cout << "Flight canceled successfully for customer ID: " << cancelId << endl;
        }
        else
        {
            cout << "Invalid customer ID. Flight cancellation failed." << endl;
        }
    }

    // Function to reserve a seat (new functionality)
    void reserveSeat()
    {
        cout << "Enter the customer ID to reserve a seat: ";
        int reserveId;
        cin >> reserveId;

        if (reserveId == Detail::cId)
        {
            cout << "Seat reserved successfully for customer ID: " << reserveId << endl;
        }
        else
        {
            cout << "Invalid customer ID. Seat reservation failed." << endl;
        }
    }
};

// Initializing static variables of the Registration class
float Registration::charges;
int Registration::choice;

// Class for tickets, inherits from Registration and Detail
class ticket : public Registration, public Detail
{
public:
    void dispBill()
    {
        ofstream outf("records.txt");

        outf << "XYZ AIRLINES" << endl;
        outf << "_Ticket_" << endl;
        outf << "" << endl;
        outf << "Customer ID:" << Detail::cId << endl;
        outf << "Customer NAME:" << Detail::name << endl;
        outf << "Customer GENDER:" << Detail::gender << endl;
        outf << "\tDescription" << endl
             << endl;

        string destination;
        switch (Registration::choice)
        {
        case 1:
            destination = "Dubai";
            break;
        case 2:
            destination = "Canada";
            break;
        case 3:
            destination = "Uk";
            break;
        case 4:
            destination = "Usa";
            break;
        case 5:
            destination = "Australia";
            break;
        case 6:
            destination = "Qatar";
            break;
        default:
            break;
        }

        outf << "Destination\t\t" << destination << endl;
        outf << "Flight cost:\t\t" << Registration::charges << endl;

        outf.close();
    }

    // Function to display the saved bill from the file
    void displayBill()
    {
        ifstream ifs("records.txt");

        if (!ifs)
        {
            cout << "File Error!" << endl;
        }

        // Displaying the content of the records.txt file
        while (!ifs.eof())
        {
            ifs.getline(arr, 100);
            cout << arr << endl;
        }

        ifs.close();
    }
};


// Function to display the main menu
void mainMenu()
{
    // Creating instances of classes
    Detail d;
    Registration r;
    ticket t;

    int lchoice;
    int back;

     cout << "\n**\n";
    cout << "*           Welcome to QARAR AIRWAYS        *\n";
    cout << "\n";

    cout << "* 1. Add Customer Details                   *\n";
    cout << "* 2. Flight Registration                    *\n";
    cout << "* 3. Ticket and Charges                     *\n";
    cout << "* 4. Cancel a Flight                        *\n";
    cout << "* 5. Reserve a Seat                         *\n";
    cout << "* 6. Access Staff Menu                      *\n";
    cout << "* 7. Exit                                   *\n";

    cout << "\n";

    cout << "Enter the choice : ";
    cin >> lchoice;

    // Switch case to handle user's choice
    switch (lchoice)
    {
    case 1:
        cout << "Customers\n"
             << endl;
        d.information();
        cout << "Press any key to go back to the mainMenu ";
        cin >> back;
        mainMenu();
        break;

    case 2:
        cout << "Book a Flight using this system\n"
             << endl;
        r.flight();
        break;

    case 3:
        cout << "Get your ticket\n"
             << endl;
        t.dispBill();
        cout << "Your ticket is printed, you can collect it \n"
             << endl;
        cout << "Press 1 to display your ticket ";

        cin >> back;

        if (back == 1)
        {
            t.displayBill();
            cout << "Press any key to go back to the main menu: ";
            cin >> back;
            mainMenu();
        }
        else
        {
            mainMenu();
        }
        break;

    case 4:
        cout << "Cancel a Flight\n"
             << endl;
        r.cancelFlight();
        cout << "Press any key to go back to the main menu: ";
        cin >> back;
        mainMenu();
        break;

    case 5:
        cout << "Reserve a Seat\n"
             << endl;
        r.reserveSeat();
        cout << "Press any key to go back to the main menu: ";
        cin >> back;
        mainMenu();
        break;

    case 6:
        cout << "Staff Menu\n"
             << endl;
        staffMenu();
        break;

    case 7:
        cout << "\n\n\t_THANK YOU" << endl;
        break;

    default:
        cout << "Invalid input, Please try again! \n"
             << endl;
        mainMenu();
    }
}

// Entry point of the program
int main()
{
    // Display the main menu
    mainMenu();

    return 0;
}