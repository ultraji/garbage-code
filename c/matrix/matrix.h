#ifndef __MATRIX__
#define __MATRIX__

typedef struct matrix
{
    int row, col;
    float **ele;
} mat;

/* 创建 */
mat* mat_creat(mat* m, int row, int col);

/* 销毁 */
void mat_del(mat* m);

/* 加法 */
mat* mat_add(mat* s1, mat* s2, mat* d);

/* 减法 */
mat* mat_sub(mat* s1, mat* s2, mat* d);

/* 乘法 */
mat* mat_mul(mat* s1, mat* s2, mat* d);

/* 零 */
mat* mat_zero(mat* m);

/* 单位矩阵 */
mat* mat_eye(mat* m);

/* 转置 */
mat* mat_trans(mat* from, mat* to);

/* 伴随矩阵 */
mat* mat_adj(mat* s, mat* d);

/* 求模 */
float mat_det(mat* m);

/* 求逆 */
mat* mat_inv(mat* from, mat* to);

/* 复制 */
void mat_cpy(mat* src, mat* dst);

/* 打印 */
void mat_print(const mat* m);
#endif
