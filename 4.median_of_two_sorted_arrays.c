double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, index = 0;
    int mergedSize = nums1Size + nums2Size;
    
    int *merge = malloc(mergedSize * sizeof(int));
    
    while(i < nums1Size && j < nums2Size) {
        if(nums1[i] < nums2[j]) {
            merge[index++] = nums1[i++];
        }
        else {
            merge[index++] = nums2[j++];
        }
    }
    if(i < nums1Size) {
        while(i < nums1Size) {
            merge[index++] = nums1[i++];
        }
    }                      
    if(j < nums2Size) {
        while(j < nums2Size) {
            merge[index++] = nums2[j++];
        }
    }
                        
    if(mergedSize % 2 == 0) {
        return (double)(merge[mergedSize/2] + merge[(mergedSize/2)-1]) / 2;
    }
    else {
        return (double)merge[mergedSize/2];
    }   
    
}