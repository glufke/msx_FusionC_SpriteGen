#include <stdio.h>
#include "header/msx_fusion.h"
#include "header/vdp_graph2.h"
#include "header/vars_msxSystem.h"
#include "header/vdp_sprites.h"
 
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
int mapa[16][16];

//created this pattern for test for now

#ifdef __DEBUG  
static const unsigned int cross_pattern[] = {
  0b1111111111111111,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,
  0b1000000000000001,  
  0b1111111111111111
};
#else
static const unsigned int cross_pattern[] = {
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,  
  0b0000000000000000
};
#endif

// --------------------------------------------------------------------
// For now, this is a table 8x8 (TODO: to be implemented later)
// --------------------------------------------------------------------
void tabela16(int x1, int y1)
{
  int j;
    for (j=0; j<16; j++) {
    Locate(x1,y1+j);
    Print("................");
  }
}

// --------------------------------------------------------------------
// Update sprite in real time
// --------------------------------------------------------------------
void updateSprite(void)
{
  PutSprite( 0, 0, 20, 20,  (0 & 7) + 8 );
  
}
 
// --------------------------------------------------------------------
// Main program.
// --------------------------------------------------------------------
void laco()
{
  int c;
  do 
  {   
    c=WaitKey();  
    //for now, showing the ascii cursor in the 0,0 (remove)
    #ifdef __DEBUG        
      Locate(0,0);
      PrintNumber(c);
    #endif

    if      (c==AESQ) { if (x==0)  {x=16;}  x=x-1;}
    else if (c==ADIR) { if (x==15) {x=-1;}  x=x+1;}
    else if (c==ACIM) { if (y==0)  {y=16;}  y=y-1;}
    else if (c==ABAI) { if (y==15) {y=-1;}  y=y+1;}
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
      updateSprite();
    }           
  } while (c != AESC ); 
}

// --------------------------------------------------------------------
// M A I N 
// --------------------------------------------------------------------
void main(void)
{
  Screen(1);
  Cls();

  //set Sprite table
  SpriteReset();
  Sprite16();
  SpriteSmall();
  SetSpritePattern( 0, Sprite32Bytes(cross_pattern), 256 );

  x=0;
  y=0;
  tabela16(BOXX,BOXY);
  Locate(x+BOXX,y+BOXY);
  laco();

  Exit(0);
}

