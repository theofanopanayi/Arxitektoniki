#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()  //2bit k diavasma kateu8eian se pin
{
	FILE *input_file; //pointer to read a file
	//FILE *output_file; //pointer to write file
	//FILE *output1bit;
   //FILE *output2bit;

    bool charaktiras[8]; //diavazei charaktira
	//anoigma arxeiwn

	input_file=fopen("eisodos.txt","r");
	//output_file= fopen("exodos.txt, "w");

	/*
	ena bit


	*/
	 bool pin[100];
	 bool provle4i[100], apot[100];
	 bool hm; //hit miss

	 int sum1=0; //sum of apotelesma=taken
	 int sum2=0; //sum of apotelesma=not taken
	 int sum3=0; //sum of hits
	 int sum4=0; //sum of miss
	 int sum5=0; //sum of provle4i=taken
	 int sum6=0; //sum of provle4i=nottaken


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
	 

	 provle4i[0]="taken";


	 int i,z;

	while ((charaktiras[z] = fgetc(input_file))!=EOF)
	{
		while ((charaktiras[z] = fgetc(input_file))!=NULL)
		{
			pin[i]=charaktiras[z]+charaktiras[z+1]+charaktiras[z+2]+charaktiras[z+3]+charaktiras[z+4]+charaktiras[z+5]+charaktiras[z+6]+charaktiras[z+7];
		}



		for (int i=0; i<=100; i++)
		{

			
				
			if (pin[i]=pin [i+1])
			{
				apot[i]="taken";
				sum1=sum1+1;
			}
			else
			{
				apot[i]="not_taken";
				sum2=sum2+1;
			}

			if (provle4i[i]="taken" && apot[i]="taken")
			{
				provle4i[i+1]="taken";
				sum5=sum5+1;
				hm="hit";
				sum3=sum3+1;
			}
			else if (provle4i[i]="taken" && apot[i]="not_taken")
			{
				hm="miss";
				sum4=sum4+1;
				provle4i[i+1]="not_taken";
				sum6=sum6+1;
			}
			else if (provle4i[i]="not_taken" && apot[i]="taken")
			{
				hm="miss";
				sum4=sum4+1;
				provle4i[i+1]="taken";
				sum5=sum5+1;
			}
			else if (provle4i[i]="not_taken" && apot[i]="not_taken")
			{
				hm="hit";
				sum3=sum3+1;
				provle4i[i+1]="not_taken";
				sum6=sum6+1;
			}
	


		}
		pin[0..100]=NULL;


	}

	printf("sum of apotelesma=taken %d \n", sum1);
	printf("sum of apotelesma=not taken %d \n", sum2);
	printf("sum of hits %d \n", sum3);
	printf("sum of miss %d \n", sum4);
	printf("sum of provle4i=taken %d\n", sum5);
	printf("sum of provle4i=nottaken %d\n", sum6);







//2 BIT

	prov[0]="taken";

	for (int i=0; i<=100; i++)
		{

				
			if (pin[i]=pin [i+1])
			{
				apotel[i]="taken";
				ar1=ar1+1;
			}
			else
			{
				apote[i]="not_taken";
				ar2=ar2+1;
			}




			if (prov[i]="taken" && apotel[i]="taken")
			{
				prov[i+1]="taken";
				ar5=ar5+1;
				h_m="hit";
				ar3=ar3+1;
			}
			else if (prov[i]="taken" && apotel[i]="not_taken")
			{
				h_m="miss";
				ar4=ar4+1;
				prov[i+1]="taken2";
				ar6=ar6+1;
			}

			else if (prov[i]="taken2" && apotel[i]="taken")
			{
				h_m="hit";
				ar7=ar7+1;
				prov[i+1]="taken";
				ar8=ar8+1;
			}
			else if (prov[i]="taken2" && apotel[i]="not_taken")
			{
				h_m="miss";
				ar9=ar9+1;
				prov[i+1]="not_taken2";
				ar10=ar10+1;
			}
			else if (prov[i]="not_taken2" && apotel[i]="not_taken")
			{
				h_m="hit";
				ar11=ar11+1;
				prov[i+1]="not_taken2";
				ar12=ar12+1;
			}
			else if (prov[i]="not_taken2" && apotel[i]="taken")
			{
				h_m="miss";
				ar13=ar13+1;
				prov[i+1]="not_taken";
				ar14=ar14+1;
			}
			else if (prov[i]="not_taken" && apotel[i]="taken")
			{
				h_m="miss";
				ar15=ar15+1;
				prov[i+1]="taken";
				ar16=ar16+1;
			}
			else if (prov[i]="not_taken" && apotel[i]="not_taken")
			{
				hm="hit";
				ar17=ar17+1;
				prov[i+1]="not_taken";
				ar18=ar18+1;
			}
	

	}






//KLEISIMO ARXEIWN

	fclose(input_file);
	//fclose(output_file);
	
	return(0);



}