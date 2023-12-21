#include "gauss.h"

int eliminate(Matrix *mat, Matrix *b){
	int n = mat->r;
	for (int k = 0; k < n - 1; k++) {
        	if (mat->data[k][k] == 0.0) {
            		return 1; 
        }
        for (int i = k + 1; i < n; i++) {
            	double m = mat->data[i][k] / mat->data[k][k];
            	for (int j = k; j < n; j++) {
                	mat->data[i][j] -= m * mat->data[k][j];
            	}
            
            	b->data[i][0] -= m * b->data[k][0];
        }
    }
    return 0;
}

