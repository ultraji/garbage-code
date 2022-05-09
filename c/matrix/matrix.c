#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define min(a, b) ((a) > (b) ? (b) : (a))
#define equal(a, b)	((a-b)<1e-7 && (a-b)>-(1e-7))

static void swap(int *a, int *b)
{
	int m;
	m = *a;
	*a = *b;
	*b = m;
}

static void perm(int list[], int k, int m, int* p, mat* mat, float* det) 
{
	int i;

	if(k > m){
		float res = mat->ele[0][list[0]];

		for (i = 1; i < mat->row; i++) {
			res *= mat->ele[i][list[i]];
		}

		if (*p%2) {
			*det -= res;
		} else {
			*det += res;
		}
	}
	else {
		if(!equal(mat->ele[k][list[k]], 0.0f))
			perm(list, k + 1, m, p, mat, det);
		for(i = k+1; i <= m; i++)
		{
			if(equal(mat->ele[k][list[i]], 0.0f))
				continue;
			swap(&list[k], &list[i]);
			*p += 1;
			perm(list, k + 1, m, p, mat, det);
			swap(&list[k], &list[i]);
			*p -= 1; 
		}
	}
}

mat* mat_creat(mat *m, int row, int col)
{
    int i = 0, j = 0;

	m->ele = (float**)malloc( row * sizeof(float*) );
	if (!m->ele) {
		return NULL;
	}
	for (i = 0; i < row; i++) {
		m->ele[i] = (float*)malloc( col * sizeof(float) );	
		if (!m->ele[i]) {
			for (j = 0; j < i; j++) {
				free(m->ele[j]);
            }
			free(m->ele);
			return NULL;
		}
	}
	m->row = row;
	m->col = col;

	return m;
}

void mat_del(mat* m)
{
	int i = 0;

	for(i = 0; i < m->row; i++)
	{
		free(m->ele[i]);
	}
	free(m->ele);
}


mat* mat_add(mat* s1, mat* s2, mat* d)
{
    int row = 0, col = 0;

	if( s1->row != s2->row || s2->row != d->row || s1->col != s2->col || s2->col != d->col ){
		return NULL;
	}
	for(row = 0 ; row < s1->row ; row++){
		for(col = 0 ; col < s1->col ; col++){
			d->ele[row][col] = s1->ele[row][col] + s2->ele[row][col];
		}
	}

	return d;
}


mat* mat_sub(mat* s1, mat* s2, mat* d)
{
    int row = 0, col = 0;

	if( s1->row != s2->row || s2->row != d->row || s1->col != s2->col || s2->col != d->col ){
		return NULL;
	}
	for(row = 0 ; row < s1->row ; row++){
		for(col = 0; col < s1->col; col++){
			d->ele[row][col] = s1->ele[row][col] - s2->ele[row][col];
		}
	}

	return d;
}


mat* mat_mul(mat* s1, mat* s2, mat* d)
{
	int row = 0, col = 0, i = 0;
	float temp;

	if( s1->col != s2->row || s1->row != d->row || s2->col != d->col ){
		return NULL;
	}
	for(row = 0 ; row < d->row ; row++){
		for(col = 0 ; col < d->col ; col++){
			temp = 0.0f;
			for(i = 0 ; i < s1->col ; i++){
				temp += s1->ele[row][i] * s2->ele[i][col];
			}
			d->ele[row][col] = temp;
		}
	}

	return d;
}


mat* mat_zero(mat* m)
{
	int i, j;

	for(i = 0 ; i < m->row ; i++){
		for(j = 0 ; j < m->col ; j++){
			m->ele[i][j] = 0.0f;
		}
	}

	return m;
}


mat* mat_eye(mat* m)
{
	int i;
	
	mat_zero(m);
	for(i = 0; i < min(m->row, m->col); i++){
		m->ele[i][i] = 1.0f;
	}

	return m;
}



mat* mat_trans(mat* from, mat* to)
{
    int row, col;

	if( from->row != to->col || from->col != to->row ){
		return NULL;
	}
	for(row = 0; row < to->row; row++){
		for(col = 0; col < to->col; col++){
			to->ele[row][col] = from->ele[col][row];
		}
	}

	return to;

}

float mat_det(mat* m)
{
	float det = 0.0f;
	int plarity = 0;
	int *list;
	int i;

	if( m->row != m->col){
		return 0.0f;
	}

	list = (int*)malloc(sizeof(int)*m->col);
	if(list == NULL){
		return 0.0f;
	}
	for(i = 0 ; i < m->col ; i++)
		list[i] = i;

	perm(list, 0, m->row-1, &plarity, m, &det);
	free(list);

	return det;
}

mat* mat_adj(mat* s, mat* d)
{
	mat smat;
	int row, col;
	int i, j, r, c;
	float det;

	if( s->row != s->col || s->row != d->row || s->col != d->col){
		return NULL;
	}

	mat_creat(&smat, s->row-1, s->col-1);

	for(row = 0 ; row < s->row ; row++){
		for(col = 0 ; col < s->col ; col++){
			r = 0;
			for(i = 0 ; i < s->row ; i++){
				if(i == row) {
					continue;
                }
				c = 0;
				for(j = 0; j < s->col ; j++){
					if(j == col) {
						continue;
                    }
					smat.ele[r][c] = s->ele[i][j];
					c++;
				}
				r++;
			}
			det = mat_det(&smat);
			if ( (row + col) % 2 != 0) {
				det = -det;
            }
			d->ele[col][row] = det;
		}
	}

	mat_del(&smat);

	return d;
}

mat* mat_inv(mat* from, mat* to)
{
	mat adj_mat;
	float det;
	int row, col;

	if ( from->row != from->col || from->row != to->row || from->col != to->col) {
		return NULL;
	}

	mat_creat(&adj_mat, from->row, from->col);
	mat_adj(from, &adj_mat);
	det = mat_det(from);

	if (det<1e-7 && det>-(1e-7)) {
		return NULL;
	}
	
	for(row = 0 ; row < from->row ; row++){
		for(col = 0 ; col < from->col ; col++)
			to->ele[row][col] = adj_mat.ele[row][col] / det;
	}
	
	mat_del(&adj_mat);

	return to;
}


void mat_cpy(mat* src, mat* dst)
{
	int i, j;

	if( src->row != dst->row || src->col != dst->col){
		return ;
	}
	
	for(i = 0; i < src->row; i++){
		for(j = 0; j < src->col; j++) {
			dst->ele[i][j] = src->ele[i][j];
        }
	}
}

void mat_print(const mat* m)
{
	int row,col;

	if(m == NULL){
		return ;
	}

	printf("mat %dx%d:\n", m->row, m->col);
	for(row = 0 ; row < m->row ; row++){
		for(col = 0 ; col < m->col ; col++){
			printf("%.4f\t", m->ele[row][col]);
		}
		printf("\n");
	}
}