/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MFRCREG_H
#define	MFRCREG_H

// TODO Insert appropriate #include <>


#define read					0x80
/*-----------Command and Status--------------*/
//#define Reserved 0x00 << 1
#define CommandReg              0x01 << 1           //starts and stops command execution
#define ComlEnReg               0x02 << 1           //enable and disable interrupt request control bits
#define DivlEnReg               0x03 << 1           //enable and disable interrupt request control bits
#define ComIrqReg               0x04 << 1           //interrupt request bits
#define DivIrqReg               0x05 << 1           //interrupt request bits
#define ErrorReg                0x06 << 1           //error bits showing the error status of the last command executed
#define Status1Reg              0x07 << 1           //communication status bits 
#define Status2Reg              0x08 << 1           //receiver and transmitter status bits
#define FIFODataReg             0x09 << 1           //input and output of 64 byte FIFO buffer
#define FIFOLevelReg            0x0A << 1           //number of bytes stored in the FIFO buffer
#define WaterLevelReg           0x0B << 1           //level for FIFO underflow and overflow warning
#define ControlReg              0x0C << 1           //miscellaneous(ger.: sonstiges) control register
#define BitFramingReg           0x0D << 1           //adjustments for bit-oriented frames 
#define CollReg                 0x0E << 1           //bit position of the first bit-collision detected on the RF interface
//#define Reserved              0x0F << 1           




/*-----------Command--------------*/
//#define Reserved                0x10 << 1
#define ModeReg                 0x11 << 1           //defines general modes for transmitting and receiving
#define TxModeReg               0x12 << 1           //defines transmission data rate and framing
#define RxModeReg               0x13 << 1           //defines reception data rate and framing
#define TxControlReg            0x14 << 1           //controls the logical behavior of the antenna driver pins TX1 and TX2
#define TxASKReg                0x15 << 1           //controls the setting of the transmission modulation
#define TxSelReg                0x16 << 1           //selects the internal sources for the antenna driver
#define RxSelReg                0x17 << 1           //selects internal receiver setting
#define RxThresholdReg          0x18 << 1           //selects thresholds for the bit decoder
#define DemodReg                0x19 << 1           //defines demodulator settings
//#define Reserved                0x1A << 1
//#define Reserved                0x1B << 1
#define MfTxReg                 0x1C << 1           //controls some MIFARE communication transmit parameters
#define MfRxReg                 0x1D << 1           //controls some MIFARE communication receive parameters
//#define Reserved                0x1E << 1
#define SerialSpeedReg          0x1F << 1           //selects the speed of the serial UART interface


/*-----------Configuration--------------*/
//#define Reserved                0x20 << 1
#define CRCResultMSB            0x21 << 1           //shows the MSB and LSB values of the CRC calculation
#define CRCResultLSB            0x22 << 1           //shows the MSB and LSB values of the CRC calculation
//#define Reserved                0x23 << 1
#define ModWidthReg             0x24 << 1           //controls the ModWidth setting
//#define Reserved                0x25 << 1 
#define RFCfgReg                0x26 << 1           //configures the receiver gain
#define GsNReg                  0x27 << 1           //selects the conductance of the antenna driver pins TX1 and T2 for modulation
#define CWGsPReg                0x28 << 1           //defines the conductance of the p-driver output during periods of no modulation
#define ModGsPReg               0x29 << 1           //defines the conductance of the p-driver output during periods of modulation
#define TModeReg                0x2A << 1           //defines settings for the internal timer
#define TPrescalerReg           0x2B << 1           //defines settings for the internal timer
#define TReload_Hi              0x2C << 1           //defines the 16-bit timer reload value
#define TReload_Lo              0x2D << 1           //defines the 16-bit timer reload value
#define TCounterVal_Hi          0x2E << 1           //shows the 16-bit timer value
#define TCounterVal_Lo          0x2F << 1           //shows the 16-bit timer value
 

/*-----------Test Register--------------*/
//#define Reserved                0x30 << 1
#define TestSel1Reg             0x31 << 1           //general test signal configuration
#define TestSel2Reg             0x32 << 1           //general test signal coniguration and PRBS control
#define TestPinEnReg            0x33 << 1           //enables pin output driver on pins D1 to D7
#define TestPinValueReg         0x34 << 1           //defines the values for D1 to D7 when it is used as an I/O Bus
#define TestBusReg              0x35 << 1           //shows the status of the internal test bus
#define AutoTestReg             0x36 << 1           //controls the digital self test
#define VersionReg              0x37 << 1           //shows the software version
#define AnalogTestReg           0x38 << 1           //controls the pins AUX1 and AUX2
#define TestDAC1Reg             0x39 << 1           //defines the test value for TestDAC1
#define TestDAC2Reg             0x3A << 1           //defines the test value for TestDAC2
#define TestADCReg              0x3B << 1           //shows the value of ADC 1 and Q channels
//#define Reserved                0x3C << 1     

/*Command Defines*/
//*****************************************
#define IDLE                    0x00
#define Mem                     0x01
#define Generate_RandomID       0x02
#define CalcCRC                 0x03
#define Transmit                0x04
#define NoCmdChange             0x07
#define Receive                 0x08
#define Transceive              0x0C
#define None                    0x0D
#define MFAuthent               0x0E
#define SoftReset               0x0F
//******************************************















// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

