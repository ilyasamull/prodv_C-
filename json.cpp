#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "single_include/nlohmann/json.hpp"

struct Man {
    std::string name;
    unsigned short age;
    unsigned short height;
    std::string nationality;
    std::string citizenship;
};

std::istream& operator>>(std::istream& in, Man& man) {
    in >> man.name >> man.age >> man.height >> man.nationality >> man.citizenship;
    return in;
}

int main() {
    std::cout << "Enter the number of people:\n";
    size_t count;
    std::cin >> count;
    std::vector<Man> v(count);
    std::cout << "Enter " << count << " men (name, age, height, nationality, citizenship):\n";
    for (auto& man : v)
        std::cin >> man;
    std::filesystem::create_directory("persons");
    for (size_t i = 0; i != v.size(); ++i) {
        nlohmann::json json_person;
        json_person["name"] = v[i].name;
        json_person["age"] = v[i].age;
        json_person["height"] = v[i].height;
        json_person["nationality"] = v[i].nationality;
        json_person["citizenship"] = v[i].citizenship;
        std::ofstream file("persons/person" + std::to_string(i + 1) + ".json");
        file << json_person;
    }
}
