#pragma once
#include <exception>
#include <string>

class RepositoryException : public std::exception {
private:
    std::string message;
public:
    RepositoryException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ValidationException : public std::exception {
private:
    std::string message;
public:
    ValidationException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InputException : public std::exception {
private:
    std::string message;
public:
    InputException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
