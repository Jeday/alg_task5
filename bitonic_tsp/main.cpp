#include <iostream>
#include <btsp.h>


int main(int argc, char *argv[])
{
    std::vector<point> v;
    v.push_back({1,5});
    v.push_back({2,3});
    v.push_back({3,2});
    v.push_back({4,8});
    v.push_back({2,-2});
    v.push_back({6,9});
    v.push_back({7,10});
    btsp p(v);
    std::cout<<p.solve();
    return 0;
}
