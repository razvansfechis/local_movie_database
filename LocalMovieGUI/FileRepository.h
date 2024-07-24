#pragma once
#include <vector>
#include "Movie.h"

class FileRepository {
public:
    virtual void saveToFile(const std::vector<Movie>& watchList) = 0;
};

class CSVFileRepository : public FileRepository {
private:
    std::string filename;
public:
    CSVFileRepository(const std::string& filename);
    void saveToFile(const std::vector<Movie>& watchList) override;
};

class HTMLFileRepository : public FileRepository {
private:
    std::string filename;
public:
    HTMLFileRepository(const std::string& filename);
    void saveToFile(const std::vector<Movie>& watchList) override;
};
