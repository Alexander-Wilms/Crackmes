# https://stackoverflow.com/questions/28896909/how-to-call-clang-format-over-a-cpp-project-folder#comment83912792_36046965
find . -name "*.c" -print0 | xargs -0 clang-format -i
