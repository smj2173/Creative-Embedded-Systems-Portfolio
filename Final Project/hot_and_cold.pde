import processing.serial.*;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JPanel;

Serial myPort;  // Create object from Serial class
String val; 
int past_distance;
int target_distance;
int Y_AXIS = 1;
boolean game_over;
PImage win_img;
String last_label;
int X_AXIS = 2;
color b1, b2, c1, c2;
int b1_R, b1_G, b1_B, b2_B, b2_G, b2_R;
//constants

// Data received from the serial port
int dim;   

void setup() {
  size(640, 360);
  target_distance = 50;
  colorMode(RGB);
  int b1_R = 0;
  int b1_G = 190;
  int b1_B = 255;
  int b2_R = 0;
  int b2_G = 0;
  game_over = false;
  last_label = "colder";
  win_img = loadImage("winner.gif");
  past_distance = abs(400 - target_distance); //max distance it can be away
  int b2_B = 255;
  b1 = color(b1_R, b1_G, b1_B, 255);
  b2 = color(b2_R, b2_G, b2_B, 255);
  //orange is RGB(255, 102, 0)
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[1];
  System.out.println(portName);
  myPort = new Serial(this, portName, 115200);
}

void draw()
{
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
  }
  val = trim(val);
  String s = val.replaceAll("[^\\d.]", "");
  System.out.println(s);
  int val_2 = Integer.parseInt(s);
  String temp = "";
  
  if (abs(target_distance-val_2) < 10){
    game_over = true;
    image(win_img, 150, 0, width, height);
    noLoop();
  }
  
  // getting further away
  if (game_over == false){
    
    if (abs(target_distance-val_2) > abs(target_distance-past_distance)) {
      //make colors darker
      b1_R = b1_R - 10;
      b1_G = b1_G + 5;
      b1_B = b1_B + 30;
  
      b2_R = b2_R - 30;
      b2_G = b2_G - 5;
      b2_B = b2_B + 30;
      b1 = color(b1_R, b1_G, b1_B);
      b2 = color(b2_R, b2_G, b2_B);
      setGradient(0, 0, width/2, height, b1, b2, X_AXIS);
      setGradient(width/2, 0, width/2, height, b2, b1, X_AXIS);
      if (abs(val_2 - past_distance) > 3){
        textSize(100);
        text("colder",170, 100, width/2, height/2);
        temp = "colder";
      }
      }   
    }
    if (val_2 == past_distance){
      temp = last_label; //want to keep the label the same
    }
    if (abs(target_distance-val_2) < abs(target_distance-past_distance)) {
      // Background
      b1_R = b1_R + 10;
      b1_G = b1_G - 5;
      b1_B = b1_B - 30;
  
      b2_R = b2_R + 30;
      b2_G = b2_G + 5;
      b2_B = b2_B - 30;
      b1 = color(b1_R, b1_G, b1_B);
      b2 = color(b2_R, b2_G, b2_B);
      setGradient(0, 0, width/2, height, b1, b2, X_AXIS);
      setGradient(width/2, 0, width/2, height, b2, b1, X_AXIS);
      int sum = abs(past_distance - val_2);
      textSize(100);
      if (sum > 3){
        textSize(100);
        text("hotter",170, 100, width/2, height/2);
      }
    }
     past_distance = val_2;
     last_label = temp;
}

void setGradient(int x, int y, float w, float h, color c1, color c2, int axis ) {

  noFill();

  if (axis == Y_AXIS) {  // Top to bottom gradient
    for (int i = y; i <= y+h; i++) {
      float inter = map(i, y, y+h, 0, 1);
      color c = lerpColor(c1, c2, inter);
      stroke(c);
      line(x, i, x+w, i);
    }
  }  
  else if (axis == X_AXIS) {  // Left to right gradient
    for (int i = x; i <= x+w; i++) {
      float inter = map(i, x, x+w, 0, 1);
      color c = lerpColor(c1, c2, inter);
      stroke(c);
      line(i, y, i, y+h);
    }
  }
}
