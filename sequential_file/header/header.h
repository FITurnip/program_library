#include <vector>
class SequentialFile {
    std::string _file_path;
    char _delimiter;

    std::vector<std::string> _file_data;

    public:
    void setPath(std::string);
    void setDelimiter(char);
    void set(std::string, char = '\n');

    explicit SequentialFile (std::string = "", char = '\n');
    SequentialFile(const SequentialFile & file);

    void read();
    void write();
    
    std::vector<std::string> getAll();
    std::string getData(size_t);
    size_t getTotalUnits();
};