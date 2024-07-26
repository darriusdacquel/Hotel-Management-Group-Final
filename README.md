# Hotel Management System

This project is a simple Hotel Management System written in C++. It allows you to manage rooms, check in customers, check out customers, and perform other hotel management tasks.

## Features

- **Manage Rooms**: Add, search, and delete rooms.
- **Check-In Room**: Check in a customer to a room.
- **Available Rooms**: Display a list of available rooms.
- **Search Customer**: Find a customer by name.
- **Check-Out Room**: Check out a customer from a room and calculate the total amount due.
- **Guest Summary Report**: Display a summary report for a customer.

## Classes and Functions

### Customer Class
This class stores details about a customer including booking ID, name, address, phone number, advance payment, check-in date, check-out date, and room number.

### Room Class
The `Room` class stores details about a room including room number, air conditioning type, comfort level, size, rate, and availability.

### HotelManagement Class
The `HotelManagement` class handles the overall management of the hotel including adding rooms, deleting rooms, searching rooms, checking in customers, checking out customers, and generating guest summary reports.

#### Key Functions
- `addRoom`: Adds a new room to the hotel.
- `deleteRoom`: Deletes an existing room from the hotel.
- `searchRoom`: Searches for a room by its number.
- `checkInRoom`: Checks in a customer to a room.
- `checkOutRoom`: Checks out a customer from a room and calculates the total amount due.
- `searchCustomer`: Searches for a customer by name.
- `guestSummaryReport`: Generates a summary report for a customer.
- `manageRooms`: Manages rooms (add, search, delete).

## How to Run

### Prerequisites
- A C++ compiler (e.g., GCC, Clang)
- An IDE or text editor (e.g., Visual Studio Code, Code::Blocks, CLion)

### Steps

1. **Clone the Repository**
   ```sh
   git clone https://github.com/darriusdacquel/Hotel-Management-Group-Final.git
   cd Hotel-Management-Group-Final

2. **Compile the Code**
   Open a terminal or command prompt in the project directory and compile the code using the following command:
   ```sh
   g++ -o hotel_management Hotel.cpp

3. **Run the Program**
   After compiling, run the program with the following command:
   ```sh
   ./hotel_management

4. **Follow the On-Screen Instructions**
   The program will display a menu with various options. Enter the number corresponding to the desired action and follow the prompts.

## Contributions
-- **Darrius**: Implemented the Customer class, searchRoom function, and checkOutRoom function.
- **Yongsheng**: Implemented the `addRoom` function, wrote the `main` function.
- **Josh**: Implemented the `deleteRoom` function, implemented the `manageRooms` function.
- **Jett**: Implemented the `searchCustomer` function, implemented the `roomAvail` function.
- **Yuzu**: Implemented the `guestSummaryReport` function, implemented the `checkInRoom` function.
