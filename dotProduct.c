#include "mex.h"
void dotProduct(double *A, double *B, double *AB, mwSize n)
{
	mwSize i;
        *AB=0.0;
	for ( i=0; i<n; i++){
		*AB+=A[i]*B[i];
	}
}

void mexFunction( int nlhs, mxArray *plhs[],int nrhs, const mxArray *prhs[] )
{

	double *A,*B,*AB;
	size_t n,sA,sB;

	if( nlhs != 1){
		mexErrMsgIdAndTxt("MyToolbox:dotProduct:nlhs","One output required.");
	}
	if( nrhs != 2){
		mexErrMsgIdAndTxt("MyToolbox:dotProduct:nrhs","Two vectors input required.");
	}
	sA=mxGetN(prhs[0]);
	sB=mxGetN(prhs[1]);
    mexPrintf("%d %d\n",sA,sB);
	if(sA != sB){
		mexErrMsgIdAndTxt("MyToolbox:dotProduct:nrhs","The vectors have must same length, A[n] ^ B[m] => n==m");
	}
    	if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0])){
        	mexErrMsgIdAndTxt("MyToolbox:dotProduct:notDouble","Input matrix must be type double.");
	}
    	if( !mxIsDouble(prhs[1]) || mxIsComplex(prhs[1])){
        	mexErrMsgIdAndTxt("MyToolbox:dotProduct:notDouble","Input matrix must be type double.");
	}
    	if(mxGetM(prhs[0])!=1){
        	mexErrMsgIdAndTxt("MyToolbox:dotProduct:notRowVector","Input must be a row vector 1.");
	}
    	if(mxGetM(prhs[1])!=1){
        	mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notRowVector","Input must be a row vector 2.");
	}
    	
    
	A=mxGetPr(prhs[0]);
	B=mxGetPr(prhs[1]);
	plhs[0] = mxCreateDoubleMatrix(1,(mwSize)1,mxREAL);
	AB=mxGetPr(plhs[0]);
	dotProduct(A,B,AB,(mwSize)sA);
}
