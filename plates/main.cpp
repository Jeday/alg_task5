#include <iostream>

int count_plates(int plt_sz, int ln){
    if(plt_sz > ln)
        return 0;
    if(plt_sz == ln)
        return 1;
    int p_ln = 0;
    int sum = 1;
    int _ln = ln/2+1;
    ln-=plt_sz;
    while(_ln>0){
         sum+=1;
         sum+=count_plates(plt_sz,ln);
         sum+=count_plates(plt_sz,p_ln);
         ln-=1;
         p_ln+=1;
         _ln-=1;
        }
    return sum;

}

class  plt
    {
public:
    int * solutions;
    int sz;
    int plt_sz;
    int ln;
    plt(int _plt_sz, int _ln) {
         sz = _ln - _plt_sz+2;
         plt_sz = _plt_sz;
         ln =_ln;
         if (sz>0){
         solutions = new int[sz];
         if(solutions == nullptr)
             return;
         solutions[0] = 0;
         solutions[1] = 1;
         for(int i = 2;i<sz;++i)
            solutions[i] = -1;
         }
         for(int i = 0;i<sz;++i)
            std::cout<<solutions[i]<<" ";

    }

    int get_index(int ps,int ln){
        if(ps>ln)
            return 0;
        return ln-ps+1;
    }

   int solve(int ps, int ln){
         int ind = get_index(ps,ln);
         if(solutions[ind] != -1)
             return solutions[ind];
         int sol = 0 ; // solutions counter
         int _ln = ln/2+1; // steps
         int p = 0;
         while(ln-ps-p>=0 && _ln>0){
                 sol+=1;
                 sol+=solve(ps,p)+solve(ps,ln-p-ps);
                 ++p;
                 --_ln;
             }
         solutions[ind] = sol;
         return sol;
     }




    };


int main(int argc, char *argv[])
{
    plt p(3,5);
    std::cout<<p.solve(3,5);

}
