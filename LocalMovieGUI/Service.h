#pragma once
#include "Repository.h"
#include "base_headers.h"

class Service {
private:
	Repository* repository;

public:
	/// <summary>
	/// The constructor for the service
	/// </summary>
	/// <param name="repository">The repository corresponding to the service</param>
	Service(Repository* repository);

	/// <summary>
	/// Adds a movie to the service
	/// </summary>
	/// <param name="title">Movie's title</param>
	/// <param name="genre">Movie's genre</param>
	/// <param name="release_year">Movie's release year</param>
	/// <param name="no_likes">Movie's number of likes</param>
	/// <param name="trailer">Movie's trailer</param>
	/// <returns>True, if the movie was added, false if not</returns>
	bool addMovieService(std::string title, std::string genre, int release_year, int no_likes, std::string trailer);

	/// <summary>
	/// Returns the number of movies in the service
	/// </summary>
	/// <returns>The number of movies</returns>
	int getNumberOfMoviesService();

	/// <summary>
	/// Updates a movie in the service
	/// </summary>
	/// <param name="title">Movie's title</param>
	/// <param name="genre">Movie's genre</param>
	/// <param name="release_year">Movie's year of release</param>
	/// <param name="no_likes">Movie's number of likes</param>
	/// <param name="trailer">Movie's trailer</param>
	/// <returns>True, if the movie was updated, False if not</returns>
	bool updateMovieService(std::string title, std::string genre, int release_year, int no_likes, std::string trailer);

	/// <summary>
	/// Returns all the movies in the service
	/// </summary>
	/// <returns>All the movies</returns>
	const std::vector<Movie>& getAllMoviesService();

	/// <summary>
	/// Deletes a movie in the service
	/// </summary>
	/// <param name="title">Movie's title</param>
	/// <returns>True, if the movie was deleted, False if not</returns>
	bool deleteMovieService(std::string title);

	/// <summary>
	/// Returns all the movies of a given genre
	/// </summary>
	/// <returns>All the movies of a given genre</returns>
	const std::vector<Movie> getMoviesGenreService(std::string genre);

};