#include <iostream>
#include <cmath>

using namespace std;

void matrixInversion(double **a, int n)//矩阵求逆
{
	int *is = new int[n];
	int *js = new int[n];
	int i,j,k;
	double d,p;
	for ( k = 0; k < n; k++)
	{
		d = 0.0;
		for (i=k; i<=n-1; i++)
			for (j=k; j<=n-1; j++)
			{
				p=fabs(a[i][j]);
				if (p>d) { d=p; is[k]=i; js[k]=j;}
			}
        if ( 0.0 == d )
        {
            free(is); free(js); printf("err**not inv\n");
        }
        if (is[k]!=k)
            for (j=0; j<=n-1; j++)
            {
                p=a[k][j];
                a[k][j]=a[is[k]][j];
                a[is[k]][j]=p;
            }
        if (js[k]!=k)
            for (i=0; i<=n-1; i++)
            {
                p=a[i][k];
                a[i][k]=a[i][js[k]];
                a[i][js[k]]=p;
            }
        a[k][k] = 1.0/a[k][k];
        for (j=0; j<=n-1; j++)
            if (j!=k)
            {
                a[k][j] *= a[k][k];
            }
        for (i=0; i<=n-1; i++)
            if (i!=k)
                for (j=0; j<=n-1; j++)
                    if (j!=k)
                    {
                        a[i][j] -= a[i][k]*a[k][j];
                    }
        for (i=0; i<=n-1; i++)
            if (i!=k)
            {
                a[i][k] = -a[i][k]*a[k][k];
            }
	}
	for ( k = n-1; k >= 0; k--)
	{
		if (js[k]!=k)
			for (j=0; j<=n-1; j++)
			{
				p = a[k][j];
				a[k][j] = a[js[k]][j];
				a[js[k]][j]=p;
			}
        if (is[k]!=k)
            for (i=0; i<=n-1; i++)
            {
                p = a[i][k];
                a[i][k]=a[i][is[k]];
                a[i][is[k]] = p;
            }
	}
	free(is); free(js);
}
/*
double compute(int i,int j,int ibegin,int jbegin,int wsize)
{
    double sigma=0;//总和
    double sigmak[3][3];//sigma k
    double E;//参数
    double _wk_;//绝对值wk
    double tmp[3][3];//中间的部分
    double uk[3];//参数uk
    double Ii[3],Ij[3];
    for(int k=0;k<3;k++)//中间部分
        for(int l=0;l<3;l++)
            if(k==l)
                tmp[k][l]=sigmak[k][l]+E/_wk_;
            else
                tmp[k][l]=sigmak[k][l];
    matrixInversion(tmp[3][3],3);
    double sigma_part1[3];
    for(k=0;k<3;k++)
    {
        sigma_part1[k]=0;
        for(l=0;l<3;l++)
            sigma_part1[k]+=(Ii[k]-uk)*tmp[l][k];
        sigma+=sigma_part1[k]*(Ij-uk);
    }
    sigma++;
    sigma=-sigma/_wk_;
    if(i==j) sigma++;
    return sigma;
}
*/

int main()
{
	//prior_testMatrix();	// 这个是测试原来的方法的函数，内容和原来的main函数一致
	int i,j;
	double a[4][4];
	for(int i1 = 0; i1 < 4; i1++){
		for(int i2 = 0; i2 < 4; i2++){
			cin >> a[i1][i2];
		}
	}
    
	double b[4][4];
	for (i=0; i< 4; i++)
	{
		for (j=0; j< 4; j++)
			b[i][j]=a[i][j];		// 拷贝a
	}
    
	matrixInversion(b,4);	// 计算逆矩阵，结果在b中
	printf("MAT A IS:\n");
	for (i=0; i<=3; i++)
	{
		for (j=0; j<=3; j++)
			printf("%13.4f",a[i][j]);
		printf("\n");
	}
	printf("\nMAT A- IS:\n");
	for (i=0; i<=3; i++)
	{
		for (j=0; j<=3; j++)
			printf("%13.4f",b[i][j]);
		printf("\n");
	}

	cout << "Check the result" << endl;
	for(int i1 = 0; i1 < 4; i1++){
		for(int i2 = 0; i2 < 4; i2++){
			double sum = 0.0;
			for(int k = 0; k < 4; k++){
				 sum += a[i1][k] * b[k][i2]; 
			}
			cout << sum << ' ';
		}
		cout << endl;
	}

	return 0;
}
