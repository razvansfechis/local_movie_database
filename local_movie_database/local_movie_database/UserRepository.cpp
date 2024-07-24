#include "UserRepository.h"

UserRepository::UserRepository(DynamicArray<Movie>* watch_list) : watch_list(watch_list) {}

void UserRepository::addMovieUserRepository(Movie movie)
{
	this->watch_list->addElem(movie);
}

void UserRepository::updateMovieUserRepository(int i, Movie movie)
{
	this->watch_list->updateElem(i, movie);
}

void UserRepository::deleteMovieUserRepository(int position)
{
	this->watch_list->deleteElem(position);
}

const std::vector<Movie>& UserRepository::getMoviesUserRepository()
{
	return this->watch_list->elemGetter();
}

int UserRepository::getNumberOfElementsUserRepository()
{
	return this->watch_list->nrEntitiesGetter();
}
