#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

struct Movie{
    std::string film_title;
    std::string age_category;
    std::string year;
    std::string genre;
    std::string duration;
    std::string country;
    std::string studio;
    std::string screenwriter;
    std::string director;
    std::string producer;
    std::map<std::string, std::string>mainRoles;
};

void enterSubStruct(std::map<std::string, std::string>& subStruct, std::string _key, std::string _val){
    do {
        std::string key, value;
        std::cout << _key << ":  ";
        std::getline(std::cin, key);
        if (key == "end" ) break;
        std::cout << _val << ":  ";
        std::getline(std::cin, value);
        if (value == "end") break;
        subStruct.insert(std::make_pair(key,value));
    } while(true);
}

int main() {
    std::cout << "Write or read?" << std::endl;
    std::string answer;
    std::cin >> answer;
    if (answer == "write") {
        std::ofstream file("Movie.json");
        if (!file.is_open()) {
            std::cerr << "not open file" << std::endl;
            return 0;
        }
        Movie movie;
        std::cout << "Enter the title and release year of the movie: ";
        std::getline(std::cin, movie.film_title);
        std::getline(std::cin, movie.year);

        std::cout << "Enter the genre and duration of the picture: ";
        std::getline(std::cin, movie.genre);
        std::getline(std::cin, movie.duration);

        std::cout << "Enter the country and the shooting studio: ";
        std::getline(std::cin, movie.country);
        std::getline(std::cin, movie.studio);

        std::cout << "Enter the author of the script, director and producer of the picture: ";
        std::cout << "";
        std::getline(std::cin, movie.screenwriter);
        std::getline(std::cin, movie.director);
        std::getline(std::cin, movie.producer);

        std::cout << "Enter the age category: ";
        std::getline(std::cin, movie.age_category);
        std::cout << "Enter the actors and the main roles they played (enter \'end\' for exit): ";
        enterSubStruct(movie.mainRoles, "Role", "Actor");

        nlohmann::json movie_info;
        movie_info["film_title"] = movie.film_title;
        movie_info["year"] = movie.year;
        movie_info["genre"] = movie.genre;
        movie_info["duration"] = movie.duration;
        movie_info["country"] = movie.country;
        movie_info["studio"] = movie.studio;
        movie_info["screenwriter"] = movie.screenwriter;
        movie_info["director"] = movie.director;
        movie_info["producer"] = movie.producer;
        movie_info["age_category"] = movie.age_category;
        movie_info["mainRoles"] = movie.mainRoles;
        file << movie_info;
        file.close();

    } else if (answer == "read") {

        std::ifstream in_file("Movie.json");
        if (in_file.is_open())
        {
            nlohmann::json dict;
            in_file >> dict;
            Movie LoadInfo;

            LoadInfo.film_title = dict["film_title"];
            LoadInfo.year = dict["year"];
            LoadInfo.genre = dict["genre"];
            LoadInfo.age_category = dict["age_category"];
            LoadInfo.country = dict["country"];
            LoadInfo.director = dict["director"];
            LoadInfo.producer = dict["producer"];
            LoadInfo.screenwriter = dict["screenwriter"];
            LoadInfo.studio = dict["studio"];
            LoadInfo.duration = dict["duration"];
            LoadInfo.mainRoles = dict["mainRoles"].get<std::map<std::string, std::string>>();

            std::cout << "Title: " << LoadInfo.film_title << std::endl;
            std::cout << "Duration: " << LoadInfo.duration << std::endl;
            std::cout << "Year: " << LoadInfo.year << std::endl;
            std::cout << "Genre: " << LoadInfo.genre << std::endl;
            std::cout << "Age category: " << LoadInfo.age_category << std::endl;
            std::cout << "Country: " << LoadInfo.country << std::endl;
            std::cout << "Studio: " << LoadInfo.studio << std::endl;
            std::cout << "Director: " << LoadInfo.director << std::endl;
            std::cout << "Producer: " << LoadInfo.producer << std::endl;
            std::cout << "Screenwriter: " << LoadInfo.screenwriter << std::endl;
            for (auto it: LoadInfo.mainRoles) std::cout << "Roles:  " << it.first << "\t\tActor:  " << it.second << std::endl;
            in_file.close();
        } else {
            std::cerr << "not open file" << std::endl;
        }
    } else std::cout << "Nothing selected" << std::endl;
    return 0;
}
