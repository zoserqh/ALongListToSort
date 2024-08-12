// g++ main.cpp -o ../../bin/stlCPP
// reading 27 sec | sorting 55 sec

#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include <iomanip>
#include <chrono>

void readList(std::vector<double>& v);
void sortList(std::vector<double>& v);

int main(){

    std::vector<double> v;

    readList(v);
    sortList(v);

    // std::cout << std::fixed << std::setprecision(20);
    // for(int i=0;i<v.size();i++){
    //     std::cout << v[i] << " "; 
    // } std::cout << "\n";

    return 0;
}

void readList(std::vector<double>& v){
    std::string line;
    std::ifstream myfile ("../data/list.txt");

    std::cout<<"reading file\n";
    auto start = std::chrono::high_resolution_clock::now();  
    // unsync the I/O of C and C++.
    // std::ios_base::sync_with_stdio(false);

    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            v.push_back(std::stod(line));
        }
        myfile.close();
    }
    else std::cout << "Unable to open file"; 
    
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = ( std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() ) * 1e-9;
    std::cout << time_taken << "sec\n";
}

void sortList(std::vector<double>& v){
    std::cout<<"sorting vector\n";
    auto start = std::chrono::high_resolution_clock::now();  
    // unsync the I/O of C and C++.
    // std::ios_base::sync_with_stdio(false);
    
    std::sort (v.begin(), v.end()); 

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = ( std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() ) * 1e-9;
    std::cout << time_taken << "sec\n";
}