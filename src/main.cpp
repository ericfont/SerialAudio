// main.cpp
#include <sqlite3.h>
#include <stdio.h>
#include <fmt/core.h>
#include <QCoreApplication>

using namespace std;
int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

    fmt::print("Hello, world!\n");
    printf("%s\n", sqlite3_libversion());

    return 0;// a.exec();
}
