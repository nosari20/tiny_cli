cmake_minimum_required(VERSION 2.8)

project(cli)
add_executable(
    ${PROJECT_NAME}

    "lib/cli-parser/app.cpp"

    "main.cpp"
)
