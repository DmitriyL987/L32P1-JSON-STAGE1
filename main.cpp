#include <iostream>
#include <fstream>
#include <vector>
#include <map>
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
    //std::vector<std::pair<std::string, std::string>> roles_and_actors;
    std::map<std::string, std::string>mainRoles;
};

int main() {
    std::ofstream file("Movie.json");
    if(!file.is_open()){
        std::cerr << "not open file" <<std::endl;
        return 0;
    }
    Movie movie;
    std::cout << "Enter the title and release year of the movie: ";
    std::getline(std::cin, movie.film_title) ;
    std::getline(std::cin, movie.year);

    std::cout << "Enter the genre and duration of the picture: ";
    std::getline(std::cin, movie.genre) ;
    std::getline(std::cin, movie.duration);

    std::cout << "Enter the country and the shooting studio: ";
    std::getline(std::cin, movie.country) ;
    std::getline(std::cin, movie.studio);

    std::cout << "Enter the author of the script, director and producer of the picture: ";
    std::cout << "";
    std::getline(std::cin, movie.screenwriter) ;
    std::getline(std::cin, movie.director);
    std::getline(std::cin, movie.producer);

    std::cout << "Enter the age category: ";
    std::getline(std::cin, movie.age_category) ;
    std::cout << "Enter the actors and the main roles they played: ";
    do {
        std::string key, value;
        std::cout << "Role:  ";
        std::getline(std::cin, key);
        key = "\t" + key;
        std::cout << "Actor:  ";
        std::getline(std::cin, value);
        if (key == "end" || value == "end") break;
        movie.mainRoles.insert(std::make_pair(key,value));
    } while(true);


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
    //movie_info["roles_and_actors"] = movie.roles_and_actors;
    movie_info["mainRoles"] = movie.mainRoles;
    file << movie_info;
    file.close();
    return 0;
}
