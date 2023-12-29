#include <iostream>
#include <vector>
#include <string>

class Astronaut {
public:
    std::string name;
    int age;
    std::string specialty;

    Astronaut(const std::string& n, int a, const std::string& s)
        : name(n), age(a), specialty(s) {}
};

class Mission {
public:
    std::string name;
    std::string destination;
    int launchYear;
    std::vector<Astronaut> astronauts;

    Mission(const std::string& n, const std::string& d, int year)
        : name(n), destination(d), launchYear(year) {}

    void addAstronaut(const Astronaut& astronaut) {
        astronauts.push_back(astronaut);
    }

    void displayMissionDetails() const {
        std::cout << "Mission: " << name << "\n";
        std::cout << "Destination: " << destination << "\n";
        std::cout << "Launch Year: " << launchYear << "\n";
        std::cout << "Astronauts on board:\n";
        for (const auto& astronaut : astronauts) {
            std::cout << " - " << astronaut.name << ", Age: " << astronaut.age
                      << ", Specialty: " << astronaut.specialty << "\n";
        }
    }
};

class NASA {
private:
    std::vector<Astronaut> astronauts;
    std::vector<Mission> missions;

public:
    void addAstronaut(const Astronaut& astronaut) {
        astronauts.push_back(astronaut);
    }

    std::vector<Astronaut> displayAstronauts() const {
        std::cout << "NASA Astronauts:\n";
        for (const auto& astronaut : astronauts) {
            std::cout << " - " << astronaut.name << ", Age: " << astronaut.age
                      << ", Specialty: " << astronaut.specialty << "\n"<<"\n";
        }
        return astronauts;
    }

    void scheduleMission(const Mission& mission) {
        missions.push_back(mission);
        std::cout << "Mission scheduled successfully.\n \n";
    }

    void displayMissions() const {
        std::cout << "Scheduled Missions:\n \n";
        for (const auto& mission : missions) {
            mission.displayMissionDetails();
            std::cout << "\n";
        }
    }
};

int main() {
    NASA nasa;

    nasa.addAstronaut(Astronaut("Neil Armstrong", 39, "Commander"));
    nasa.addAstronaut(Astronaut("Buzz Aldrin", 39, "Pilot"));
    nasa.addAstronaut(Astronaut("Sally Ride", 32, "Physicist"));

    std::vector<Astronaut> astronauts = nasa.displayAstronauts();

    Mission apollo11("Apollo 11", "Moon", 1969);
    apollo11.addAstronaut(astronauts[0]);
    apollo11.addAstronaut(astronauts[1]);
    nasa.scheduleMission(apollo11);

    Mission marsRover("Mars Rover Mission", "Mars", 2022);
    marsRover.addAstronaut(astronauts[2]);
    nasa.scheduleMission(marsRover);

    nasa.displayMissions();

    return 0;
}
