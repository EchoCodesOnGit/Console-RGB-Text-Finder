#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

int main() {

CONSOLE_SCREEN_BUFFER_INFOEX data;
data.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int redVal;
int greenVal;
int blueVal;

cout << "****************************************************" << endl;
cout << "Enter three whole numbers for color values (0 - 255)" << endl;
cout << "****************************************************" << endl;

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[5] = RGB(255,0,0);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 5);
cout << "Red: ";
cin >> redVal;

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[6] = RGB(0,255,0);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 6);
cout << "Green: ";
cin >> greenVal;

GetConsoleScreenBufferInfoEx(hConsole,&data); 
data.ColorTable[1] = RGB(0,0,255); 			  
SetConsoleScreenBufferInfoEx(hConsole,&data); 
SetConsoleTextAttribute(hConsole, 1);
cout << "Blue: ";
cin >> blueVal;

if ((redVal > 255 || redVal < 0) || (blueVal > 255 || blueVal < 0) ||(greenVal > 255 || greenVal < 0)) {
	
cout << "Please enter a valid whole number between 0 to 255 for each color." << endl;

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[5] = RGB(255,0,0);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 5);
cout << "Red: ";
cin >> redVal;

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[6] = RGB(0,255,0);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 6);
cout << "Green: ";
cin >> greenVal;

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[1] = RGB(0,0,255);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 1);
cout << "Blue: ";
cin >> blueVal;

} else {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[8] = RGB(redVal, greenVal, blueVal);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 8);
cout << endl;
cout << "Success!" << endl;

}

if (redVal > greenVal && redVal > blueVal) {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[9] = RGB(255, 0, 0);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 9);
cout << endl;
cout << "Red has the highest amount of presence: " << redVal;

} else if (greenVal > redVal && greenVal > blueVal) {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[10] = RGB(0, 255, 0);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 10);
cout << endl;
cout << "Green has the highest amount of presence: " << greenVal;

} else if (blueVal > redVal && blueVal > greenVal) {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[11] = RGB(0, 0, 255);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 11);
cout << endl;
cout << "Blue has the highest amount of presence: " << blueVal;

} else if (redVal == blueVal && redVal > greenVal ) {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[12] = RGB(255, 0, 255);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 12);
cout << endl;
cout << "Both Red and Blue have the highest amount of presence: " << redVal;

} else if (redVal == greenVal && redVal > blueVal) {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[13] = RGB(255, 255, 0);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 13);
cout << endl;
cout << "Both Red and Green have the highest amount of presence: " << greenVal;

} else if (blueVal == greenVal && blueVal > redVal) {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[14] = RGB(0, 255, 255);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 14);
cout << endl;
cout << "Both Blue and Green have the highest amount of presence: " << blueVal;

} else if (redVal == blueVal && redVal == greenVal && blueVal == greenVal) {

GetConsoleScreenBufferInfoEx(hConsole, &data);
data.ColorTable[15] = RGB(redVal, greenVal, blueVal);
SetConsoleScreenBufferInfoEx(hConsole, &data);
SetConsoleTextAttribute(hConsole, 15);
cout << endl;
cout << "All of Red, Green, and Blue have the highest amount of presence: " << redVal;

}

return 0;

}
