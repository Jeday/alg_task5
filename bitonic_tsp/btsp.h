#ifndef BTSP_H
#define BTSP_H

#include <vector>
#include <utility>
#include <math.h>


    typedef std::pair<double,double> point;

class btsp
    {
public:

    std::vector<std::vector<double>> distance_pool;
    std::vector<point> points;
    int sz;
    double distance(const point& p1,const point& p2);


    btsp(const std::vector<point>& _points);


    int solve();
    };
#endif // BTSP_H
