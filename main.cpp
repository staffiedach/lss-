#include <iostream>
#include <string>
#include <filesystem>
#include <iomanip>


namespace fs = std::filesystem;

void ls(const fs::path& pathtoread);


int main(int argc, char* argv[]) {

    try {
         if (argc == 1) {
        ls(fs::current_path());
    }

    if (argc == 2) {
        ls(argv[1]);
    }

    if (argc == 3) {
        std::cout << "You can only include one path. if there are spaces in your path format the command like this: lss /PARENT/'dir with spaces'" << std::endl;
    }
    }
    catch(const fs::filesystem_error& e){
        std::cout << "Error: " << e.what();
    }

}

void ls(const fs::path& pathtoread) {
    const int outputleft = 16;

        std::cout << std::left;

        for(auto& entry : fs::directory_iterator{pathtoread}) {
            if (!fs::is_directory(entry)) {
                std::cout << std::left;
                std::cout << "[FILE]" << "\t" << std::setw(outputleft) << entry.path().filename() << fs::file_size(entry) << " bytes" << std::endl;
            }

            else if (fs::is_directory(entry)) {
                std::cout << "[DIR]" << "\t" << std::setw(outputleft) << entry.path().filename() << "N/A" << "\tbytes" << std::endl;
            }
        }
        return;
}