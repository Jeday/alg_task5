#ifndef PARS_H
#define PARS_H

#include <string>
#include <vector>
#include <utility>
#include <queue>

class braket_parser{

public:

    class cmpr{
    public:
        bool operator()(std::pair<int,char> p1,std::pair<int,char> p2);
    };

    std::string str;
    std::priority_queue<std::pair<int,char>,std::vector<std::pair<int,char>>,cmpr> insertion_map;

    static char opposite(const char & c);

    static bool is_closing(const char& c);
    braket_parser();
    braket_parser(std::string s):str(s){}

    void find_opp(int f,int l);
    std::string parse(std::string s);


};





#endif // PARS_H
