#include "FileRepository.h"
#include <fstream>

CSVFileRepository::CSVFileRepository(const std::string& filename) : filename(filename) {}

void CSVFileRepository::saveToFile(const std::vector<Movie>& watchList) {
    std::ofstream file(filename);
    for (const auto& movie : watchList) {
        file << movie.getTitle() << ","
            << movie.getGenre() << ","
            << movie.getReleaseYear() << ","
            << movie.getNoLikes() << ","
            << movie.getTrailer() << "\n";
    }
    file.close();
}

HTMLFileRepository::HTMLFileRepository(const std::string& filename) : filename(filename) {}

void HTMLFileRepository::saveToFile(const std::vector<Movie>& watchList) {
    std::ofstream file(filename);
    file << "<html><body><table border='1'>\n";
    file << "<tr><th>Title</th><th>Genre</th><th>Year</th><th>Likes</th><th>Trailer</th></tr>\n";
    for (const auto& movie : watchList) {
        file << "<tr>"
            << "<td>" << movie.getTitle() << "</td>"
            << "<td>" << movie.getGenre() << "</td>"
            << "<td>" << movie.getReleaseYear() << "</td>"
            << "<td>" << movie.getNoLikes() << "</td>"
            << "<td><a href=\"" << movie.getTrailer() << "\">Link</a></td>"
            << "</tr>\n";
    }
    file << "</table></body></html>";
    file.close();
}
