#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

int main ()  
{
	FILE *input_file; //pointer to read a file
	FILE *output_file; //pointer to write file
  
	//anoigma arxeiwn

	FILE *inf;
	FILE *outf;
	inf=fopen("input_file.txt","r");
	outf= fopen("output_file.txt","w");

	char charaktiras; //diavazei charaktira

	int pin[1000][0];
	//char provle4i[100], apot[100], apotel[100], prov[100];
	char hm,h_m; //hit miss

	int i,z;

	//gia ena bit
	int sum1=0; //sum of apotelesma=taken
	int sum2=0; //sum of apotelesma=not taken
	int sum3=0; //sum of hits
	 

	 //gia 2 bit
	int ar1=0;
	int ar2=0;
	int ar3=0;
	

	 provle4i[0] = "T";


	 for (i=0; i<1000; i++)
		{
			while ((charaktiras = fgetc(input_file))!=EOF)
			{
	
				if (charaktiras<0 || charaktiras>9 || charaktiras!='A' || charaktiras!='B' || charaktiras!='C' || charaktiras!='D' || charaktiras!='E' || charaktiras!='F' || charaktiras!='A')
				{
					fprintf ("error");
					exit;
				}

				while (charaktiras != '\n')//for (i=0; i<8; i++)
				{
					pin[i]=charaktiras;
				}
				
			

			}


		}

	

	 fclose(input_file);
	 fclose(output_file);



	//3anaanoigmaaa


	 inf=fopen("input_file.txt","r");
	 outf= fopen("output_file.txt","w");


	//1bit
	 for (int i=0; i<=100; i++)
		{
				
			if (pin[i]=pin[i+1])
			{
				apot[i] = "T";
				sum1=sum1+1;
				fprintf ("taken\n");
			}
			else
			{
				apot[i] = "N";
				sum2=sum2+1;
				fprintf("not taken");
			}

			if (provle4i[i] = "T" && apot[i] = "T")
			{
				provle4i[i+1] = "T";
				fprintf ("hit");
				hm = "H";
				sum3=sum3+1;
			}
			else if (provle4i[i] = "T" && apot[i] = "N")
			{
				hm = "M";
				fprintf ("miss");
				provle4i[i+1] = "N";
				fprintf ("not taken");
				
			}
			else if (provle4i[i] = "N" && apot[i] = "T")
			{
				hm = "M";
				fprintf ("miss");
				provle4i[i+1] = "T";
				
			}
			else if (provle4i[i] = "N" && apot[i] = "N")
			{
				hm = "H";
				fprintf ("hit");
				sum3=sum3+1;
				provle4i[i+1] = "N";
				
			}
	


		}
		


	}

	printf("sum of apotelesma=taken %d \n", sum1);
	printf("sum of apotelesma=not taken %d \n", sum2);
	printf("sum of hits %d \n", sum3);
	
	fprintf (sum3); //pososto epitixias hit/all
	fprintf ("/");
	fprintf (sum2+sum1);




//2 BIT

	prov[0]="T";

	for (int i=0; i<=100; i++)
		{

				
			if (pin[i]=pin [i+1])
			{
				apotel[i]="T";
				fprintf("taken");
				ar1=ar1+1;
			}
			else
			{
				apotel[i]="N";
				fprintf("not taken");
				ar2=ar2+1;
			}




			if (prov[i]="T" && apotel[i]="T")      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				prov[i+1]="T";
				h_m="H";
				ar3=ar3+1;
				fprintf ("hit");
			}
			else if (prov[i]="T" && apotel[i]="N")
			{
				h_m="M";
				fprintf ("miss");
				prov[i+1]="I";
				
			}

			else if (prov[i]="I" && apotel[i]="T")
			{
				h_m="H";
				ar3=ar3+1;
				prov[i+1]="T";
				fprintf ("hit");
				
			}
			else if (prov[i]="I" && apotel[i]="N")
			{
				h_m="M";
				fprintf ("miss");
				prov[i+1]="D";
				
			}
			else if (prov[i]="D" && apotel[i]="N")
			{
				h_m="H";
				ar3=ar3+1;
				prov[i+1]="D";
				fprintf ("hit");
				
			}
			else if (prov[i]="D" && apotel[i]="T")
			{
				h_m="M";
				fprintf ("miss");
				prov[i+1]="N";
				
			}
			else if (prov[i]="N" && apotel[i]="T")
			{
				h_m="M";
				fprintf ("miss");
				prov[i+1]="T";
				
			}
			else if (prov[i]="N" && apotel[i]="N")
			{
				hm="H";
				ar3=ar3+1;
				prov[i+1]="N";
				fprintf ("hit");
				
			}
	
			
	}


	printf("sum of apotelesma=taken %d \n", ar1);
	printf("sum of apotelesma=not taken %d \n", ar2);
	printf("sum of hits %d \n", ar3);
	
	fprintf (ar3); //pososto epitixias hit/all
	fprintf ("/");
	fprintf (ar2+ar1);



//KLEISIMO ARXEIWN

	fclose(input_file);
	fclose(output_file);



	system ("pause");
	return (0);
}