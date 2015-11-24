#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

void readfnc(const int N, double* p, const string noisydata);
void filterfnc(const int N, double* p, const string noisydata);
void outputfnc(const int N, double* p);

int main(){
  
  const int N = 237;
  int n;
  double* p = new double [n];
  const string noisydata = "noisy.txt";
  
  readfnc(N,p,noisydata);
  filterfnc(N,p,noisydata);
  outputfnc(N,p);
  
  delete[] p;
  
  
  return 0;
  
}

void readfnc(const int N, double* p, const string noisydata){
  
  ifstream in(noisydata.c_str());
  
  for (int i = 0; i < N; i++){
    in >> p[i];
  }
  
  in.close();
}

void filterfnc(const int N, double* p, const string noisydata){
  
  double palt;//altes p
  double pneu = p[N-1];
  
  for(int j = 0; j < 4; j++){
    
    for(int i = 0; i < N; i++){
      
      palt = p[i];
      p[i] = (pneu + p[i] + p[i+1])/3.0;
      pneu = palt;
      
    }
    
  }
  
}
  
  void outputfnc(const int N, double* p){
    
    ofstream out("filtered.txt");
    
    for(int i = 0; i < N; i++){
      
      out << p[i] << endl;
       
      
    }
    
    out.close();
    
  }
  