#define LIGHT_CHANEL 16    
#define LIGHT_VALUES 8
#define KEYPADI2C 0x20
#define LCD_ADR 0x27
#define LED_DRV 0x40


  // PIN MAPPING NICHT ÄNDERN!!!
// Pin Mapping für Nano
  #define PIN_TEMP 4  // Temperatur
  #define PIN_PWM 11  // PWM PIN    // Lüfter

// Temperatur ab Wann Lüfter an gehen (Ganzzahl)
const float cTemp = 60;

// Licht Einstellungen immer paar aus Uhrzeit und % angabe. Je reihe Zahl von LIGHT_VALUES, so viele Reihen wie in LIGHT_CHANEL
LIGHT light_channels[LIGHT_CHANEL][LIGHT_VALUES] ={
        {{get_ts(0,1,0),0},{get_ts(10,0,0),0},{get_ts(11,30,0),100},{get_ts(19,0,0),100},{get_ts(20,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(9,0,0),0},{get_ts(11,0,0),100},{get_ts(19,0,0),100},{get_ts(21,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(10,0,0),0},{get_ts(11,30,0),100},{get_ts(19,0,0),100},{get_ts(20,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(9,0,0),0},{get_ts(11,0,0),100},{get_ts(19,0,0),100},{get_ts(21,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(10,30,0),0},{get_ts(11,30,0),0},{get_ts(12,30,0),0},{get_ts(13,30,0),0},{get_ts(14,30,0),0},{get_ts(15,30,0),0},{get_ts(16,30,0),0},{get_ts(17,30,0),0}},
        {{get_ts(10,30,0),0},{get_ts(11,30,0),0},{get_ts(12,30,0),0},{get_ts(13,30,0),0},{get_ts(14,30,0),0},{get_ts(15,30,0),0},{get_ts(16,30,0),0},{get_ts(17,30,0),0}},
        {{get_ts(0,1,0),0},{get_ts(8,30,0),0},{get_ts(9,0,0),20},{get_ts(9,30,0),0},{get_ts(20,0,0),0},{get_ts(20,30,0),70},{get_ts(21,0,0),0},{get_ts(23,30,0),0}}, //Rot
        {{get_ts(8,30,0),5},{get_ts(9,30,0),0},{get_ts(20,30,0),0},{get_ts(21,0,0),40},{get_ts(21,30,0),20},{get_ts(21,50,0),10},{get_ts(21,55,20),10},{get_ts(23,55,20),5}},  // Blau
        
        {{get_ts(0,1,0),0},{get_ts(10,0,0),0},{get_ts(11,30,0),100},{get_ts(19,0,0),100},{get_ts(20,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(9,0,0),0},{get_ts(11,0,0),100},{get_ts(19,0,0),100},{get_ts(21,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(10,0,0),0},{get_ts(11,30,0),100},{get_ts(19,0,0),100},{get_ts(20,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(0,1,0),0},{get_ts(9,0,0),0},{get_ts(11,0,0),100},{get_ts(19,0,0),100},{get_ts(21,0,0),0},{get_ts(21,30,0),0},{get_ts(23,30,0),0},{get_ts(23,32,0),0}},
        {{get_ts(10,30,0),0},{get_ts(11,30,0),0},{get_ts(12,30,0),0},{get_ts(13,30,0),0},{get_ts(14,30,0),0},{get_ts(15,30,0),0},{get_ts(16,30,0),0},{get_ts(17,30,0),0}},
        {{get_ts(10,30,0),0},{get_ts(11,30,0),0},{get_ts(12,30,0),0},{get_ts(13,30,0),0},{get_ts(14,30,0),0},{get_ts(15,30,0),0},{get_ts(16,30,0),0},{get_ts(17,30,0),0}},
        {{get_ts(0,1,0),0},{get_ts(8,30,0),0},{get_ts(9,0,0),20},{get_ts(9,30,0),0},{get_ts(20,0,0),0},{get_ts(20,30,0),70},{get_ts(21,0,0),0},{get_ts(23,30,0),0}}, //Rot
        {{get_ts(8,30,0),5},{get_ts(9,30,0),0},{get_ts(20,30,0),0},{get_ts(21,0,0),40},{get_ts(21,30,0),20},{get_ts(21,50,0),10},{get_ts(21,55,20),10},{get_ts(23,55,20),5}}  // Blau
      };

// Dies nicht ändern!!!
LIGHT dimming[LIGHT_CHANEL] ={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
