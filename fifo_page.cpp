#include <iostream>
using namespace std;
int main() {
int frames, pages;
cout << "Enter number of frames: ";
cin >> frames;
cout << "Enter number of pages: ";
cin >> pages;
int page[50];
cout << "Enter page reference string: ";
for (int i = 0; i < pages; i++) {
cin >> page[i];
}
int frame[10];
int count = 0, pageFaults = 0, pageHits = 0;
for (int i = 0; i < frames; i++) {
frame[i] = -1;
}
for (int i = 0; i < pages; i++) {
int flag = 0;
for (int j = 0; j < frames; j++) {
if (frame[j] == page[i]) {
flag = 1;
pageHits++;
break;
}
}
if (flag == 0) {
frame[count] = page[i];
count = (count + 1) % frames;
pageFaults++;
}
cout << "Page " << page[i] << " -> ";
        for (int j = 0; j < frames; j++) {
            if (frame[j] == -1)
                cout << "- ";
            else
                cout << frame[j] << " ";
        }
        if (flag == 0) cout << " <-- Fault";
        else cout << " <-- Hit";
        cout << endl;
}
cout << "\nTotal Page Faults: " << pageFaults << endl;
cout << "Total Page Hits: " << pageHits << endl;
cout << "Page Fault Rate: " << (float)pageFaults / pages << endl;
return 0;
}