#include <string>
#include <utility>
#include <vector>
#include <algorithm>


#include "pars.h"

     char braket_parser::opposite(const char & c){
        switch (c) {
            case '(':
                return ')';
                break;
            case ')':
                return '(';
                break;
            case '{':
                return '}';
                break;
            case '}':
                return '{';
                break;
            case '[':
                return ']';
                break;
            case ']':
                return '[';
                break;
            case '<':
                return '>';
                break;
            case '>':
                return '<';
                break;
            default:
                return 0;
                break;
            }
    }

     bool braket_parser::is_closing(const char& c){
        switch (c) {
            case ')':
            case '}':
            case ']':
            case '>':
                return true;
            default:
                return false;
            }
    }


    braket_parser::braket_parser(){
        str = "";

    }

    void braket_parser::find_opp(int f,int l){
        if (f>l)
            return;
        if (f == l ){
            if (is_closing(str[f]))
            insertion_map.push({f,opposite(str[f])});
            else
               insertion_map.push({f,opposite(str[f])});
            return;
            }
        char c = str[f];
        int f1 = f;
        if(!is_closing(str[f]))
            while(opposite(str[f]) != c && ++f<=l  ){}
        else {
                find_opp(f,f);
                find_opp(f+1,l);
                return;
            }
        if (f<=l){
                 find_opp(f1+1,f-1);
                 find_opp(f+1,l);
                 return;
             }
         else{
               insertion_map.push({f,opposite(c)});
               find_opp(f1+1,l);
               return;
             }

    }

    bool braket_parser::cmpr::operator()(std::pair<int,char> p1,std::pair<int,char> p2){
        return p1.first<p2.first;
    }

    std::string braket_parser::parse(std::string s){
        str = s;
        find_opp(0,str.length()-1);
        while(!insertion_map.empty()){
           int  pos = insertion_map.top().first;
           std::string  c;
           c+=insertion_map.top().second;
           insertion_map.pop();
           str.insert(pos,c);
        }

        return str;
    }




