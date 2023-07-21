// ================================
// GUARD MASTER HEADER
// ================================
#ifndef __SEQUENTIAL_FILE_INCLUDED__
#define __SEQUENTIAL_FILE_INCLUDED__

// ================================
// DEPENDENCIES HEADER
// ================================
#include <vector>

// ================================
// ACTUAL HEADER CONTENT
// ================================
class SequentialFile {
    private:
        /* Property */
        std::string _file_path;
        char _delimiter;

        /* Content */
        std::vector<std::string> _file_data;

    public:
        /* Set value */
        void setPath(std::string);
        void setDelimiter(char);
        void set(std::string, char = '\n');

        /* Set up */
        explicit SequentialFile (std::string = "", char = '\n');
        SequentialFile(const SequentialFile & file);

        /* Interaction with file */
        void read();
        void write();

        /* Content */
        std::string getPath();
        std::vector<std::string> getAll();
        std::string getData(unsigned long);
        size_t getTotalUnits();
};

#endif // __SEQUENTIAL_FILE_INCLUDED__