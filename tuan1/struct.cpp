#include<iostream>
using namespace std;
struct Info{
    string name;
    string code;
    double math_score;
    double ph_score;
    double ch_score;
};
class Score{
    private:
        Info info;
    public:
        Score(Info infor){
            info=infor;
        };
        double score_of_sub()
        {
            return (info.math_score+info.ph_score+info.ch_score);
        }
};

class Score1{
    private:
            double *score;
    public:
            Score1(int n_s){
            score=new double; 

            }
}


