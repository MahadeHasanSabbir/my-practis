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
	int page_faults = 0, i = 0, j = 0, k = 0, framequeue[frameno];
	while (i < pageno) {
		//check if the frame can hold pages
		if (frameno > capacity) {
            //check for page hit
			for(j = 0; j < capacity; j++){
                if(pages[i] == frames[j]){
                    //update queue
                    for(int x = 0; x < frameno - 1; x++){
                        if(j == framequeue[x]){
                            int t = framequeue[x];
                            framequeue[x] = framequeue[x + 1];
                            framequeue[x + 1] = t;
                        }
                    }
                    i++;
                    break;
                }
			}
			if(j == capacity){
                framequeue[k++] = capacity;
                //insert page into frame
                frames[capacity++] = pages[i++];
                // increment page fault
                page_faults++;
			}
		}
		else {
            //check for page hit
			for(j = 0; j < frameno; j++){
                if(pages[i] == frames[j]){
                    //update queue
                    for(int x = 0; x < frameno - 1; x++){
                        if(j == framequeue[x]){
                            int t = framequeue[x];
                            framequeue[x] = framequeue[x + 1];
                            framequeue[x + 1] = t;
                        }
                    }
                    i++;
                    break;
                }
			}
			if(j == frameno){
                //update queue
                int t = framequeue[0];
                for(int x = 0; x < frameno - 1; x++){
                    framequeue[x] = framequeue[x + 1];
                }
                framequeue[frameno - 1] = t;
                //insert page into frame
                frames[t] = pages[i++];
                // Increment page faults
                page_faults++;
			}
		}
	}
	//print result
    printf("\n Total page faults: %d\n Total page hit: %d\n", page_faults, pageno - page_faults);

	return 0;
}
