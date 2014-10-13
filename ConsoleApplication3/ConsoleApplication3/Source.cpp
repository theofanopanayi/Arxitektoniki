#include<stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

int leitourgia (FILE *inf);


FILE *outf;
FILE *bit1;
FILE *bit2;

int main()

{
	FILE *inf;
	int y=0;
	inf=fopen("input_file.txt","r");
	outf= fopen("output_file.txt","w");
	bit1= fopen("output_1bitfile.txt","w");
	bit2= fopen("output_2bitfile.txt","w");
	//y=leitourgia(inf);
	

		
	
	




	while (y==0)
	{
		y=leitourgia(inf);
		//printf("xaxaxa");
	}

	
//KLEISIMO ARXEIWN
	 fclose(inf);
	 fclose(outf);
	 fclose(bit1); 
	 fclose(bit2);


	return(0);

}





int leitourgia (FILE *inf)  
{ 

	//gia ena bit
	int sum1=0; //sum of all 1 bit
	//int sum2=1; //sum of apotelesma=not taken
	int sum3=0; //sum of hits 1 bit
	//gia 2 bit
	int finish=0;
	int p=0;
	int ar1=0;  // sum of all 2 bit
	//int ar2=0;
	int ar3=0; // sum of hits 2 bit
	int j=0; //counter gia pin
	bool apot;
	int x=0;
	int counter = 0;
	int branch=0;   //num of branches
	
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


	
/*	charaktiras = fgetc(inf);

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
					}
				charaktiras = fgetc(inf);
			} */
	 


	// fclose(inf); //KLEISIMO INPUT FILE
	 inf=fopen("input_file.txt","r"); //3ANAANOIGMA

	 for (i=0; i<1000; i++)
	 {
		
				for (j=0; j<8; j++)
				{
					charaktiras=fgetc(inf);  //PAIRNEI CHARAKTIRA KAI TON VAZEI STIN SWSTI THESI STON PIN
					pin[i][j]=charaktiras;
				}		

		if (i==0)
		{
			for (j=0; j<8; j++)
			{	
				first[j]=pin[i][j];  //VAZEI TIN PRWTI TIMI STON FIRST
					//branch++;
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
				if (first[j]!=pin[i][j])  //ELEGXOS AN EINAI ANISOS TOU FIRST
				{
					p++;
						
				}
			}
			if (p!=0)
			{
			for (j=0;j<8;j++)
			{
				sec[j]=pin[i][j];  //TOPOTHETI STON SEC THN DEUTERI TIMI
				branch++;
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
			if (first[j]!=pin[i][j])   //AN DEN EINAI ISOS ME FIRST KAI SEC TOTE EINAI THIRD
			{
			 if (sec[j]!=pin[i][j])
			{
				p++;
					//branch++;
			}
			}
			if (p!=0)
			{
			for (j=0;j<8;j++)
			{
			third[j]=pin[i][j];
			//branch++;
			}
			w=2;
			counter = i;  //krata thesi pou stamata

			i=1000;
			}
		

		}
		/////////////////
		for  (i=0; i<counter; i++)
		{ 
			z=0;
			for (j=0; j<8; j++)
			{ x=0;
				if (first[j] = pin[i][j])  //1os branch (loop) provle4eis
				{
					x++;
				}

				if (x=8 && z==0);  //molis diavasei first kai to z einai 0 gia first
				{
					provle4i1 = 'T';
					provle4i2 = 'N';
				}

				z=1;
			}
			for (j=0; j<8; j++)
			{ x=0;
				if (sec[j] = pin [i][j])  //2os branch (loop) provle4eis
				{
					x++;
				}

				if (x=8 && z==1);  //diavazei sec k elegxei an z=1
				{
					provle4i1 = 'T';  
					provle4i2 = 'N';
				}

			}

			for (j=0; j<8; j++)
			{

				if (pin[i][j] == pin[i+1][j])  //apotelesmata
				{
					apotel = 'T';
				}
				else
				{
					apotel = 'N';
				}
			//}

			//for (j=0; j<8; j++)
			//{



			// 1 bit 1os branch
			if (provle4i1 == 'T' && apotel == 'T')
			{
				//provle4i = 'T';
				fprintf (bit1, "hit\n");
				hm = 'H';
				sum3=sum3+1;
				sum1++;
			}
			else if (provle4i1 == 'T' && apotel == 'N')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i1 == 'N' && apotel == 'T')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i2 = 'T';
				
			}
			else if (provle4i1 == 'N' && apotel == 'N')
			{
				hm = 'H';
				sum1++;
				fprintf (bit1, "hit\n");
				sum3=sum3+1;
				//provle4i2 = 'N';
				
			}




			//gia provle4i 2 2os branch




			if (provle4i2 == 'T' && apotel == 'T')
			{
				//provle4i = 'T';
				fprintf (bit1, "hit\n");
				hm = 'H';
				sum3=sum3+1;
				sum1++;
			}
			else if (provle4i2 == 'T' && apotel == 'N')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i2 == 'N' && apotel == 'T')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i2 = 'T';
				
			}
			else if (provle4i2 == 'N' && apotel == 'N')
			{
				hm = 'H';
				sum1++;
				fprintf (bit1, "hit\n");
				sum3=sum3+1;
				//provle4i2 = 'N';
				
			}





			//}
				


			}

	//fprintf(outf, "2bit");
	
			for (j=0; j<8; j++)
		{


			//1os branch 2 bit



			if (provle4i1=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				//prov='T';
				h_m='H';
				ar3=ar3+1;
				ar1++;
				fprintf (bit2, "hit\n");
			}
			else if (provle4i1=='T' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='I';
				ar1++;
				
			}

			else if (provle4i1=='I' && apotel=='T')
			{
				h_m='H';
				ar1++;
				ar3=ar3+1;
				//provle4i2='T';
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i1=='I' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='D';
				ar1++;
				
			}
			else if (provle4i1=='D' && apotel=='N')
			{
				h_m='H';
				ar3=ar3+1;
				//provle4i2='D';
				ar1++;
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i1=='D' && apotel=='T')
			{
				h_m='M';
				ar1++;
				fprintf (bit2 , "miss\n");
				//provle4i2='N';
				
			}
			else if (provle4i1=='N' && apotel=='T')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2 = 'T';
				ar1++;
				
			}
			else if (provle4i1=='N' && apotel=='N')
			{
				hm='H';
				ar3=ar3+1;
				//provle4i2='N';
				ar1++;
				fprintf (bit2, "hit\n");
				
			}


	//2os branch 2 bit




			
			if (provle4i2=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				//prov='T';
				h_m='H';
				ar3=ar3+1;
				ar1++;
				fprintf (bit2, "hit\n");
			}
			else if (provle4i2=='T' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='I';
				ar1++;
				
			}

			else if (provle4i2=='I' && apotel=='T')
			{
				h_m='H';
				ar1++;
				ar3=ar3+1;
				//provle4i2='T';
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i2=='I' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='D';
				ar1++;
				
			}
			else if (provle4i2=='D' && apotel=='N')
			{
				h_m='H';
				ar3=ar3+1;
				//provle4i2='D';
				ar1++;
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i2=='D' && apotel=='T')
			{
				h_m='M';
				ar1++;
				fprintf (bit2 , "miss\n");
				//provle4i2='N';
				
			}
			else if (provle4i2=='N' && apotel=='T')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2 = 'T';
				ar1++;
				
			}
			else if (provle4i2=='N' && apotel=='N')
			{
				hm='H';
				ar3=ar3+1;
				//provle4i2='N';
				ar1++;
				fprintf (bit2, "hit\n");
				
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


	  for (i=1; i<30;i++)   //tipwnw sto output_file tis prwtes 8esis tou pin
	 {
		 for (j=0; j<8; j++)
		 {
			 fprintf (outf, "%c", pin[i][j]);
		 }
		 fprintf(outf,"\n");
	 }




	  //fprintf(bit1, "sum of apotelesma=taken %d \n", sum1);
	  //fprintf(bit1, "sum of apotelesma=not taken %d \n", sum2);
	  //fprintf(bit1, "sum of hits %d \n", sum3);
	
	fprintf (bit1, "%d", sum3); //pososto epitixias hit/all gia 1 bit
	fprintf (bit1, "/");
	fprintf (bit1, "%d", sum1);


	  
	//fprintf(bit2, "sum of apotelesma=taken %d \n", ar1);
	//fprintf(bit2, "sum of apotelesma=not taken %d \n", ar2);
	//fprintf(bit2, "sum of hits %d \n", ar3);
	
	fprintf (bit2, "%d", ar3); //pososto epitixias hit/all gia 2 bit
	fprintf (bit2, "/");
	fprintf (bit2, "%d", ar1);



	//fprintf (outf, "branch %d", branch);
	
	/*
	 while(finish==0)
	 {
		 for(j=0;j<8;j++)
		 {
		 pin[0][j]=third[j];
		 first[j]=third[j];
		 sec[j]=NULL;
		 third[j]=NULL;
		 }
	
	 
	  for (i=1; i<1000; i++)
	 {
		
				for (j=0; j<8; j++)
				{
					charaktiras=fgetc(inf);
					pin[i][j]=charaktiras;

				}	

				 if (charaktiras == 'EOF')
					{
					finish=1;
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

	w=0;


	for  (i=0; i<counter; i++)
		{ 
			z=0;
			for (j=0; j<8; j++)
			{ x=0;
				if (first[j] = pin[i][j])  //1os branch (loop) provle4eis
				{
					x++;
				}

				if (x=8 && z==0);  //molis diavasei first kai to z einai 0 gia first
				{
					provle4i1 = 'T';
					provle4i2 = 'N';
				}

				z=1;
			}
			for (j=0; j<8; j++)
			{ x=0;
				if (sec[j] = pin [i][j])  //2os branch (loop) provle4eis
				{
					x++;
				}

				if (x=8 && z==1);  //diavazei sec k elegxei an z=1
				{
					provle4i1 = 'T';  
					provle4i2 = 'N';
				}

			}

			for (j=0; j<8; j++)
			{

				if (pin[i][j] == pin[i+1][j])  //apotelesmata
				{
					apotel = 'T';
				}
				else
				{
					apotel = 'N';
				}


				
			// 1 bit 1os branch
			if (provle4i1 == 'T' && apotel == 'T')
			{
				//provle4i = 'T';
				fprintf (bit1, "hit\n");
				hm = 'H';
				sum3=sum3+1;
				sum1++;
			}
			else if (provle4i1 == 'T' && apotel == 'N')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i1 == 'N' && apotel == 'T')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i2 = 'T';
				
			}
			else if (provle4i1 == 'N' && apotel == 'N')
			{
				hm = 'H';
				sum1++;
				fprintf (bit1, "hit\n");
				sum3=sum3+1;
				//provle4i2 = 'N';
				
			}




			//gia provle4i 2 2os branch




			if (provle4i2 == 'T' && apotel == 'T')
			{
				//provle4i = 'T';
				fprintf (bit1, "hit\n");
				hm = 'H';
				sum3=sum3+1;
				sum1++;
			}
			else if (provle4i2 == 'T' && apotel == 'N')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i2 == 'N' && apotel == 'T')
			{
				hm = 'M';
				fprintf (bit1, "miss\n");
				sum1++;
				//provle4i2 = 'T';
				
			}
			else if (provle4i2 == 'N' && apotel == 'N')
			{
				hm = 'H';
				sum1++;
				fprintf (bit1, "hit\n");
				sum3=sum3+1;
				//provle4i2 = 'N';
				
			}





			//}
				


			}

	//fprintf(outf, "2bit");
	
			for (j=0; j<8; j++)
		{


			//1os branch 2 bit



			if (provle4i1=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				//prov='T';
				h_m='H';
				ar3=ar3+1;
				ar1++;
				fprintf (bit2, "hit\n");
			}
			else if (provle4i1=='T' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='I';
				ar1++;
				
			}

			else if (provle4i1=='I' && apotel=='T')
			{
				h_m='H';
				ar1++;
				ar3=ar3+1;
				//provle4i2='T';
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i1=='I' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='D';
				ar1++;
				
			}
			else if (provle4i1=='D' && apotel=='N')
			{
				h_m='H';
				ar3=ar3+1;
				//provle4i2='D';
				ar1++;
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i1=='D' && apotel=='T')
			{
				h_m='M';
				ar1++;
				fprintf (bit2 , "miss\n");
				//provle4i2='N';
				
			}
			else if (provle4i1=='N' && apotel=='T')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2 = 'T';
				ar1++;
				
			}
			else if (provle4i1=='N' && apotel=='N')
			{
				hm='H';
				ar3=ar3+1;
				//provle4i2='N';
				ar1++;
				fprintf (bit2, "hit\n");
				
			}


	//2os branch 2 bit




			
			if (provle4i2=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				//prov='T';
				h_m='H';
				ar3=ar3+1;
				ar1++;
				fprintf (bit2, "hit\n");
			}
			else if (provle4i2=='T' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='I';
				ar1++;
				
			}

			else if (provle4i2=='I' && apotel=='T')
			{
				h_m='H';
				ar1++;
				ar3=ar3+1;
				//provle4i2='T';
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i2=='I' && apotel=='N')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2='D';
				ar1++;
				
			}
			else if (provle4i2=='D' && apotel=='N')
			{
				h_m='H';
				ar3=ar3+1;
				//provle4i2='D';
				ar1++;
				fprintf (bit2, "hit\n");
				
			}
			else if (provle4i2=='D' && apotel=='T')
			{
				h_m='M';
				ar1++;
				fprintf (bit2 , "miss\n");
				//provle4i2='N';
				
			}
			else if (provle4i2=='N' && apotel=='T')
			{
				h_m='M';
				fprintf (bit2, "miss\n");
				//provle4i2 = 'T';
				ar1++;
				
			}
			else if (provle4i2=='N' && apotel=='N')
			{
				hm='H';
				ar3=ar3+1;
				//provle4i2='N';
				ar1++;
				fprintf (bit2, "hit\n");
				
			}
			
	}

	}

	  for (i=0; i<30;i++)   //tipwnw sto output_file tis prwtes 8esis tou pin
	 {
		 for (j=0; j<8; j++)
		 {
			 fprintf (outf, "%c", pin[i][j]);
		 }
		 fprintf(outf,"\n");
	 }


	 
}


*/


			if (charaktiras==EOF)
			return 1;


	return (0);
}



