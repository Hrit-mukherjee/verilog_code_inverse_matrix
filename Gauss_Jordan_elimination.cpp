#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void getmatrix(float **m, int row, int col)
{
	cout<<"-----Enter Matrix-----"<<endl;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cin>>m[i][j];
		}
	}
}
void printmatrix(float **m, int row, int col)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Gauss_Jordan(float **m, int order)
{
	float **mat = new float*[order];
	float temp;
	for(int i=0; i<order; i++)
	{
		mat[i] = new float[2*order];
	}
	for(int i=0; i<order; i++)
	{
		for(int j=0; j<order; j++)
		{
			mat[i][j]=m[i][j];
		}
		for(int j=order; j<2*order; j++)
		{
			if(i==(j-order))
				mat[i][j]=1.0;
			else
				mat[i][j]=0.0;	
		}
	}
	//printmatrix(mat,order,2*order);//Augmented Matrix
	
	//upper triangularisation
	for(int k=0; k<order; k++)
	{
		if(mat[k][k]!=0)
		{
			temp = mat[k][k];
			for(int col=0; col<(2*order); col++)
			{
				mat[k][col] = mat[k][col]/temp;;
			}
			for(int row=k+1; row<order; row++)
			{
				temp = mat[row][k];
				for(int col=0; col<(2*order); col++)
				{
					mat[row][col] = mat[row][col] - temp*mat[k][col];
				}
			}
		}
	}
	//printmatrix(mat,order,2*order);//Gauss-Jordan Elimination
	
	//lower triangularisation
	for(int k=order-1; k>=0; k--)
	{
			for(int row=k-1; row>=0; row--)
			{
				temp = mat[row][k];
				for(int col=0; col<(2*order); col++)
				{
					mat[row][col] = mat[row][col] - temp*mat[k][col];
				}
			}
	}
	//printmatrix(mat,order,2*order);//Gauss-Jordan Elimination
	
	float **minv = new float*[order];
	for(int i=0; i<order; i++)
	{
		minv[i] = new float[order];
	}
	for(int i=0; i<order; i++)
	{
		for(int j=0; j<order; j++)
		{
			minv[i][j] = mat[i][j+order];
		}
	}
	cout<<"-----Printing Inverse Matrix-----"<<endl;
	printmatrix(minv,order,order);//inverse matrix
}
int main()
{
	int order;
	cin>>order;
	float **a = new float*[order];
	for(int i=0; i<order; i++)
	{
		a[i] = new float[order];
	}
	getmatrix(a,order,order);
	cout<<"-----Printing Matrix-----"<<endl;
	printmatrix(a,order,order);
	Gauss_Jordan(a,order);
	
	return 0;
}
