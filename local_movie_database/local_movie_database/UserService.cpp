#include "UserService.h"
#include "Exceptions.h"

UserService::UserService(Repository* repository, UserRepository* user_repository) : repository(repository), user_repository(user_repository), file_repository(nullptr) {}

void UserService::setFileRepository(FileRepository* file_repository) {
    this->file_repository = file_repository;
}

FileRepository* UserService::getFileRepository() {
    return this->file_repository;
}

void UserService::addMovieUserService(Movie movie) {
    this->user_repository->addMovieUserRepository(movie);
}

int UserService::getNumberOfMoviesUserService() {
    return this->user_repository->getNumberOfElementsUserRepository();
}

const std::vector<Movie>& UserService::getAllMoviesUserService() {
    return this->user_repository->getMoviesUserRepository();
}

bool UserService::deleteMovieUserService(std::string title) {
    bool movie_deleted = false;
    std::vector<Movie> movies = this->getAllMoviesUserService();
    for (auto movie = movies.begin(); movie != movies.end(); ++movie) {
        if (movie->getTitle() == title) {
            int position = std::distance(movies.begin(), movie);
            try {
                this->user_repository->deleteMovieUserRepository(position);
                movie_deleted = true;
            }
            catch (const RepositoryException& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        }
    }
    return movie_deleted;
}

void UserService::saveWatchListToFile() {
    if (this->file_repository) {
        this->file_repository->saveToFile(this->getAllMoviesUserService());
    }
}
