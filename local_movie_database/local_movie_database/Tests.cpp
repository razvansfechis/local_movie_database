//#include "Tests.h"
//
//void Tests::testDynamicArray() {
//    // Test constructor
//    DynamicArray<int> arr(5);
//    assert(arr.nrEntitiesGetter() == 0);
//
//    // Test adding elements
//    arr.addElem(10);
//    assert(arr.nrEntitiesGetter() == 1);
//    assert(arr.elemGetter()[0] == 10);
//
//    // Test resizing
//    arr.addElem(20);
//    arr.addElem(30);
//    arr.addElem(40);
//
//    // Test updating elements
//    arr.updateElem(0, 100);
//    assert(arr.elemGetter()[0] == 100);
//
//    // Test deleting elements
//    arr.deleteElem(0);
//    assert(arr.nrEntitiesGetter() == 3);
//    assert(arr.elemGetter()[0] == 20); // Check if elements are shifted correctly after deletion
//    assert(arr.elemGetter()[1] == 30);
//    assert(arr.elemGetter()[2] == 40);
//}
//
//void Tests::testRepository() {
//    // Create a DynamicArray object
//    DynamicArray<Movie>* dynamicArray = new DynamicArray<Movie>(10);
//    std::string filename = R"(C:\Users\razva\Documents\GitHub\git_sixth_semester\oop-a6-7-razvansfechis\local_movie_database\local_movie_database\test_movies.txt)";
//
//    // Create a Repository object
//    Repository repository(dynamicArray, filename);
//
//    // Add some test movies to the repository
//    repository.addMovieRepository(Movie("Avatar", "Sci-Fi", 2009, 2000000, "https://www.imdb.com/title/tt0499549/"));
//    repository.addMovieRepository(Movie("Inception", "Sci-Fi", 2010, 2000000, "https://www.imdb.com/title/tt1375666/"));
//
//    // Test loading from file
//    repository.loadFromFile();
//    assert(repository.getNumberOfElementsRepository() == 2);
//
//    // Test writing to file
//    repository.writeToFile();
//
//    // Test adding a movie
//    repository.addMovieRepository(Movie("Interstellar", "Sci-Fi", 2014, 2100000, "https://www.imdb.com/title/tt0816692/"));
//    assert(repository.getNumberOfElementsRepository() == 3);
//
//    // Test deleting a movie
//    repository.deleteMovieRepository(0);
//    assert(repository.getNumberOfElementsRepository() == 2);
//
//    // Clean up dynamic memory
//    delete dynamicArray;
//}
//
//void Tests::testUserRepository() {
//    // Create a DynamicArray object
//    DynamicArray<Movie>* watchList = new DynamicArray<Movie>(10);
//
//    // Create a UserRepository object
//    UserRepository userRepository(watchList);
//
//    // Add some test movies to the user's watch list
//    userRepository.addMovieUserRepository(Movie("The Matrix", "Sci-Fi", 1999, 1702104, "https://www.imdb.com/video/vi1032782617/?playlistid=tt0133093"));
//    userRepository.addMovieUserRepository(Movie("Inception", "Sci-Fi", 2010, 2000000, "https://www.imdb.com/video/vi1032782617/?playlistid=tt1375666"));
//
//    // Test adding a movie
//    assert(userRepository.getNumberOfElementsUserRepository() == 2);;
//
//    // Test deleting a movie
//    userRepository.deleteMovieUserRepository(0);
//    assert(userRepository.getNumberOfElementsUserRepository() == 1);
//
//    // Clean up dynamic memory
//    delete watchList;
//}
//
//void Tests::testService() {
//    // Create a DynamicArray object
//    DynamicArray<Movie>* dynamicArray = new DynamicArray<Movie>(10);
//
//    std::string filename = R"(C:\Users\razva\Documents\GitHub\git_sixth_semester\oop-a6-7-razvansfechis\local_movie_database\local_movie_database\test_movies.txt)";
//
//    // Create a Repository object
//    Repository repository(dynamicArray, filename);
//
//    // Create a Service object
//    Service service(&repository);
//
//    // Add a movie
//    bool movieAdded = service.addMovieService("Avatar", "Sci-Fi", 2009, 2000000, "https://www.imdb.com/title/tt0499549/");
//    assert(movieAdded);
//
//    // Try adding the same movie again (should fail)
//    movieAdded = service.addMovieService("Avatar", "Sci-Fi", 2009, 2000000, "https://www.imdb.com/title/tt0499549/");
//    assert(!movieAdded);
//
//    // Test getNumberOfMoviesService
//    assert(service.getNumberOfMoviesService() == 1);
//
//    // Test getAllMoviesService
//    const std::vector<Movie>& movies = service.getAllMoviesService();
//    assert(movies.size() == 1);
//
//    //const std::string title = movies[/*0].getTitle();
//
//   /*assert(title == "Avatar");*/
//
//    // Update a movie
//    bool movieUpdated = service.updateMovieService("Avatar", "Sci-Fi", 2009, 2500000, "https://www.imdb.com/title/tt0499549/");
//    assert(movieUpdated);
//
//    // Try updating a non-existent movie (should fail)
//    movieUpdated = service.updateMovieService("Interstellar", "Sci-Fi", 2014, 2100000, "https://www.imdb.com/title/tt0816692/");
//    assert(!movieUpdated);
//
//    // Delete a movie
//    bool movieDeleted = service.deleteMovieService("Avatar");
//    assert(movieDeleted);
//
//    // Try deleting a non-existent movie (should fail)
//    movieDeleted = service.deleteMovieService("Inception");
//    assert(!movieDeleted);
//
//    // Test getMoviesGenreService
//    service.addMovieService("Inception", "Sci-Fi", 2010, 2000000, "https://www.imdb.com/title/tt1375666/");
//    service.addMovieService("Interstellar", "Sci-Fi", 2014, 2100000, "https://www.imdb.com/title/tt0816692/");
//    const std::vector<Movie> sciFiMovies = service.getMoviesGenreService("Sci-Fi");
//    assert(sciFiMovies.size() == 2);
//
//    // Clean up dynamic memory
//    delete dynamicArray;
//}
//
//void Tests::testMovie() {
//    // Test constructor and getters
//    Movie movie("The Shawshank Redemption", "Drama", 1994, 100, "https://www.youtube.com/watch?v=6hb3s9biaco");
//    assert(movie.getTitle() == "The Shawshank Redemption");
//    assert(movie.getGenre() == "Drama");
//    assert(movie.getReleaseYear() == 1994);
//    assert(movie.getNoLikes() == 100);
//    assert(movie.getTrailer() == "https://www.youtube.com/watch?v=6hb3s9biaco");
//
//    // Test toString method
//    std::string expectedString = "The Shawshank Redemption | Drama | 1994 | 100 | https://www.youtube.com/watch?v=6hb3s9biaco\n";
//    assert(movie.toString() == expectedString);
//}
//
//void Tests::testUserService() {
//    // Create a DynamicArray object for the main repository
//    DynamicArray<Movie>* dynamicArray = new DynamicArray<Movie>(10);
//
//    std::string filename = R"(C:\Users\razva\Documents\GitHub\git_sixth_semester\oop-a6-7-razvansfechis\local_movie_database\local_movie_database\test_movies.txt)";
//
//    Repository repository(dynamicArray, filename);
//
//    // Create a DynamicArray object for the user repository
//    DynamicArray<Movie>* userDynamicArray = new DynamicArray<Movie>(10);
//    UserRepository userRepo(userDynamicArray);
//
//    // Create a UserService object
//    UserService userService(&repository, &userRepo);
//
//    // Add some movies to the user's watch list
//    userService.addMovieUserService(Movie("The Matrix", "Sci-Fi", 1999, 1702104, "https://www.imdb.com/video/vi1032782617/?playlistid=tt0133093"));
//    userService.addMovieUserService(Movie("Inception", "Sci-Fi", 2010, 2000000, "https://www.imdb.com/video/vi1032782617/?playlistid=tt1375666"));
//
//    // Test getNumberOfMoviesUserService
//    assert(userService.getNumberOfMoviesUserService() == 2);
//
//    // Test getAllMoviesUserService
//    const std::vector<Movie>& userMovies = userService.getAllMoviesUserService();
//    assert(userMovies.size() == 2);
//    //assert(userMovies[0].getTitle() == "The Matrix");/*
//    //assert(userMovies[1].getTitle() == "Inception");*/
//
//    // Test deleteMovieUserService
//    bool movieDeleted = userService.deleteMovieUserService("The Matrix");
//    assert(movieDeleted);
//    assert(userService.getNumberOfMoviesUserService() == 1);
//
//    // Try deleting a non-existent movie (should fail)
//    movieDeleted = userService.deleteMovieUserService("Interstellar");
//    assert(!movieDeleted);
//
//    // Clean up dynamic memory
//    delete dynamicArray;
//    delete userDynamicArray;
//}