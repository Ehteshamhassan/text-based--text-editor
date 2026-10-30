#include <iostream>
#include <vector>
#include <conio.h>  
#include <stdlib.h> 

using namespace std;

class GapBuffer {
private:
    vector<char> buffer;
    int gap_left;
    int gap_right;
    int size;

public:
    GapBuffer(int s = 30) {
        size = s;
        buffer.resize(size, '_'); 
        gap_left = 0;
        gap_right = size;         
    }

    void insert(char c) {
        if (gap_left == gap_right) return; 
        buffer[gap_left] = c;
        gap_left++;
    }

    void backspace() {
        if (gap_left > 0) {
            gap_left--;
            buffer[gap_left] = '_'; 
        }
    }

    void move_left() {
        if (gap_left > 0) {
            gap_left--;
            gap_right--;
            buffer[gap_right] = buffer[gap_left];
            buffer[gap_left] = '_'; 
        }
    }

    void move_right() {
        if (gap_right < size) {
            buffer[gap_left] = buffer[gap_right];
            buffer[gap_right] = '_';
            gap_left++;
            gap_right++;
        }
    }

    void debug_print() {
        cout << "Memory Array: [ ";
        for (int i = 0; i < size; i++) {
            cout << buffer[i] << " ";
        }
        cout << "]\n";
    }
    
    void print_text() {
        cout << "Actual Text : \"";

        for (int i = 0; i < gap_left; i++) cout << buffer[i];
        cout << "|"; 

        for (int i = gap_right; i < size; i++) cout << buffer[i];
        cout << "\"\n";
    }
};

int main() {
    GapBuffer editor(30);
    char ch;

    while (true) {
        system("cls"); 
        
        cout << "=== INTERACTIVE GAP BUFFER ===\n";
        cout << "Type letters. Press BACKSPACE to delete.\n";
        cout << "Press '<' to move cursor left, '>' to move cursor right.\n";
        cout << "Press ESC to quit.\n\n";

        editor.debug_print();
        cout << "\n";
        editor.print_text();

        ch = _getch(); 

        if (ch == 27) {         // for ESC
            break;
        } 
        else if (ch == 8) {   // for Backspace
            editor.backspace();
        } 
        else if (ch == '<') { 
            editor.move_left();
        } 
        else if (ch == '>') { 
            editor.move_right();
        } 
        else if (ch >= 32 && ch <= 126) { 
            editor.insert(ch);
        }
    }

    cout << "\nEditor closed.\n";
    return 0;
}