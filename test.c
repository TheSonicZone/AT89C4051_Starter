//
//				The Sonic Zone (PTY) LTD
//			Simple starter application for ATMEL AT89C4051
//
//
//--------------------------------------------------------------------------------------------
#include<reg51.h>


// Bit Definitions (I/O port pins)
//--------------------------------------

sbit led = P1^0;				// led indication

// Variables
//---------------



// Local functions (no C header file to declare prototypes :()
//-------------------------------------------------------------
void delay(){					
  	int k;
		TL1 = 0xAF;					// load value 15535 = 3CAF
		TH1 = 0x3C;
		TR1 = 1;
		for(k = 0; k < 20; k++){
			while(TF1==0);
			TF1 = 0;
			TL1 = 0xAF;
			TH1 = 0x3C;
	  }
		TR1 = 0;
  }

// Interrupt Service Routine
// Note the syntax here..
//------------------------------------------------------------
// external interrupt 1 function
void int1(void) interrupt 2	{
		EA=0; 							

 }

 
	
//------------------------------------------------------------------------------------------------------------
//                                    Main Function
//------------------------------------------------------------------------------------------------------------
void main(void){
	
		TMOD = 0x15;	  			// timer 0 in 16 bit counter and timer 1 in 16 bit counter
		TH0 = 0x00;				  	// clear T0
		TL0 = 0x00;
		//IE = 0x84;				  // enable external interrupt 1
	  for(;;){
			led = 1;
			delay();
			led = 0;
			delay();
		}
	}	 
