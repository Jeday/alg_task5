#include "btsp.h"
#include "limits"

btsp::btsp(const std::vector<point>& _points)
{
  points = _points;
  sz = points.size();
  distance_pool.resize(sz);
  for(int i = 0;i<sz;++i )
      distance_pool[i].resize(sz);

}

double btsp::distance(const point &p1, const point &p2){
    double xdif = p2.first-p1.first;
    xdif = xdif*xdif;
    double ydif = p2.second - p1.second;
    ydif = ydif*ydif;
    return std::sqrt(xdif+ydif);
}

double  btsp::solve(){
    distance_pool[0][0] = 0;
    distance_pool[0][1] = distance(points[0],points[1]);
    for(int j=2; j<sz;++j)
        distance_pool[0][j] = distance_pool[0][j-1] + distance(points[j-1],points[j]);
    double temp, min;
    for ( int i = 1; i < sz; ++i ) {
      for ( int j = i; j < sz; ++j ) {
        distance_pool.at(i).at(j) = -1;
        min = std::numeric_limits<double>::max();
        if ( i == j || i == j -1 ) {
          for( int k = 0; k < i; ++k ) {
            temp = distance_pool.at(k).at(i) + distance(points[k],points[j]);
            min = ( temp < min ) ? temp : min;
          }
          distance_pool.at(i).at(j) = min;
        } else {
          distance_pool.at(i).at(j) = distance_pool.at(i).at(j-1) + distance(points[j-1],points[j]);
        }
      }
    }

    return  distance_pool.at(sz-1).at(sz-1);
  }


