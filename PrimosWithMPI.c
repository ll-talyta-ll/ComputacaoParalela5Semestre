#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
//método para verificar se um número é primo
int is_prime(int num){
  int max_divisor, d;
  if(num<1)
  return 0;
else if(num==1)
  return 1;
  else if(num>3){
  if(num%2==0)
    return 0;
max_divisor = sqrt(num);
for(d = 3; d<=max_divisor; d+=2){
  if(num%d==0) return 0;
  }
}
return 1;
}
int main(int argc, char** argv){
  double startwtime = 0.0, endwtime;
  int quant = 1000000000,
  i,
  localSum = 0,
  globalSum = 0, tmp;
// comm
  int myrank, nprocs;
// split
  int split,
  begin,
  end;


MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
if (myrank == 0)
  startwtime = MPI_Wtime();
  split = ceil((float)(quant)/nprocs);
  begin = split * myrank;
  end = split * (myrank+1);
// Se acontecer um overflow
if (end > quant)
  end = quant;
for (i = begin; i < end; ++i){
  if (is_prime(i))
    localSum++;
}
if (myrank == 0){
  globalSum = localSum;
  for (i = 1; i < nprocs; ++i)
{
  MPI_Recv(&tmp,1,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
  globalSum += tmp;
}
endwtime = MPI_Wtime();
while(nprocs>=0){
  num =
  nprocs ++;
}
printf("I got %d from", nprocs);
printf("I got %d from", nprocs);
printf("The total primes is %i \n", globalSum, 0, quant);
//SPEEDUP
printf("Time: \t%f\n", endwtime - startwtime);
fflush(stdout);
}
// Mandando a Soma local para o processo principal
else{
MPI_Send(&localSum,1,MPI_INT,0,0,MPI_COMM_WORLD);
}
MPI_Finalize();
return 0;
}
