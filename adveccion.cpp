#include <iostream>
using std::cout;
using std::endl;

double u_tnext(double u_tx, double dt, double dx, double c, double u_xant){
  double u = u_tx - c*(dt/dx)*(u_tx - u_xant);
  return u;
}

int main(){
  double  dx = 0.001;
  double dt = 0.001;
  double L = 2;
  double T = 0.5;
  double c = 1;

  
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
     if(x_i < 0.75){
       u[i][0] = 0;
     }
     else if((x_i>= 0.75) && (x_i <= 1.25)){
       u[i][0] = 1;
     }
     else{
       u[i][0] = 0;
     }
   }


   for(int j = 1; j < n_t;j++){
     double t = dt*j;
     cout << t << " ";
     for(int i = 0; i < n_x; i++){
       if((i == 0) || (i == n_x-1)){
	 u[i][j] = u[i][j-1];
       }
       else{
	 u[i][j] = u_tnext(u[i][j-1],dt,dx,c,u[i-1][j-1]);
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
