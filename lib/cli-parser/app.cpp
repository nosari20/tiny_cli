#include "App.h"
#include <iostream>
#include <algorithm>
#include <sstream>

namespace Cli {

    const std::string App::FLAG_PREFIX = "-";
    const std::string App::OPTION_PREFIX = "--";

    App::App(int argc, char *argv[]) : raw(), args(), options(), flags()
    {

        for (int i=1;i<argc;i++){
            raw.push_back(std::string(argv[i]));
        }

        for(int i = 0; i< raw.size(); i++){

            // Options
            if(raw.at(i).substr(0, OPTION_PREFIX.size()) == OPTION_PREFIX) {
                std::string argumentValue = raw.at(i).substr(OPTION_PREFIX.size());

                if (argumentValue.find('=') != std::string::npos)
                {
                    std::vector<std::string> t = split(argumentValue,'=');
                    if(t.size()>1){
                       options.insert(std::pair<std::string, std::string>(t.at(0), t.at(1)));

                    }

                }
                continue;
            }

            // Flags
            if(raw.at(i).substr(0, FLAG_PREFIX.size()) == FLAG_PREFIX) {
                std::string argumentValue = raw.at(i).substr(FLAG_PREFIX.size());
                flags.push_back(argumentValue);
                continue;

            }

            // Args
            args.push_back(raw.at(i));


        }

    }

    App:: ~App()
    {

    }

    std::vector<std::string> App::split(std::string str, char delimiter) {
        std::vector<std::string> internal;
        std::stringstream ss(str);
        std::string tok;

        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }

    std::string App::arg(int index)
    {
       if(index >= 0 && index < args.size())
            return args.at(index);
       return "";
    }

    std::string App::option(std::string opt)
    {
        if(options.find(opt) != options.end())
            return options.at(opt);
        return "";
    }

    bool App::flag(std::string flag)
    {
       return (std::find(flags.begin(), flags.end(), flag) != flags.end());
    }


    void App::debug(){
        std::cerr << "Arguments : " << std::endl;
        for(int i = 0 ; i< args.size(); i++){
            std::cerr << args.at(i) << std::endl;
        }


        std::cerr << "Options : " << std::endl;
        std::map<std::string, std::string>::iterator pos;
        for (pos = options.begin(); pos != options.end(); ++pos) {
             std::cerr << pos->first << " = " << pos->second << std::endl;
        }

        std::cerr << "Flags : " << std::endl;
        for(int i = 0 ; i< flags.size(); i++){
            std::cerr << flags.at(i) << std::endl;
        }
    }


}
