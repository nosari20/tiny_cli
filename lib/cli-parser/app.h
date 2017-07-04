#ifndef App_H
#define App_H

#include <string>
#include <map>
#include <vector>

namespace Cli {


    class App
    {

        public :
            App(int argc, char *argv[]);
            ~App();

            static const std::string FLAG_PREFIX;
            static const std::string OPTION_PREFIX;

            std::string arg(int index);
            std::string option(std::string option);
            bool flag(std::string flag);

            void debug();

        private :
            std::vector<std::string> split(std::string str, char delimiter);

            std::vector<std::string> raw;
            std::vector<std::string> args;
            std::map<std::string, std::string> options;
            std::vector<std::string> flags;

    };




}

#endif // App_H
