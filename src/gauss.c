#include "gauss.h"
#include "math.h"

int eliminate(Matrix *mat, Matrix *b){
	int n = mat->r;
	for (int k=0; k<n-1; k++) {
		int ielmax = k;
		double elmax = fabs(mat->data[k][k]);
		for (int i = k+1;i<n;i++) {
			if (fabs(mat->data[i][k]) > elmax) {
				elmax = fabs(mat->data[i][k]);
				ielmax = i;
			}
		}
		if (elmax==0) {
			return 1;
		}	
		if (ielmax != k) {
			double *temp = mat->data[k];
			mat->data[k] = mat->data[ielmax];
			mat->data[ielmax] = temp;

			double temp_b = b->data[k][0];
            		b->data[k][0] = b->data[ielmax][0];
           		b->data[ielmax][0] = temp_b;
		}
		for (int j = k+1; j<n; j++) {
			double r = mat->data[j][k] / mat->data[k][k];
			for (int p = k; p<n; p++){
				mat->data[j][p] = mat->data[j][p] - r*mat->data[k][p];
			}
			b->data[j][0] = b->data[j][0] - r * b->data[k][0];
		}
		if (mat->data[n-1][n-1] == 0) {
			return 1;
		}
	}
	if (mat->data[n-1][n-1] == 0) {
        	return 1;	
	}
	return 0;
}

