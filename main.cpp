#include <iostream>
#include "lib/cli-parser/app.h"

using namespace std;

int main(int argc, char *argv[])
{

    Cli::App app = Cli::App(argc, argv);

    if(app.arg(0) == "hello"){

        if(app.option("name") != ""){
            cout << "Hello " << app.option("name") << "!" << endl;
        }else{
            cout << "Hello World!" << endl;
        }

        if(app.flag("love")){
            cout << "<3 <3 <3 <3 <3 <3 <3" << endl;
        }

    }


    return 0;
}
