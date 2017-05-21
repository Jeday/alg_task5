#include "pars.h"

#include "iostream"
int main(int argc, char *argv[])
{
    braket_parser p("<]{}}([])<");
    std::cout<< p.parse("(([))") << std::endl;
    return 0;
}
