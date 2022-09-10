/* Function to swap array elements at x and y */
void Swap(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

/* Function Selection Sort */
void SelectionSort(int arr[], int n) {
	int pass, j, min_indx;

	// One by one move boundary of unsorted subarray
	for(pass = 0; pass < n-1; pass++) {
		// Find the minimum element in unsorted array
		min_indx = pass;
		for(j = pass + 1; j < n; j++) {
			if(arr[j] < arr[min_indx]) {
				min_indx = j;
			}
		}

		// Swap the found minimum element with the first element
		if(min_indx != pass) {
			Swap(arr, min_indx, pass);
		}
	}
}