/*
 * Base Example 
 *
 *   Sketch that features the basic building blocks of a Spacebrew client app.
 * 
 */

import spacebrew.*;

String server="sandbox.spacebrew.cc";//keep the same 
String name="CC Lab Spacebrew";
String description ="Button...";

Spacebrew sb;
color color_on = color(255,0,0); //red 
color color_off = color(0,255,0);
int currentColor = color_off;//?

void setup() {
  size(600, 400);

  // instantiate the sb variable
  sb = new Spacebrew( this );

  // add each thing you publish to
  sb.addPublish( "buttonYSQ", "boolean", true ); //set the button a value 

  // add each thing you subscribe to
  sb.addSubscribe( "change_background", "boolean" ); //"range" is a data type should be the same 

  // connect to spacebrew
  sb.connect(server, name, description ); //passing the vairables 

}

void draw() {
  // do whatever you want to do here  
  background(currentColor);
  //draw button
  fill(0,0,255);
  rectMode(CENTER);
  ellipse(width/2, height/2, 250, 250);
  
  //add text 
  fill(230);
  textAlign(CENTER);
  textSize(20);
  if(mousePressed == true){
    text("true", width/2, height/2);
  }else{
    //do this 
    text("False", width/2, height/2);
  }
}

//mouse pressed functions 
void mousePressed(){
  sb.send("buttonYSQ", true);//the name should be the same from the beginning 
}

//mouse released functions 
void mouseReleased(){
  sb.send("buttonCathy", false);
}

//void onRangeMessage( String name, int value ){
//  println("got range message " + name + " : " + value);
//}

void onBooleanMessage( String name, boolean value ){
  println("got boolean message " + name + " : " + value);  
  //send the colors, boolean value 
  if(value == true){
  currentColor = color_on;
  } else{
  currentColor = color_off;
  }
}

//void onStringMessage( String name, String value ){
//  println("got string message " + name + " : " + value);  
//}

//void onCustomMessage( String name, String type, String value ){
//  println("got " + type + " message " + name + " : " + value);  
//}
