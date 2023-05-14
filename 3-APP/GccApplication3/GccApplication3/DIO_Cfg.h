/*******************************************/
/*              DIO configuration          */
/* Target: ATMEGA32                        */
/* Author: Bishoy Zakaria                  */
/*******************************************/

#ifndef      DIO_CFG_H
#define      DIO_CFG_H

#define DIO_PinNumber        32

DIO_tstrPinConfig DIO_srtConfigArray[DIO_PinNumber] =
{       /*pin direction , pin mode*/
	/*DIO_Pin0*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin1*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin2*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin3*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin4*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin5*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin6*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin7*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin8*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin9*/ {DIO_Output    , DIO_OutputHigh},
	/*DIO_Pin10*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin11*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin12*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin13*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin14*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin15*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin16*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin17*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin18*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin19*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin20*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin21*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin22*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin23*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin24*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin25*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin26*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin27*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin28*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin29*/ {DIO_Output    , DIO_OutputLow},
	/*DIO_Pin30*/ {DIO_Input    , DIO_PullDown},
	/*DIO_Pin31*/ {DIO_Output    , DIO_OutputLow}
};
#endif
#define      DIO_CFG_H