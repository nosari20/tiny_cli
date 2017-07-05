cmake_minimum_required(VERSION 2.8)

project(cli)
add_executable(
    hello

    "lib/cli-parser/app.cpp"

    "main.cpp"
)
