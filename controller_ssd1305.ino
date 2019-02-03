enum Letters {M='M',U='U',I='I',E='E',A='A',R='R',S='S',MIDDLE};
class Letter{
  public:
    Letter(Letters l){
      this->l = l;
      switch(l){
        case (Letters::M):
          pixels = new bool[30]{1,0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1};
          w = 5;
          h = 6;
          break;
        case (Letters::U):
          pixels = new bool[30]{1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,1,1,1};
          w = 5;
          h = 6;
          break;
        case(Letters::I):
          pixels = new bool[6]{1,1,1,1,1,1};
          w = 1;
          h = 6;
          break;
        case(Letters::E):
          pixels = new bool[24]{1,1,1,1,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,1};
          w = 4;
          h = 6;
          break;
        case(Letters::MIDDLE):
          pixels = new bool[256]{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0};
          w = 16;
          h = 16;
          break;
        case(Letters::A):
          pixels = new bool[30]{0,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1};
          w = 5;
          h = 6;
        break;
        case(Letters::R):
          pixels = new bool[30]{1,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1};
          w = 5;
          h = 6;
        break;
        case(Letters::S):
          pixels = new bool[30]{0,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0};
          w = 5;
          h = 6;
        break;
      }
    }
    ~Letter(){
      delete pixels;
    }
  Letters l;
  bool *pixels;
  int h,w;
};

class SSD1305{
  uint8_t* c;
  uint8_t* d;
  public:uint8_t buff[8][132];
  SSD1305(uint8_t* c /*RST,CS,RD,WR,DC*/,uint8_t* d){
    this->c = c;
    this->d = d;
    for(int i = 0;i<8;i++)
      for(int j = 0;j<132;j++)
        buff[i][j] = 0x00;
    Serial.begin(9600);
    for(int i = 0;i<5;i++)
      pinMode(c[i], OUTPUT);
    for(int i = 0; i < 8; i++)
      pinMode(d[i], OUTPUT);
    for(int i = 0;i<5;i++)
      digitalWrite(c[i], HIGH);
    delay(50);
    digitalWrite(c[0], LOW);
    delay(150);
    digitalWrite(c[0], HIGH);
    delay(150);
    digitalWrite(c[1], LOW);
    delay(10);
    //Serial.begin(9600); // FOR OUTPUT
    //controller->clear();
    writeBuff();
  }
  void writeBuff(){
    for(uint8_t i = 0;i<8;i++){
    setPageStartAddress(i);
    enterReadModifyWrite(); 
    for(uint8_t j=0;j<132;j++){
      write_data(buff[i][j]);
    }
    exitReadModifyWrite();
    }
  }
  void setLowerColumn(boolean d1,boolean d2,boolean d3,boolean d4){
    
  }
  void setHigherColumn(boolean d1,boolean d2,boolean d3,boolean d4){
    
  }
  void setMemoryAddressingMode(boolean a1,boolean a2){
    
  }
  void setPageAddress(boolean a0,boolean a1,boolean a2,boolean b0,boolean b1,boolean b2){
    
  }
  void setDisplayStartLine(boolean x0,boolean x1,boolean x2,boolean x3,boolean x4,boolean x5){
    
  }
  void setContrastControl(uint8_t hex){
    write_cmd_data(0x81,hex);
    delay(10);
  }
  void setBrightnessForArea(uint8_t hex){
    write_cmd_data(0x82,hex);
    delay(10);
  }
  void setLookUpTable(uint8_t hex6x,uint8_t hex6a,uint8_t hex6b,uint8_t hex6c){
    
  }
  void setSegReMap(boolean d0){
    
  }
  void setEntireDisplayOn(boolean d0){
    write_cmd(0xa5);
    delay(10);
  }
  void setNormalInvers(boolean d0){
    if(d0)
      write_cmd(0xa6);
    else
      write_cmd(0xa7);
  }
  void setMultiplexRatio(uint8_t hex6){
    
  }
  void setDisplayONOFF(boolean d0,boolean d1){
    write_cmd(0xac);
    delay(10);
  }
  void setPageStartAddress(uint8_t page){
    uint8_t s = 0xB0;
    uint8_t t = s|page;
    write_cmd(t);
  }
  void setColumnAddress(uint8_t start,uint8_t end){
    write_cmd(0x21);
    write_cmd(start);
    write_cmd(end);
  }
  void setCOMOutput(boolean d3){
    
  }
  void setDisplayOffset(uint8_t hex6){
    
  }
  void horizontalScrollSetup(){
    write_cmd(0x27);
    //How much columns
    write_cmd(0x01);
    //From what page
    write_cmd(0x00);
    //Speed
    write_cmd(0x04);
    //To what page
    write_cmd(0x02);
  }
  void continuousScrollSetup(){
    write_cmd(0x29);
    write_cmd(0x01);
    write_cmd(0x03);
    write_cmd(0x04);
    write_cmd(0x07);
    write_cmd(0x01);
  }
  void activateScroll(){
    write_cmd(0x2f);
  }
  void dezactivateScroll(){
    write_cmd(0x2e);
  }
  void enterReadModifyWrite(){
    write_cmd(0xe0);
    delay(10);
  }
  void exitReadModifyWrite(){
    write_cmd(0xee);
    delay(10);
  }
  
  void clear(){
    for(uint8_t i = 0;i<8;i++){
      for(uint8_t j=0;j<132;j++){
        buff[i][j] = 0x00;
      }
    }
    writeBuff();
  }
  void write_cmd(uint8_t cmd) {
    digitalWrite(c[4], LOW);
    delay(10);
    write_bus(cmd);
  }
  void write_cmd_data(uint8_t cmd, uint8_t data) { //Pull low for write command or read status
    write_cmd(cmd);
    write_data(data);
  }
  void write_data(uint8_t data) { //Pull high for write/read display data
    digitalWrite(c[4], HIGH);
    write_bus(data);
  }
  void write_bus(uint8_t val) {
    unsigned char i, temp, data;
    data = val;
    digitalWrite(c[3], LOW);
  //  delay(10);
    for (i = 0; i < 8; i++) {
      temp = (data & 0x01);
      if (temp)
        digitalWrite(d[i], HIGH);
      else
        digitalWrite(d[i], LOW);
      data = data >> 1;
    }
   // delay(10);
    digitalWrite(c[3], HIGH);
  }
};

SSD1305* controller;
void setup() {
  uint8_t* CPINS = new uint8_t[5]{A0,A1,A2,A3,A4}; //RST,WR,RD,CS,DC
  uint8_t* DPINS = new uint8_t[8]{13, 12, 11, 10, 9, 8, 7, 6};//d0-d7
  //uint8_t DPINS = new uint8_t[8]{6,7,8,9,10,11,12,13};
  controller = new SSD1305(CPINS,DPINS);
  controller->setDisplayONOFF(true,true);
  //controller->horizontalScrollSetup();
//  controller->continuousScrollSetup();
 // controller->setColumnAddress(0,132);
  //writeLetter(new Letter(Letters::MIDDLE),48,32,2);
  writeText("MMMAAAMAAIU",0,1);
  //writeText("MAMA",32,2);
 // controller->activateScroll();
}

void writeText(String text,uint8_t posy,uint8_t scale){
  int start = 2;
  for (int i = 0; i < text.length(); i++){
    char c = text.charAt(i);
    if(c != ' '){
      Letter *l = new Letter((Letters)c);
      int k = (l->w+1)*scale;
      writeLetter(l,start,posy,scale);
      start+=k;
    }else
      start+=8*scale;
  }
  
  //controller->dezactivateScroll();
  controller->writeBuff();
  //controller->activateScroll();
}
void writeLetter(Letter* l,uint8_t x,uint8_t y,uint8_t s){
  for(int i = x;(i<x+l->w*s);i++){
    for(int j = y;(j<y + l->h*s);j++){
      uint8_t px = (i-x)/s;
      uint8_t py = (j-y)/s;
      uint8_t hex = controller->buff[j/8][i];
      uint8_t m = j%8;
      uint8_t mask = 0x01;
      mask = mask << m;
      if(l->pixels[py*l->w + px] == 1)
        hex = hex|mask;
      else{
        mask = ~mask;
        hex = hex&mask;
      }
      controller->buff[j/8][i] = hex;
    }
  }
  delete l;
}
