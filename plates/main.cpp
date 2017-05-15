#include <iostream>

int count_plates(int plt_sz, int ln){
    if(plt_sz > ln)
        return 0;
    if(plt_sz == ln)
        return 1;
    int p_ln = 0;
    int sum = 1;
    while(ln>0){
         ln-=plt_sz;
         p_ln+=plt_sz;
         sum+=1;
         sum+=count_plates(plt_sz,ln);
         sum+=count_plates(plt_sz,p_ln);

        }
    return sum;

}



int main(int argc, char *argv[])
{
    std::cout<<count_plates(2,5);
    return 0;
}
