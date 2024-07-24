#include "Console.h"
#include "Exceptions.h"
#include "Validator.h"
#include "FileRepository.h"
#include <windows.h>

Console::Console(Service* service, UserService* user_service) : service(service), user_service(user_service) {}

std::string Console::inputGenre() {
    std::string genre;
    std::cout << "\nPick genre (Drama / Action / Sci-Fi / Crime etc.): ";
    getline(std::cin, genre);
    return genre;
}

void Console::playMovieInBrowser(Movie movie) {
    std::cout << "\nCurrently playing: " << movie.toString();
    ShellExecuteA(NULL, NULL, movie.getTrailer().c_str(), NULL, NULL, SW_SHOWMAXIMIZED);
}

std::string Console::trailerOptions() {
    std::cout << "\n\n\tLike the trailer?\n\t\tadd: add the movie to the watch list\n\t\tskip: display the next movie\n\t\tstop: stop showing trailers\n";
    std::string option;
    std::cout << "\noption: ";
    std::cin >> option;
    std::cin.ignore();
    return option;
}

void Console::readMovieForAdding(std::string& title, std::string& genre, int& release_year, int& no_likes, std::string& trailer) {
    std::cout << "\ttitle: ";
    getline(std::cin, title);
    std::cout << "\tgenre: ";
    getline(std::cin, genre);

    std::cout << "\tyear of release: ";
    std::string release_year_str;
    getline(std::cin, release_year_str);
    try {
        release_year = std::stoi(release_year_str);
    }
    catch (const std::invalid_argument&) {
        throw InputException("Invalid input for year of release!");
    }

    std::cout << "\tnumber of likes: ";
    std::string no_likes_str;
    getline(std::cin, no_likes_str);
    try {
        no_likes = std::stoi(no_likes_str);
    }
    catch (const std::invalid_argument&) {
        throw InputException("Invalid input for number of likes!");
    }

    std::cout << "\ttrailer: ";
    getline(std::cin, trailer);
}

void Console::readMovieForUpdating(std::string& title, std::string& genre, int& release_year, int& no_likes, std::string& trailer) {
    std::cout << "\ttitle: ";
    getline(std::cin, title);
    std::cout << "\tnew genre: ";
    getline(std::cin, genre);

    std::cout << "\tnew year of release: ";
    std::string release_year_str;
    getline(std::cin, release_year_str);
    try {
        release_year = std::stoi(release_year_str);
    }
    catch (const std::invalid_argument&) {
        throw InputException("Invalid input for year of release!");
    }

    std::cout << "\tnew number of likes: ";
    std::string no_likes_str;
    getline(std::cin, no_likes_str);
    try {
        no_likes = std::stoi(no_likes_str);
    }
    catch (const std::invalid_argument&) {
        throw InputException("Invalid input for number of likes!");
    }

    std::cout << "\tnew trailer: ";
    getline(std::cin, trailer);
}

void Console::displayAllMovies() {
    std::vector<Movie> movies = this->service->getAllMoviesService();
    std::cout << "\n";
    for (auto movie = movies.begin(); movie != movies.end(); ++movie) {
        int position = std::distance(movies.begin(), movie);
        std::cout << position + 1 << ". " << movie->toString();
    }
}

void Console::addMovie() {
    std::string title, genre, trailer;
    int release_year, no_likes;
    try {
        this->readMovieForAdding(title, genre, release_year, no_likes, trailer);
        Validator::validateMovie(Movie(title, genre, release_year, no_likes, trailer));
        if (!this->service->addMovieService(title, genre, release_year, no_likes, trailer)) {
            std::cout << "\nFailed to add movie!\n";
        }
        else {
            std::cout << "\nMovie successfully added!\n";
        }
    }
    catch (const ValidationException& e) {
        std::cout << "Validation error: " << e.what() << std::endl;
    }
    catch (const InputException& e) {
        std::cout << "Input error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Console::updateMovie() {
    std::string title, new_genre, new_trailer;
    int new_release_year, new_no_likes;
    try {
        this->readMovieForUpdating(title, new_genre, new_release_year, new_no_likes, new_trailer);
        Validator::validateMovie(Movie(title, new_genre, new_release_year, new_no_likes, new_trailer));
        if (!this->service->updateMovieService(title, new_genre, new_release_year, new_no_likes, new_trailer)) {
            std::cout << "\nFailed to update movie!\n";
        }
        else {
            std::cout << "\nMovie successfully updated!\n";
        }
    }
    catch (const ValidationException& e) {
        std::cout << "Validation error: " << e.what() << std::endl;
    }
    catch (const InputException& e) {
        std::cout << "Input error: " << e.what() << std::endl;
    }
    catch (const RepositoryException& e) {
        std::cout << "Repository error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Console::deleteMovie() {
    std::string title;
    try {
        std::cout << "title:";
        getline(std::cin, title);
        if (!this->service->deleteMovieService(title)) {
            std::cout << "\nFailed to delete movie!\n";
        }
        else {
            std::cout << "\nMovie successfully deleted!\n";
        }
    }
    catch (const RepositoryException& e) {
        std::cout << "Repository error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Console::displayAdminMenu() {
    std::cout << "\nADMIN MODE\n";
    std::cout << "\n\tadd: Adds a movie\n";
    std::cout << "\tupdate: Updates a movie\n";
    std::cout << "\tdelete: Deletes a movie\n";
    std::cout << "\tdisplay: Displays all the movies with their characteristics\n";
    std::cout << "\tback: Back to the admin/user mode\n\n";
}

void Console::displayUserMenu() {
    std::cout << "\nUSER MODE\n";
    std::cout << "\n\tgenre: See movies of a given genre, if empty see all the movies\n";
    std::cout << "\tlist: See the watch list\n";
    std::cout << "\tdelete: Deletes a movie from the watch list\n";
    std::cout << "\tview: View the watch list file\n"; // New command added here
    std::cout << "\tback: Back to the admin/user mode\n\n";
}

void Console::addMovieWatchList(Movie movie_to_add) {
    bool movie_in_watch_list = false;
    std::vector<Movie> all_movies = this->user_service->getAllMoviesUserService();
    for (auto movie = all_movies.begin(); movie != all_movies.end(); ++movie) {
        if (movie->getTitle() == movie_to_add.getTitle()) {
            std::cout << "\nMovie already in watch list!\n";
            movie_in_watch_list = true;
        }
    }
    if (!movie_in_watch_list) {
        this->user_service->addMovieUserService(movie_to_add);
        std::cout << "\nMovie added to the watch list\n";
    }
}

std::string Console::optionsWatchListEnd() {
    std::string option;
    std::cout << "\n\nYou have reached the end.\n\nType: \n\trepeat - see the movies again\n\tback - back in the user mode\n\n";
    std::cout << "option: ";
    std::cin >> option;
    std::cin.ignore();
    return option;
}

void Console::displayMoviesByGenre() {
    std::string genre = this->inputGenre();
    std::vector<Movie> validMovies = this->service->getMoviesGenreService(genre);
    if (std::distance(validMovies.begin(), validMovies.end()) == 0) {
        std::cout << "\nNo corresponding movies!\n";
    }
    else {
        int i = 0;
        bool stop = false;
        while (!stop) {
            this->playMovieInBrowser(validMovies[i]);
            std::string option = this->trailerOptions();
            if (option == "add") {
                this->addMovieWatchList(validMovies[i]);
            }
            else if (option == "skip") {
                std::cout << "\nPlaying the next trailer...\n";
            }
            else if (option == "stop") {
                stop = true;
            }
            else {
                std::cout << "\nInvalid option!\n";
            }
            i++;
            if (i == (std::distance(validMovies.begin(), validMovies.end())) && stop == false) {
                while (1) {
                    option = this->optionsWatchListEnd();
                    if (option == "repeat") {
                        i = 0; break;
                    }
                    else if (option == "back") {
                        stop = true; break;
                    }
                    else {
                        std::cout << "\nInvalid option!\n";
                    }
                }
            }
        }
    }
}

void Console::displayWatchList() {
    std::vector<Movie> movies = this->user_service->getAllMoviesUserService();
    std::cout << "\nWATCH LIST\n\n";
    for (auto movie = movies.begin(); movie != movies.end(); ++movie) {
        std::cout << movie->toString();
    }
}

void Console::deleteMovieWatchList() {
    this->displayWatchList();
    bool movie_deleted = false;
    std::vector<Movie> all_movies = this->user_service->getAllMoviesUserService();
    while (!movie_deleted) {
        std::string title;
        std::cout << "\nPick the title: ";
        getline(std::cin, title);
        try {
            for (auto movie = all_movies.begin(); movie != all_movies.end() && !movie_deleted; ++movie) {
                if (movie->getTitle() == title) {
                    std::string option = this->deleteAndRateMovieWatchList(*movie);
                    if (option == "yes") {
                        int increasedLikes = movie->getNoLikes() + 1;
                        this->service->updateMovieService(movie->getTitle(), movie->getGenre(), movie->getReleaseYear(), increasedLikes, movie->getTrailer());
                        std::cout << "\nNumber of likes increased by 1!\n";
                    }
                    else if (option == "no") {
                        std::cout << "\nNot rated\n";
                    }
                    else {
                        std::cout << "\nInvalid option!\n";
                    }
                    movie_deleted = true;
                }
            }
            if (!movie_deleted) {
                std::cout << "\nTitle does not correspond to a movie in the watch list!\n";
                break;
            }
        }
        catch (const RepositoryException& e) {
            std::cout << "Repository error: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

std::string Console::deleteAndRateMovieWatchList(Movie movie) {
    std::string title = movie.getTitle();
    std::string genre = movie.getGenre();
    int release_year = movie.getReleaseYear();
    int no_likes = movie.getNoLikes();
    std::string trailer = movie.getTrailer();
    int new_no_likes = no_likes + 1;
    this->user_service->deleteMovieUserService(title);
    std::cout << "\n\nMovie successfully removed from the watch list!\n";
    std::cout << "\nRate the movie?\n";
    std::cout << "\n\tyes - rate it positively";
    std::cout << "\n\tno - don't rate it\n\n";
    std::string option;
    std::cout << "Option (yes/no): ";
    getline(std::cin, option);
    return option;
}

void Console::viewWatchList() {
    if (dynamic_cast<CSVFileRepository*>(user_service->getFileRepository())) {
        ShellExecuteA(NULL, "open", "watch_list.csv", NULL, NULL, SW_SHOW);
    }
    else if (dynamic_cast<HTMLFileRepository*>(user_service->getFileRepository())) {
        ShellExecuteA(NULL, "open", "watch_list.html", NULL, NULL, SW_SHOW);
    }
}

void Console::adminStartMode() {
    while (true) {
        this->displayAdminMenu();
        std::string option;
        std::cout << "Choose option: ";
        getline(std::cin, option);
        if (option == "add") {
            this->addMovie();
        }
        else if (option == "update") {
            this->updateMovie();
        }
        else if (option == "delete") {
            this->deleteMovie();
        }
        else if (option == "display") {
            this->displayAllMovies();
        }
        else if (option == "back") {
            break;
        }
        else {
            std::cout << "Invalid option!\n";
        }
    }
}

void Console::userStartMode() {
    while (true) {
        this->displayUserMenu();
        std::string option;
        std::cout << "Choose option: ";
        getline(std::cin, option);
        if (option == "genre") {
            this->displayMoviesByGenre();
        }
        else if (option == "list") {
            this->displayWatchList();
        }
        else if (option == "delete") {
            this->deleteMovieWatchList();
        }
        else if (option == "view") {
            this->viewWatchList();
        }
        else if (option == "back") {
            break;
        }
        else {
            std::cout << "Invalid option!\n";
        }
    }
}

void Console::displayStartUIOptions() {
    std::cout << "\nadmin: The application starts in administrator mode\n";
    std::cout << "user: The application starts in user mode\n";
    std::cout << "exit: Exit the application\n\n";
    std::cout << "Choose mode: ";
}

void Console::startUI() {
    std::string start_mode;
    while (true) {
        this->displayStartUIOptions();
        getline(std::cin, start_mode);
        if (start_mode == "admin") {
            this->adminStartMode();
        }
        else if (start_mode == "user") {
            this->userStartMode();
        }
        else if (start_mode == "exit") {
            std::cout << "Bye!";
            break;
        }
        else {
            std::cout << "\nInvalid input!\n\n";
        }
    }
}
