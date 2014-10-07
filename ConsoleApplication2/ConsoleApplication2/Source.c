#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main ()  //2bit k diavasma kateu8eian se pin
{
	FILE *input_file; //pointer to read a file
	FILE *output_file; //pointer to write file
   //FILE *output2bit;


	//anoigma arxeiwn

	FILE *inf;
	FILE *outf;
	inf=fopen("input_file.txt","r");
	outf= fopen("output_file.txt","w");

	int charaktiras[100]; //diavazei charaktira

	char pin[100];
	char provle4i[100], apot[100], apotel[100], prov[100];
	char hm,h_m; //hit miss

	int i,z;


	
	 //gia ena bit
	 int sum1=0; //sum of apotelesma=taken
	 int sum2=0; //sum of apotelesma=not taken
	 int sum3=0; //sum of hits
	 int sum4=0; //sum of miss
	 int sum5=0; //sum of provle4i=taken
	 int sum6=0; //sum of provle4i=nottaken

	 //gia 2 bit
	 int ar1=0;
	 int ar2=0;
	 int ar3=0;
	 int ar4=0;
	 int ar5=0;
	 int ar6=0;
	 int ar7=0;
	 int ar8=0;
	 int ar9=0;
	 int ar10=0;
	 int ar11=0;
	 int ar12=0;
	 int ar13=0;
	 int ar14=0;
	 int ar15=0;
	 int ar16=0;
	 int ar17=0;
	 int ar18=0;
	 

	 provle4i[0] = "T";



	while ((charaktiras[z] = fgetc(input_file))!=EOF)
	{
		for (i=0; i<8; i++)
		{
		pin[i]=charaktiras[z]+charaktiras[z+1]+charaktiras[z+2]+charaktiras[z+3]+charaktiras[z+4]+charaktiras[z+5]+charaktiras[z+6]+charaktiras[z+7];
		//}


//		for (i=0; i<100; i++)
//		{
			if (pin[i]>'FFFFFFFF' || pin[i]<00000000 || (charaktiras[i]>'g' && charaktiras[i]<='z') )
			{
				printf ("error\n");
					exit;
			}

		}


	}

	fclose(input_file);
	fclose(output_file);

	inf=fopen("input_file.txt","r");
	outf= fopen("output_file.txt","w");
//3anaanoigmaaa

	//1bit
for (int i=0; i<=100; i++)
		{
				
			if (pin[i]=pin [i+1])
			{
				apot[i] = "T";
				sum1=sum1+1;
			}
			else
			{
				apot[i] = "N";
				sum2=sum2+1;
			}

			if (provle4i[i] = "T" && apot[i] = "T")
			{
				provle4i[i+1] = "T";
				sum5=sum5+1;
				hm = "H";
				sum3=sum3+1;
			}
			else if (provle4i[i] = "T" && apot[i] = "N")
			{
				hm = "M";
				sum4=sum4+1;
				provle4i[i+1] = "N";
				sum6=sum6+1;
			}
			else if (provle4i[i] = "N" && apot[i] = "T")
			{
				hm = "M";
				sum4=sum4+1;
				provle4i[i+1] = "T";
				sum5=sum5+1;
			}
			else if (provle4i[i] = "N" && apot[i] = "N")
			{
				hm = "H";
				sum3=sum3+1;
				provle4i[i+1] = "N";
				sum6=sum6+1;
			}
	


		}
		


	}

	printf_s("sum of apotelesma=taken %d \n", sum1);
	printf_s("sum of apotelesma=not taken %d \n", sum2);
	printf_s("sum of hits %d \n", sum3);
	printf_s("sum of miss %d \n", sum4);
	printf_s("sum of provle4i=taken %d\n", sum5);
	printf_s("sum of provle4i=nottaken %d\n", sum6);



	
//2 BIT

	prov[0]="T";

	for (int i=0; i<=100; i++)
		{

				
			if (pin[i]=pin [i+1])
			{
				apotel[i]="T";
				ar1=ar1+1;
			}
			else
			{
				apotel[i]="N";
				ar2=ar2+1;
			}




			if (prov[i]="T" && apotel[i]="T")      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				prov[i+1]="T";
				ar5=ar5+1;
				h_m="H";
				ar3=ar3+1;
			}
			else if (prov[i]="T" && apotel[i]="N")
			{
				h_m="M";
				ar4=ar4+1;
				prov[i+1]="I";
				ar6=ar6+1;
			}

			else if (prov[i]="I" && apotel[i]="T")
			{
				h_m="H";
				ar7=ar7+1;
				prov[i+1]="T";
				ar8=ar8+1;
			}
			else if (prov[i]="I" && apotel[i]="N")
			{
				h_m="M";
				ar9=ar9+1;
				prov[i+1]="D";
				ar10=ar10+1;
			}
			else if (prov[i]="D" && apotel[i]="N")
			{
				h_m="H";
				ar11=ar11+1;
				prov[i+1]="D";
				ar12=ar12+1;
			}
			else if (prov[i]="D" && apotel[i]="T")
			{
				h_m="M";
				ar13=ar13+1;
				prov[i+1]="N";
				ar14=ar14+1;
			}
			else if (prov[i]="N" && apotel[i]="T")
			{
				h_m="M";
				ar15=ar15+1;
				prov[i+1]="T";
				ar16=ar16+1;
			}
			else if (prov[i]="N" && apotel[i]="N")
			{
				hm="H";
				ar17=ar17+1;
				prov[i+1]="N";
				ar18=ar18+1;
			}
	
			//printf ar
	}






//KLEISIMO ARXEIWN

	fclose(input_file);
	fclose(output_file);



	system ("pause");
		return (0);
}