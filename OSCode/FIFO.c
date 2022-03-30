#include<stdio.h>

int main(void) {
    //normal variable
	int pageno, frameno, capacity;
	printf("\n Enter amount of page: ");
	scanf("%d", &pageno);
	printf("\n Enter amount of frame: ");
	scanf("%d", &frameno);
	capacity = 0;
    //page and frame array
	int pages[pageno], frames[frameno];
	//take reference string
	printf("\n Enter reference string (Ex: 2 5 10 3 ...): ");
	for(int i = 0; i < pageno; i++){
        scanf("%d", &pages[i]);
	}
	//initialize frame with big int
	for(int i = 0; i < frameno; i++){
        frames[i] = 99999;
	}
	//calculate page fault
	int page_faults = 0, i = 0, j = 0, k;
	while (i < pageno) {
		//check if the frame can hold more pages
		if (frameno > capacity) {
            //check for page hit
			for(k = 0; k < capacity; k++){
                if(pages[i] == frames[k]){
                    i++;
                    break;
                }
			}
            //insert page into frame
			if(k == capacity){
                frames[capacity++] = pages[i++];
                // increment page fault
                page_faults++;
			}
		}
		else {
			if (frameno == j) {
			    j = 0;
			}
            //check for page hit
			for(k = 0; k < frameno; k++){
                if(pages[i] == frames[k]){
                    i++;
                    break;
                }
			}
			//insert page into frame
			if(k == frameno){
                frames[j++] = pages[i++];
                // Increment page faults
                page_faults++;
			}
		}
	}
	//print result
    printf("\n Total page faults: %d\n Total page hit: %d\n", page_faults, pageno - page_faults);

	return 0;
}
