/*
 * File:   main.c
 * Author: csar36
 *
 * Created on August 13, 2019, 10:23 AM
 */

/*DEFINES*/

/*Address defines in write to MCFRC522 logic*/

#include "PISPI.h"





void init(){
	 
    char adr, data;
    
     
    
    /*------------Register initialisieren---------------*/
    
    adr=ModeReg;                        //general mode settings for transmitting and receiving
    data = 0xA0;                        //CRC MSB first, transmitter can only be started if RF fiel is generated
    MFRC_PUT(adr,data);       //polarity of MFIN is active LOW
    //defines data rate during transmission
    adr = TxModeReg;                    //receiver is deactivated after receiving data frame
    data= 0xB0;
	MFRC_PUT(adr,data);
    //Defines Data Rate During reception
    adr = RxModeReg;
    data=0xBC;
    MFRC_PUT(adr,data);
    
    //Logical behavior of antenna driver pins TX1, TX2
    adr=TxControlReg;                   //output signal on pin Tx2 continously delivers unmodulated 13.56 Mhz carrier
    data=0xFB;
    MFRC_PUT(adr,data);
    //Controls transmit modulation settings
    adr=TxASKReg;                       //forces a 100% ASK modulation indepented of ModGsPReg
    data=0x40;
    MFRC_PUT(adr,data);
    //Selects internal sources for the analog module
    adr=TxSelReg;                       //modulation signal from the internal encoder, Miller pulse encoded
    data=0x14;                          //input for pin MFOUT: modulation signal from the internal encoder Miller pulse encoder
    MFRC_PUT(adr,data);
    //Selects internal receiver settings
    adr=RxSelReg;                       //modulated signal from the internal analog module, default
    data=0x80;
    MFRC_PUT(adr,data);
    //Selects thresholds for the bit decoder
    
    adr=RxThresholdReg;
    data= 0x00;
    MFRC_PUT(adr,data);
  /*
    //defines demodulator settings
    adr=DemodReg;
    data=??;
    //Controls some MIFARE communication transmit parameters
    adr=MfTxReg;
    data=??;
    */
    //MfRxReg -> Parity check disable
    adr=MfRxReg;
    data= 0x08;                         //parity-bit read as data bit
    MFRC_PUT(adr,data);
    
    /*------------Configuration-------------*/
    //Configures receiver gain
    
    adr=RFCfgReg;
    data= 0x09;                         //36 dB
    MFRC_PUT(adr,data);
    
    MFRC_PUT(WaterLevelReg, 20);
    
}

void init_iso_14443()
{
	//Grundeinstellung für 424 kBd
	MFRC_PUT(WaterLevelReg, 4);
	MFRC_PUT(FIFODataReg, 0x80);
	MFRC_PUT(TModeReg, 0x48);
	MFRC_PUT(ModeReg,0x3F);
	MFRC_PUT(TxModeReg,0xA0);
	MFRC_PUT(RxModeReg,0xAC);
	//MFRC_PUT(TxControlReg,??);
	MFRC_PUT(TxASKReg,0x40);
	MFRC_PUT(TxSelReg,0x14);
	MFRC_PUT(RxSelReg,0x84);
}




int main(int argc, char* argv[])
{
	int ret;
	int adr;
	char anz;
	char fifo_data[64];
	char test[64];
	anz = sizeof(fifo_data);
    ret = SPI_init();
	
	
	
	//init();
	init_iso_14443();


//hier wird ein Array befüllt, welches in den FIFO geschrieben wird
	for(int i=0;i<anz;i++)
	{
		if(i%2!=0)
		{
			test[i] = 8;
		}
		else
		{	
		test[i] = 99;
		}
				
	}
	//MFRC_WRITE_FIFO(test, anz);



//Übergabeparameter test ---> Ausgabe alles
	if(strcmp(argv[1],"test")==0)
		{
			adr=CommandReg;
			printf("CommandReg: 0x%X\n",MFRC_GET(adr));
			
			adr=ComlEnReg;
			printf("ComlEnReg: 0x%X\n",MFRC_GET(adr));
			
			adr=DivlEnReg;
			printf("DivlEnReg: 0x%X\n",MFRC_GET(adr));
			
			adr=ComIrqReg;
			printf("ComIrqReg: 0x%X\n",MFRC_GET(adr));
			
			adr=DivIrqReg;
			printf("DivIrqReg: 0x%X\n",MFRC_GET(adr));
			
			adr=ErrorReg;
			printf("ErrorReg: 0x%X\n",MFRC_GET(adr));
			
			adr=Status1Reg;
			printf("Status1Reg: 0x%X\n",MFRC_GET(adr));
			
			adr=Status2Reg;
			printf("Status2Reg: 0x%X\n",MFRC_GET(adr));
			
			adr=WaterLevelReg;
			printf("WaterLevelReg: 0x%X\n",MFRC_GET(adr));
			
			adr=ControlReg;
			printf("ControlReg: 0x%X\n",MFRC_GET(adr));
			
			adr=BitFramingReg;
			printf("BitFramingReg: 0x%X\n",MFRC_GET(adr));
			
			adr=CollReg;
			printf("CollReg: 0x%X\n",MFRC_GET(adr));
			
			adr=ModeReg;
			printf("ModeReg: 0x%X\n",MFRC_GET(adr));
			
			adr=TxModeReg;
			printf("TxModeReg: 0x%X\n",MFRC_GET(adr));
			
			adr=RxModeReg;
			printf("RxModeReg: 0x%X\n",MFRC_GET(adr));
			
			adr=TxControlReg;
			printf("TxControlReg: 0x%X\n",MFRC_GET(adr));
			
			adr=TxASKReg;
			printf("TxASKReg: 0x%X\n",MFRC_GET(adr));
			
			adr=TxSelReg;
			printf("TxSelReg: 0x%X\n",MFRC_GET(adr));
			
			adr=RxSelReg;
			printf("RxSelReg: 0x%X\n",MFRC_GET(adr));
			
			adr=RxThresholdReg;
			printf("RxThresholdReg: 0x%X\n",MFRC_GET(adr));
		
			adr=DemodReg;
			printf("DemodReg: 0x%X\n",MFRC_GET(adr));
			
			adr=MfTxReg;
			printf("MfTxReg: 0x%X\n",MFRC_GET(adr));
			
			adr=MfRxReg;
			printf("MfRxReg: 0x%X\n",MFRC_GET(adr));
			
			adr=SerialSpeedReg;
			printf("SerialSpeedReg: 0x%X\n",MFRC_GET(adr));
			
			adr=CRCResultMSB;
			printf("CRCResultMSB: 0x%X\n",MFRC_GET(adr));
			
			adr=CRCResultLSB;
			printf("CRCResultLSB: 0x%X\n",MFRC_GET(adr));
			
			adr=ModWidthReg;
			printf("ModWidthReg: 0x%X\n",MFRC_GET(adr));
			
			adr=RFCfgReg;
			printf("RFCfgReg: 0x%X\n",MFRC_GET(adr));
			
			adr=GsNReg;
			printf("GsNReg: 0x%X\n",MFRC_GET(adr));
			
			adr=CWGsPReg;
			printf("CWGsPReg: 0x%X\n",MFRC_GET(adr));
			
			adr=ModGsPReg;
			printf("ModGsPReg: 0x%X\n",MFRC_GET(adr));
			
			adr=TModeReg;
			printf("TModeReg: 0x%X\n",MFRC_GET(adr));
			
			adr=TPrescalerReg;
			printf("TPrescalerReg: 0x%X\n",MFRC_GET(adr));
					
			adr=TReload_Hi;
			printf("TReload_Hi: 0x%X\n",MFRC_GET(adr));
					
			adr=TReload_Lo;
			printf("TReload_Lo: 0x%X\n",MFRC_GET(adr));
					
			adr=TCounterVal_Hi;
			printf("TCounterVal_Hi: 0x%X\n",MFRC_GET(adr));
					
			adr=TCounterVal_Lo;
			printf("TCounterVal_Lo: 0x%X\n",MFRC_GET(adr));
					
			adr=TestSel1Reg;
			printf("TestSel1Reg: 0x%X\n",MFRC_GET(adr));
					
			adr=TestSel2Reg;
			printf("TestSel2Reg: 0x%X\n",MFRC_GET(adr));
					
			adr=TestPinEnReg;
			printf("TestPinEnReg: 0x%X\n",MFRC_GET(adr));
					
			adr=TestPinValueReg;
			printf("TestPinValueReg: 0x%X\n",MFRC_GET(adr));
					
			adr=TestBusReg;
			printf("TestBusReg: 0x%X\n",MFRC_GET(adr));
					
			adr=AutoTestReg;
			printf("AutoTestReg: 0x%X\n",MFRC_GET(adr));
					
			adr=VersionReg;
			printf("VersionReg: 0x%X\n",MFRC_GET(adr));
					
			adr=AnalogTestReg;
			printf("AnalogTestReg: 0x%X\n",MFRC_GET(adr));
					
			adr=TestDAC1Reg;
			printf("TestDAC1Reg: 0x%X\n",MFRC_GET(adr));
					
			adr=TestDAC2Reg;
			printf("TestDAC2Reg: 0x%X\n",MFRC_GET(adr));
					
			adr=TestADCReg;
			printf("TestADCReg: 0x%X\n",MFRC_GET(adr));
				
			//adr = FIFODataReg;
			//MFRC_WRITE_FIFO(test, anz);
			
			//adr=FIFOLevelReg;
			//printf("FIFOLevelReg: 0x%x\n",MFRC_GET(adr));
			//aus irgendeinem Grund wird der Fifo mit 64 überschrieben -> prüfeN!"
			
		
			MFRC_READ_FIFO(fifo_data, anz);
			
			
			char value;
			value = MFRC_GET(FIFOLevelReg);
			MFRC_READ_FIFO(fifo_data, anz);
			printf("#################### FIFO  %d / 64 Bytes stored ####################\n",value);
			for(int i=0;i<64;i++)
			{
				if(i%8==0)
				{	
					printf("\n %d\t",fifo_data[i]);
				}
				else
				{
					printf("%d \t",fifo_data[i]);
				}
			}
			printf("\n###################################################################\n");
		}
		else if(strcmp(argv[1],"fifo")==0)			//ausgabe fifo
		{
			char value;
			value = MFRC_GET(FIFOLevelReg);
			MFRC_READ_FIFO(fifo_data, anz);
			printf("#################### FIFO  %d / 64 Bytes stored ####################\n",value);
			for(int i=0;i<64;i++)
			{
				if(i%8==0)
				{	
					printf("\n %d\t",fifo_data[i]);
				}
				else
				{
					printf("%d \t",fifo_data[i]);
				}
			}
			printf("\n###################################################################\n");
		}
		else if(strcmp(argv[1],"show_state")==0)
		{
			char value;
			value = MFRC_GET(Status2Reg);
			value &= 0x07;
			
			switch(value)
			{
				case 0: printf("current State: IDLE\n"); break;
				case 1: printf("current State: wait for BitFramingReg register's StartSend bit\n"); break;
				case 2: printf("current State: TxWait: wait until RF field is present if the TModeReg \n register’s TxWaitRF bit is set to logic 1 the minimum time for TxWait is defined by the TxWaitReg register\n"); break;
				case 3: printf("current State: transmitting\n"); break;
				case 4: printf("current State: RxWait: wait until RF field is present if the TModeReg \n register’s TxWaitRF bit is set to logic 1 the minimum time for RxWait is defined by the RxWaitReg register\n"); break;
				case 5: printf("current State: wait for data\n"); break;
				case 6: printf("current State: receiving\n"); break;
				default: printf("ERROR\n"); break;
			
			}
		}
		else if(argv[1][0]=='-')		//read/write für bestimmte Adresse
		{
			char c = argv[1][1];
			char adr_parameter,value;
			int x;
			switch(c)
			{				
				case 'r': 
							adr_parameter = (char)atoi(argv[2]);
							adr_parameter = adr_parameter << 1;
							printf("0x%X\n",MFRC_GET(adr_parameter));			
							break;
							
				case 'w':
							adr_parameter = (char)atoi(argv[2]);
							adr_parameter = adr_parameter << 1;
							value = (char)atoi(argv[3]);
							x = atoi(argv[3]);
							
							printf("Übergebener Wert: 0x%X\n",value);
							MFRC_PUT(adr_parameter,value);
							
							printf("Registerwert nach Schreibvorgang: 0x%X\n",MFRC_GET(adr_parameter));
				
				break;
				
			
			}
		}
	



    return 0;
}

