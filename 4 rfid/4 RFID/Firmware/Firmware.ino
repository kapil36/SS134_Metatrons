
// Include Libraries
#include "Arduino.h"
#include "RFID.h"


// Pin Definitions
#define RFID_1_PIN_RST	2
#define RFID_1_PIN_SDA	10
#define RFID_2_PIN_RST	3
#define RFID_2_PIN_SDA	4
#define RFID_3_PIN_RST	5
#define RFID_3_PIN_SDA	6
#define RFID_4_PIN_RST	7
#define RFID_4_PIN_SDA	8




RFID rfid_1(RFID_1_PIN_SDA,RFID_1_PIN_RST);
RFID rfid_2(RFID_2_PIN_SDA,RFID_2_PIN_RST);
RFID rfid_3(RFID_3_PIN_SDA,RFID_3_PIN_RST);
RFID rfid_4(RFID_4_PIN_SDA,RFID_4_PIN_RST);


//define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
//char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    //initialize RFID module
    rfid_1.init();
    //initialize RFID module
    rfid_2.init();
    //initialize RFID module
    rfid_3.init();
    //initialize RFID module
    rfid_4.init();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    String rfid_1tag = rfid_1.readTag();
    //print the tag to serial monitor if one was discovered
    rfid_1.printTag(rfid_1tag);

    String rfid_2tag = rfid_2.readTag();
    //print the tag to serial monitor if one was discovered
    rfid_2.printTag(rfid_2tag);
    
    String rfid_3tag = rfid_3.readTag();
    //print the tag to serial monitor if one was discovered
    rfid_3.printTag(rfid_3tag);
    
    String rfid_4tag = rfid_4.readTag();
    //print the tag to serial monitor if one was discovered
    rfid_4.printTag(rfid_4tag);    
}
