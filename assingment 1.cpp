
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class ticket {
public:
    string passenger_name;
    int age;
    string gender;
    int seat_number;

    void input() {
        cout << "Enter Name: ";
        getline(cin, passenger_name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Gender: ";
        cin >> gender;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() {
        cout << "Seat No: " << seat_number
             << " | Name: " << passenger_name
             << " | Age: " << age
             << " | Gender: " << gender << endl;
    }
};

int main() {
    const int MAX_TICKETS = 20;
    ticket tickets[MAX_TICKETS];
    int count = 0;

    while (true) {
        cout << "\n===== Railway Reservation System =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Train Status\n";
        cout << "4. View Passenger List\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            return 1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else if (choice == 1) {
            if (count == MAX_TICKETS) {
                cout << "Sorry, booking is full!\n";
                continue;
            }

            // Find the lowest available seat
            int seat = 1;

            while (seat <= MAX_TICKETS) {
                bool booked = false;

                for (int i = 0; i < count; i++) {
                    if (tickets[i].seat_number == seat) {
                        booked = true;
                        break;
                    }
                }

                if (!booked) {
                    break;
                }

                seat++;
            }

            tickets[count].input();
            tickets[count].seat_number = seat;

            cout << "Ticket booked! Seat No "
                 << tickets[count].seat_number << "\n";

            count++;
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "there is no ticket to cancle\n";
                continue;
            }

            int seat;
            cout << "Enter seat number to cancel ";
            cin >> seat;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int index = -1;

            for (int i = 0; i < count; i++) {
                if (tickets[i].seat_number == seat) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "Ticket not found\n";
            }
            else {
                for (int i = index; i < count - 1; i++) {
                    tickets[i] = tickets[i + 1];
                }

                count--;
                cout << "Ticket cancelled \n";
            }
        }
        else if (choice == 3) {
            cout << "\nTrain Status:\n\n";

            for (int seat = 1; seat <= MAX_TICKETS; seat++) {
                bool booked = false;

                for (int i = 0; i < count; i++) {
                    if (tickets[i].seat_number == seat) {
                        booked = true;
                        break;
                    }
                }

                cout << "Seat " << seat << ": "
                     << (booked ? "Booked" : "Available")
                     << endl;
            }
        }
        else if (choice == 4) {
            cout << "\nPassenger List:\n\n";

            if (count == 0) {
                cout << "No passengers booked yet.\n";
            }
            else {
                for (int i = 0; i < count; i++) {
                    tickets[i].display();
                    cout << endl;
                }
            }
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
        if (choice == 5) {
    cout << "Exiting program...\n";
    break;
}
    }

    return 0;
}




