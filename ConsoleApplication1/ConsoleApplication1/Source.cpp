#include<stdio.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

int leitourgia (/*FILE *inf,*/ int ap);
int corfun(char nextprov,char apotel,char provle4i2, char provle4i1);
int bit1fun(char,char, char,int, char, int, int,char);
int tourfun( char provle4i1, char provle4i2, char apotel);
int bit2fun(int j, char provle4i1, char apotel, char h_m, int ar3, int ar1, int ap, char provle4i2, int hm);


FILE *outf;
FILE *bit1;
FILE *bit2;
FILE *col;
FILE *sig;
FILE *tour;
FILE *inf;

int tester=0;

int main()
{
	/*printf("doke");
	scanf("%d",&tester);
	inf=fopen("input_file.txt","r");
	if (!inf) return 0;
	sig=fopen("apotelesmata.txt","w");
	if (!sig) return 0;

	if (tester == 1)
	{
	outf=fopen("output_file.txt","w");
	if (!outf) return 0;
	bit1=fopen("output_1bitfile.txt","w");
	if (!bit1) return 0;
	bit2=fopen("output_2bitfile.txt","w");
	if (!bit2) return 0;
	col=fopen("correlating.txt","w");
	if (!col) return 0;
	tour=fopen("tournoua.txt","w");
	if (!tour) return 0;
	}*/

	int ap=0;
	int y=0;
	//int ap='t'; //apantisi an 8lei arxeia
	int sum3=0;
	int sum1=0;
	int olcol=0;
	int ar1=0;
	int ar3=0;
	char upd1='t';
	char upd2='t';
	int hitcol=0;
	int colbit1sum=0;
	int hitour=0;
	//y=leitourgia(inf);
	inf=fopen("input_file.txt","r");
	if (!inf) return 0;
	sig=fopen("apotelesmata.txt","w");
	if (!sig) return 0;
	printf("theleis arxeia? 0 or 1 \n");
	scanf("%d",&ap);
	if (ap==1)
	{
	outf=fopen("output_file.txt","w");
	if (!outf) return 0;
	bit1=fopen("output_1bitfile.txt","w");
	if (!bit1) return 0;
	bit2=fopen("output_2bitfile.txt","w");
	if (!bit2) return 0;
	col=fopen("correlating.txt","w");
	if (!col) return 0;
	tour=fopen("tournoua.txt", "w");
	if (!tour) return 0;
	}
	while (y==0)
	{
		y=leitourgia(/*inf,*/ ap);

		//printf("xaxaxa");
	}

	fprintf(sig,"apotelesma ena bit: ");
	fprintf(sig,"%d",sum3); //pososto epitixias hit/all gia 1 bit
	fprintf(sig,"/");
	fprintf(sig,"%d \n",sum1);


	
	fprintf(sig, "apotelesmata gia 2 bit: ");
	fprintf (sig, "%d", ar3); //pososto epitixias hit/all gia 2 bit
	fprintf (sig, "/");
	fprintf (sig, "%d \n", ar1);


	olcol= sum1-colbit1sum;

	if (ap==1)
	{
		fprintf(col, "update pred1 %c \n", upd1);
		fprintf(col, "update pred2 %c \n" , upd2);
		fprintf(col, "kalesma 1bit : %d fores \n", colbit1sum);
		fprintf(col, "num of iner loops %d \n", olcol);
	}


	fprintf(sig,"apotelesmata gia correlating: ");
	fprintf(sig,"%d", hitcol); //pososto epitixias hit/all gia 2 bit
	fprintf(sig,"/");
	fprintf(sig,"%d \n", sum1);

	
//KLEISIMO ARXEIWN
	fclose(inf);
	fclose(sig);
	if (ap==1)
	{
	 fclose(outf);
	 fclose(bit1); 
	 fclose(bit2);
	 fclose(col);
	 fclose(tour);
	}
	return(0);

}

int leitourgia (/*FILE *inf,*/ int ap)

{ 
	/*int corfun(char nextprov,char apotel,char provle4i2, char provle4i1);
	int bit1fun(char, char,int, char, int, int,char);
	int tourfun( char provle4i1, char provle4i2, char apotel);
	int bit2fun(int j, char provle4i1, char apotel, char h_m, int ar3, int ar1, int ap, char provle4i2, int hm);*/

	int sum3=0;
	int sum1=0;
	int olcol=0;
	int ar1=0;
	int ar3=0;
	char upd1='T';
	char upd2='t';
	int hitcol=0; 
	int colbit1sum=0;
	//gia ena bit
	//int sum1=0; //sum of all 1 bit
	//int sum2=1; //sum of apotelesma=not taken
	//int sum3=0; //sum of hits 1 bit
	//gia 2 bit
	int finish=0;
	int p=0;
	//int ar1=0;  // sum of all 2 bit
	//int ar2=0;
	//int ar3=0; // sum of hits 2 bit
	int j=0; //counter gia pin
	bool apot=1;
	int x=0;
	int counter = 0;
	//int branch=0;   //num of branches
	
	char charaktiras; //diavazei charaktira
	char first[8];
	char sec[8];
	char third[8];
	char pin[1000][8];
	char hm='t';
	char h_m='t'; //hit miss
	int i=0;
	int z=0;
	int a=0;
	int w=0;
	int k=0;
	char provle4i1='T';
	char provle4i2='T';
	char apotel, hitour='T';
	char prov='T';
	char apot1bit='T';
	//int colbit1sum=0;
	int colsum=0;
	//int hitcol=0;
	//int olcol=0;
	char real='T';
	//char upd1;
	//char upd2;
	char pred1='T';
	char pred2='T';
	char pred='T';
	char now='T';
	int counter2=0;
	char corapot='T';
	char nextprov='T';
	int apt2bit=0;
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
	 //inf=fopen("input_file.txt","r"); //3ANAANOIGMA
	//printf("xaxaxa1");
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
			for (j=0;j<8;j++)
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
				//branch++;
				//fprintf(outf,"%c",sec[j]);
			}
			//fprintf(outf,"\n");
			w=1;
		    }
		}
		else if (i>=1  && w==1)
		{
			p=0;
		for (j=0;j<8;j++)
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
			counter=i;  //krata thesi pou stamata
			i=1000;
			}
		}
		/////////////////
		for  (i=0; i<counter; i++)
		{ 
			z=0;
			for (j=0; j<8; j++)
			{ x=0;
				if (first[j] == pin[i][j])  //1os branch (loop) provle4eis
				{
					x++;
				}

				if (x==8 && z==0);  //molis diavasei first kai to z einai 0 gia first
				{
					provle4i1 = 'T';
					provle4i2 = 'N';
				}

				z=1;
			}
			for (j=0; j<8; j++)
			{ x=0;
				if (sec[j] == pin [i][j])  //2os branch (loop) provle4eis
				{
					x++;
				}

				if (x==8 && z==1);  //diavazei sec k elegxei an z=1
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

				apot1bit = bit1fun(apot1bit ,provle4i1, apotel, ap, hm, sum3, sum1,provle4i2);
				
			}

			apt2bit=bit2fun(j, provle4i1, apotel, h_m, ar3, ar1, ap, provle4i2,hm);
		}

		}
		charaktiras=fgetc(inf);
		}


		 for (i=1; i<30;i++)   //tipwnw sto output_file tis prwtes 8esis tou pin
	 {
		 for (j=0; j<8; j++)
		 {
			 if (ap==1)
				{
			 fprintf (outf, "%c", pin[i][j]);
			 }
		 }
		 if (ap==1)
				{
		 fprintf(outf,"\n");
		 }
	 }
/*	fclose(inf);
	//printf("hahah2");

	inf=fopen("input_file.txt","r"); //3ANAANOIGMA


	corapot = corfun (nextprov, apotel , provle4i2,  provle4i1);
	apt2bit=tourfun(provle4i1, provle4i2, apotel);
	if (nextprov=='T' || nextprov=='t')
	{

		fprintf(tour, "%c\n" ,apot1bit);
		if (apot1bit == 'T')
		{
			hitour++;
		}
		
	}
	else if (nextprov=='F' || nextprov=='f')
	{
		fprintf(tour, "%c\n", corapot); 

		if (corapot == 'h')
		{
			hitour++;
		}
	}*/
		charaktiras=fgetc(inf);
		printf("%c",charaktiras);
		if (charaktiras==EOF)
			{
			return 1;
			}
		else
			{
			return 0;
			}


		}







		//1BIT FUNCTION



		int bit1fun(char apot1bit, char provle4i1, char apotel,int ap, char hm, int sum3, int sum1,char provle4i2)
		{

	//bit1= fopen("output_1bitfile.txt","w");
	

			// 1 bit 1os branch
			if (provle4i1 == 'T' && apotel == 'T')
			{
				apot1bit='T';
				//provle4i = 'T';
				if (ap==1)
				{
				fprintf (bit1, "hit\n");
				}
				hm = 'H';
				sum3=sum3+1;
				sum1++;
			}
			else if (provle4i1 == 'T' && apotel == 'N')
			{
				apot1bit='N';
				hm = 'M';
				if (ap==1)
				{
				fprintf (bit1, "miss\n");
				}
				sum1++;
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i1 == 'N' && apotel == 'T')
			{
				apot1bit='T';
				hm = 'M';
				if (ap==1)
				{
				fprintf (bit1, "miss\n");
				}
				sum1++;
				//provle4i2 = 'T';
				
			}
			else if (provle4i1 == 'N' && apotel == 'N')
			{
				apot1bit='N';
				hm = 'H';
				sum1++;
				if (ap==1)
				{
				fprintf (bit1, "hit\n");
				}
				sum3=sum3+1;
				//provle4i2 = 'N';
				
			}




			//gia provle4i 2 2os branch




			if (provle4i2 == 'T' && apotel == 'T')
			{
				//provle4i = 'T';
				if (ap==1)
				{
				fprintf (bit1, "hit\n");
				}
				hm = 'H';
				sum3=sum3+1;
				sum1++;
			}
			else if (provle4i2 == 'T' && apotel == 'N')
			{
				hm = 'M';
				if (ap==1)
				{
				fprintf (bit1, "miss\n");
				}
				sum1++;
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i2 == 'N' && apotel == 'T')
			{
				hm = 'M';
				if (ap==1)
				{
				fprintf (bit1, "miss\n");
				}
				sum1++;
				//provle4i2 = 'T';
				
			}
			else if (provle4i2 == 'N' && apotel == 'N')
			{
				hm = 'H';
				sum1++;
				if (ap==1)
				{
				fprintf (bit1, "hit\n");
				}
				sum3=sum3+1;
				//provle4i2 = 'N';
				
			}

			return (apot1bit);				
		}










		//2BIT FUNCTION



		int bit2fun(int j, char provle4i1, char apotel, char h_m, int ar3, int ar1, int ap, char provle4i2, int hm)
		{


		//bit2= fopen("output_2bitfile.txt","w");

			for (j=0; j<8; j++)
		{


			//1os branch 2 bit



			if (provle4i1=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				//prov='T';
				h_m='H';
				ar3=ar3+1;
				ar1++;
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
			}
			else if (provle4i1=='T' && apotel=='N')
			{
				h_m='M';
				if (ap==1)
				{
				fprintf (bit2, "miss\n");
				}
				//provle4i2='I';
				ar1++;
				
			}

			else if (provle4i1=='I' && apotel=='T')
			{
				h_m='H';
				ar1++;
				ar3=ar3+1;
				//provle4i2='T';
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
				
			}
			else if (provle4i1=='I' && apotel=='N')
			{
				h_m='M';
				if (ap==1)
				{
				fprintf (bit2, "miss\n");
				}
				//provle4i2='D';
				ar1++;
				
			}
			else if (provle4i1=='D' && apotel=='N')
			{
				h_m='H';
				ar3=ar3+1;
				//provle4i2='D';
				ar1++;
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
			}
			else if (provle4i1=='D' && apotel=='T')
			{
				h_m='M';
				ar1++;
				if (ap==1)
				{
				fprintf (bit2 , "miss\n");
				}
				//provle4i2='N';
				
			}
			else if (provle4i1=='N' && apotel=='T')
			{
				h_m='M';
				if (ap==1)
				{
				fprintf (bit2, "miss\n");
				}
				//provle4i2 = 'T';
				ar1++;
				
			}
			else if (provle4i1=='N' && apotel=='N')
			{
				hm='H';
				ar3=ar3+1;
				//provle4i2='N';
				ar1++;
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
				
			}


	//2os branch 2 bit




			
			if (provle4i2=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				//prov='T';
				h_m='H';
				ar3=ar3+1;
				ar1++;
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
			}
			else if (provle4i2=='T' && apotel=='N')
			{
				h_m='M';
				if (ap==1)
				{
				fprintf (bit2, "miss\n");
				}
				//provle4i2='I';
				ar1++;
				
			}

			else if (provle4i2=='I' && apotel=='T')
			{
				h_m='H';
				ar1++;
				ar3=ar3+1;
				//provle4i2='T';
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
				
			}
			else if (provle4i2=='I' && apotel=='N')
			{
				h_m='M';
				if (ap==1)
				{
				fprintf (bit2, "miss\n");
				}
				//provle4i2='D';
				ar1++;
				
			}
			else if (provle4i2=='D' && apotel=='N')
			{
				h_m='H';
				ar3=ar3+1;
				//provle4i2='D';
				ar1++;
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
				
			}
			else if (provle4i2=='D' && apotel=='T')
			{
				h_m='M';
				ar1++;
				if (ap==1)
				{
				fprintf (bit2 , "miss\n");
				}
				//provle4i2='N';
				
			}
			else if (provle4i2=='N' && apotel=='T')
			{
				h_m='M';
				if (ap==1)
				{
				fprintf (bit2, "miss\n");
				}
				//provle4i2 = 'T';
				ar1++;
				
			}
			else if (provle4i2=='N' && apotel=='N')
			{
				hm='H';
				ar3=ar3+1;
				//provle4i2='N';
				ar1++;
				if (ap==1)
				{
				fprintf (bit2, "hit\n");
				}
				
			}
			
	}
	return (0);
		}





//CORRELATING FYNCTION
		int corfun(char nextprov,char apotel,char provle4i2, char provle4i1)
		{
		
			//col= fopen("correlating.txt","w");
			char corapot='t';
			char real='t'; 
			char pred1='t';
			char pred2='t';
			char upd1='t';
			char upd2='t';
			char pred='t';
			char charaktiras='t';
			char now='t'; 
			char hitcol='t';
			int x=0;
			int z=0;
			int w=0;
			int p=0;
			int i=0;
			int ap=0;
			int counter2=0;
			int colbit1sum=0;
			int j=0;
			char sec[8];
			char first[8];
			char third[8];
			char pin[1000][8];
		corapot = 'T';
		apotel='T';
		real= 'T';
		pred1= 'T';
		pred2= 'T';
		upd1= 'T';
		upd2= 'T';
		pred= 'T';
		now=apotel;
		//int first[8];
		//char charaktiras;
	//i=0;
	//j=0;

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
			}
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
				}
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
				//counter2 = i;  //krata thesi pou stamata
				counter2++;
				//fprintf(col, "%d", counter2);
				i=1000;
				
			}
		

		}
		
		///////////////
	 
	for  (i=0; i<counter2; i++)
		{  //fprintf(col, "ddffffff");
			z=0;
			for (j=0; j<8; j++)
			{ x=0;

			

			if (first[j] == pin[i][j])  //1os branch (loop) provle4eis
				{
					x++;
				}

				if (x==8 && z==0);  //molis diavasei first kai to z einai 0 gia first
				{
					provle4i1 = 'T';
					provle4i2 = 'N';
				}

				z=1;
			}
			for (j=0; j<8; j++)
			{ x=0;
				if (sec[j] == pin [i][j])  //2os branch (loop) provle4eis
				{
					x++;
				}

				if (x==8 && z==1);  //diavazei sec k elegxei an z=1
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
					corapot = 'T';
				}
				else
				{
					apotel = 'N';
					corapot = 'N';
				}


				if (first[j] == sec[j])  //1os bit
				{
					provle4i1 = 'T';
					provle4i2 = 'N';
					apotel = 'T';
					colbit1sum++;
			
				if (provle4i1 == 'T' && apotel == 'T')
				{
					corapot = 'T';
				if (ap==1)
				{
				fprintf (col, "hit\n");
				}
				hitcol++;
				//olcol++;
				//hm = 'H';
				//sum3=sum3+1;
				//sum1++;
			}
			else if (provle4i1 == 'T' && apotel == 'N')
			{
				corapot = 'N';
				//hm = 'M';
				if (ap==1)
				{
				fprintf (col, "miss\n");
				}
				//olcol++;
				//sum1++;
				//provle4i = 'N';
				//fprintf (outf, "not taken");
				
			}
			else if (provle4i1 == 'N' && apotel == 'T')
			{
				corapot = 'T';
				//hm = 'M';
				if (ap==1)
				{
				fprintf (col, "miss\n");
				}
				//olcol++;
				//sum1++;
				//provle4i2 = 'T';
				
			}
			else if (provle4i1 == 'N' && apotel == 'N')
			{
				corapot = 'N';
				//hm = 'H';
				//sum1++;
				if (ap==1)
				{
				fprintf (col, "hit\n");
				}
				hitcol++;
				//olcol++;
				//sum3=sum3+1;
				//provle4i2 = 'N';
				
			}


			}

	
	else if (first[j] != pin[i][j])
	{
		//olcol++;
		/*real= 'T';
		pred1= 'T';
		pred2= 'T';
		upd1= 'T';
		upd2= 'T';
		pred= 'T';
		now=apotel;
		*/
		printf("lalallalal");
		if (real='T')
		{
			
			pred=pred1;
			
		}
		else
		{
			pred=pred2;
		}

		if (real==pred)
		{
			hitcol++;
			corapot = 'T';
		}
		

		if (now!=pred)
		{
			if (real=='T')
			{
				upd1 = 'N';
			}
			else
			{
				upd2 = 'N';
			}
		}

			real=now;

			if (pin [i][j] == first[j] )
			{
				pred1=upd1;
				pred2=upd2;
			}

	

	}



	first[j] = pin[i+1][j];
	third[j]=sec[j];
	sec[j]= pin[i][j];

		
		






	}



	}

	return (corapot);

	}





	//TOURNOUA FUNCTION

	int tourfun( char provle4i1, char provle4i2, char apotel)

	{

		int j=0;
		char h_m='T';
		int ar3=0; 
		int ar1=0; 
		int ap=0;
		int hm=0;
		char nextprov='T';

			for (j=0; j<8; j++)
		{


			//1os branch 2 bit

			char nextprov;

			if (provle4i1=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				nextprov = 'T';
			}
			else if (provle4i1=='T' && apotel=='N')
			{
				nextprov = 't';
			}

			else if (provle4i1=='I' && apotel=='T')
			{
				nextprov = 'T';
				
			}
			else if (provle4i1=='I' && apotel=='N')
			{
				nextprov = 'n';
				
			}
			else if (provle4i1=='D' && apotel=='N')
			{
				nextprov = 'N';
			}
			else if (provle4i1=='D' && apotel=='T')
			{
				nextprov = 't';
				
			}
			else if (provle4i1=='N' && apotel=='T')
			{
				nextprov = 'n';
				
			}
			else if (provle4i1=='N' && apotel=='N')
			{
				nextprov = 'N';
				
			}


	//2os branch 2 bit




			
			if (provle4i2=='T' && apotel=='T')      //T TAKEN1  N NOT_TAKEN1  I TAKEN1 D NOT_TAKEN2
			{
				nextprov = 'T';
			}
			else if (provle4i2=='T' && apotel=='N')
			{
				nextprov = 't';
			}

			else if (provle4i2=='I' && apotel=='T')
			{
				nextprov = 'T';
			}
			else if (provle4i2=='I' && apotel=='N')
			{
				nextprov= 'n';
			}
			else if (provle4i2=='D' && apotel=='N')
			{
				nextprov = 'N';
			}
			else if (provle4i2=='D' && apotel=='T')
			{
				nextprov = 't';
				
			}
			else if (provle4i2=='N' && apotel=='T')
			{
				nextprov = 'n';
			}
			else if (provle4i2=='N' && apotel=='N')
			{
				nextprov = 'N';
			}
			
	}

		
		return (nextprov);
	}