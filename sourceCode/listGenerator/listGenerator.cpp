// g++ listGenerator.cpp -o ../../bin/listGenerator
// 75 seg

#include <random>
#include<iostream>
#include<fstream>
#include <iomanip>
//#include<vector>

int main()
{
    int nroValues = 100000000;

    double lower_bound = 0;
    double upper_bound = 1;
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<double> dis(lower_bound, upper_bound);

    std::ofstream myfile;
    myfile.open ("../data/list.txt");
    
    myfile << std::fixed << std::setprecision(20);
    for(int i=0;i<nroValues;i++){
        double a_random_double = dis(gen);
        myfile << a_random_double <<"\n";
    }
    myfile.close();
     
    return 0;
}

/* uniformity tests
    std::vector<double> v;
    for(int i=0;i<nroValues;i++){
        double a_random_double = dis(gen);
        //std::cout << a_random_double << std::endl;
        v.push_back(a_random_double);
    }

    std::vector<int> count(10,0);
    for(int i=0;i<nroValues;i++){
        for(int j=0;j<10;j++){
            if(v[i]<0.1*(j+1)){
                count[j]++;
                break;
            }
        }
    }

    for(int i=0;i<10;i++){
        std::cout<<count[i]<<" ";
    }   std::cout<<"\n";
    */   