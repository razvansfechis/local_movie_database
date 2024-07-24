#include "Repository.h"
#include "Exceptions.h"
#include <fstream>

Repository::Repository(DynamicArray<Movie>* dynamic_array, std::string& file_name) : dynamic_array(dynamic_array), file_name(file_name) {}

void Repository::loadFromFile() {
    if (!this->file_name.empty()) {
        Movie movieFromFile;
        std::ifstream fin(this->file_name);
        while (fin >> movieFromFile) {
            bool exists = false;
            for (int i = 0; i < this->dynamic_array->nrEntitiesGetter(); ++i) {
                if (this->dynamic_array->elemGetter()[i] == movieFromFile) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                this->dynamic_array->addElem(movieFromFile);
            }
        }
        fin.close();
    }
}

void Repository::writeToFile() {
    if (!this->file_name.empty()) {
        std::ofstream fout(this->file_name);
        for (const Movie& movie : this->dynamic_array->elemGetter()) {
            fout << movie << "\n";
        }
        fout.close();
    }
}

void Repository::initialiseRepository() {
    this->loadFromFile();
}

void Repository::addMovieRepository(Movie movie) {
    for (const auto& existingMovie : dynamic_array->elemGetter()) {
        if (existingMovie == movie) {
            throw RepositoryException("Movie with the same title already exists!");
        }
    }
    dynamic_array->addElem(movie);
    writeToFile();
}

void Repository::updateMovieRepository(int position, Movie movie) {
    if (position < 0 || position >= dynamic_array->nrEntitiesGetter()) {
        throw RepositoryException("Invalid position for movie update!");
    }
    dynamic_array->updateElem(position, movie);
    writeToFile();
}

void Repository::deleteMovieRepository(int position) {
    if (position < 0 || position >= dynamic_array->nrEntitiesGetter()) {
        throw RepositoryException("Invalid position for movie deletion!");
    }
    dynamic_array->deleteElem(position);
    writeToFile();
}

const std::vector<Movie>& Repository::getMoviesRepository() {
    return this->dynamic_array->elemGetter();
}

int Repository::getNumberOfElementsRepository() {
    return this->dynamic_array->nrEntitiesGetter();
}
