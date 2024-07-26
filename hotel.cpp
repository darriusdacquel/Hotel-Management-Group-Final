#include <iostream>
#include <string>

using namespace std;

// Define MAX_ROOMS and MAX_CUSTOMERS for array sizes
const int MAX_ROOMS = 100;
const int MAX_CUSTOMERS = 100;

class Customer {
private:
    std::string bookingID;
    std::string customerName;
    std::string address;
    std::string phoneNumber;
    double advancePayment;
    std::string checkInDate;
    std::string checkOutDate;
    int roomNumber;

public:
    // Default constructor
    Customer() {
        bookingID = "";
        customerName = "";
        address = "";
        phoneNumber = "";
        advancePayment = 0.0;
        checkInDate = "";
        checkOutDate = "";
        roomNumber = 0;
    }

    // Parameterized constructor
    Customer(std::string newID, std::string newCustomerName, std::string newAddress,
             std::string newPhoneNumber, double newAdvancePayment, std::string newCheckInDate,
             std::string newCheckOutDate, int newRoomNumber) {
        bookingID = newID;
        customerName = newCustomerName;
        address = newAddress;
        phoneNumber = newPhoneNumber;
        advancePayment = newAdvancePayment;
        checkInDate = newCheckInDate;
        checkOutDate = newCheckOutDate;
        roomNumber = newRoomNumber;
    }

    // Getter methods
    std::string getBookingID() const { return bookingID; }
    std::string getName() const { return customerName; }
    std::string getPhone() const { return phoneNumber; }
    std::string getAddress() const { return address; }
    int getRoomNumber() const { return roomNumber; }
    std::string getCheckInDate() const { return checkInDate; }
    std::string getCheckOutDate() const { return checkOutDate; }
    double getAdvancePayment() const { return advancePayment; }

    // Setter methods
    void setBookingID(std::string newID) { bookingID = newID; }
    void setName(std::string newName) { customerName = newName; }
    void setPhone(std::string newPhone) { phoneNumber = newPhone; }
    void setAddress(std::string newAddress) { address = newAddress; }
    void setRoomNumber(int newRoomNumber) { roomNumber = newRoomNumber; }
    void setCheckInDate(std::string newCheckInDate) { checkInDate = newCheckInDate; }
    void setCheckOutDate(std::string newCheckOutDate) { checkOutDate = newCheckOutDate; }
    void setAdvancePayment(double newAdvancePayment) { advancePayment = newAdvancePayment; }
};

class Room {
private:
    int roomNum;
    std::string acTemp;
    std::string comfort;
    std::string size;
    int rate;
    bool avail;

public:
    // Default constructor
    Room() {
        roomNum = 0;
        acTemp = ""; // initializes to empty string
        comfort = "";
        size = "";
        rate = 0;
        avail = true; // default availability is true
    }

    // Setter methods
    void setRoomNum(int n) { roomNum = n; }
    void setAcTemp(std::string t) { acTemp = t; }
    void setComfort(std::string c) { comfort = c; }
    void setSize(std::string s) { size = s; }
    void setRate(int r) { rate = r; }
    void setAvail(bool a) { avail = a; }

    // Getter methods
    int getRoomNum() { return roomNum; }
    std::string getAcTemp() { return acTemp; }
    std::string getComfort() { return comfort; }
    std::string getSize() { return size; }
    int getRate() { return rate; }
    bool getAvail() { return avail; }

    // Display room details
    void displayRoom() {
        std::cout << "Room Details\n" << std::endl;
        std::cout << (avail ? "Room is available" : "Room is not available") << std::endl;
        std::cout << "Room number: " << getRoomNum() << std::endl;
        std::cout << "Type AC/No AC (A/N): " << getAcTemp() << std::endl;
        std::cout << "Type Comfort (S/N): " << getComfort() << std::endl;
        std::cout << "Type Size (B/S): " << getSize() << std::endl;
        std::cout << "Daily Rate: " << getRate() << std::endl;
    }
};

class HotelManagement {
private:
    // Variables to store the number of rooms and customers
    int amtOfRooms;
    int amtOfCustomers;

public:
    int getAmtOfRooms() { return amtOfRooms; }
    int getAmtOfCustomers() { return amtOfCustomers; }

    // Constructor
    HotelManagement() {
        amtOfRooms = 0;
        amtOfCustomers = 0;
    }

    // Add a new room
    Room addRoom(Room rooms[MAX_ROOMS]) {
        Room r;
        std::string temp;
        int itemp = 0;

        if (amtOfRooms >= MAX_ROOMS) {
            std::cout << "No rooms available";
            return r;
        }

        std::cout << "Enter room number: ";
        std::cin >> itemp;

        for (int i = 0; i < amtOfRooms; i++) {
            if (itemp == rooms[i].getRoomNum()) {
                cout << "This room number exists. Enter a new room number." << endl;
                return r; // Return an empty room since the room number already exists
            }
        }
        r.setRoomNum(itemp);

        std::cout << "Type AC/No AC (A/N): ";
        std::cin >> temp;
        while (temp != "A" && temp != "N") {
            std::cout << "Invalid option. Please enter 'A' for AC or 'N' for No AC: ";
            std::cin >> temp;
        }
        r.setAcTemp(temp);

        std::cout << "Type Comfort (S/N): ";
        std::cin >> temp;
        while (temp != "S" && temp != "N") {
            std::cout << "Invalid option. Please enter 'S' for Comfort or 'N' for No Comfort: ";
            std::cin >> temp;
        }
        r.setComfort(temp);

        std::cout << "Type Size (B/S): ";
        std::cin >> temp;
        while (temp != "B" && temp != "S") {
            std::cout << "Invalid option. Please enter 'B' for Big or 'S' for Small: ";
            std::cin >> temp;
        }
        r.setSize(temp);

        std::cout << "Daily rate: ";
        std::cin >> itemp;
        r.setRate(itemp);

        return r;
    }

    // Delete a room
    Room deleteRoom(Room rooms[MAX_ROOMS]) {
        Room tempRoom;
        int roomNum;
        cout << "Enter room number to delete: ";
        cin >> roomNum;

        bool roomFound = false;
        for (int i = 0; i < amtOfRooms; i++) { 
            if (roomNum == rooms[i].getRoomNum()) { 
                tempRoom = rooms[i];

                for (int j = i; j < amtOfRooms - 1; j++) {
                    rooms[j] = rooms[j + 1];
                }
                
                amtOfRooms--;
                cout << "\nRoom Details to Delete\n" << endl;
                cout << "Room Number: " << tempRoom.getRoomNum() << endl;
                cout << "Room with AC/No AC (A/N): " << tempRoom.getAcTemp() << endl;
                cout << "Type of Comfort (S/N): " << tempRoom.getComfort() << endl;
                cout << "Room Size (B/S): " << tempRoom.getSize() << endl;
                cout << "Daily Rate: " << tempRoom.getRate() << endl;
                cout << "Room Deleted Successfully" << endl;

                roomFound = true;
                break;
            }
        }
        if (!roomFound) {
            cout << "Room not found or invalid room number!" << endl;
        }
        return tempRoom;
    }

    // Search for a room
    Room searchRoom(Room rooms[MAX_ROOMS]) {
        Room tempRoom;
        int roomNumber;

        std::cout << "Enter room number: ";
        std::cin >> roomNumber;

        for (int i = 0; i < amtOfRooms; i++) {
            if (roomNumber == rooms[i].getRoomNum()) {
                tempRoom = rooms[i];
                rooms[i].displayRoom();
                return tempRoom;
            }
        }

        std::cout << "Room not found!!!" << std::endl;
        return tempRoom;
    }

    // Manage rooms menu
    void manageRooms(Room rooms[MAX_ROOMS]) {
        int choice2;
        do {
            cout << "### Manage Rooms ###" << endl;
            cout << "1. Add Room" << endl;
            cout << "2. Search Room" << endl;
            cout << "3. Delete Room" << endl;
            cout << "4. Back to Main Menu" << endl;
            cout << "\nEnter Option: ";
            cin >> choice2;

            switch (choice2) {
            case 1: {
                rooms[amtOfRooms] = addRoom(rooms);
                amtOfRooms++;
                break;
            }
            case 2: {
                searchRoom(rooms);
                break;
            }
            case 3: {
                deleteRoom(rooms);
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Invalid output" << endl;
                break;
            }
            }
        } while (choice2 != 4);
    }

    // Check-in customer to a room
    Customer checkInRoom(int RoomNum, std::string bookingID, std::string Name, std::string Address, 
                         std::string PhoneNum, std::string checkIn, std::string checkOut, 
                         double advancePayment, Room rooms[MAX_ROOMS]) {
        Customer c;

        c.setRoomNumber(RoomNum);
        c.setBookingID(bookingID);
        c.setName(Name);
        c.setAddress(Address);
        c.setPhone(PhoneNum);
        c.setCheckInDate(checkIn);
        c.setCheckOutDate(checkOut);
        c.setAdvancePayment(advancePayment);

        amtOfCustomers++;
        return c;
    }

    // Display available rooms
    void roomAvail(Room rooms[MAX_ROOMS]) {
        std::cout << "These room numbers are available " << std::endl;

        int counter = 0;
        for (int i = 0; i < amtOfRooms; i++) {
            if (rooms[i].getAvail()) {
                counter++;
                rooms[i].displayRoom();
                std::cout << std::endl;
            }
        }
        if (counter == 0) {
            cout << "\nNo rooms available" << endl;
        }
    }

    // Search for a customer
    Customer searchCustomer(Customer customers[MAX_CUSTOMERS]) {
        std::string customerName;
        Customer temp;

        std::cout << "Enter Customer Name: ";
        std::cin >> customerName;

        for (int i = 0; i < amtOfCustomers; i++) {
            if (customerName == customers[i].getName()) {
                std::cout << "\nCustomer Name: " << customers[i].getName() << std::endl;
                std::cout << "Room number: " << customers[i].getRoomNumber() << std::endl;
                temp = customers[i];
                break;
            }
        }
        if (temp.getName() == "") {
            std::cout << "Customer not found!!!" << std::endl;
        }

        return temp;
    }

    // Check-out customer from a room
    Customer checkOutRoom(Customer customer[MAX_CUSTOMERS], Room rooms[MAX_ROOMS]) {
        Customer ctemp;
        Room rtemp;
        int numStay;
        int tempRoomNum;

        std::cout << "Enter Room Number: ";
        std::cin >> tempRoomNum;

        for (int i = 0; i <= amtOfCustomers; i++) {
            if (tempRoomNum == customer[i].getRoomNumber()) {
                ctemp = customer[i];
                for (int k = 0; k < amtOfRooms; k++) {
                    if (tempRoomNum == rooms[k].getRoomNum()) {
                        rtemp = rooms[k];
                        break;
                    }
                }
            }
        }

        std::cout << "Enter Number of Days: ";
        std::cin >> numStay;

        std::cout << "######## CheckOut Details ########" << std::endl;
        std::cout << "Total Amount Due: " << rtemp.getRate() * numStay << std::endl;
        std::cout << "Advance Paid: " << ctemp.getAdvancePayment() << std::endl;
        std::cout << "*** Total Payable: " << rtemp.getRate() * numStay - ctemp.getAdvancePayment() << std::endl;

        return ctemp;
    }

    // Display guest summary report
    void guestSummaryReport(Customer customer) {
        if (customer.getAddress() != "" && customer.getPhone() != "") {
            std::cout << "Address (city only): " << customer.getAddress() << std::endl;
            std::cout << "Phone Number: " << customer.getPhone() << std::endl;
            std::cout << endl;
        }
    }
};

int main() {
    HotelManagement hotel;
    int choice;
    int i = 0;
    Room rooms[MAX_ROOMS];
    Customer customers[MAX_CUSTOMERS];

    std::string Name, Address, PhoneNum, bookingID, checkIn, checkOut;
    int RoomNum;
    double advancePayment;

    // Declare variables outside the switch
    Customer remove;
    Customer temp[MAX_CUSTOMERS];
    Customer summary;

    do {
        std::cout << "----------------HOTEL MANAGEMENT----------------\n"
                  << "1. Manage Rooms" << std::endl
                  << "2. Check-In Room" << std::endl
                  << "3. Available Rooms" << std::endl
                  << "4. Search Customer" << std::endl
                  << "5. Check-Out Room" << std::endl
                  << "6. Guest Summary Report" << std::endl
                  << "7. Exit" << std::endl
                  << std::endl
                  << "Enter Option: ";
        std::cin >> choice;

        switch (choice) {
        case 1: // Manage rooms
            hotel.manageRooms(rooms);
            break;
        case 2: // Check in customer
            if (hotel.getAmtOfRooms() == 0) {
                cout << "No rooms exist, please add a room before proceeding." << endl;
                break;
            }

            std::cout << "Enter Room Number: ";
            std::cin >> RoomNum;

            for (int x = 0; x < hotel.getAmtOfRooms(); x++) {
                if (rooms[x].getRoomNum() == RoomNum && rooms[x].getAvail()) {
                    std::cout << "Enter Booking ID: ";
                    std::cin >> bookingID;
                    std::cout << "Enter Name: ";
                    std::cin >> Name;
                    std::cout << "Enter Address(City Only): ";
                    std::cin >> Address;
                    std::cout << "Enter Phone Number: ";
                    std::cin >> PhoneNum;
                    std::cout << "Check in date: ";
                    std::cin >> checkIn;
                    std::cout << "Check out date: ";
                    std::cin >> checkOut;
                    std::cout << "Enter Advance Payment: ";
                    std::cin >> advancePayment;
                    rooms[x].setAvail(false);

                    customers[i] = hotel.checkInRoom(RoomNum, bookingID, Name, Address, PhoneNum, checkIn, checkOut, advancePayment, rooms);
                    i++;

                    std::cout << "Check-In Successfully!" << std::endl;
                    break;
                }
                else if (x == hotel.getAmtOfRooms() - 1) {
                    std::cout << "Room not found or not available!!!" << std::endl;
                }
            }
            break;
        case 3: // Room availability
            hotel.roomAvail(rooms);
            break;
        case 4: // Search customer
            hotel.searchCustomer(customers);
            break;
        case 5: // Check out
            if (i == 0) {
                cout << "No customers exist, please check in a customer before proceeding." << endl;
                break;
            }

            remove = hotel.checkOutRoom(customers, rooms);

            for (int x = 0; x < i; x++) {
                if (customers[x].getRoomNumber() != remove.getRoomNumber()) {
                    temp[x] = customers[x];
                } else {
                    for (int k = 0; k < hotel.getAmtOfRooms(); k++) {
                        if (rooms[k].getRoomNum() == remove.getRoomNumber()) {
                            rooms[k].setAvail(true);
                        }
                    }
                }
            }

            for (int x = 0; x < i; x++) {
                customers[x] = temp[x];
            }
            i--;
            break;
        case 6: // Guest summary report
            summary = hotel.searchCustomer(customers);
            hotel.guestSummaryReport(summary);
            break;
        case 7:
            std::cout << "THANK YOU! FOR USING SOFTWARE" << std::endl;
            break;
        default:
            std::cout << "Invalid Choice. Please try again" << std::endl;
            break;
        }
    } while (choice != 7);

    return 0;
}
