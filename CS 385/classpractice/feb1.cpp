/*

 * feb1.cpp
 *
 *      Author: JamesJz
 */
int sequential_search(int array[], int length, int key){
	for (int i=0, i<length, i++){
		if (array[i]==key){
			return i;
		}
	}
	return -1;
}



