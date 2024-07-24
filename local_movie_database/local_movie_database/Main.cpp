#include "Movie.h"
#include "DynamicArray.h"
#include "Repository.h"
#include "UserRepository.h"
#include "Service.h"
#include "UserService.h"
#include "Console.h"
#include "base_headers.h"
#include "FileRepository.h"
#include <crtdbg.h>
#include <stdlib.h>

int main() {
    DynamicArray<Movie>* dynamic_array = new DynamicArray<Movie>(0);
    std::string filename = R"(C:\Users\razva\Documents\GitHub\git_sixth_semester\oop-a6-7-razvansfechis\local_movie_database\local_movie_database\movies.txt)";
    Repository* repository = new Repository(dynamic_array, filename);
    repository->initialiseRepository();

    DynamicArray<Movie>* watch_list = new DynamicArray<Movie>(0);
    UserRepository* user_repository = new UserRepository(watch_list);

    Service* service = new Service(repository);
    UserService* user_service = new UserService(repository, user_repository);

    Console* console = new Console(service, user_service);

    std::string file_type;
    std::cout << "Choose file type for watch list (csv/html): ";
    std::getline(std::cin, file_type);

    if (file_type == "csv") {
        user_service->setFileRepository(new CSVFileRepository("watch_list.csv"));
    }
    else if (file_type == "html") {
        user_service->setFileRepository(new HTMLFileRepository("watch_list.html"));
    }
    else {
        std::cout << "Invalid file type selected. Defaulting to CSV." << std::endl;
        user_service->setFileRepository(new CSVFileRepository("watch_list.csv"));
    }

    console->startUI();
    user_service->saveWatchListToFile();

    return 0;
}
