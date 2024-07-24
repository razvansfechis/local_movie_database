#pragma once
#include "Movie.h"
#include "Exceptions.h"

class Validator {
public:
    static void validateMovie(const Movie& movie) {
        if (movie.getTitle().empty()) {
            throw ValidationException("Title cannot be empty!");
        }
        if (movie.getGenre().empty()) {
            throw ValidationException("Genre cannot be empty!");
        }
        if (movie.getReleaseYear() < 1888 || movie.getReleaseYear() > 2024) {
            throw ValidationException("Year of release is invalid!");
        }
        if (movie.getNoLikes() < 0) {
            throw ValidationException("Number of likes cannot be negative!");
        }
        if (movie.getTrailer().empty()) {
            throw ValidationException("Trailer cannot be empty!");
        }
    }
};
