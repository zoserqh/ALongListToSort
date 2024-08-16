// g++ main.cpp -pthread -o ../../bin/stlCPP
// reading 5.62197sec | sorting 55 sec

#include<string>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
#include <iomanip>
#include <chrono>
#include<thread>
#include <filesystem>
#include <cstdint>
#include <cstring>

void readList(std::vector<double>& v);
void sortList(std::vector<double>& v);
void mtRead(char* ptrb,double* ptra,int lengthLine,int arrSize, int nroThreads);
void printTimeTaken(std::chrono::_V2::high_resolution_clock::time_point start,
                    std::chrono::_V2::high_resolution_clock::time_point end,std::string text);
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
    auto start = std::chrono::high_resolution_clock::now();
    
    std::string pathFile = "../data/list.txt";
    std::ifstream myFile (pathFile);
    unsigned long int bufferSize = std::filesystem::file_size(pathFile);
    std::cout << "File size is: "<< bufferSize << " bytes" << std::endl;
    std::unique_ptr<char[]> buffer(new char[bufferSize]);
    
    if (myFile.is_open()){
        myFile.read(buffer.get(), bufferSize);

        //each line have one number with 22 digits + 1 \n = 23
        int lengthLine = 23;
        int arrSize = bufferSize/lengthLine;
        std::unique_ptr<double[]> arr(new double[arrSize]);
        
        //multiThreading using 10 threads
        int nroThreads = 10;
        char* ptrB[nroThreads]; // pointer to buffer
        double* ptrA[nroThreads]; // pointer to array
        std::thread myThreads[nroThreads];
        for(int i=0;i<nroThreads;i++){
            ptrB[i]=&buffer[i*(bufferSize/nroThreads)];
            ptrA[i]=&arr[i*(arrSize/nroThreads)];
            myThreads[i] = std::thread(mtRead,ptrB[i],ptrA[i],lengthLine,arrSize,nroThreads);
        }

        for(int i=0;i<nroThreads;i++){
            myThreads[i].join();
        }

        v.insert(v.begin(),ptrA[0],ptrA[0]+arrSize);
    }
    else {  std::cout << "Unable to open file"; }

    auto end = std::chrono::high_resolution_clock::now();
    printTimeTaken(start,end,"reading file: ");
}

void sortList(std::vector<double>& v){
    auto start = std::chrono::high_resolution_clock::now();  
    // unsync the I/O of C and C++.
    // std::ios_base::sync_with_stdio(false);
    
    std::sort (v.begin(), v.end()); 

    auto end = std::chrono::high_resolution_clock::now();
    printTimeTaken(start,end,"sorting vector: ");
}

void mtRead(char* ptrb, double* ptra, int lengthLine, int arrSize, int nroThreads){
    for(int i=0;i<arrSize/nroThreads;i++){
        char number[lengthLine-1];
        std::memcpy(number,ptrb,lengthLine-1);
        *ptra=std::atof(number);

        ptrb += lengthLine;
        ptra += 1;
    }
    // std::cout<< "id: "<<std::this_thread::get_id()<< " "<< *(ptrb+2) <<"\n";
}

void printTimeTaken(std::chrono::_V2::high_resolution_clock::time_point start,
                    std::chrono::_V2::high_resolution_clock::time_point end,std::string text){
    double time_taken = ( std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() ) * 1e-9;
    std::cout << text << time_taken << " sec\n";

}