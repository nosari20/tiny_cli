# Tiny CLI

## Allowed Formats

```
args
--option
--option=1
-flag
```
## Example
```cpp

#include <iostream>
#include "lib/cli-parser/app.h"

using namespace std;

void doc(){
    cout << "Say hello with style" << endl;
    cout << "Usage : hello hello [OPTIONS]" << endl << endl;
    cout << "Options : " << endl;
    cout << '\t' << "--name=NAME," << '\t' << "Replace 'world' by NAME in the message" << endl;
    cout << '\t' << "-l," << '\t' << "--love" << '\t' << "Display hearts at the end of the message" << endl;
}

int main(int argc, char *argv[])
{

    Cli::App app = Cli::App(argc, argv);

    if(app.arg(0) == "hello"){

        if(app.hasOption("version")){
            cout << "Hello version 1.0" << endl;
            return 0;
        }

        if(app.hasOption("help")){
            doc();
            return 0;

        }


        if(app.option("name") != ""){
            cout << "Hello " << app.option("name") << "!" << endl;
        }else{
            cout << "Hello World!" << endl;
        }

        if(app.hasOption("love") || app.hasFlag("l")){
            cout << "<3 <3 <3 <3 <3 <3 <3" << endl;
        }

    }else{
        doc();
    }

    return 0;
}


```