#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <vector>


int main() {
    std::ifstream file("input3.txt");
    if (!file.is_open()) {
        std::cout << "Failed to read input file." << std::endl;
        return 1;
    }

    char c;
    typedef std::array<int, 2> point;
    
    std::vector<point> part1_positions;
    std::vector<point> part2_positions;
    point part1_position = {0, 0};
    point part2_position = {0, 0};
    point robo_position = {0, 0};
    part1_positions.push_back(part1_position);
    part2_positions.push_back(part2_position);

    int whos_moving = 0;
    while (file.get(c)) {
        switch (c) {
            case '<':
                part1_position[0] -= 1;
                if (whos_moving % 2 == 0)
                    part2_position[0] -= 1;
                else
                    robo_position[0] -= 1;
                break;
            case '>':
                part1_position[0] += 1;
                if (whos_moving % 2 == 0)
                    part2_position[0] += 1;
                else
                    robo_position[0] += 1;
                break;
            case '^':
                part1_position[1] += 1;
                if (whos_moving % 2 == 0)
                    part2_position[1] += 1;
                else
                    robo_position[1] += 1;
                break;
            case 'v':
                part1_position[1] -= 1;
                if (whos_moving % 2 == 0)
                    part2_position[1] -= 1;
                else
                    robo_position[1] -= 1;
                break;
        }
        if (std::find(part1_positions.begin(), part1_positions.end(), part1_position) == part1_positions.end()) {
            part1_positions.push_back(part1_position);
        } 
        if (std::find(part2_positions.begin(), part2_positions.end(), part2_position) == part2_positions.end()) {
            part2_positions.push_back(part2_position);
        } 
        if (std::find(part2_positions.begin(), part2_positions.end(), robo_position) == part2_positions.end()) {
            part2_positions.push_back(robo_position);
        } 
        whos_moving++;
    }

    file.close();
    std::cout << part1_positions.size() << std::endl << part2_positions.size() << std::endl;
    return 0;
}