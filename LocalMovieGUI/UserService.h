#pragma once
#include "Repository.h"
#include "UserRepository.h"
#include "base_headers.h"
#include "FileRepository.h"

class UserService {
private:
	UserRepository* user_repository;
	Repository* repository;
	FileRepository* file_repository;

public:
	/// <summary>
	/// Constructor for the User Service
	/// </summary>
	/// <param name="repository">The repository corresponding to the user service</param>
	/// <param name="user_repository">The user repository corresponding to the user service</param>
	UserService(Repository* repository, UserRepository* user_repository);

	void setFileRepository(FileRepository* file_repository);

	/// <summary>
	/// Adds a movie to the user service
	/// </summary>
	/// <param name="movie">Movie to be added to the user service</param>
	void addMovieUserService(Movie movie);

	/// <summary>
	/// Returns the number of movies in the user service
	/// </summary>
	/// <returns>The number of movies in the user service</returns>
	int getNumberOfMoviesUserService();

	/// <summary>
	/// Returns all the movies inside the user service
	/// </summary>
	/// <returns>All the movies inside the user service</returns>
	const std::vector<Movie>& getAllMoviesUserService();

	/// <summary>
	/// Deletes a movie from the user service 
	/// </summary>
	/// <param name="title">The title corresponding to the movie</param>
	/// <returns>True, if deleted, False if not</returns>
	bool deleteMovieUserService(std::string title);

	void saveWatchListToFile();

	FileRepository* getFileRepository();

};