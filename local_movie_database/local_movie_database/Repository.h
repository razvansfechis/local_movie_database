#pragma once
#include "DynamicArray.h"
#include "Movie.h"

class Repository {
private:
	DynamicArray<Movie>* dynamic_array;
	std::string file_name;
public:

	void loadFromFile();

	void writeToFile();

	/// <summary>
	/// Constructor for the repository
	/// </summary>
	/// <param name="dynamic_array">The dynamic array corresponding to the repository</param>
	Repository(DynamicArray<Movie>* dynamic_array, std::string &file_name);

	/// <summary>
	/// Initialize then repository by adding 10 elements at the start
	/// </summary>
	void initialiseRepository();

	/// <summary>
	/// Adds a movie to the repository
	/// </summary>
	/// <param name="movie">The movie to be added</param>
	void addMovieRepository(Movie movie);

	/// <summary>
	/// Updates a movie in the repository
	/// </summary>
	/// <param name="i">updates a movie in the repository</param>
	/// <param name="movie">the movie with the new parameters</param>
	void updateMovieRepository(int i, Movie movie);

	/// <summary>
	/// Deletes a movie in the repository
	/// </summary>
	/// <param name="position">The position of the movie in the repository</param>
	void deleteMovieRepository(int position);

	/// <summary>
	/// Returns all the movies
	/// </summary>
	/// <returns>All the movies</returns>
	const std::vector<Movie>& getMoviesRepository();

	/// <summary>
	/// Returns the number of elements in the repository
	/// </summary>
	/// <returns>The number of elements in the repository</returns>
	int getNumberOfElementsRepository();
};