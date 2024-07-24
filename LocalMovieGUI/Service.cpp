#include "Service.h"
#include "Validator.h"
#include "Exceptions.h"

Service::Service(Repository* repository) : repository(repository) {}

bool Service::addMovieService(std::string title, std::string genre, int release_year, int no_likes, std::string trailer) {
    Movie movie(title, genre, release_year, no_likes, trailer);
    Validator::validateMovie(movie);
    try {
        repository->addMovieRepository(movie);
    }
    catch (const RepositoryException& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}

int Service::getNumberOfMoviesService() {
    return this->repository->getNumberOfElementsRepository();
}

const std::vector<Movie>& Service::getAllMoviesService() {
    return this->repository->getMoviesRepository();
}

bool Service::updateMovieService(std::string title, std::string genre, int release_year, int no_likes, std::string trailer) {
    Movie movie(title, genre, release_year, no_likes, trailer);
    Validator::validateMovie(movie);
    std::vector<Movie> all_movies = this->repository->getMoviesRepository();

    for (auto movie = all_movies.begin(); movie != all_movies.end(); movie++) {
        if (title == movie->getTitle()) {
            int position = std::distance(all_movies.begin(), movie);
            try {
                this->repository->updateMovieRepository(position, Movie(title, genre, release_year, no_likes, trailer));
            }
            catch (const RepositoryException& e) {
                std::cout << e.what() << std::endl;
                return false;
            }
            return true;
        }
    }
    throw RepositoryException("Movie not found for update!");
}

bool Service::deleteMovieService(std::string title) {
    std::vector<Movie> all_movies = this->repository->getMoviesRepository();

    for (auto movie = all_movies.begin(); movie != all_movies.end(); ++movie) {
        if (title == movie->getTitle()) {
            int position = std::distance(all_movies.begin(), movie);
            try {
                this->repository->deleteMovieRepository(position);
            }
            catch (const RepositoryException& e) {
                std::cout << e.what() << std::endl;
                return false;
            }
            return true;
        }
    }
    throw RepositoryException("Movie not found for deletion!");
}

const std::vector<Movie> Service::getMoviesGenreService(std::string genre) {
    std::vector<Movie> movies = this->getAllMoviesService();
    std::vector<Movie> moviesGenre;

    for (auto movie = movies.begin(); movie != movies.end(); ++movie) {
        if (movie->getGenre() == genre) {
            moviesGenre.push_back(*movie);
        }
    }

    return moviesGenre;
}
