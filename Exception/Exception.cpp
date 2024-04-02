#include <iostream>
#include <exception>
#include <string>

class Exception : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "General error";
    }
};
class MathException : public Exception {
public:
    virtual const char* what() const noexcept override {
        return "Math error";
    }
};

class DivideByZeroException : public MathException {
public:
    virtual const char* what() const noexcept override {
        return "Division by zero";
    }
};

class MemoryException : public Exception {
public:
    virtual const char* what() const noexcept override {
        return "Memory error";
    }
};

class FileException : public Exception {
private:
    std::string filename;
public:
    FileException(const std::string& filename) : filename(filename) {}

    virtual const char* what() const noexcept override {
        return ("File error: " + filename).c_str();
    }
};

int main() {
    try {
        int x = 10, y = 2;
        if (y == 0) {
            throw DivideByZeroException();
        }

        int* ptr = nullptr;
        if (!ptr) {
            throw MemoryException();
        }

        std::string filename = "nonexistent.txt";
        throw FileException(filename);
    }
    catch (const Exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
