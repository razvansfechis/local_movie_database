#pragma once
#include "base_headers.h"
#include "Service.h"
#include "UserService.h"
#include <limits>
#include <iomanip>

class Console {
private:
    Service* service;
    UserService* user_service;

public:
    Console(Service* service, UserService* user_service);

    void startUI();
    void displayStartUIOptions();
    void readMovieForAdding(std::string& title, std::string& genre, int& release_year, int& no_likes, std::string& trailer);
    void readMovieForUpdating(std::string& title, std::string& genre, int& release_year, int& no_likes, std::string& trailer);
    std::vector<Movie> filterMoviesGenre(std::string genre);
    std::string inputGenre();
    void playMovieInBrowser(Movie movie);
    std::string trailerOptions();
    std::string optionsWatchListEnd();

    // ----------------------------- ADMIN -----------------------------
    void adminStartMode();
    void displayAllMovies();
    void addMovie();
    void updateMovie();
    void deleteMovie();
    void displayAdminMenu();

    // ----------------------------- USER -----------------------------
    void userStartMode();
    void addMovieWatchList(Movie movie_to_add);
    void displayUserMenu();
    void displayMoviesByGenre();
    void displayWatchList();
    void deleteMovieWatchList();
    std::string deleteAndRateMovieWatchList(Movie movie);

    // New method for viewing the watch list
    void viewWatchList();
};
