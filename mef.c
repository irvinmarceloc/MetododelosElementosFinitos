#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char const *argv[])
{

	float x0, xf, y0, yf, l;

	/*Matriz rigidez total*/
	int gl,i,j;

	printf("\nGrados de libertad> ");
	
	scanf("%d",&gl);
	
	float **mRigidez;
	
	mRigidez = (float **)malloc(gl*sizeof(int*));
	
	for (i = 0; i < gl; ++i){mRigidez[i]= (float *) malloc(gl*sizeof(int));}


	for(j = 0; j < gl; j++) {
		for(i = 0; i < gl; i++){
		 mRigidez[i][j] = (float) 0;
		}
	}
	
	/*Matriz rigidez total*/

	int miembros,c=0;
	printf("\nCantidad de miembros> ");
	scanf("%d",&miembros);

	
	while(c<miembros){
		printf("\nMiembro %d", c + 1);
		printf("\nX0 >");
		scanf("%f",&x0);
		printf("Y0 >");
		scanf("%f",&y0);
		printf("\nXf >");
		scanf("%f",&xf);
		printf("Yf >");
		scanf("%f",&yf);
		printf("\nLongitud >");
		scanf("%f",&l);


		float lx,ly;
		lx = (xf - x0)/l;
		ly = (yf - y0)/l;

		float mk[4][4];

		mk[0][0] = lx*lx; 
		mk[1][0] = lx*ly; 
		mk[2][0] = -mk[0][0];
		mk[3][0] = -mk[1][0];

		mk[0][1] = lx*ly; 
		mk[1][1] = ly*ly; 
		mk[2][1] = -mk[0][1];
		mk[3][1] = -mk[1][1];

		mk[0][2] = -mk[0][0]; 
		mk[1][2] = -mk[1][0]; 
		mk[2][2] = -mk[2][0];
		mk[3][2] = -mk[3][0];

		mk[0][3] = -mk[0][1]; 
		mk[1][3] = -mk[1][1]; 
		mk[2][3] = -mk[2][1];
		mk[3][3] = -mk[3][1];		

		int t, s, x01, y01, xf1, yf1;

		printf("\nIndice X0 >");
		scanf("%i",&x01);
		printf("Indice Y0 >");
		scanf("%i",&y01);
		printf("\nIndice Xf >");
		scanf("%i",&xf1);
		printf("Indice Yf >");
		scanf("%i",&yf1);		

		printf("\n");
		
		for (i = 0; i < 4; ++i)
		{
			for (j = 0; j < 4; ++j){
				mk[i][j] = mk[i][j]/l;
				if(mk[i][j]>0) printf(" "); 
				printf("%.4f\t",mk[i][j]);
			}
			printf("\n");		
		}
		printf("\n");

		x01--;
		y01--;
		xf1--;
		yf1--;

		mRigidez[x01][x01] += mk[0][0];
 		mRigidez[x01][y01] += mk[0][1];
		mRigidez[x01][xf1] += mk[0][2];
 		mRigidez[x01][yf1] += mk[0][3];

		mRigidez[y01][x01] += mk[1][0];
 		mRigidez[y01][y01] += mk[1][1];
		mRigidez[y01][xf1] += mk[1][2];
 		mRigidez[y01][yf1] += mk[1][3];

 		mRigidez[xf1][x01] += mk[2][0];
 		mRigidez[xf1][y01] += mk[2][1];
		mRigidez[xf1][xf1] += mk[2][2];
 		mRigidez[xf1][yf1] += mk[2][3];

 		mRigidez[yf1][x01] += mk[3][0];
 		mRigidez[yf1][y01] += mk[3][1];
		mRigidez[yf1][xf1] += mk[3][2];
 		mRigidez[yf1][yf1] += mk[3][3];

		c++;
	}	

	printf("\n=================Matriz Rigidez Global========================\n");
	for (int i = 0; i < gl; ++i)
		{
			for (int j = 0; j < gl; ++j){ 
				printf("%2.4f\t",mRigidez[i][j]);
			}
			printf("\n");		
		}
	printf("\n");

	return 0;
}