#include<stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

int main ()  
{ 

	//gia ena bit
	int sum1=1; //sum of apotelesma=taken
	int sum2=1; //sum of apotelesma=not taken
	int sum3=1; //sum of hits
	//gia 2 bit
	int finish = 0;
	int p=0;
	int ar1=0;
	int ar2=0;
	int ar3=0;
	int j=0;
	bool apot;
	int x=0;
	int counter = 0;
	
	char charaktiras; //diavazei charaktira
	char first[8];
	char sec[8];
	char third[8];
	char pin[1000][8];
	char hm,h_m; //hit miss
	int i=0;
	int z=0;
	int a=0;
	int w=0;
	int k=0;
	char provle4i1;
	char provle4i2;
	char apotel;
	char prov;
	

	
	//anoigma arxeiwn

	FILE *inf;
	FILE *outf;
	inf=fopen("input_file.txt","r");
	outf= fopen("output_file.txt","w");
	
	charaktiras = fgetc(inf);

			while (charaktiras!=EOF)  //elegxos
			{
	           if (z>8)
			   {
				if (charaktiras !='0' && charaktiras!='1' && charaktiras!='2' && charaktiras!='3' && charaktiras!='4' && charaktiras!='5' && charaktiras!='6' && charaktiras!='7' && charaktiras!='8' && charaktiras!='9' && charaktiras!='A' && charaktiras!='B' && charaktiras!='C' && charaktiras!='D' && charaktiras!='E' && charaktiras!='F'&& charaktiras!='\n')
				{
					fprintf (outf, "error char");
					return 0;
				}
			z++;
				}

			
		
		/*	else
					if (charaktiras != '\n')
					{
						fprintf (outf, "error num of chars");
						return 0;
					}*/
				charaktiras = fgetc(inf);
			}
	 
	 fclose(inf);
	 inf=fopen("input_file.txt","r");

	 for (i=0; i<1000; i++)
	 {
		
				for (j=0; j<8; j++)
				{
					charaktiras=fgetc(inf);
					pin[i][j]=charaktiras;
				}		

		if (i==0)
		{
			for (j=0; j<8; j++)
			{	
				first[j]=pin[i][j];
		//		fprintf(outf,"%c",first[j]);
				w=0;
			}
			//fprintf(outf,"\n");
		}
		else if (i>=1 && w==0)
		{
			p=0;
			for (j =0;j<8;j++)
			{
				if (first[j]!=pin[i][j])
				{
					p++;
				}
			}
			if (p!=0)
			{
			for (j=0;j<8;j++)
			{
				sec[j]=pin[i][j];
				//fprintf(outf,"%c",sec[j]);
			}
			//fprintf(outf,"\n");
			w=1;
		    }
		}
		else if (i>=1  && w==1)
		{
			p=0;
		for (j =0;j<8;j++)
		{
			if (first[j]!=pin[i][j])
			{
			 if (sec[j]!=pin[i][j])
			{
				p++;
			}
			}
			if (p!=0)
			{
			for (j=0;j<8;j++)
			{
			third[j]=pin[i][j];
			}
			w=2;
			counter = i;
			i=1000;
			}

		}
		/////////////////
		for  (i=0; i<counter; i++)
		{ 
			z=0;
			for (j=0; j<8; j++)
			{ x=0;
				if (first[j] = pin[i][j])  //1os branch
				{
					x++;
				}

				if (x=8 && z==0);
				{
					provle4i1 = 'T';
					provle4i2 = 'N';
				}

				z=1;
			}
			for (j=0; j<8; j++)
			{ x=0;
				if (sec[j] = pin [i][j])  //2os branch
				{
					x++;
				}

				if (x=8 && z==1);
				{
					provle4i1 = 'T';
					provle4i2 = 'N';
				}

			}

			for (j=0; j<8; j++)
			{

				if (pin[i][j] == pin[i+1][j])
				{
					apotel = 'T';
				}
				else
				{
					apotel = 'N';
				}
			}

			for (j=0; j<8; j++)
			{
			if (provle4i1 == 'T' && apotel == 'T')
			{
				//provle4i = 'T';
				fprintf (outf, "hit\n");
				hm = 'H';
				sum3=sum3+1;
			}
			else if (provle4i1 == 'T' && apotel == 'N')
			{
				hm = 'M';
				fprintf (outf, "miss\n");
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i1 == 'N' && apotel == 'T')
			{
				hm = 'M';
				fprintf (outf, "miss\n");
				//provle4i2 = 'T';
				
			}
			else if (provle4i1 == 'N' && apotel == 'N')
			{
				hm = 'H';
				fprintf (outf, "hit\n");
				sum3=sum3+1;
				//provle4i2 = 'N';
				
			}


			}
				

		}






	//fprintf(outf, "2bit");
	for  (i=0; i<counter; i++)
		{ 
			for (j=0; j<8; j++)
		{

			if (provle4i1=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				prov='T';
				h_m='H';
				ar3=ar3+1;
				fprintf (outf, "hit\n");
			}
			else if (provle4i1=='T' && apotel=='N')
			{
				h_m='M';
				fprintf (outf, "miss\n");
				provle4i2='I';
				
			}

			else if (provle4i1=='I' && apotel=='T')
			{
				h_m='H';
				ar3=ar3+1;
				provle4i2='T';
				fprintf (outf, "hit\n");
				
			}
			else if (provle4i1=='I' && apotel=='N')
			{
				h_m='M';
				fprintf (outf, "miss\n");
				provle4i2='D';
				
			}
			else if (provle4i1=='D' && apotel=='N')
			{
				h_m='H';
				ar3=ar3+1;
				provle4i2='D';
				fprintf (outf, "hit\n");
				
			}
			else if (provle4i1=='D' && apotel=='T')
			{
				h_m='M';
				fprintf (outf , "miss\n");
				provle4i2='N';
				
			}
			else if (provle4i1=='N' && apotel=='T')
			{
				h_m='M';
				fprintf (outf, "miss\n");
				provle4i2 = 'T';
				
			}
			else if (provle4i1=='N' && apotel=='N')
			{
				hm='H';
				ar3=ar3+1;
				provle4i2='N';
				fprintf (outf, "hit\n");
				
			}


	
			
	}

	}




/////////


		}
		charaktiras=fgetc(inf);
	}
	/*fprintf(outf,"\n");
	for (i=0;i>8;i++)
	{
		fprintf(outf,"%c",first[i]);
	}
	fprintf(outf,"\n");
	for (i=0;i>8;i++)
	{
		fprintf(outf,"%c",sec[i]);
	}
	fprintf(outf,"\n");
	for (i=0;i>8;i++)
	{
		fprintf(outf,"%c",third[i]);
	}
	fprintf(outf,"\n");
	fprintf(outf,"\n");
	fprintf(outf,"\n");
	*/
	  for (i=1; i<30;i++)
	 {
		 for (j=0; j<8; j++)
		 {
			 fprintf (outf, "%c", pin[i][j]);
		 }
		 fprintf(outf,"\n");
	 }




	fprintf(outf, "sum of apotelesma=taken %d \n", sum1);
	fprintf(outf, "sum of apotelesma=not taken %d \n", sum2);
	fprintf(outf, "sum of hits %d \n", sum3);
	
	fprintf (outf, "%d", sum3); //pososto epitixias hit/all
	fprintf (outf, "/");
	fprintf (outf, "%d", sum2+sum1);


	  
	fprintf(outf, "sum of apotelesma=taken %d \n", ar1);
	fprintf(outf, "sum of apotelesma=not taken %d \n", ar2);
	fprintf(outf, "sum of hits %d \n", ar3);
	
	fprintf (outf, "%d", ar3); //pososto epitixias hit/all
	fprintf (outf, "/");
	fprintf (outf, "%d", ar2+ar1);

	/* while(finish==0)
	 {
		 for(i=0;i<8;i++)
		 {
		 pin[0][i]=third[i];
		 first[i]=third[i];
		 sec[i]=NULL;
		 third[i]=NULL;
		 }
	
	 
	  for (i=1; i<1000; i++)
	 {
		
				for (j=0; j<8; j++)
				{
					charaktiras=fgetc(inf);
					pin[i][j]=charaktiras;
				}		

		if (i==1)
		{	
				w=0;
			}
		else if (i>1 && w==0)
		{
			p=0;
			for (j =0;j<8;j++)
			{
				if (first[j]!=pin[i][j])
				{
					p++;
				}
			}
			if (p!=0)
			{
			for (j=0;j<8;j++)
			{
				sec[j]=pin[i][j];
				//fprintf(outf,"%c",sec[j]);
			}
			//fprintf(outf,"\n");
			w=1;
		    }
		}
		else if (i>=1  && w==1)
		{
			p=0;
	      	for (j =0;j<8;j++)
		    {
		     	if (first[j]!=pin[i][j])
			    {
			    if (sec[j]!=pin[i][j])
			    {
				p++;
		     	}
			} 
			}
			if (p!=0)
			{
			for (j=0;j<8;j++)
			{
			third[j]=pin[i][j];
			}
			w=2;
			counter = i;
			i=1000;
			}

		
			
		}
	charaktiras=fgetc(inf);
	}
	  if (charaktiras == 'EOF')
	  {
		  finish=1;
	  }
	 }*/





		/*
	for (j=0; j<1000; j++)
	{

			if (first[i] = sec[i])
			{
				fprintf (outf, "T\n");
			}
			else
			{
				fprintf (outf, "NT\n");
			}

			if ( sec[i] = third[i])
			{
				fprintf (outf, "T\n");
			}
			else
			{
				fprintf (outf, "F\n");
			}


	}

	
	


		*/	


	 fclose(inf);
	 fclose(outf);

/*

	//3anaanoigmaaa


	 inf=fopen("input_file.txt","r");
	 outf= fopen("output_file.txt","w");

///////////////////////////////////////////////////////////////////////////////////////////////////////////



//KLEISIMO ARXEIWN

	fclose(input_file);
	fclose(output_file);


*/
	return (0);
}


