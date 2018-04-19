#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

double u_tnext(double u_tx, double dt, double dx, double u_xant){
  double u = u_tx - u_tx*(dt/dx)*(u_tx - u_xant);
  return u;
}

int main(){
  double  dx = 0.01;
  double dt = 0.01;
  double L = 2;
  double T = 0.5;
  double sigma = 0.125;
  double pi =3.1415926;
  
  int n_x = L/dx + 1;
  int n_t = T/dt;
  
  double **u = new double*[n_x];
  double *x = new double[n_x];
  x[0] = 0;
  for(int i = 0; i < n_x; i++){
    u[i] = new double[n_t];
    x[i] = x[i-1] + dx; 
  }

   for(int i = 0; i < n_x; i++){
     double x_i = x[i];
     u[i][0] = exp(-(x_i - 1)*(x_i-1)/(2*sigma*sigma));
   }


   for(int j = 1; j < n_t;j++){
     double t = dt*j;
     cout << t << " ";
     for(int i = 0; i < n_x; i++){
       if((i == 0) || (i == n_x-1)){
	 u[i][j] = u[i][j-1];
       }
       else{
	 u[i][j] = u_tnext(u[i][j-1],dt,dx,u[i-1][j-1]);
       }
       cout << u[i][j] << " ";
     }
     cout << endl;
   }

   cout << 0;
   for(int i = 0; i < n_x; i++){
     cout << " " << x[i] << " ";
   }
   cout << endl;

   

   return 0;
  
}
