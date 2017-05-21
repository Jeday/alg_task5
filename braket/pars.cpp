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
        if (f>l) // case for empty seq
            return;
        if (f == l ){ // one char seq
            if (is_closing(str[f]))
            insertion_map.push({f,opposite(str[f])}); // case for closing bracket
            else
               insertion_map.push({f+1,opposite(str[f])}); // case for openning, idk should have different insertion offset, so far works, bc other shit's broken
            return;
            }
        /// proper seq case
        char c = str[f]; // save up dat openning char
        int f1 = f;      // its position too
        if(!is_closing(str[f])){
            // cycle to find longest proper seq
            // guranteed to find more proper seqs
            int _f = l; // pos of last  good occurence
            while(f<=l){
                if(str[f] == opposite(c))
                    _f = f;
                ++f;
                }
            f=_f;
            }

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




