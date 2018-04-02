#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
__global__ void number_xor(int* d_out, int* d_in,int num){
        int myid = blockDim.x * blockIdx.x + threadIdx.x;
        int tid = threadIdx.x;
        for( int i = blockDim.x/2;i>0;i=i/2){
          if(tid<i && (myid +i)<num){
            d_in[myid] ^= d_in[myid + i];
          }
        __syncthreads();
        }
        if(tid==0){
        atomicXor(d_out,d_in[myid]);
        }

}

int main(int argc, char** argv){
        int size= atoi(argv[1]);
        int seed = atoi(argv[2]);
        srand(seed);
	 int h_in[size];
        for(int i=0; i<size; i++) {
                h_in[i]= (int)rand();
        }
        int h_out=0;
        int* d_in;
        int* d_out;

        cudaMalloc ((void**)&d_in, size* sizeof(int));
        cudaMalloc ((void**)&d_out, sizeof(int));
        cudaMemcpy(d_out,&h_out, sizeof(int),cudaMemcpyHostToDevice);
	 cudaMemcpy(d_in, h_in, size* sizeof(int), cudaMemcpyHostToDevice);
        int block = (size/1024);
        if(size%1024!=0) block ++;
        number_xor<<<block,1024>>>(d_out, d_in,size);
        cudaMemcpy(&h_out, d_out, sizeof(int), cudaMemcpyDeviceToHost);
        cudaDeviceSynchronize();
	 printf("%d\n",h_out);
        cudaFree(d_out);
        cudaFree(d_in);
        return 0;
}
