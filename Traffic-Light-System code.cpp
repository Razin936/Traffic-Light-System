// 'C++ code
//
void setup()
{
pinMode (0, OUTPUT);
pinMode(1, OUTPUT);
pinMode (2, OUTPUT); 
}
void loop ()
{
digitalWrite(0, HIGH); 
delay (3000); 
digitalWrite(0, LOW); 

digitalWrite(1, HIGH); 
delay (1000); 
digitalWrite(1, LOW); 
digitalWrite(2, HIGH); 
delay (15000); 
digitalWrite(2, LOW);

}
