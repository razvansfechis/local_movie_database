#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QLabel>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), service(nullptr), userService(nullptr) {
    try {
        // Set up the main widget and layout
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
        setCentralWidget(centralWidget);

        // Set up the table widget
        tableWidget = new QTableWidget(this);
        tableWidget->setColumnCount(5);
        tableWidget->setHorizontalHeaderLabels(QStringList() << "Title" << "Genre" << "Year" << "Likes" << "Trailer");
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        mainLayout->addWidget(tableWidget);

        // Set up input fields and buttons
        QHBoxLayout* inputLayout = new QHBoxLayout();
        titleInput = new QLineEdit(this);
        genreInput = new QLineEdit(this);
        yearInput = new QLineEdit(this);
        likesInput = new QLineEdit(this);
        trailerInput = new QLineEdit(this);

        inputLayout->addWidget(new QLabel("Title:", this));
        inputLayout->addWidget(titleInput);
        inputLayout->addWidget(new QLabel("Genre:", this));
        inputLayout->addWidget(genreInput);
        inputLayout->addWidget(new QLabel("Year:", this));
        inputLayout->addWidget(yearInput);
        inputLayout->addWidget(new QLabel("Likes:", this));
        inputLayout->addWidget(likesInput);
        inputLayout->addWidget(new QLabel("Trailer:", this));
        inputLayout->addWidget(trailerInput);

        mainLayout->addLayout(inputLayout);

        QHBoxLayout* buttonLayout = new QHBoxLayout();
        QPushButton* addButton = new QPushButton("Add Movie", this);
        QPushButton* updateButton = new QPushButton("Update Movie", this);
        QPushButton* deleteButton = new QPushButton("Delete Movie", this);

        buttonLayout->addWidget(addButton);
        buttonLayout->addWidget(updateButton);
        buttonLayout->addWidget(deleteButton);

        mainLayout->addLayout(buttonLayout);

        // Connect signals and slots
        connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddMovie);
        connect(updateButton, &QPushButton::clicked, this, &MainWindow::onUpdateMovie);
        connect(deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteMovie);

        // Initialize the service and user service
        DynamicArray<Movie>* dynamicArray = new DynamicArray<Movie>(0);
        std::string filename = R"(C:\Users\razva\Desktop\OOP\Labs\A8\LocalMovieGUI\LocalMovieGUI\movies.txt)";
        Repository* repository = new Repository(dynamicArray, filename);
        repository->initialiseRepository();

        DynamicArray<Movie>* watchList = new DynamicArray<Movie>(0);
        UserRepository* userRepository = new UserRepository(watchList);

        service = new Service(repository);
        userService = new UserService(repository, userRepository);

        // Populate the table
        populateTable();
    }
    catch (const std::exception& e) {
        std::cerr << "Error during initialization: " << e.what() << std::endl;
        QMessageBox::critical(this, "Initialization Error", "Failed to initialize the main window.");
    }
}


MainWindow::~MainWindow() {
    delete service;
    delete userService;
}

void MainWindow::populateTable() {
    if (!tableWidget) {
        std::cerr << "Error: tableWidget is not initialized." << std::endl;
        return;
    }

    tableWidget->setRowCount(0); // Clear the table before populating

    std::vector<Movie> movies;
    try {
        movies = service->getAllMoviesService();
    }
    catch (const std::exception& e) {
        std::cerr << "Error retrieving movies: " << e.what() << std::endl;
        return;
    }

    if (movies.empty()) {
        std::cerr << "No movies to display." << std::endl;
        return;
    }

    for (const auto& movie : movies) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        // Validate data before setting items
        QString title = QString::fromUtf8(movie.getTitle().c_str());
        QString genre = QString::fromUtf8(movie.getGenre().c_str());
        QString year = QString::number(movie.getReleaseYear());
        QString likes = QString::number(movie.getNoLikes());
        QString trailer = QString::fromUtf8(movie.getTrailer().c_str());

        tableWidget->setItem(row, 0, new QTableWidgetItem(title));
        tableWidget->setItem(row, 1, new QTableWidgetItem(genre));
        tableWidget->setItem(row, 2, new QTableWidgetItem(year));
        tableWidget->setItem(row, 3, new QTableWidgetItem(likes));
        tableWidget->setItem(row, 4, new QTableWidgetItem(trailer));
    }
}

void MainWindow::onAddMovie() {
    // Retrieve input values
    QString qTitle = titleInput->text();
    QString qGenre = genreInput->text();
    QString qYear = yearInput->text();
    QString qLikes = likesInput->text();
    QString qTrailer = trailerInput->text();

    // Convert to their type
    std::string title = qTitle.toUtf8().constData();
    std::string genre = qGenre.toUtf8().constData();
    int year = qYear.toInt();
    int likes = qLikes.toInt();
    std::string trailer = qTrailer.toUtf8().constData();

    try {
        if (service->addMovieService(title, genre, year, likes, trailer)) {
            QMessageBox::information(this, "Success", "Movie added successfully.");
            populateTable();
        }
        else {
            QMessageBox::warning(this, "Failure", "Failed to add movie.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error adding movie: " << e.what() << std::endl;
        QMessageBox::critical(this, "Error", "An error occurred while adding the movie.");
    }
}



void MainWindow::onUpdateMovie() {
    // Retrieve input values
    QString qTitle = titleInput->text();
    QString qGenre = genreInput->text();
    QString qYear = yearInput->text();
    QString qLikes = likesInput->text();
    QString qTrailer = trailerInput->text();

    // Convert to their type
    std::string title = qTitle.toUtf8().constData();
    std::string genre = qGenre.toUtf8().constData();
    int year = qYear.toInt();
    int likes = qLikes.toInt();
    std::string trailer = qTrailer.toUtf8().constData();

    try {
        if (service->updateMovieService(title, genre, year, likes, trailer)) {
            QMessageBox::information(this, "Success", "Movie updated successfully.");
            populateTable();
        }
        else {
            QMessageBox::warning(this, "Failure", "Failed to update movie.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error updating movie: " << e.what() << std::endl;
        QMessageBox::critical(this, "Error", "An error occurred while updating the movie.");
    }
}

void MainWindow::onDeleteMovie() {
    std::string title = titleInput->text().toUtf8().constData();

    try {
        if (service->deleteMovieService(title)) {
            QMessageBox::information(this, "Success", "Movie deleted successfully.");
            populateTable();
        }
        else {
            QMessageBox::warning(this, "Failure", "Failed to delete movie.");
        }
    }
    catch (const std::exception& e) { 
        std::cerr << "Error deleting movie: " << e.what() << std::endl;
        QMessageBox::critical(this, "Error", "An error occurred while deleting the movie.");
    }
}

void MainWindow::onDisplayMovies() {
    populateTable();
}
