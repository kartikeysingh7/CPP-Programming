#include <iostream>
#include <vector>
#include <iomanip>

class Seat {
public:
    int row;
    int seatNumber;
    bool booked;

    Seat(int r, int seat) : row(r), seatNumber(seat), booked(false) {}
};

class Stadium {
private:
    int numRows;
    int numSeatsPerRow;
    std::vector<std::vector<Seat>> seats;

public:
    Stadium(int rows, int seatsPerRow) : numRows(rows), numSeatsPerRow(seatsPerRow) {
        seats.resize(numRows);
        for (int i = 0; i < numRows; ++i) {
            seats[i].reserve(numSeatsPerRow);
            for (int j = 0; j < numSeatsPerRow; ++j) {
                seats[i].emplace_back(i + 1, j + 1);
            }
        }
    }

    void displayAvailableSeats() const {
        std::cout << "Available Seats:\n";
        for (const auto& row : seats) {
            for (const auto& seat : row) {
                if (!seat.booked) {
                    std::cout << "Row " << seat.row << ", Seat " << seat.seatNumber << "\n";
                }
            }
        }
    }

    bool bookSeat(int row, int seatNumber) {
        if (row <= 0 || row > numRows || seatNumber <= 0 || seatNumber > numSeatsPerRow) {
            std::cout << "Invalid seat selection.\n";
            return false;
        }

        Seat& selectedSeat = seats[row - 1][seatNumber - 1];

        if (!selectedSeat.booked) {
            selectedSeat.booked = true;
            std::cout << "Seat booked successfully. Enjoy the game!\n";
            return true;
        } else {
            std::cout << "Sorry, the selected seat is already booked. Please choose another seat.\n";
            return false;
        }
    }
};

int main() {
    const int numRows = 5;
    const int numSeatsPerRow = 10;

    Stadium footballStadium(numRows, numSeatsPerRow);

    int choice;
    do {
        std::cout << "\n1. Display Available Seats\n";
        std::cout << "2. Book a Seat\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                footballStadium.displayAvailableSeats();
                break;
            case 2: {
                int row, seatNumber;
                std::cout << "Enter row number: ";
                std::cin >> row;
                std::cout << "Enter seat number: ";
                std::cin >> seatNumber;
                footballStadium.bookSeat(row, seatNumber);
                break;
            }
            case 3:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
