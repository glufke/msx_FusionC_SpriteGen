#include <stdio.h>
#include "header/msx_fusion.h"
 
#define COF 80
#define CON 65
#define AESQ 29
#define ADIR 28
#define ACIM 30
#define ABAI 31
#define AESC 27
#define AESP 32
#define BOXX 5
#define BOXY 3

//Some global vars
int x,y;
int mapa[8][8];


//
// For now, this is a table 8x8 (TODO: to be implemented later)
//
void tabela8(int x1, int y1)
{
	int j;

	for (j=0; j<8; j++) {
		Locate(x1,y1+j);
		Print("........");
	}
}

//
// Main program.
//
void laco()
{
	int c;

	do 
	{   
		
		c=WaitKey();  
		//for now, showing the ascii cursor in the 0,0 (remove)
		Locate(0,0);
		PrintNumber(c);

	    if      (c==AESQ) { if (x==0) {x=8;}  x=x-1;}
		else if (c==ADIR) { if (x==7) {x=-1;} x=x+1;}
        else if (c==ACIM) { if (y==0) {y=8;}  y=y-1;}
		else if (c==ABAI) { if (y==7) {y=-1;} y=y+1;}
		else if (c==AESP) { if (mapa[x][y]==0) 
			                {mapa[x][y]=1;
		                    }
		                    else 
		                    {mapa[x][y]=0; 
		                    }
		                  }

        Locate(x+BOXX,y+BOXY);
        if (c==AESP) 
        {
            if ( mapa[x][y] ==0 ) Print("X"); else Print(".");
        	Locate(x+BOXX,y+BOXY);
        }           

	} while (c != AESC ); 
   
}




void main(void)
{
	Screen(1);
 	Cls();

 	x=0;
 	y=0;
 	tabela8(BOXX,BOXY);
 
    Locate(x+BOXX,y+BOXY);
    laco();


 	Exit(0);
}

