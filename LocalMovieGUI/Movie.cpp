#include "Movie.h"
#include "base_headers.h"
#include <sstream>
#include <iostream>

Movie::Movie() : release_year(0), no_likes(0) {}

Movie::Movie(std::string title, std::string genre, int release_year, int no_likes, std::string trailer)
    : title(title), genre(genre), release_year(release_year), no_likes(no_likes), trailer(trailer) {}

std::string Movie::getTitle() const {
    return this->title;
}

std::string Movie::getGenre() const {
    return this->genre;
}

int Movie::getReleaseYear() const {
    return this->release_year;
}

int Movie::getNoLikes() const {
    return this->no_likes;
}

std::string Movie::getTrailer() const {
    return this->trailer;
}

std::string Movie::toString() const {
    return this->title + " | " + this->genre + " | " + std::to_string(this->release_year) + " | " + std::to_string(this->no_likes) + " | " + this->trailer + "\n";
}

std::vector<std::string> tokenize(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter)) {
        // Trim whitespace from each token
        token.erase(0, token.find_first_not_of(" \t\n\r\f\v"));
        token.erase(token.find_last_not_of(" \t\n\r\f\v") + 1);
        result.push_back(token);
    }
    return result;
}

bool Movie::operator==(const Movie& movieToCheck) const {
    return this->title == movieToCheck.title;
}

std::istream& operator>>(std::istream& inputStream, Movie& movie) {
    std::string line;
    std::getline(inputStream, line);
    if (line.empty()) {
        return inputStream;
    }

    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() < 5) {
        std::cerr << "Invalid input line (expected 5 tokens, got " << tokens.size() << "): " << line << std::endl;
        return inputStream;
    }

    try {
        movie.title = tokens[0];
        movie.genre = tokens[1];
        movie.release_year = std::stoi(tokens[2]);
        movie.no_likes = std::stoi(tokens[3]);
        movie.trailer = tokens[4];
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error parsing line: " << line << " - " << e.what() << std::endl;
        return inputStream;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error parsing line: " << line << " - " << e.what() << std::endl;
        return inputStream;
    }

    // Debugging output
    /*std::cout << "Parsed Movie: " << movie.title << ", " << movie.genre << ", "
       << movie.release_year << ", " << movie.no_likes << ", " << movie.trailer << std::endl;
       */
    return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Movie& movieOutput) {
    outputStream << movieOutput.title << "," << movieOutput.genre << ","
        << std::to_string(movieOutput.release_year) << ","
        << std::to_string(movieOutput.no_likes) << "," << movieOutput.trailer;
    return outputStream;
}
