#pragma once

#include <string>
#include <vector>
#include <iostream>

class Movie {
private:
    std::string title;
    std::string genre;
    int release_year;
    int no_likes;
    std::string trailer;

public:
    Movie();
    Movie(std::string title, std::string genre, int release_year, int no_likes, std::string trailer);

    std::string getTitle() const;
    std::string getGenre() const;
    int getReleaseYear() const;
    int getNoLikes() const;
    std::string getTrailer() const;
    std::string toString() const;

    bool operator==(const Movie& movieToCheck) const;

    friend std::istream& operator>>(std::istream& inputStream, Movie& movie);
    friend std::ostream& operator<<(std::ostream& outputStream, const Movie& movieOutput);
};

std::vector<std::string> tokenize(const std::string& str, char delimiter);
