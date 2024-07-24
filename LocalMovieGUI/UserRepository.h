#pragma once
#include "DynamicArray.h"
#include "Movie.h"

class UserRepository {
private:
	DynamicArray<Movie>* watch_list;

public:
	/// <summary>
	/// Constructor for the User Repository
	/// </summary>
	/// <param name="watch_list">The watch list</param>
	UserRepository(DynamicArray<Movie>* watch_list);

	/// <summary>
	/// Adds a movie to the watch list
	/// </summary>
	/// <param name="movie">Movie to be added to the watch list</param>
	void addMovieUserRepository(Movie movie);

	/// <summary>
	/// Updates a movie in the watch list
	/// </summary>
	/// <param name="i">Position of the movie in the watch list</param>
	/// <param name="movie">The new movie to be added at that position</param>
	void updateMovieUserRepository(int i, Movie movie);

	/// <summary>
	/// Deletes a movie from the watch list
	/// </summary>
	/// <param name="position">The position of the movie in the watch list repository</param>
	void deleteMovieUserRepository(int position);

	/// <summary>
	/// Returns all the movies in the watch list
	/// </summary>
	/// <returns>All the movies in the watch list</returns>
	const std::vector<Movie>& getMoviesUserRepository();

	/// <summary>
	/// Returns the number of movies in the watch list
	/// </summary>
	/// <returns>The number of movies in the watch list</returns>
	int getNumberOfElementsUserRepository();
};