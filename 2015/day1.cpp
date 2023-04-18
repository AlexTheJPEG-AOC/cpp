#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("input1.txt");
    if (!file.is_open()) {
        std::cout << "Failed to read input file." << std::endl;
        return 1;
    }

    char c;
    int floor = 0, instruction_index = 0, basement_index = 0;

    while (file.get(c)) {
        if (c == '(') floor++;
        else floor--;

        if (!basement_index && floor == -1)
            basement_index = instruction_index + 1;

        instruction_index++;
    }

    file.close();
    std::cout << floor << std::endl << basement_index << std::endl;
    return 0;
}
